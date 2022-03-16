#pragma once
#include <functional>

namespace skrex {


// Class of Function that will be execute once.
// After called the function at first,
// set the next function for execute other function.
template <class TRes, class TArg>
class FunctionOnceSet final {
public:

	// Constructor with nothing.
	FunctionOnceSet() :
		m_func(),
		m_funcAft(),
		m_res  ()
	{ }


	// Constructor with function.
	FunctionOnceSet(
			std::function<TRes(TArg)> a_func,
			std::function<TRes(TArg)> a_funcAfter
	) :
		m_func   (a_func),
		m_funcAft(a_funcAfter),
		m_res    ()
	{ }


	// Constructor with function and default return value.
	FunctionOnceSet(
			std::function<TRes(TArg)> a_func,
			std::function<TRes(TArg)> a_funcAfter,
			TRes                      a_res
	) :
		m_func   (a_func),
		m_funcAft(a_funcAfter),
		m_res    (a_res)
	{ }


	// Destructor.
	~FunctionOnceSet()
	{
		m_func    = nullptr;
		m_funcAft = nullptr;
	}




	// Execute function (once).
	// If this function was already executed then do nothing.
	TRes execute(
			TArg a_arg
	) {
		m_res        = m_func( a_arg );
		m_func       = m_funcAft;
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
	std::function<TRes(TArg)> m_funcAft;

	// Return value.
	TRes m_res;




};


// Class of Function that will be execute once.
// After called the function at first,
// set the next function for execute other function.
template <class TRes>
class FunctionOnceSetNoArgument final {
public:

	// Constructor with nothing.
	FunctionOnceSetNoArgument() :
		m_func(),
		m_funcAft(),
		m_res  ()
	{ }


	// Constructor with function.
	FunctionOnceSetNoArgument(
			std::function<TRes()> a_func,
			std::function<TRes()> a_funcAfter
	) :
		m_func   (a_func),
		m_funcAft(a_funcAfter),
		m_res    ()
	{ }


	// Constructor with function and default return value.
	FunctionOnceSetNoArgument(
			std::function<TRes()> a_func,
			std::function<TRes()> a_funcAfter,
			TRes                  a_res
	) :
		m_func   (a_func),
		m_funcAft(a_funcAfter),
		m_res    (a_res)
	{ }


	// Destructor.
	~FunctionOnceSetNoArgument()
	{
		m_func    = nullptr;
		m_funcAft = nullptr;
	}




	// Execute function (once).
	// If this function was already executed then do nothing.
	TRes execute() {
		m_res  = m_func();
		m_func = m_funcAft;
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
	std::function<TRes()> m_funcAft;

	// Return value.
	TRes m_res;




};








// Class of Function that will be execute once if you not need return value.
// After called the function at first,
// set the next function for execute other function.
template <class TArg>
class FunctionOnceSetNoReturn final {
public:

	// Constructor with nothing.
	FunctionOnceSetNoReturn() :
		m_func   (),
		m_funcAft()
	{ }


	// Constructor with function.
	FunctionOnceSetNoReturn(
			std::function<void(TArg)> a_func,
			std::function<void(TArg)> a_funcAfter
	) :
		m_func   (a_func),
		m_funcAft(a_funcAfter)
	{ }


	// Destructor.
	~FunctionOnceSetNoReturn() { }




	// Execute function (once).
	// If this function was already executed then do nothing.
	void execute(
			TArg a_arg
	) {
		m_func( a_arg );
		m_func = m_funcAft;
	}




private:

	// Function pointer.
	std::function<void(TArg)> m_func;
	std::function<void(TArg)> m_funcAft;




};








// Class of Function that will be execute once if you not need return value and argument.
class FunctionOnceSetNoAll final {
public:

	// Constructor with nothing.
	FunctionOnceSetNoAll() :
		m_func   (),
		m_funcAft()
	{ }


	// Constructor with function.
	FunctionOnceSetNoAll(
			std::function<void(void)> a_func,
			std::function<void(void)> a_funcAfter
	) :
		m_func   (a_func),
		m_funcAft(a_funcAfter)
	{ }


	// Destructor.
	~FunctionOnceSetNoAll() { }




	// Execute function (once).
	// If this function was already executed then do nothing.
	void execute() {
		m_func();
		m_func = m_funcAft;
	}




private:

	// Function pointer.
	std::function<void(void)> m_func;
	std::function<void(void)> m_funcAft;




};




} // namespace skrex



