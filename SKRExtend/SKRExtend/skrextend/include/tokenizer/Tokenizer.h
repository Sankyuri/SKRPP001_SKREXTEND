#pragma once
#include <string>


namespace skrex {


// String to slice to token.
class Tokenizer {
public:

	Tokenizer();

	// open script file
	Tokenizer(const std::string &a_fileName);




	// open script file
	// @a_fileName Script file name.
	// @return If succeeded to load file then return true, otherwise return false.
	bool openScriptFile(const std::string &a_fileName);


	// set script data
	void setScriptData(const std::string &a_data);




	// Returns length of current token.
	// @return Length of current token.
	size_t getTokenLength() const;


	// Check to next token is exist.
	// @return If exist next token when return true.
	bool hasNext() const;


	// return true if script data is ended
	bool isEnd() const;




	// Move cursor to next token.
	// @return String of next token.
	const std::string &next();
	const std::string &nextString();
	int                nextInt();
	long               nextLong();
	long long          nextLLong();
	unsigned long      nextULong();
	unsigned long long nextULLong();
	float              nextFloat();
	double             nextDouble();
	long double        nextLDouble();


	// get last token
	const std::string &last()        const;
	const std::string &lastString()  const;
	int                lastInt()     const;
	long               lastLong()    const;
	long long          lastLLong()   const;
	unsigned long      lastULong()   const;
	unsigned long long lastULLong()  const;
	float              lastFloat()   const;
	double             lastDouble()  const;
	long double        lastLDouble() const;


	// last token convert to lower
	const std::string &lastToLower();


	// Search next token with included by a_idt.
	// @return Next token with included by a_idt.
	const std::string &inclusive(const char *a_idt);


	// Search next token with included by a_idt.
	// @return Next token with included by a_idt.
	const std::string &inclusive(const char a_idt);


	// Move cursor to next token on after next a_ch.
	void moveCursorTo(const char a_ch);




private:
	static constexpr auto SPACE = "\r\n\t ";

	std::string  m_name;
	std::string  m_str;
	std::string  m_ltk; // last token
	std::size_t  m_chd; // cursor of head on token
	std::size_t  m_ctl; // cursor of tail on token


};


}



