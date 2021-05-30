#if 0
#include <iostream>
#include <string>
#include <limits>

using namespace std;

//preprocessor directive
#define val 5
#define cVal 'a'

int globalNum; //global variable

void foo1();
void foo2();

int main(int argc, char** argv) {
	const size_t val1 = 10;					//constant
	//checking the size of a macro and a constant variable
	std::cout << "preprocessor, int = " << val << " " << sizeof(val) << std::endl;	// 5 4
	std::cout << "preprocessor, char = " << cVal << " " << sizeof(cVal) << std::endl;	// a 1
	std::cout << "const size_t = " << val1 << " " << sizeof(val1) << std::endl;	// 10 4
	foo1();
	return 0;
}

void foo1() {
	for (int n = 0; n < 10; n++) {
		foo2();
	}
}

void foo2() {
	static unsigned int i = 0;
	std::cout << i++ << " ";
}
#endif