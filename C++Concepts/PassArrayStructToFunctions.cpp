#if 0
#include <iostream>

using namespace std;

/*Passing array and structures as parameters to function
1. Call by values - arrays cannot be passed by values!!!!!!!
2. Call by address
3. Call by reference			
*/

void printArr_Address(int a[], int size) { //passing the address of 0th element of array a, a[] acts as pointer to hold the address of
											//0th index of an array, can also be written as *a
	for (int i = 0; i < size; i++) {
		cout << a[i] << " ";
	}
	a[0] += 15;
	cout << endl;
}

void printArr_Ref(int (&a)[5], int size) { //adding a reference to the array
	for (int i = 0; i < size; i++) {
		cout << a[i] << " ";
	}
	a[0] += 15;
	cout << endl;
}


int* fun() {
	//int *p = new(nothrow) int[n];
	int p[5];
	for (int i = 0; i < 5; i++) {
		p[i] = i + 10;
	}
	return p;
}

typedef struct rectangle {
	int length;
	int breadth;
}rect;

int area_callbyVal(rect r) {
	int area = r.length * r.breadth;
	r.length += 5;
	r.breadth += 10;
	cout << "r.length:" << r.length << " ,r.breadth:" << r.breadth << "\n";
	return area;
}

int area_callbyRef(rect &r) {
	int area = r.length * r.breadth;
	r.length += 5;
	r.breadth += 10;
	cout << "r.length:" << r.length << " ,r.breadth:" << r.breadth << "\n";
	return area;
}

void area_callbyAddress(rect *r) {
	//here the values of r are updated
	r->length += 5;
	r->breadth += 10;
}

rect *val() {
	rect *r;
	r = new rect;
	r->length = 10;
	r->breadth = 20;
	return r;
}

int main() {
	/*****Pass array as parameter to function*************/
	int a[5] = { 2, 3, 4, 5, 6 };
	cout << "Call by address" << endl;
	printArr_Address(a, 5); 
	for (int i = 0; i < 5; i++) {
		cout << a[i] << " ";
	}
	cout << endl;
	cout << "Call by reference" << endl;
	printArr_Ref(a, 5);
	for (int i = 0; i < 5; i++) {
		cout << a[i] << " ";
	}
	cout << endl;
	/************Function returning an array*********/
	int *A;
	A = fun();

	/**********Pass struct to function*************/
	rect r = { 10, 20 };
	int area = area_callbyVal(r);
	cout << "struct - call by value\n";
	cout << "area - " << area << endl;
	cout << "length = " << r.length << " ,breadth = " << r.breadth << endl;		//change in the value of length and breadth are not reflected here

	area = area_callbyRef(r);
	cout << "struct - call by reference\n";
	cout << "area - " << area << endl;
	cout << "length = " << r.length << " ,breadth = " << r.breadth << endl;		//the values of legth and breadth updated in the function are reflected here

	area_callbyAddress(&r);
	area = r.length*r.breadth;
	cout << "struct - call by address\n";
	cout << "area - " << area << endl;
	cout << "length = " << r.length << " ,breadth = " << r.breadth << endl;		//the values of legth and breadth updated in the function are reflected here

	cout << "Returning rectangle from function" << endl;
	rect *r1 = val();
	area = r1->length*r1->breadth;
	cout << "struct - return from function\n";
	cout << "area - " << area << endl;
	cout << "length = " << r1->length << " ,breadth = " << r1->breadth << endl;		//the values of legth and breadth updated in the function are reflected here
}
#endif