#if 0
#include <iostream>
#include <vector>
#include <list>

//range based for loop for printing different types of data-structures
/*
for( declaration : expression)
{
	//do some loop stuff
}
*/
void print(std::list<int> v) {
	/*acces by value*/
	for (auto i : v) {
		i += 1;
	}
	/*access by const reference*/
	for (const auto &i : v) {
		std::cout << i << "\t";
	}
	std::cout << std::endl;
}

int RandomOperation(int *data) {
	data = data + 1;
	return *data;
}

/*difference between const auto&i and const auto i:
in first case, i is a reference of the container and hence in an event of change in the element,
would be reflected in the loop. This would not happen in the second case*/


/*&v[0] and v.data() return the reference to the first element of vector
Although they are not same as v.begin() which is an iterator and not a reference*/

int main() {

	/****************vector*********************/
	std::cout << "Vector Operations" << std::endl;
	std::vector<int> v = { 1, 2, 3, 4, 5 };
	for (auto &i : v) {
		std::cout << i << "\t" << &i;
	}
	std::cout << std::endl;
	std::cout << sizeof(int) << "\t" << v[0] << "\t" << &v[0] << "\t" << v.data() <<
							 "\t" << &v.begin() << "\t" << *(&v[0]) << std::endl;

	//call random operation 
	int randomVal = RandomOperation(v.data()); //or &v[0]
	std::cout << randomVal << std::endl;

	/****************list***********************/
	std::cout << "List Operations" << std::endl;
	std::list<int> l = { 1, 2, 3, 4, 5 };
	std::list<int>::iterator it;
	for (auto i = l.begin(); i != l.end(); i++) {
		std::cout << *i << "\t" << &(*i) <<  "\t";
	}
	it = l.end();
	l.push_back(6);
	//it++;
	l.insert(it, 7);

	/*begin() and end() are used for iterator pointing but back() contains the 
	last element of the data structure*/
	/*end() returns a bidirectional iterator to the past last element of the 
	container*/
	std::cout << std::endl;
	std::cout << *l.begin() << " " << &l.begin() << " " << *l.end() << " " 
			  << &l.end() << " " << &l.back() << " " << l.back() << std::endl;
	print(l);
	return 0;
}
#endif