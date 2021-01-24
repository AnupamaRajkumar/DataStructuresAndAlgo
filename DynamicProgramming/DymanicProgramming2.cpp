// A Dynamic Programming solution for Rod cutting problem 
/*********************************************************************************
Given a rod of length n inches and an array of prices that contains prices of all pieces of size smaller than n. 
Determine the maximum value obtainable by cutting up the rod and selling the pieces. For example, if length of 
the rod is 8 and the values of different pieces are given as following, then the maximum obtainable value is 22 
(by cutting in two pieces of lengths 2 and 6)

length   | 1   2   3   4   5   6   7   8		
--------------------------------------------
price    | 1   5   8   9  10  17  17  20
And if the prices are as following, then the maximum obtainable value is 24 (by cutting in eight pieces of length 1)

length   | 1   2   3   4   5   6   7   8
--------------------------------------------
price    | 3   5   8   9  10  17  17  20
**********************************************************************************/

#if 0
#include <iostream>
#include <new>
#include<limits.h> 

using namespace std;

// A utility function to get the maximum of two integers 
int max(int a, int b) { return (a > b) ? a : b; }

/* Returns the best obtainable price for a rod of length n and
   price[] as prices of different pieces */
int cutRod(int price[], int n)
{
	int *val = new (nothrow) int[n + 1];
	val[0] = 0;
	int i, j;

	// Build the table val[] in bottom up manner and return the last entry 
	// from the table 
	for (i = 1; i <= n; i++)
	{
		int max_val = INT_MIN;
		for (j = 0; j < i; j++) {
			max_val = max(max_val, price[j] + val[i - j - 1]);
			cout << j << ": " << max_val << endl;
		}		
		val[i] = max_val;
		cout << "val[" << i << "]:" << val[i] << endl;
	}

	return val[n];
}

/* Driver program to test above functions */
int main()
{
	int arr[] = { 1, 5, 8, 9, 10, 17, 17, 20 };
	int size = sizeof(arr) / sizeof(arr[0]);
	printf("Maximum Obtainable Value is %dn", cutRod(arr, size));
	getchar();
	return 0;
}
#endif