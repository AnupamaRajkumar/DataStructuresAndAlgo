#if 0
#include <iostream>

using namespace std;

/*grouping instructions form a function - procedural programming
parameters in the calling function - actual parameters
parameters in the prototype - formal parameters
Types of parameter passing
a. pass/call by value - pass actual parameter values to the formal parameters. Once the function call ends, the formal parameters
are deleted from stack and hence the value and hence any modifications done to formal parameters are not reflected.

b. pass/call by address - addresses of actual parameters are passed to formal parameters, through pointers. Changes done to formal
parameters gets reflected to actual parameters

c. pass/call by reference - use references for formal parameters. The references as formal parameters are alias of the actual 
parameters and hence changes done in formal parameters are reflected to actual parameters
*/
int add_callbyVal(int a, int b) {
	++a;
	++b;
	int sum = a + b;
	cout << "a = " << a << " b = " << b << endl;	// 11 21
	return sum;
}

int add_callbyAddress(int *a, int *b) {
	++(*a);
	++(*b);
	int sum = *a + *b;
	cout << "a = " << *a << " b = " << *b << endl;	// 11 21
	return sum;
}

int add_callbyRef(int&a, int&b) {
	//a and b are aliases of num1 and num2
	++(a);
	++(b);
	int sum = a + b;
	cout << "a = " << a << " b = " << b << endl;	// 11 21
	return sum;
}

int main()
{
	int num1 = 10, num2 = 20;

	/****Call by value*****/
	cout << "----Call by value---\n";
	int sum = add_callbyVal(num1, num2);
	//returned sum is correct for call by value because the return values get modified correctly, as desired
	cout << "Sum is - " << sum << endl;								// 32
	cout << "Num 1 - " << num1 << " Num 2 - " << num2 << endl;		// 10 20

	/****Call by address******/
	cout << "----Call by address----\n";
	sum = add_callbyAddress(&num1, &num2);
	cout << "Sum is - " << sum << endl;								//32
	cout << "Num 1 - " << num1 << " Num 2 - " << num2 << endl;		// 11 21

	/****Call by reference*****/
	cout << "---Call by reference----\n";
	sum = add_callbyRef(num1, num2);
	cout << "Sum is - " << sum << endl;								//34----do you know why? because call by address earlier already modifies num1 and num2
	cout << "Num 1 - " << num1 << " Num 2 - " << num2 << endl;		// 12 22
	
	/****Array as parameters*********/


	return 0;
}

#endif
