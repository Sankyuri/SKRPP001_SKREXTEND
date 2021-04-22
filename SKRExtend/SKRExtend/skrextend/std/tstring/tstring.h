#pragma once

namespace std {

#ifdef _UNICODE
	using _tstring = wstring;
#else
	using _tstring = string;
#endif // _UNICODE

} // namespace std



