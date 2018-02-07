#ifndef CONFIG_H_INCLUDED
#define CONFIG_H_INCLUDED

#define MEMS_DISABLED 0
#define MEMS_ACC 1
#define MEMS_9DOF 2
#define MEMS_DMP 3

#define STORAGE_NONE 0
#define STORAGE_SD 1
#define STORAGE_SPIFFS 2

/**************************************
* Data logging/streaming out
**************************************/

#ifndef ENABLE_DATA_OUT

// enable(1)/disable(0) data streaming
#define ENABLE_DATA_OUT 0

// file size limit
#define MAX_DATA_FILE_SIZE 1024000 /* KB */

/**************************************
* Hardware setup
**************************************/

// enable(1)/disable(0) OBD-II reading
#define USE_OBD 1

// enable(1)/disable(0) GPS module
#define USE_GPS 1

#endif

// enable(1)/disable(0) quaternion calculation to get orientation
#ifndef ENABLE_ORIENTATION
#define ENABLE_ORIENTATION 0
#endif

#if ENABLE_ORIENTATION
#define MEMS_MODE MEMS_9DOF
#elif !defined(MEMS_MODE)
#define MEMS_MODE MEMS_ACC
#endif

#ifndef STORAGE
#define STORAGE STORAGE_SD
#endif

// GPS parameters
#define GPS_SERIAL_BAUDRATE 115200L

// motion detection
#define WAKEUP_MOTION_THRESHOLD 0.2 /* G */

#endif // CONFIG_H_INCLUDED
