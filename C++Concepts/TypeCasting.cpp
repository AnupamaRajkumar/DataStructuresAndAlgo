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
double average(int* data) {
	double sum = 0;
	unsigned int lengthOfArr = sizeof(data) / sizeof(data[0]);
	for (size_t i = 0; i < ; ++i) {
		sum += static_cast<double>(data) / static_cast<double>(data.size());
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

	int data[5] = { 1, 2, 3, 4, 5 };

	//pass by reference
	double sum = average(&data[0]);
	
	/*ans  = 400 because the lower data type ie char gets promoted to int and the result is int*/
	//std::cout << a + b << std::endl;
	//std::cout << c - b << std::endl;
	//std::cout << static_cast<int>(std::numeric_limits<unsigned char>::min()) << " " << static_cast<int>(std::numeric_limits<unsigned char>::max()) << std::endl;

	return 0;
}
#endif