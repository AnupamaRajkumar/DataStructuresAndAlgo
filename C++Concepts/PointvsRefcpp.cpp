#if 0
#include <iostream>

using namespace std;

int main() {
	/***********Pointer***********/
	std::cout << "****Pointers********" << std::endl;
	int a1 = 10;
	int *p = &a1;
	std::cout << p << " " << a1 << std::endl; // address to a1 value of a1
	std::cout << *p << " " << a1 << std::endl; // 10 10, *p - de-referencing
	std::cout << &p << std::endl;				// address of pointer p, hence a pointer has a memory of its own
	int b1 = 5;
	p = &b1;									//vaid syntax
	std::cout << p << " " << *p << " " << b1 << std::endl;

	/**********Reference*********/
	std::cout << "****References*********" << std::endl;
	//References are useful for parameter passing
	// a reference is an "alias" to a memory location
	int a2 = 10;
	//int &r;				//reference - this is a syntax error. A ref should always be initialised when declared
	//the correct way of declaring a reference
	int &r = a2;
	std::cout << r << " " << a2 << std::endl;		//10 10
	std::cout << &r << " " << &a2 << std::endl;		//same address, reference doesnt have an address of its own
	int b2 = 5;
	//&r = b; this is a syntax error. A reference is tied to the same variable. It can be considered to be a const pointer
	r = b2;			//valid syntax
	std::cout << r << " " << a2 <<  std::endl; //here the values are updated to that of b2. This is because value of r gets updated which is same
											 //as the value of a2. Hence that value gets updated too
}

#endif