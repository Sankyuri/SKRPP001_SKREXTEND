#pragma once
#include <string>


namespace skrex {


// Check object is parsable.
// Returns if convertable then true, otherwise false.
class TryParse {
public:

	static bool toInt  (const char         *a_str, int a_base = 0);
	static bool toInt  (const wchar_t      *a_str, int a_base = 0);
	static bool toInt  (const std::string  &a_str, int a_base = 0);
	static bool toInt  (const std::wstring &a_str, int a_base = 0);

	static bool toSChar(const char         *a_str, int a_base = 0);
	static bool toSChar(const wchar_t      *a_str, int a_base = 0);
	static bool toSChar(const std::string  &a_str, int a_base = 0);
	static bool toSChar(const std::wstring &a_str, int a_base = 0);

	static bool toShort(const char         *a_str, int a_base = 0);
	static bool toShort(const wchar_t      *a_str, int a_base = 0);
	static bool toShort(const std::string  &a_str, int a_base = 0);
	static bool toShort(const std::wstring &a_str, int a_base = 0);

	static bool toLong (const char         *a_str, int a_base = 0);
	static bool toLong (const wchar_t      *a_str, int a_base = 0);
	static bool toLong (const std::string  &a_str, int a_base = 0);
	static bool toLong (const std::wstring &a_str, int a_base = 0);

	static bool toLLong(const char         *a_str, int a_base = 0);
	static bool toLLong(const wchar_t      *a_str, int a_base = 0);
	static bool toLLong(const std::string  &a_str, int a_base = 0);
	static bool toLLong(const std::wstring &a_str, int a_base = 0);




	static bool toUInt  (const char         *a_str, int a_base = 0);
	static bool toUInt  (const wchar_t      *a_str, int a_base = 0);
	static bool toUInt  (const std::string  &a_str, int a_base = 0);
	static bool toUInt  (const std::wstring &a_str, int a_base = 0);

	static bool toUChar (const char         *a_str, int a_base = 0);
	static bool toUChar (const wchar_t      *a_str, int a_base = 0);
	static bool toUChar (const std::string  &a_str, int a_base = 0);
	static bool toUChar (const std::wstring &a_str, int a_base = 0);

	static bool toUShort(const char         *a_str, int a_base = 0);
	static bool toUShort(const wchar_t      *a_str, int a_base = 0);
	static bool toUShort(const std::string  &a_str, int a_base = 0);
	static bool toUShort(const std::wstring &a_str, int a_base = 0);

	static bool toULong (const char         *a_str, int a_base = 0);
	static bool toULong (const wchar_t      *a_str, int a_base = 0);
	static bool toULong (const std::string  &a_str, int a_base = 0);
	static bool toULong (const std::wstring &a_str, int a_base = 0);

	static bool toULLong(const char         *a_str, int a_base = 0);
	static bool toULLong(const wchar_t      *a_str, int a_base = 0);
	static bool toULLong(const std::string  &a_str, int a_base = 0);
	static bool toULLong(const std::wstring &a_str, int a_base = 0);


	

	static bool toFloat (const char         *a_str);
	static bool toFloat (const wchar_t      *a_str);
	static bool toFloat (const std::string  &a_str);
	static bool toFloat (const std::wstring &a_str);

	static bool toDouble(const char         *a_str);
	static bool toDouble(const wchar_t      *a_str);
	static bool toDouble(const std::string  &a_str);
	static bool toDouble(const std::wstring &a_str);


	

	// toByte is just same as toUChar.
	static bool toByte  (const char         *a_str, int a_base = 0);
	static bool toByte  (const wchar_t      *a_str, int a_base = 0);
	static bool toByte  (const std::string  &a_str, int a_base = 0);
	static bool toByte  (const std::wstring &a_str, int a_base = 0);

	// isBoolString checks a_str is "true" or "false".
	static bool isBoolString(std::string     a_str);
	static bool isBoolString(std::wstring    a_str);




};


}



