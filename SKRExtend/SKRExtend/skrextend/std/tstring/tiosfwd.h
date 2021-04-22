#pragma once

namespace std {

#ifdef _UNICODE
	using _tios           = wios;
	using _tstreambuf     = wstreambuf;
	using _tistream       = wistream;
	using _tostream       = wostream;
	using _tiostream      = wiostream;
	using _tstringbuf     = wstringbuf;
	using _tistringstream = wistringstream;
	using _tostringstream = wostringstream;
	using _tstringstream  = wstringstream;
	using _tfilebuf       = wfilebuf;
	using _tifstream      = wifstream;
	using _tofstream      = wofstream;
	using _tfstream       = wfstream;
#else
	using _tios           = ios;
	using _tstreambuf     = streambuf;
	using _tistream       = istream;
	using _tostream       = ostream;
	using _tiostream      = iostream;
	using _tstringbuf     = stringbuf;
	using _tistringstream = istringstream;
	using _tostringstream = ostringstream;
	using _tstringstream  = stringstream;
	using _tfilebuf       = filebuf;
	using _tifstream      = ifstream;
	using _tofstream      = ofstream;
	using _tfstream       = fstream;
#endif // _UNICODE

} // namespace std



