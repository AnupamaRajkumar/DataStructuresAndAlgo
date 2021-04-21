#if 0

#include <iostream>

void CallByValDemo(int a, int b) {
	a += 10;
	b += 10;
}

void CallByReferenceDemo(int &a, int &b) {
	a += 10;
	b += 10;
}

int main() {

	int a, b;

	a = 10;
	b = 25;

	std::cout << "---Call by Value---" << std::endl;
	std::cout << "Before function call" << std::endl;
	std::cout << "a: " << a << "\tb:" << b << std::endl;
	CallByValDemo(a, b);
	std::cout << "After function call" << std::endl;
	std::cout << "a: " << a << "\tb:" << b << std::endl;

	std::cout << "---Call by Reference---" << std::endl;
	std::cout << "Before function call" << std::endl;
	std::cout << "a: " << a << "\tb:" << b << std::endl;
	CallByReferenceDemo(a, b);
	std::cout << "After function call" << std::endl;
	std::cout << "a: " << a << "\tb:" << b << std::endl;

	return 0;
}

#endif