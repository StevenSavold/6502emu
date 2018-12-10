#pragma once

/* This is the pre-compiled header for the 6502 
 * project. Any #includes that will not be frequently 
 * modified should be placed in this header, so it can
 * be pre-compiled and help to speed up build times.
 *
 */

// Some common C++ Standard Library headers
#include <iostream>
#include <vector>
#include <memory>
#include <utility>
#include <string>
#include <sstream>
#include <functional>
#include <algorithm>
#include <fstream>
#include <chrono>

/* windows only includes */
#ifdef _6502_PLATFORM_WINDOWS
	/* 
		NOTE: putting this here out of precaution.
		This will probably be more suited to only be 
		included in a future project to create a monitor 
		peripheral 
	*/
	#include <Windows.h>

#else

/* Unix-based systems includes */

#endif