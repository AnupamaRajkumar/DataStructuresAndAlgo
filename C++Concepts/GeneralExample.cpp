#if 0
#include <iostream>
#include <vector>

/*
 * Modify this code so that:
 * 1. it compiles without modifying the Container type
 * 2. explain what this code is trying to do, and why it is not working
 * 3. explain how we can solve this issue

 1 2 3...10
 */
struct Container {

	int *data;
	Container(int *data) : data(data) {
	}

	void printFirst() {
		std::cout << data[0] << std::endl;
	}
};

int main() {

	std::vector<int> vec = {0};
	vec.reserve(11);
	Container container(&vec[0]);

	for (size_t i = 0; i < 10; ++i) {
		vec[0] = 1 + i;
		vec.push_back(i);
		container.printFirst();
	}
}
#endif

