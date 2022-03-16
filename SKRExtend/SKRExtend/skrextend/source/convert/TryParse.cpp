#include "../../include/convert/TryParse.h"
#include <stdexcept>
#include <cassert>
#include <algorithm>


bool skrex::TryParse::toInt(const char         *a_str, int a_base)
{
	assert(nullptr != a_str);

	char *pchr;
	long n = strtol(a_str, &pchr, a_base);
	
	return (pchr != a_str)       &&
		   ! ( (errno == ERANGE) ||
		       (n < INT_MIN)     || (INT_MAX < n)   );
}




bool skrex::TryParse::toInt(const wchar_t      *a_str, int a_base)
{
	assert(nullptr != a_str);

	wchar_t *pchr;
	long n = wcstol(a_str, &pchr, a_base);
	
	return (pchr != a_str)       &&
		   ! ( (errno == ERANGE) ||
		       (n < INT_MIN)     || (INT_MAX < n)   );
}




bool skrex::TryParse::toInt(const std::string  &a_str, int a_base)
{
	return toInt(a_str.c_str(), a_base);
}




bool skrex::TryParse::toInt(const std::wstring &a_str, int a_base)
{
	return toInt(a_str.c_str(), a_base);
}








bool skrex::TryParse::toSChar(const char         *a_str, int a_base)
{
	assert(nullptr != a_str);

	char *pchr;
	long n = strtol(a_str, &pchr, a_base);
	
	return (pchr != a_str)       &&
		   ! ( (errno == ERANGE) ||
		       (n < SCHAR_MIN)   || (SCHAR_MAX < n) );
}




bool skrex::TryParse::toSChar(const wchar_t      *a_str, int a_base)
{
	assert(nullptr != a_str);

	wchar_t *pchr;
	long n = wcstol(a_str, &pchr, a_base);
	
	return (pchr != a_str)       &&
		   ! ( (errno == ERANGE) ||
		       (n < SCHAR_MIN)   || (SCHAR_MAX < n) );
}




bool skrex::TryParse::toSChar(const std::string  &a_str, int a_base)
{
	return toSChar(a_str.c_str(), a_base);
}




bool skrex::TryParse::toSChar(const std::wstring &a_str, int a_base)
{
	return toSChar(a_str.c_str(), a_base);
}








bool skrex::TryParse::toShort(const char         *a_str, int a_base)
{
	assert(nullptr != a_str);

	char *pchr;
	long n = strtol(a_str, &pchr, a_base);
	
	return (pchr != a_str)       &&
		   ! ( (errno == ERANGE) ||
		       (n < SHRT_MIN)    || (SHRT_MAX < n)  );
}




bool skrex::TryParse::toShort(const wchar_t      *a_str, int a_base)
{
	assert(nullptr != a_str);

	wchar_t *pchr;
	long n = wcstol(a_str, &pchr, a_base);
	
	return (pchr != a_str)       &&
		   ! ( (errno == ERANGE) ||
		       (n < SHRT_MIN)    || (SHRT_MAX < n)  );
}




bool skrex::TryParse::toShort(const std::string  &a_str, int a_base)
{
	return toShort(a_str.c_str(), a_base);
}




bool skrex::TryParse::toShort(const std::wstring &a_str, int a_base)
{
	return toShort(a_str.c_str(), a_base);
}








bool skrex::TryParse::toLong(const char         *a_str, int a_base)
{
	assert(nullptr != a_str);

	char *pchr;
	long n = strtol(a_str, &pchr, a_base);
	
	return (pchr != a_str)       &&
		   ! ( (errno == ERANGE)    );
}




bool skrex::TryParse::toLong(const wchar_t      *a_str, int a_base)
{
	assert(nullptr != a_str);

	wchar_t *pchr;
	long n = wcstol(a_str, &pchr, a_base);
	
	return (pchr != a_str)       &&
		   ! ( (errno == ERANGE)    );
}




bool skrex::TryParse::toLong(const std::string  &a_str, int a_base)
{
	return toLong(a_str.c_str(),a_base);
}




bool skrex::TryParse::toLong(const std::wstring &a_str, int a_base)
{
	return toLong(a_str.c_str(), a_base);
}








