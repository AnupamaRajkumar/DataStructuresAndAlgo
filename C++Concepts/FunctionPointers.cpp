#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/****************************
Function pointers are popularly used as callback functions that are invoked when some event happens.
Callback functions are popular for GUI, mouse and keyboard inputs
eg.
void create_button(int x, int y, const char *text, function callback_func);

syntax for declaring function pointer:
void (*foo)(int);
here foo is a pointer to a function taking one argument, an integer, and returns a void.

to read a function pointer - read inside-out
void *(*foo)(int *)
here, foo is pointer to a function that returns a void * and takes an int *

***************************/

void printData(int num) {
	cout << "num = " << num << endl;
}

int findMax(int a, int b) {
	return a > b;
}

int main() {
	//declaring a function pointer
	void(*foo)(int);
	foo = &printData;
	//prints 2
	foo(2);		//same as (*foo)(2)

	//example of function pointer in sort
	vector<int> v = { 3, 4, 7, 2, 1, 0, 9, 13, 22, 5 };
	sort(v.begin(), v.end(), *findMax); //the last function is a function pointer to change the behavior of sorting --> [](int a, int b) {return a > b; }
	for (auto& i : v) {
		cout << i << " ";
	}
}