#include "memoryex.h"
#include <memory>


size_t skrex::memfind(
		const Byte *a_buf,
		const Byte *a_val,
		size_t      a_buflen,
		size_t      a_vallen)
{
	size_t max = a_buflen - a_vallen;
	for (size_t i = 0; i < max; ++i) {
			// compair
		if (memcmp(a_buf + i, a_val, a_vallen) == 0) {
			return i;
		}
	}
	return -1;
}



