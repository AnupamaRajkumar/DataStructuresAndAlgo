#include <iostream>

using namespace std;

#if 0
/**************************************
template <class identifier> function_declaration;
template <typename identifier> function_declaration;

the only difference between these two prototypes is the use of either the keyword "class" or
"typename". Its use is indistinct, since both have exactly the same meaning and behave 
exactly the same way
**************************************/

template<class T>
class arithmetic {
private:
	T a;
	T b;
public:
	arithmetic(T a, T b);
	T add();
	T sub();
};

template<class T>
arithmetic<T>::arithmetic(T a, T b) {
	this->a = a;
	this->b = b;
}

template<class T>
T arithmetic<T>::add() {
	T sum = this->a + this->b;
	return sum;
}

template<class T>
T arithmetic<T>::sub() {
	int diff = abs(this->a - this->b);
	return diff;
}

template <typename T>
T myMax(T x, T y)
{
	return (x > y) ? x : y;
}

int main() {
	arithmetic<int> a(5, 10);
	int sum = a.add();
	cout << "sum = " << sum << endl;
	int diff = a.sub();
	cout << "diff = " << diff << endl;

	cout << "Max value is: " <<  myMax<int>(5, 10) << endl;
	cout << "Max value is: " << myMax<float>(2.663, 2.536) << endl;
}
#endif