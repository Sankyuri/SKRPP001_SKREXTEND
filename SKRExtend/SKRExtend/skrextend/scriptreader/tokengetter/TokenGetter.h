/*

    class skrextend::TokenGetter

	Method class of get token by script file.
	Default delimiters is '\r', '\n', '\t' and ' ';


	Created by Sankyuri.

*/


#pragma once
#include <string>
#include <fstream>


namespace skrextend {

	//
	//  Method class of get token by script file.
	//
	class TokenGetter {
	public:

		TokenGetter();

		// open script file
		TokenGetter(const std::string &a_fileName);

		// set script data
		void setScriptData(const std::string &a_data);


		// re-open script file
		void reopen();

		// open other script file
		void reopen(const std::string &a_fileName);


		// add delimiter to the set deliimiter
		void addDelimiter(const std::string &a_delim);

		// set new delimiter
		void setDelimiter(const std::string &a_delim);


		const std::string &getFileName() const;
		const std::string &getData()     const;


		// return true if script data is ended
		bool isEnd() const;


		// get next token
		std::string        next();
		std::string        nextString();
		int                nextInt();
		long               nextLong();
		long long          nextLLong();
		unsigned long      nextULong();
		unsigned long long nextULLong();
		float              nextFloat();
		double             nextDouble();
		long double        nextLDouble();


		// get last token
		std::string        last();
		std::string        lastString();
		int                lastInt();
		long               lastLong();
		long long          lastLLong();
		unsigned long      lastULong();
		unsigned long long lastULLong();
		float              lastFloat();
		double             lastDouble();
		long double        lastLDouble();


		// Move cursor to next a_ch.
		void moveCursorTo(const char a_ch);




		~TokenGetter();


	private:

		size_t        m_cur;
		std::string   m_fileName;
		std::string   m_data;
		std::string   m_delim;
		std::string   m_last;

		void loadData(std::ifstream &ifs);


	};

}



