#include "../../include/memriff/memriff.h"
#include <memory>
#include "../../include/memory/memoryex.h"




// Check this data is RIFF.
// @param a_data   File data.
// @param a_offset Offset to begin file data.
// @return If FourCC is "RIFF" then return true, otherwise return false.
bool skrex::isRIFFMemory(
		const Byte *a_data,
		size_t      a_offset)
{
	return (a_data[a_offset + 0] == 'R' &&
			a_data[a_offset + 1] == 'I' &&
			a_data[a_offset + 2] == 'F' &&
			a_data[a_offset + 3] == 'F');
}








// Find riff chunk.
// @param a_pbuf         Pointer to buffer.
// @param a_buflen       Length of a_buf.
// @param a_pmmcki       MMChunk info.
// @param a_pmmckiParent Parent MMChunk info.
// @param a_fuDescend    Search flag.
// @return If found chunk then return true, not found then return false.
bool skrex::memRIFFDescend(
		const Byte     *a_pbuf,
		size_t          a_buflen,
		LPMMCKINFO      a_pmmcki,
		const MMCKINFO *a_pmmckiParent,
		UINT            a_fuDescend)
{
	constexpr size_t CKIDSIZE = 4; // Chunk ID length

	size_t offset = 0;
	if (a_pmmckiParent) {
		size_t offset = a_pmmckiParent->dwDataOffset;
	}


	DWORD idx = -1;
	{
		Byte id[CKIDSIZE];

		// find chunk
		if      (a_fuDescend & MMIO_FINDCHUNK) {
			id[0] = (Byte)(a_pmmcki->ckid);
			id[1] = (Byte)(a_pmmcki->ckid >>  8);
			id[2] = (Byte)(a_pmmcki->ckid >> 16);
			id[3] = (Byte)(a_pmmcki->ckid >> 24);
		}
		// find RIFF
		else if (a_fuDescend & MMIO_FINDRIFF) {
			id[0] = 'R';
			id[1] = 'I';
			id[2] = 'F';
			id[3] = 'F';
		}
		// find LIST
		else if (a_fuDescend & MMIO_FINDLIST) {
			id[0] = 'L';
			id[1] = 'I';
			id[2] = 'S';
			id[3] = 'T';
		}

		idx = (DWORD)memfind(a_pbuf + offset, id, a_buflen, CKIDSIZE);
	}
	if (-1 == idx) {
		return false;
	}




	// get chunk size
	DWORD sz;
	memcpy(&sz, a_pbuf + offset + idx + CKIDSIZE, sizeof(int32_t));


	// copy data
	a_pmmcki->cksize       = sz;
	a_pmmcki->dwDataOffset = (DWORD)(offset + idx + CKIDSIZE + sizeof(int32_t));


	return true;
}



