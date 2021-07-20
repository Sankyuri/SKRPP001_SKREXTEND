#pragma once
#include <cstdint>


namespace skrex {


using Byte = unsigned char;


// Find index of a_val in a_buf.
// @param a_buf    Memory buffer.
// @param a_val    Memory search value.
// @param a_buflen Length of a_buf.
// @param a_vallen Length of a_val.
// @return If found a_val in a_buf then return index, else not found then return -1.
size_t memfind(
		const Byte *a_buf,
		const Byte *a_val,
		size_t      a_buflen,
		size_t      a_vallen);


}



