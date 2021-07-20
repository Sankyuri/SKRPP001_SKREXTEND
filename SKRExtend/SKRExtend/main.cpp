#include <iostream>

#include "skrextend/tokenizer/Tokenizer.h"


using std::cout;
using std::cin;
using std::endl;


int main() {
	skrex::Tokenizer tknzr("test.txt");
	cout << tknzr.last() << endl;
	while ( ! tknzr.isEnd()) {
		cout << tknzr.next() << endl;
		cout << tknzr.last() << endl;
	}
	cout << tknzr.last() << endl;
}



