#if 0
#include <iostream>

using namespace std;

/*globalNum is a global variable and stored in the data segment*/
int globalNum;

int *badPointer() {
	int temp = 100;
	return (&temp);
}

int *staticPointer() {
	static int temp = 150;
	temp += 10;
	return (&temp);
}

void f() {
	/*for an array if the first element is initialised, all the other locations 
	by default are initialised to 0*/
	int a[10] = { 1 };
	for (auto i : a) {
		cout << i << " ";
	}
	cout << endl;
}

int* createArray() {
	//int arr[10];			//array stored on stack memort
	int *arr = new (nothrow) int[10];		//array stored on heap through dynamic memort allocation
	return arr;

	int val = 10;
	int *ptr = new (nothrow) int;
	ptr = &val;
}

int main() {

	/***demonstration of auto variable****/
	/*auto variables : stored in the stack with a scope and lifetime that of the block
	in which they are defined*/
	auto x = 4;
	auto y = 3.14;
	auto z = 'a';
	auto *ptr = &x;

	cout << typeid(x).name() << "\t"
		<< typeid(y).name() << "\t"
		<< typeid(z).name() << "\t"
		<< typeid(ptr).name() << endl;

	/*if global variables are not assigned a value, it is assigned 0
	They are stored in data segment of memory layout if uninitialised.
	Initialised variables are stored in the bss section*/
	cout << globalNum << endl;

	int *badPtr = badPointer();
	f();
	cout << *badPtr << endl;

	int *staticPtr = staticPointer();
	cout << *staticPtr << endl;
	cout << ++(*staticPtr) << "\t" << *staticPointer() << endl;	//static variable keeps the value between subsequent function calls

	/*****Demonstration of segmentation error due to stack****/

	int *arr = createArray();
	for (int i = 0; i < 10; i++) {
		arr[i] = i+1;
	}
	/*here, we see that the values printed are garbage except the first value. This is because after createArray returns the
	address of the first element of array, the variable arr in the function gets deallocated as it is stored in the stack
	and hence the subequent addresses are no longer contiguous and garbage. This can be fixed by assigning the array on 
	heap instead of stack. Stack is controlled by the program while memory allocation in heap is controlled by the programmer*/
	for (int i = 0; i < 10; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
	delete[] arr;		//deleting the array
	return 0;
}
#endif