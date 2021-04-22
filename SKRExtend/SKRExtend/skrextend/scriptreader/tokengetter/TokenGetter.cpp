/*

	class skrextend::TokenGetter

	Method class of get token by script file.
	Default delimiters is '\r', '\n', '\t' and ' ';


	Created by Sankyuri.

*/


#include "TokenGetter.h"
#include "ScriptReaderException.h"


using namespace skrextend;




TokenGetter::TokenGetter() :
	m_cur(0),
	m_fileName(""),
	m_data(""),
	m_delim("\r\n\t "),
	m_last("")
{
	// none
}


TokenGetter::TokenGetter(const std::string &a_fileName) :
	m_cur(0),
	m_fileName(a_fileName),
	m_data(""),
	m_delim("\r\n\t "),
	m_last("")
{
	std::ifstream ifs(a_fileName);
	if ( ! ifs.is_open()) {
		throw FileOpenException(a_fileName);
	}
	loadData(ifs);
}


TokenGetter::~TokenGetter() {
	// none
}




void TokenGetter::setScriptData(const std::string &a_data) {
	m_data = a_data;
}




void TokenGetter::reopen() {
	std::ifstream ifs(m_fileName);
	if ( ! ifs.is_open()) {
		throw FileOpenException(m_fileName);
	}
	loadData(ifs);
}


void TokenGetter::reopen(const std::string &a_fileName) {
	m_fileName = a_fileName;
	reopen();
}




void TokenGetter::addDelimiter(const std::string &a_delim) {
	m_delim += a_delim;
}


void TokenGetter::setDelimiter(const std::string &a_delim) {
	m_delim = a_delim;
}




const std::string &TokenGetter::getFileName() const {
	return m_fileName;
}




const std::string &TokenGetter::getData() const {
	return m_data;
}




bool TokenGetter::isEnd() const {
	return (  std::string::npos == m_cur  );
}




void TokenGetter::loadData(std::ifstream &ifs) {
	m_data.clear();
	m_data = std::string(std::istreambuf_iterator<char>(ifs),
						 std::istreambuf_iterator<char>());
	m_cur = m_data.find_first_not_of(m_delim, 0); // erase first delimiter
}








std::string    TokenGetter::next() {
	// a        b
	//  ^       ^
	//  cnt     nxt
	// 
	// 	     cnt
	// 	     V
	// define test_data
	//        ^
	//        nxt
	auto cnt = m_data.find_first_of(m_delim, m_cur);   // find delimiter
	auto nxt = m_data.find_first_not_of(m_delim, cnt + 1); // find after delimiter
	m_last   = m_data.substr(m_cur, cnt - m_cur); // trimming
	m_cur    = nxt; // move cursor
	return m_last;
}




std::string    TokenGetter::nextString() {
	return next();
}




int            TokenGetter::nextInt() {
	return std::stoi(next());
}




long               TokenGetter::nextLong() {
	return std::stol(next());
}




long long          TokenGetter::nextLLong() {
	return std::stoll(next());
}




unsigned long      TokenGetter::nextULong() {
	return std::stoul(next());
}




unsigned long long TokenGetter::nextULLong() {
	return std::stoull(next());
}




float          TokenGetter::nextFloat() {
	return std::stof(next());
}




double         TokenGetter::nextDouble() {
	return std::stod(next());
}




long double        TokenGetter::nextLDouble() {
	return std::stold(next());
}








std::string    TokenGetter::last() {
	return m_last;
}




std::string    TokenGetter::lastString() {
	return last();
}




int            TokenGetter::lastInt() {
	return std::stoi(last());
}




long               TokenGetter::lastLong() {
	return std::stol(last());
}




long long          TokenGetter::lastLLong() {
	return std::stoll(last());
}




unsigned long      TokenGetter::lastULong() {
	return std::stoul(last());
}




unsigned long long TokenGetter::lastULLong() {
	return std::stoull(last());
}




float          TokenGetter::lastFloat() {
	return std::stof(last());
}




double         TokenGetter::lastDouble() {
	return std::stod(last());
}




long double        TokenGetter::lastLDouble() {
	return std::stold(last());
}








void TokenGetter::moveCursorTo(const char a_ch) {
	// to a_ch
	m_cur = m_data.find_first_of(a_ch, m_cur) + 1;
}



