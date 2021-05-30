//#if 0
#include <iostream>

using namespace std;

struct general {
	int x;
	//bit fields
	unsigned int x2 : 6;
	char c[30];

	general():x(10),x2(6){

	}
	void printVal() {
		cout << x << " " << x2 << endl;
	}
};

typedef union specific {
	int x;
	char c[28];
}spec;



int main(int argv, char** argc) {
	/****Structure**********/
	cout << "*********Structure*************" << endl;
	struct general g;
	//pointer to structure
	struct general *gPtr = &g;


	cout << "Size of the structure - " << sizeof(g) << endl;			/*40 because memory needed by int is 4, char is 2 and the word size of compiler is 4.
																		Due to this for character array 30/4, 2 bytes remain unused making the total structure 
																		size to 40 instead of 38 (called padding)*/
	cout << "size of int x - " << sizeof(g.x) << endl;					//4
	cout << "size of char array c - " << sizeof(g.c) << endl;			//30
	g.x2 = 20;
	cout << "value of x2 - " << g.x2 << endl;
	g.x2 = 8;
	cout << "value of x2 - " << g.x2 << endl;
	g.x = 50;
	g.printVal();

	/*Pointer to structure operations*/
	(*gPtr).x = 200;
	cout << "(*gPtr).x: " << (*gPtr).x << endl;
	gPtr->x = 500;
	cout << "gPtr->x: " << gPtr->x << endl;

	//creating object dynamically - in heap..useful in data structures
	struct general *gPtr1;
	gPtr1 = (struct general *)malloc(sizeof(struct general));
	gPtr1->x = 2000;

	/******Union*********/
	cout << "********Union***********" << std::endl;
	/*The size of union is the size of the largest element in the union, 28 in this case
	If the size of char array is increased to 30, the size of union becomes 32*/
	spec s;
	cout << "Size of the union - " << sizeof(s) << endl;		
	cout << "size of int x - " << sizeof(s.x) << endl;
	cout << "size of char array c - " << sizeof(s.c) << endl;
	return 0;
}
//#endif