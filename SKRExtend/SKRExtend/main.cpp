#include <iostream>

#include "skrextend/scriptreader/tokengetter/TokenGetter.h"


using std::cout;
using std::cin;
using std::endl;


int main() {
	skrextend::TokenGetter tkgetr("test.txt");
	cout << tkgetr.last() << endl;
	while ( ! tkgetr.isEnd()) {
		cout << tkgetr.next() << endl;
		cout << tkgetr.last() << endl;
	}
	cout << tkgetr.last() << endl;
}



