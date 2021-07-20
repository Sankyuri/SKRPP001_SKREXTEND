#pragma once


#if defined(_UNICODE) || defined(UNICODE)

	#define _tstring    wstring;




#else // _UNICODE || UNICODE

	#define _tstring    string;




#endif // _UNICODE || UNICODE



