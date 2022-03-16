#pragma once
#include <functional>

namespace skrex {


// Class of Function that will be execute once.
template <class TRes, class TArg>
class FunctionOnce final {
public:

	// Constructor with nothing.
	FunctionOnce() :
		m_func(),
		m_res ()
	{ }


	// Constructor with function.
	FunctionOnce(
			std::function<TRes(TArg)> a_func
	) :
		m_func(a_func),
		m_res ()
	{ }


	// Constructor with function and default return value.
	FunctionOnce(
			std::function<TRes(TArg)> a_func,
			TRes                      a_res
	) :
		m_func(a_func),
		m_res (a_res)
	{ }


	// Destructor.
	~FunctionOnce()
	{
		m_func = nullptr;
	}




	// Execute function (once).
	// If this function was already executed then do nothing.
	TRes execute(
			TArg a_arg
	) {
		m_res  = m_func( a_arg );
		m_func = m_fndn;
		return m_res;
	}




	// Get result.
	// If you was not execute() yet then return default value.
	TRes result()
	{
		return m_res;
	}




private:

	// Function pointer.
	std::function<TRes(TArg)> m_func;

	// Return value.
	TRes m_res;

	
	// A do-nothing-function object.
	const std::function<TRes(TArg)> m_fndn = [&](TArg) -> TRes { return m_res; };




};








// Class of Function that will be execute once if you not need return value.
template <class TArg>
class FunctionOnceNoReturn final {
public:

	// Constructor with nothing.
	FunctionOnceNoReturn() :
		m_func()
	{ }


	// Constructor with function.
	FunctionOnceNoReturn(
			std::function<void(TArg)> a_func
	) :
		m_func(a_func)
	{ }


	// Destructor.
	~FunctionOnceNoReturn() { }




	// Execute function (once).
	// If this function was already executed then do nothing.
	void execute(
			TArg a_arg
	) {
		m_func( a_arg );
		m_func = m_fndn;
	}




private:

	// Function pointer.
	std::function<void(TArg)> m_func;

	
	// A do-nothing-function object.
	const std::function<void(TArg)> m_fndn = [](TArg) -> void { };




};








// Class of Function that will be execute once if you not need argument.
template <class TRes>
class FunctionOnceNoArgument final {
public:

	// Constructor with nothing.
	FunctionOnceNoArgument() :
		m_func(),
		m_res ()
	{ }


	// Constructor with function.
	FunctionOnceNoArgument(
			std::function<TRes()> a_func
	) :
		m_func(a_func),
		m_res ()
	{ }


	// Constructor with function and default return value.
	FunctionOnceNoArgument(
			std::function<TRes()> a_func,
			TRes                  a_res
	) :
		m_func(a_func),
		m_res (a_res)
	{ }


	// Destructor.
	~FunctionOnceNoArgument()
	{
		m_func = nullptr;
	}




	// Execute function (once).
	// If this function was already executed then do nothing.
	TRes execute()
	{
		m_res  = m_func();
		m_func = m_fndn;
		return m_res;
	}




	// Get result.
	// If you was not execute() yet then return default value.
	TRes result()
	{
		return m_res;
	}




private:

	// Function pointer.
	std::function<TRes()> m_func;

	// Return value.
	TRes m_res;

	
	// A do-nothing-function object.
	const std::function<TRes()> m_fndn = [&]() -> TRes { return m_res; };




};








// Class of Function that will be execute once if you not need return value and argument.
class FunctionOnceNoAll final {
public:

	// Constructor with nothing.
	FunctionOnceNoAll() :
		m_func()
	{ }


	// Constructor with function.
	FunctionOnceNoAll(
			std::function<void(void)> a_func
	) :
		m_func(a_func)
	{ }


	// Destructor.
	~FunctionOnceNoAll() { }




	// Execute function (once).
	// If this function was already executed then do nothing.
	void execute() {
		m_func();
		m_func = m_fndn;
	}




private:

	// Function pointer.
	std::function<void(void)> m_func;

	
	// A do-nothing-function object.
	const std::function<void(void)> m_fndn = [](void) -> void { };




};




} // namespace skrex



