#if 0

#include <iostream>
#include <vector>

/*pass vector to function*/
double VectorAverage(std::vector<int>& v) {

	double average = 0.0;
	for (size_t i = 0; i < v.size(); i++) {
		average += static_cast<double>(v.at(i))/v.size();
		v.at(i) += 1;
	}
	std::cout << "Inside the vector average function - vector" << std::endl;
	for (const auto&i : v) {
		std::cout << i << " ";
	}
	std::cout << std::endl;
	return average;
}

/*pass array to function*/
double ArrayAverage(int (&a)[5], int len) {			//same as int a[], int a[5], int (&a)[5]
	double average = 0.0;
	a[2] = 8;
	//std::cout << sizeof(a) << " " << sizeof(a[0]) << std::endl;
	for (size_t i = 0; i < len; i++) {
		average += static_cast<double>(a[i]) / static_cast<double>(len);
		a[i] += 1;
	}
	std::cout << "Inside the array average function - array" << std::endl;
	for (size_t i = 0; i < len; i++) {
		std::cout << a[i] << "\t";
	}
	std::cout << std::endl;
	return average;
}


int main() {

	std::vector<int> v = { 1, 2, 3, 4, 5 };
	int a[5] = { 1, 2, 3, 4, 5 };

	for (const auto&i : a) {
		std::cout << i << "\t";
	}
	std::cout << std::endl;


	//find length of vector and array
	std::cout << "Vector length:" << v.size() << "\t Length of array:" << sizeof(a) / sizeof(a[0]) << std::endl;

	/*vector - call by value*/
	/*double avgVec = VectorAverage(v);
	std::cout << "Average of vector:" << avgVec << std::endl;

	//display the vector
	std::cout << "after the function call" << std::endl;
	for (const auto& i : v) {
		std::cout << i << "\t";
	}
	std::cout << std::endl;*/

	//vector - call by reference
	double avgVec = VectorAverage(v);
	std::cout << "Average of vector:" << avgVec << std::endl;

	/*display the vector*/
	std::cout << "after the function call - vector" << std::endl;
	for (const auto& i : v) {
		std::cout << i << "\t";
	}
	std::cout << std::endl;
	v.resize(2);
	std::cout << "Resized" << std::endl;
	for (const auto& i : v) {
		std::cout << i << "\t";
	}
	std::cout << std::endl;


	unsigned int len = sizeof(a) / sizeof(a[0]);
	/*an array passed as a parameter to function is treated as a pointer and hence unless explicitly terminated 
	by a \0, the size of the array should be passed as a parameter to the function*/
	/*syntax-wise, an array cannot be passed by value in C*/
	/*since arrays are always pass by reference, any change to the array would change the original array*/
	a[4] = 10;
	double avgArr = ArrayAverage(a, len);		//same as &a[0]
	std::cout << "Average of array:" << avgArr << std::endl;
	std::cout << "After the function call - array" << std::endl;
	for (const auto& i : a) {
		std::cout << i << "\t";
	}
	std::cout << std::endl;

	//delete[] a;

	/************************************/
	//initialising entire array with 0s
	int b[10] = { 0 };
	//in an array, if the first element is initialised, all the other elements are by default initialised to 0
	for (auto&i : b) {
		std::cout << i << " " << std::endl;
	}
	//variable sized array - compiler doesnt support
	//const int s = 5;
	//int v[s];

	return 0;
}

#endif