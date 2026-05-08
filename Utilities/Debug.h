#pragma once
#include "FileUtilities.h"

// TODO: Add platform specific debug break functionality for non-MSVC compilers
// Only Works for MSVC, for other compilers 
// you will need to use platform specific intrinsics
// or APIs to trigger a breakpoint	
#ifdef _DEBUG
#define debugBreak() \
	__debugbreak();
#else
#define debugBreak() 
#endif


#ifdef _DEBUG 
#define ASSERT(expr) do { \
		if (!(expr)) \
		{ \
			const std::string error = "Assert Failure in file " __FILE__ " at line " + std::to_string(__LINE__) + " with expression: " #expr;\
			FileUtilities::Instance()->WriteToDebugLog(error); \
			debugBreak(); \
		}} while (0);
#else 
#define ASSERT(expr) 
#endif 

#ifdef _DEBUG 
#define LOGGING(expr) \
		{ \
			const std::string message = "LOGGING: " __FILE__ " at line " + std::to_string(__LINE__) + " with expression: " #expr;\
			FileUtilities::Instance()->WriteToEventLog(message); \
		} 
#else 
#define LOGGING(expr) 
#endif 

#define TRY_CATCH_START \
	try { \

#define TRY_CATCH_END \
	} catch (const std::exception& e) { \
		const std::string error = "Exception caught in file " __FILE__ " at line " + std::to_string(__LINE__) + ": " + e.what(); \
		FileUtilities::Instance()->WriteToDebugLog(error); \
	} catch (...) { \
		const std::string error = "Unknown exception caught in file " __FILE__ " at line " + std::to_string(__LINE__); \
		FileUtilities::Instance()->WriteToDebugLog(error); \
	}