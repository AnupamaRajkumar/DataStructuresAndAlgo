#if 0
#include <iostream>
#include <vector>
#include <list>
#include <limits>
#include <cstddef>

/*
 * Modify this code so that:
 * 1. it compiles.
 * 2. correctly computes the average value in a vector
 * 3. the average function can also accept other containers like arrays or lists
 */
double average(std::vector<int> data) {
	double sum = 0;

	//size() returns the number of elements in the vector. It is of unsigned int type
	//sizeof() returns the number of bytes used by object definition. It is a static const generated by compiler at run time
	//based on the declaration of vector class
	std::cout << data.size() << " " << sizeof(data) << " " << sizeof(data[0]) << " " << data.capacity() << std::endl;
	for (size_t i = 0; i < data.size(); ++i) {
		
		sum += static_cast<double>(data[i])/ (data.size());
	}

	/*for (auto it = data.begin(); it != data.end(); it++) {
		sum += static_cast<double>(*it) / static_cast<double>(data.size());
	}*/
	/*for (const auto& i : data) {
		sum += static_cast<double>(i) / static_cast<double>(data.size());
	}*/
		
	return sum;
}

int main() {

	std::vector<int> data = { 1, 2, 3, 4, 5 };
	int a[5] = { 1, 2, 3, 4, 5 };
	std::cout << sizeof(a) << " " << sizeof(a[0]) << std::endl;

	//pass by reference
	double sum = average(data);

	std::cout << "Sum=" << sum << std::endl;

	double result = 0;
	int num = 2;
	double den = 5.;
	result = num / den;
	std::cout << result << std::endl;
	
	/*ans  = 400 because the lower data type ie char gets promoted to int and the result is int*/
	//std::cout << a + b << std::endl;
	//std::cout << c - b << std::endl;
	//std::cout << static_cast<int>(std::numeric_limits<unsigned char>::min()) << " " << static_cast<int>(std::numeric_limits<unsigned char>::max()) << std::endl;

	return 0;
}
#endif