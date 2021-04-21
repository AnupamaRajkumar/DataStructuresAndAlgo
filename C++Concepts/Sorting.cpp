#if 0
#include <algorithm>
#include <iostream>
#include <list>
#include <vector>

/*
 * Modify this code so that:
 * 1. it compiles.
 * 2. correctly computes the largest value in a vector
 * 3. does not use indexing (what can we change data[0] to?) - *data.begin()
 * 4. explain what we could do if we do not want to modify the container - pass by value instead of pass ie remove & from prototype
 by reference
 */
template <typename Data>
auto largest(Data& data) {						
	std::sort(data.begin(), data.end(),
		[](const auto &e1, const auto &e2) { return e1 > e2; });
	int size = data.size();
	//std::sort(data.begin(), data.end(), std::greater<int>());
	//std::cout << *data.begin() << " " << *data.end();
	//return *data.begin();
	return *data.data(); //or *data.begin() or data[0]
}

int main() {
	std::vector<int> data = { 5, 3, 1, 9, 2 };
	std::cout << largest(data) << std::endl;
	for (size_t i = 0; i < data.size(); i++) {
		std::cout << data[i] << "\t";
	}
	std::cout << std::endl;
}
#endif