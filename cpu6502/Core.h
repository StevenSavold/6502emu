/* Core.h
 * Written by Steven Savold 
 * 
 * This file provides the preprocessor macros
 * for _6502_API and other useful build config
 * macros
 */
#ifndef _CORE_H_
#define _CORE_H_

 /* if the platform is windows, you need __declspec calls */
#ifdef _6502_PLATFORM_WINDOWS
    #ifdef _6502_BUILD_DLL
        #define _6502_API __declspec(dllexport)
    #else 
        #define _6502_API __declspec(dllimport)
    #endif

/* if the platform is not windows, you don't need __declspec calls */
#else
    #define _6502_API /*Empty_6502_API*/
#endif

#endif //_CORE_H_
