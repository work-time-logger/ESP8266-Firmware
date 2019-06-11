#ifndef _DEBUG_H
#define _DEBUG_H

#include <Arduino.h>

#ifdef DEBUG_APP_GENERIC
    #ifdef DEBUG_PORT
        #define DEBUG_APP(...) DEBUG_PORT.printf( __VA_ARGS__ )
    #else
        #define DEBUG_APP(...)
    #endif
#else
    #define DEBUG_APP(...)
#endif

#ifdef DEBUG_PORT
    #define DEBUG_TEST(...) DEBUG_PORT.printf( __VA_ARGS__ )
#else
    #define DEBUG_TEST(...)
#endif

#ifdef DEBUG_APP_BACKEND
    #ifdef DEBUG_PORT
        #define DEBUG_BACKEND(...) DEBUG_PORT.printf( __VA_ARGS__ )
    #else
        #define DEBUG_BACKEND(...)
    #endif
#else
    #define DEBUG_BACKEND(...)
#endif


#endif //_DEBUG_H
