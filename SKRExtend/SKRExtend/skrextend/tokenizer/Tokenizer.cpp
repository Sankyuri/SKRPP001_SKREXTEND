#pragma once
#include "Tokenizer.h"
#include "../common/ScriptReaderException.h"
#include <fstream>
#include <algorithm>


using namespace skrex;


Tokenizer::Tokenizer() :
	m_name(""),
	m_str(""),
	m_ltk(""),
	m_chd(0),
	m_ctl(0)
{
	// do nothing
}




Tokenizer::Tokenizer(const std::string &a_fileName) :
	m_name(""),
	m_str(""),
	m_ltk(""),
	m_chd(0),
	m_ctl(0)
{
	std::ifstream ifs(a_fileName);
	if ( ! ifs.is_open()) {
		throw (a_fileName);
	}
	m_str.clear();
	m_str = std::string(std::istreambuf_iterator<char>(ifs),
						std::istreambuf_iterator<char>());
	ifs.close();
}








// set script data
void Tokenizer::setScriptData(const std::string &a_data)
{
	m_str = a_data;
}








// Returns length of current token.
// @return Length of current token.
size_t Tokenizer::getTokenLength() const
{
	return m_ctl - m_chd;
}




// Check to next token is exist.
// @return If exist next token when return true.
bool Tokenizer::hasNext() const
{
	return (std::string::npos != m_str.find_first_not_of(SPACE, m_ctl));
}




// return true if script data is ended
bool Tokenizer::isEnd() const
{
	return ( ! hasNext());
}








// Move cursor to next token.
// @return String of next token.
const std::string &Tokenizer::next()
{
	m_chd = m_str.find_first_not_of(SPACE, m_ctl); // head cursor move to head of next node
	m_ctl = m_str.find_first_of(    SPACE, m_chd); // tail cursor move to tail of next node
	m_ltk = m_str.substr(m_chd, getTokenLength());
	return m_ltk;
}




// Search next token with included by a_idt.
// @return Next token with included by a_idt.
const std::string &Tokenizer::inclusive(const char *a_idt)
{
	m_chd = m_str.find_first_of(a_idt, m_ctl);         // head cursor move to head of next node
	m_ctl = m_str.find_first_of(
			a_idt, m_chd + (size_t)(1)) + (size_t)(1); // tail cursor move to tail of next node
	m_ltk = m_str.substr(m_chd, getTokenLength());
	return m_ltk;
}




// Search next token with included by a_idt.
// @return Next token with included by a_idt.
const std::string &Tokenizer::inclusive(const char a_idt)
{
	std::string str = { a_idt };
	return inclusive(str.c_str());
}




void Tokenizer::moveCursorTo(const char a_ch)
{
	m_ctl = m_str.find_first_of(a_ch, m_ctl); // move tail to first a_ch
}








const std::string &Tokenizer::nextString()
{
	return next();
}




int                Tokenizer::nextInt()
{
	return std::stoi(next());
}




long               Tokenizer::nextLong()
{
	return std::stol(next());
}




long long          Tokenizer::nextLLong()
{
	return std::stoll(next());
}




unsigned long      Tokenizer::nextULong()
{
	return std::stoul(next());
}




unsigned long long Tokenizer::nextULLong()
{
	return std::stoull(next());
}




float              Tokenizer::nextFloat()
{
	return std::stof(next());
}




double             Tokenizer::nextDouble()
{
	return std::stod(next());
}




long double        Tokenizer::nextLDouble()
{
	return std::stold(next());
}








const std::string &Tokenizer::last()        const
{
	return m_ltk;
}




const std::string &Tokenizer::lastString()  const
{
	return last();
}




int                Tokenizer::lastInt()     const
{
	return std::stoi(last());
}




long               Tokenizer::lastLong()    const
{
	return std::stol(last());
}




long long          Tokenizer::lastLLong()   const
{
	return std::stoll(last());
}




unsigned long      Tokenizer::lastULong()   const
{
	return std::stoul(last());
}




unsigned long long Tokenizer::lastULLong()  const
{
	return std::stoull(last());
}




float              Tokenizer::lastFloat()   const
{
	return std::stof(last());
}




double             Tokenizer::lastDouble()  const
{
	return std::stod(last());
}




long double        Tokenizer::lastLDouble() const
{
	return std::stold(last());
}




const std::string &Tokenizer::lastToLower()
{
	std::transform(m_ltk.begin(), m_ltk.end(), m_ltk.begin(), tolower);
	return m_ltk;
}



