#pragma once
#include <assert.h>

#if defined(_DEBUG) || defined(DEBUG)

	#define assertmsg(expr, msg)    ((void)(                    \
		(!!(expr)) ||                                           \
		(_wassert(                                              \
				_CRT_WIDE(#expr) L" \"" _CRT_WIDE(msg) L"\"",   \
				_CRT_WIDE(__FILE__),                            \
				(unsigned)(__LINE__)), 0)                       \
	))

	#define ASSERTMSG    assertmsg




	#define assertmsg_dbgprt(expr, msg)    ((void)(                           \
		(!!(expr)) ||                                                         \
		(OutputDebugStringW(                                                  \
				L"Assertion failed: "                                         \
					_CRT_WIDE(#expr) L" \"" _CRT_WIDE(msg) L"\"\n"), 0) ||    \
		(_wassert(                                                            \
				_CRT_WIDE(#expr) L" \"" _CRT_WIDE(msg) L"\"",                 \
				_CRT_WIDE(__FILE__),                                          \
				(unsigned)(__LINE__)), 0)                                     \
	))

	#define ASSERTMSG_DBGPRT    assertmsg_dbgprt




#else // if _DEBUG

	#define assertmsg(expr, msg)    ((void)0)

	#define ASSERTMSG    assertmsg




#endif // if _DEBUG