bool skrex::TryParse::toLLong(const char         *a_str, int a_base)
{
	assert(nullptr != a_str);

	char *pchr;
	long long n = strtoll(a_str, &pchr, a_base);
	
	return (pchr != a_str)       &&
		   ! ( (errno == ERANGE)    );
}




bool skrex::TryParse::toLLong(const wchar_t      *a_str, int a_base)
{
	assert(nullptr != a_str);

	wchar_t *pchr;
	long long n = wcstoll(a_str, &pchr, a_base);
	
	return (pchr != a_str)       &&
		   ! ( (errno == ERANGE)    );
}




bool skrex::TryParse::toLLong(const std::string  &a_str, int a_base)
{
	return toLLong(a_str.c_str(),a_base);
}




bool skrex::TryParse::toLLong(const std::wstring &a_str, int a_base)
{
	return toLLong(a_str.c_str(), a_base);
}
















bool skrex::TryParse::toUInt(const char         *a_str, int a_base)
{
	assert(nullptr != a_str);

	char *pchr;
	unsigned long n = strtoul(a_str, &pchr, a_base);
	
	return (pchr != a_str)       &&
		   ! ( (errno == ERANGE) ||
		       (UINT_MAX < n)       );
}




bool skrex::TryParse::toUInt(const wchar_t      *a_str, int a_base)
{
	assert(nullptr != a_str);

	wchar_t *pchr;
	unsigned long n = wcstoul(a_str, &pchr, a_base);
	
	return (pchr != a_str)       &&
		   ! ( (errno == ERANGE) ||
		       (UINT_MAX < n)       );
}




bool skrex::TryParse::toUInt(const std::string  &a_str, int a_base)
{
	return toUInt(a_str.c_str(), a_base);
}




bool skrex::TryParse::toUInt(const std::wstring &a_str, int a_base)
{
	return toUInt(a_str.c_str(), a_base);
}








bool skrex::TryParse::toUChar(const char         *a_str, int a_base)
{
	assert(nullptr != a_str);

	char *pchr;
	unsigned long n = strtoul(a_str, &pchr, a_base);
	
	return (pchr != a_str)       &&
		   ! ( (errno == ERANGE) ||
		       (UCHAR_MAX < n)      );
}




bool skrex::TryParse::toUChar(const wchar_t      *a_str, int a_base)
{
	assert(nullptr != a_str);

	wchar_t *pchr;
	unsigned long n = wcstoul(a_str, &pchr, a_base);
	
	return (pchr != a_str)       &&
		   ! ( (errno == ERANGE) ||
		       (UCHAR_MAX < n)      );
}




bool skrex::TryParse::toUChar(const std::string  &a_str, int a_base)
{
	return toUChar(a_str.c_str(), a_base);
}




bool skrex::TryParse::toUChar(const std::wstring &a_str, int a_base)
{
	return toUChar(a_str.c_str(), a_base);
}








bool skrex::TryParse::toUShort(const char         *a_str, int a_base)
{
	assert(nullptr != a_str);

	char *pchr;
	unsigned long n = strtoul(a_str, &pchr, a_base);

	return (pchr != a_str)   &&
		   ! ( (errno == ERANGE) ||
			   (USHRT_MAX < n)      );
}




bool skrex::TryParse::toUShort(const wchar_t      *a_str, int a_base)
{
	assert(nullptr != a_str);

	wchar_t *pchr;
	unsigned long n = wcstoul(a_str, &pchr, a_base);
	
	return (pchr != a_str)   &&
		   ! ( (errno == ERANGE) ||
		       (USHRT_MAX < n)      );
}




bool skrex::TryParse::toUShort(const std::string  &a_str, int a_base)
{
	return toUShort(a_str.c_str(), a_base);
}




bool skrex::TryParse::toUShort(const std::wstring &a_str, int a_base)
{
	return toUShort(a_str.c_str(), a_base);
}








bool skrex::TryParse::toULong(const char         *a_str, int a_base)
{
	assert(nullptr != a_str);

	char *pchr;
	unsigned long n = strtoul(a_str, &pchr, a_base);
	
	return (pchr != a_str)       &&
		   ! ( (errno == ERANGE)    );
}




