#if 0

#include <iostream>

int main() {

	size_t a = -50000.123; //unsigned int - size of size_t
	std::cout << sizeof(a) << " " << static_cast<int>(a) << " " << sizeof(size_t) <<  std::endl;

	/*pointer to constant integer - constant value*/
	const int q1 = 5;
	const int *p1 = &q1;	
	/*int *p1 = &q1; This is incorrect as q1 is contant and hence it should be specified in the declaration
	of the pointer that it will point to a constant integer*/
	std::cout << p1 << "\t" << *p1 << "\t" << q1 << " \t" << &q1 << "\t" << *(&q1) << std::endl;

	/*constant pointer to integer - constant addess*/
	int q2 = 10;
	int *const p2 = &q2;
	*p2 = 100;
	int q3 = 15;
	/*p2 = &q3;	This is incorrect as p2 is a constant pointer and hence it throws an error if it is made to
	point to a different location*/	
	std::cout << p2 << "\t" << *p2 << "\t" << q2 << "\t" << &q2 << "\t" << *(&q2) << std::endl;

	/*constant pointer to a constant integer - constant address, constant value*/
	const int q4 = 20;
	const int *const p3 = &q4;
	/*p3 = &q3; This is incorrect as p3 is a constant pointer to a constant integer and throws an error
	when it is made to point to another address. Also it is essential that the address it points to contains
	a constant value*/
	std::cout << p3<< "\t" << *p3 << "\t" << q4 << "\t" << &q4 << "\t" << *(&q4) << std::endl;

	/*neither the reference nor the value is a constant*/
	int *p4 = &q3;
	std::cout << p4 << "\t" << *p4 << "\t" << q3 << "\t" << &q3 << "\t" << *(&q3) << std::endl;
	p4 = &q2; //pointer can point to different addresses containing non constant int values
	std::cout << p4 << "\t" << *p4 << "\t" << q2 << "\t" << &q2 << "\t" << *(&q2) << std::endl;


	/***********************************Pointer Arithmetic*****************************************/
	int arr[5] = { 1, 2, 3, 4, 5 };
	int (*arithPtr)[5];

	for (int i = 0; i < 5; i++) {
		std::cout << arr[i] << " " << *(arr + i) << " " << &(*(arr+i)) <<   std::endl;
	}
	std::cout << std::endl;
	std::cout << arithPtr << " " << ++arithPtr << " " << ++(*arithPtr) << std::endl;


	/**********************************Pointer Problems*******************************************/
	/*a. Dangling pointer - when the location that a pointer points to doesnt exist anymore, this leads
	to a dangling pointer. correct way to handle this is make the ptr NULL before the variables go out of scope*/
	int *ptr;
	{
		int ch = 5;
		ptr = &ch;
	}
	//here the ptr is dangling as it doesnt point to any location since ch goes out of scope and might result in
	//unpredictable behavior
	std::cout << ptr << " " << *ptr << std::endl;

	/*b. Void pointer - pointer that points to some data location in storage without any specific type ie. void.
	Void pointers cannot be de-referenced. It can howver be de-referenced using void pointer. Pointer arithmetic
	is not possible on void pointers due to lack of concrete value and size*/

	void *vPtr;
	int i = 5;
	float f = 2.9;
	vPtr = &i;

	std::cout << "Integer variable address is:" << (int*)vPtr << " with value:" << *((int*)vPtr) << std::endl; //just using *vPtr leads to a compilation error. Hence type-casting is needed

	vPtr = &f;

	std::cout << "Float variable address is:" << (float*)vPtr << " with value:" << *((float*)vPtr) << std::endl;


	/*c. Null pointer - a pointer that points to nothing. A Null pointer doesnt have a memory assigned to it*/
	int *nPtr = NULL;
	std::cout << "The value of null pointer is:" << nPtr << std::endl;	//*nPtr is an error as the pointer points to no location and hence holds no value


	/*d. Wild pointer - Also unitialised pointer. This pointer is not assgned to any location*/
	int *wPtr;				//this is a wild pointer as it has not been assigned to any location
	wPtr = &i;				//not wild pointer anymore
	std::cout << "The uninitialized pointer points to:" << wPtr << " with value:" << *wPtr << std::endl;

	return 0;
}

#endif