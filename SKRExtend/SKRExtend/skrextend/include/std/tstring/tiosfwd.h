#pragma once


#if defined(_UNICODE) || defined(UNICODE)

	#define _tios              wios
	#define _tstreambuf        wstreambuf
	#define _tistream          wistream
	#define _tostream          wostream
	#define _tiostream         wiostream
	#define _tstringbuf        wstringbuf
	#define _tistringstream    wistringstream
	#define _tostringstream    wostringstream
	#define _tstringstream     wstringstream
	#define _tfilebuf          wfilebuf
	#define _tifstream         wifstream
	#define _tofstream         wofstream
	#define _tfstream          wfstream




#else // _UNICODE || UNICODE

	#define _tios              ios
	#define _tstreambuf        streambuf
	#define _tistream          istream
	#define _tostream          ostream
	#define _tiostream         iostream
	#define _tstringbuf        stringbuf
	#define _tistringstream    istringstream
	#define _tostringstream    ostringstream
	#define _tstringstream     stringstream
	#define _tfilebuf          filebuf
	#define _tifstream         ifstream
	#define _tofstream         ofstream
	#define _tfstream          fstream




#endif // _UNICODE || UNICODE



