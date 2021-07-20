#pragma once
#include <Windows.h>
#include <mmsystem.h>


namespace skrex {


using Byte = unsigned char;


// Check this data is RIFF.
// @param a_buf Data.
// @param a_off Offset to begin file data.
// @return If FourCC is "RIFF" then return true, otherwise return false.
bool isRIFFMemory(
		const Byte *a_buf,
		size_t      a_offset);


// Find riff chunk.
// @param a_pbuf         Pointer to buffer.
// @param a_buflen       Length of a_buf.
// @param a_pmmcki       MMChunk info.
// @param a_pmmckiParent Parent MMChunk info.
// @param a_fuDescend    Search flag.
// @return If found chunk then return true, not found then return false.
bool memRIFFDescend(
		const Byte     *a_pbuf,
		size_t          a_buflen,
		LPMMCKINFO      a_pmmcki,
		const MMCKINFO *a_pmmckiParent,
		UINT            a_fuDescend);




} // namespace skrex



