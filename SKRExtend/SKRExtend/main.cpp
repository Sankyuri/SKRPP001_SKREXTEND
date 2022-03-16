#include <iostream>
#include <string>
#include <tchar.h>

#include "skrextend/include/std/tstring/tstring.h"
#include "skrextend/include/std/tstring/tiostream.h"
#include "skrextend/include/tokenizer/Tokenizer.h"
#include "skrextend/include/memory/memoryex.h"
#include "skrextend/include/memriff/memriff.h"
#include "skrextend/include/assert/assertmsg.h"
#include "skrextend/include/math/inRange.h"
#include "skrextend/include/convert/TryParse.h"
#include "skrextend/include/console/ConsoleYesNo.h"
#include "skrextend/include/functional/FunctionOnce.h"
#include "skrextend/include/functional/FunctionOnceSet.h"




// for assertmsg sample
//#define SKREXSAMPLE_EXECUTE_ASSERTMSG
// 
// for assertmsg_dbgprt sample
//#define SKREXSAMPLE_EXECUTE_ASSERTMSG_DBGPRT


using std::cout;
using std::cin;
using std::endl;




int main() {

	// _tstring sample
	// _tstring and _tcout is #define macro.
	cout << "[_tstring SAMPLE!]" << endl;
	std::_tstring str = _T("test string");
	std::_tcout << str << endl;



	
	// Tokenizer sample
	cout << endl << "[Tokenizer SAMPLE!]" << endl;
	{
		// Tokenizer can be split by space.
		// This demo uses a text file.
		try {
			skrex::Tokenizer tknzr("test.txt");
			cout << tknzr.last() << endl;
			while ( ! tknzr.isEnd()) {
				cout << tknzr.next() << endl;
				cout << tknzr.last() << endl;
			}
			cout << tknzr.last() << endl;
		} catch(...) {
			cout << "test.txt is not found!" << endl;
		}
	}



	
	// memfind sample
	cout << endl << "[memfind SAMPLE!]" << endl;
	{
		constexpr int LEN    = 2;
		skrex::Byte dat[LEN] = {
			0x3B, 0x14,
		};
		// memfind() searches if "str(a_buf)" contains "dat(a_val)".
		if (-1 != skrex::memfind((skrex::Byte *)(str.c_str()), dat, str.size(), LEN)) {
			cout << "[0x3B, 0x14] is found!" << endl;
		} else {
			cout << "[0x3B, 0x14] is not found!" << endl;
		}
	}



	
	// memriff sample
	cout << endl << "[memriff SAMPLE!]" << endl;
	{
		constexpr int LEN    = 32;
		skrex::Byte dat[LEN] = {
			'R', 'I', 'F', 'F', 0x00, 0x01, 0x00, 0x00,
			'W', 'A', 'V', 'E', 'f', 'm', 't', ' ',
		};
		MMCKINFO mmfmt;
		mmfmt.ckid = mmioFOURCC('f', 'm', 't', ' ');
		// memRIFFDescend() checks if contains a chunk.
		// memRIFFDescend() is similar to mmioDescend().
		if (skrex::memRIFFDescend(dat, LEN, &mmfmt, NULL, MMIO_FINDCHUNK)) {
			cout << "\"fmt \" is found!" << endl;
		} else {
			cout << "\"fmt \" is not found!" << endl;
		}
	}




	// assertmsg sample
	cout << endl << "[assertmsg SAMPLE!]" << endl;
	{
		// assetmsg assertions with message.
		constexpr int NUM = 32;
#ifdef SKREXSAMPLE_EXECUTE_ASSERTMSG
		assertmsg(NUM == 0, "NUM is not 0!");
#endif
#ifdef SKREXSAMPLE_EXECUTE_ASSERTMSG_DBGPRT
		assertmsg_dbgprt(NUM == 0, "NUM is not 0!");
#endif
		cout << "No assert or not runned assert sample!" << endl;
	}




	// inRange sample
	cout << endl << "[inRange SAMPLE!]" << endl;
	{
		// inRange- checks a_obj is inner a_min to a_max.
		constexpr int NUM = 5;
		if (skrex::inRangeClosed(NUM, 0, 5)) {
			cout << NUM << " is inner to [0, 5]!" << endl;
		} else {
			cout << NUM << " is outer to [0, 5]!" << endl;
		}
		if (skrex::inRangeOpened(NUM, 0, 5)) {
			cout << NUM << " is inner to (0, 5)!" << endl;
		} else {
			cout << NUM << " is outer to (0, 5)!" << endl;
		}
	}




	// TryParse sample
	cout << endl << "[TryParse SAMPLE!]" << endl;
	{
		// Check string is parsable to int or otherwise.
		constexpr auto str1 = "0x122287";
		constexpr auto str2 = "544123.2558";
		constexpr auto str3 = "FALSE";
		if (skrex::TryParse::toInt(str1)) {
			cout << str1 << " is convertable to int!"        << endl;
		} else {
			cout << str1 << " is not convertable to int!"    << endl;
		}
		if (skrex::TryParse::toUShort(str1)) {
			cout << str1 << " is convertable to ushort!"     << endl;
		} else {
			cout << str1 << " is not convertable to ushort!" << endl;
		}
		if (skrex::TryParse::toFloat(str2)) {
			cout << str2 << " is convertable to float!"      << endl;
		} else {
			cout << str2 << " is not convertable to float!"  << endl;
		}
		// Check string is "true" or "false" with ignore case.
		if (skrex::TryParse::isBoolString(str2)) {
			cout << str2 << " is boolean string!"            << endl;
		} else {
			cout << str2 << " is not boolean string!"        << endl;
		}
		if (skrex::TryParse::isBoolString(str3)) {
			cout << str3 << " is boolean string!"            << endl;
		} else {
			cout << str3 << " is not boolean string!"        << endl;
		}
	}




	// ConsoleYesNo sample
	cout << endl << "[ConsoleYesNo SAMPLE!]" << endl;
	{
		// Ask to user Yes or No on console.
		bool result = false;

		cout << "Do you like strawberry?[Y/N]: ";

		result = skrex::ConsoleYesNo::ask();

		if (result) {
			cout << "Ya! You like strawberry!" << endl;
		} else {
			cout << "Oh... You don't like strawberry..." << endl;
		}
	}




	// FunctionOnce sample
	cout << endl << "[FunctionOnce SAMPLE!]" << endl;
	{
		// Once the function is called, the object will do nothing after that.
		constexpr int LOOPNUM = 5;

		auto fn1 = []( int a_n ){
			return std::string( "Funcion 1 called! n = " )
				       + std::to_string( a_n )
				       + std::string( "!\n" );
		};
		auto fn2 = [](){
			return std::string( "Funcion 1 called!\n" );
		};
		auto fn3 = []( int a_n ){
			cout << "Funcion 3 called! n = " << a_n << "!" << endl;
		};
		auto fn4 = [](){
			cout << "Funcion 4 called!" << endl;
		};

		auto fo1 = skrex::FunctionOnce<std::string, int>     ( fn1 );
		auto fo2 = skrex::FunctionOnceNoArgument<std::string>( fn2 );
		auto fo3 = skrex::FunctionOnceNoReturn<int>          ( fn3 );
		auto fo4 = skrex::FunctionOnceNoAll                  ( fn4 );
		
		// This class has argument, do return value.
		cout  << "    skrex::FunctionOnce:" << endl;
		for (int i = 0; i < LOOPNUM; ++i) {
			cout << fo1.execute( 10 + i );
		}

		// This class has not argument, do return value.
		cout  << "    skrex::FunctionOnceNoArgument:" << endl;
		for (int i = 0; i < LOOPNUM; ++i) {
			cout << fo2.execute();
		}

		// This class has argument, do not return value.
		cout  << "    skrex::FunctionOnceNoReturn:" << endl;
		for (int i = 0; i < LOOPNUM; ++i) {
			fo3.execute( 14 + i );
		}

		// This class has not argument, do not return value.
		cout  << "    skrex::FunctionOnceNoAll:" << endl;
		for (int i = 0; i < LOOPNUM; ++i) {
			fo4.execute();
		}
	}




	// FunctionOnceSet sample
	cout << endl << "[FunctionOnceSet SAMPLE!]" << endl;
	{
		// Once the function is called, the object will change to other function after that.
		constexpr int LOOPNUM = 5;

		auto fn1 = []( int a_n ){
			return std::string( "Funcion 1 called! n = " )
				       + std::to_string( a_n )
				       + std::string( "!\n" );
		};
		auto fn2 = [](){
			return std::string( "Funcion 1 called!\n" );
		};
		auto fn3 = []( int a_n ){
			cout << "Funcion 3 called! n = " << a_n << "!" << endl;
		};
		auto fn4 = [](){
			cout << "Funcion 4 called!" << endl;
		};
		auto fn5 = []( int a_n ){
			return std::string( "Funcion 5 called! n = " )
				       + std::to_string( a_n )
				       + std::string( "!\n" );
		};
		auto fn6 = [](){
			return std::string( "Funcion 6 called!\n" );
		};
		auto fn7 = []( int a_n ){
			cout << "Funcion 7 called! n = " << a_n << "!" << endl;
		};
		auto fn8 = [](){
			cout << "Funcion 8 called!" << endl;
		};

		auto fo1 = skrex::FunctionOnceSet<std::string, int>     ( fn1, fn5 );
		auto fo2 = skrex::FunctionOnceSetNoArgument<std::string>( fn2, fn6 );
		auto fo3 = skrex::FunctionOnceSetNoReturn<int>          ( fn3, fn7 );
		auto fo4 = skrex::FunctionOnceSetNoAll                  ( fn4, fn8 );
		
		// This class has argument, do return value.
		cout  << "    skrex::FunctionOnceSet:" << endl;
		for (int i = 0; i < LOOPNUM; ++i) {
			cout << fo1.execute( 17 + i );
		}

		// This class has not argument, do return value.
		cout  << "    skrex::FunctionOnceSetNoArgument:" << endl;
		for (int i = 0; i < LOOPNUM; ++i) {
			cout << fo2.execute();
		}

		// This class has argument, do not return value.
		cout  << "    skrex::FunctionOnceSetNoReturn:" << endl;
		for (int i = 0; i < LOOPNUM; ++i) {
			fo3.execute( 12 + i );
		}

		// This class has not argument, do not return value.
		cout  << "    skrex::FunctionOnceSetNoAll:" << endl;
		for (int i = 0; i < LOOPNUM; ++i) {
			fo4.execute();
		}
	}




}



