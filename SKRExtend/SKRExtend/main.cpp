#include <iostream>
#include <string>
#include <tchar.h>

#include "skrextend/std/tstring/tstring.h"
#include "skrextend/std/tstring/tiostream.h"

#include "skrextend/tokenizer/Tokenizer.h"

#include "skrextend/memory/memoryex.h"

#include "skrextend/memriff/memriff.h"

#include "skrextend/common/assert/assertmsg.h"




// for assertmsg sample
//#define SKREXSAMPLE_EXECUTE_ASSERTMSG
// 
// for assertmsg_dbgprt sample
#define SKREXSAMPLE_EXECUTE_ASSERTMSG_DBGPRT


using std::cout;
using std::cin;
using std::endl;




int main() {

	// _tstring sample
	// _tstring and _tcout is #define macro.
	std::_tstring str = _T("test string");
	std::_tcout << str << endl;




	// Tokenizer sample
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




#ifdef SKREXSAMPLE_EXECUTE_ASSERTMSG
	// assertmsg sample
	{
		// assetmsg assertions with message.
		constexpr int NUM = 32;
		assertmsg(NUM == 0, "NUM is not 0!");
	}
#endif




#ifdef SKREXSAMPLE_EXECUTE_ASSERTMSG_DBGPRT
	// assertmsg_dbgprt sample
	{
		// assetmsg assertions with message.
		constexpr int NUM = 181199;
		assertmsg_dbgprt(NUM == 0, "NUM is not 0!");
	}
#endif
}



