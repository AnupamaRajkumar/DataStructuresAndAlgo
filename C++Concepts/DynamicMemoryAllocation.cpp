#if 0
#include <iostream>

int *fun(){
	int x = 5;
	return &x;
}

/*new operator : returns the address of the memory location
delete is used for memory deallocation
*/
int main() {
	int *pointVar;
	pointVar = new int;
	*pointVar = 45;

	std::cout << *pointVar << std::endl;
	delete pointVar;

	/*new operator can be used to decalre an array dynamically*/
	int n = 5;	//this value can be a user input
	int *arr = new int(n);
	for (size_t i = 0; i < n; i++) {
		arr[i] = i + 1;
	}
	for (size_t i = 0; i < n; i++) {
		std::cout << arr[i] << "\t";
	}
	std::cout << std::endl;

	delete arr;

	int *arr2{ new int[n] {1, 2, 3, 4, 5} };
	for (size_t i = 0; i < n; i++) {
		std::cout << arr2[i] << "\t";
	}
	std::cout << std::endl;

	delete[] arr2;

	return 0;
}
#endif