#include <iostream>
#include <string>
#include <tchar.h>

#include "skrextend/std/tstring/tstring.h"
#include "skrextend/std/tstring/tiostream.h"
#include "skrextend/tokenizer/Tokenizer.h"
#include "skrextend/memory/memoryex.h"
#include "skrextend/memriff/memriff.h"
#include "skrextend/common/assert/assertmsg.h"
#include "skrextend/common/math/inRange.h"




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
		skrex::Tokenizer tknzr("test.txt");
		cout << tknzr.last() << endl;
		while ( ! tknzr.isEnd()) {
			cout << tknzr.next() << endl;
			cout << tknzr.last() << endl;
		}
		cout << tknzr.last() << endl;
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
}



