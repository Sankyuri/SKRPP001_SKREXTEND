#pragma once


namespace skrex {


// Check a_obj is a_min or more and a_max or less.
// min <= x <= max / x=>[min, max]; min and max is included.
// @param a_obj Check number.
// @param a_min Minimum of range.
// @param a_max Maximum of range.
// @return If a_obj is between a_min and a_max or equals a_min or a_max then return true, otherwise false.
template<typename T>
inline bool inRangeClosed(
		T a_obj,
		T a_min,
		T a_max)
{
	return a_min <= a_obj && a_obj <= a_max;
}




// Check a_obj is over than a_min and less than a_max.
// min < x < max; min and max is NOT included.
// @param a_obj Check number.
// @param a_min Minimum of range.
// @param a_max Maximum of range.
// @return If a_obj is between a_min and a_max then return true, otherwise false.
template<typename T>
inline bool inRangeOpened(
		T a_obj,
		T a_min,
		T a_max)
{
	return a_min < a_obj && a_obj < a_max;
}


} // namespace skrex




// Check a_obj is over than a_min and a_max or less.
// min <= x < max; min is included.
// @param a_obj Check number.
// @param a_min Minimum of range.
// @param a_max Maximum of range.
// @return If a_obj is between a_min and a_max or equals a_min then return true, otherwise false.
template<typename T>
inline bool inRangeLeftClosed(
		T a_obj,
		T a_min,
		T a_max)
{
	return a_min <= a_obj && a_obj < a_max;
}




// Check a_obj is a_min or more and less than a_max.
// min < x <= max; max is included.
// @param a_obj Check number.
// @param a_min Minimum of range.
// @param a_max Maximum of range.
// @return If a_obj is between a_min and a_max or equals a_max then return true, otherwise false.
template<typename T>
inline bool inRangeRightClosed(
		T a_obj,
		T a_min,
		T a_max)
{
	return a_min < a_obj && a_obj <= a_max;
}




// Check a_obj is over than a_min and a_max or less.
// min <= x < max; min is included.
// @param a_obj Check number.
// @param a_min Minimum of range.
// @param a_max Maximum of range.
// @return If a_obj is between a_min and a_max or equals a_min then return true, otherwise false.
template<typename T>
inline bool inRangeRightOpened(
		T a_obj,
		T a_min,
		T a_max)
{
	return a_min <= a_obj && a_obj < a_max;
}




// Check a_obj is a_min or more and less than a_max.
// min < x <= max; max is included.
// @param a_obj Check number.
// @param a_min Minimum of range.
// @param a_max Maximum of range.
// @return If a_obj is between a_min and a_max or equals a_max then return true, otherwise false.
template<typename T>
inline bool inRangeLeftOpened(
		T a_obj,
		T a_min,
		T a_max)
{
	return a_min < a_obj && a_obj <= a_max;
}