bool skrex::TryParse::toULong(const wchar_t      *a_str, int a_base)
{
	assert(nullptr != a_str);

	wchar_t *pchr;
	unsigned long n = wcstoul(a_str, &pchr, a_base);
	
	return (pchr != a_str)       &&
		   ! ( (errno == ERANGE)    );
}




bool skrex::TryParse::toULong(const std::string  &a_str, int a_base)
{
	return toULong(a_str.c_str(),a_base);
}




bool skrex::TryParse::toULong(const std::wstring &a_str, int a_base)
{
	return toULong(a_str.c_str(), a_base);
}








bool skrex::TryParse::toULLong(const char         *a_str, int a_base)
{
	assert(nullptr != a_str);

	char *pchr;
	unsigned long long n = strtoull(a_str, &pchr, a_base);
	
	return (pchr != a_str)       &&
		   ! ( (errno == ERANGE)    );
}




bool skrex::TryParse::toULLong(const wchar_t      *a_str, int a_base)
{
	assert(nullptr != a_str);

	wchar_t *pchr;
	unsigned long long n = wcstoull(a_str, &pchr, a_base);
	
	return (pchr != a_str)       &&
		   ! ( (errno == ERANGE)    );
}




bool skrex::TryParse::toULLong(const std::string  &a_str, int a_base)
{
	return toULLong(a_str.c_str(),a_base);
}




bool skrex::TryParse::toULLong(const std::wstring &a_str, int a_base)
{
	return toULLong(a_str.c_str(), a_base);
}
















bool skrex::TryParse::toFloat(const char         *a_str)
{
	assert(nullptr != a_str);

	char *pchr;
	float n = strtof(a_str, &pchr);
	
	return (pchr != a_str)       &&
		   ! ( (errno == ERANGE) ||
		       (n == -HUGE_VALF) || (HUGE_VALF == n) );
}




bool skrex::TryParse::toFloat(const wchar_t      *a_str)
{
	assert(nullptr != a_str);

	wchar_t *pchr;
	float n = wcstof(a_str, &pchr);
	
	return (pchr != a_str)       &&
		   ! ( (errno == ERANGE) ||
		       (n == -HUGE_VALF) || (HUGE_VALF == n) );
}




bool skrex::TryParse::toFloat(const std::string  &a_str)
{
	return toFloat(a_str.c_str());
}




bool skrex::TryParse::toFloat(const std::wstring &a_str)
{
	return toFloat(a_str.c_str());
}








bool skrex::TryParse::toDouble(const char         *a_str)
{
	assert(nullptr != a_str);

	char *pchr;
	double n = strtod(a_str, &pchr);
	
	return (pchr != a_str)       &&
		   ! ( (errno == ERANGE) ||
		       (n == -HUGE_VALF) || (HUGE_VALF == n) );
}




bool skrex::TryParse::toDouble(const wchar_t      *a_str)
{
	assert(nullptr != a_str);

	wchar_t *pchr;
	double n = wcstod(a_str, &pchr);
	
	return (pchr != a_str)       &&
		   ! ( (errno == ERANGE) ||
		       (n == -HUGE_VALF) || (HUGE_VALF == n) );
}




bool skrex::TryParse::toDouble(const std::string  &a_str)
{
	return toDouble(a_str.c_str());
}




bool skrex::TryParse::toDouble(const std::wstring &a_str)
{
	return toDouble(a_str.c_str());
}
















bool skrex::TryParse::toByte(const char         *a_str, int a_base)
{
	return toUChar(a_str, a_base);
}




bool skrex::TryParse::toByte(const wchar_t      *a_str, int a_base)
{
	return toUChar(a_str, a_base);
}




bool skrex::TryParse::toByte(const std::string  &a_str, int a_base)
{
	return toUChar(a_str.c_str(), a_base);
}




bool skrex::TryParse::toByte(const std::wstring &a_str, int a_base)
{
	return toUChar(a_str.c_str(), a_base);
}








bool skrex::TryParse::isBoolString(std::string     a_str)
{
	std::transform(a_str.begin(), a_str.end(), a_str.begin(), tolower);
	return ("true" == a_str || "false" == a_str);
}




bool skrex::TryParse::isBoolString(std::wstring    a_str)
{
	std::transform(a_str.begin(), a_str.end(), a_str.begin(), towlower);
	return (L"true" == a_str || L"false" == a_str);
}



