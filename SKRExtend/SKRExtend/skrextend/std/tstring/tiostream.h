#pragma once

namespace std {

#ifdef _UNICODE
	#define _tcin       wcin
	#define _tcout      wcout
	#define _tcerr      wcerr
	#define _tclog      wclog
	#define _t_Ptr_cin  _Ptr_wcin
	#define _t_Ptr_cout _Ptr_wcout
	#define _t_Ptr_cerr _Ptr_wcerr
	#define _t_Ptr_clog _Ptr_wclog
#else
	#define _tcin       cin
	#define _tcout      cout
	#define _tcerr      cerr
	#define _tclog      clog
	#define _t_Ptr_cin  _Ptr_cin
	#define _t_Ptr_cout _Ptr_cout
	#define _t_Ptr_cerr _Ptr_cerr
	#define _t_Ptr_clog _Ptr_clog
#endif

} // namespace std



