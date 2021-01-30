/*********************************************************************************************
Given an array of integers, find the subset of non-adjacent elements with the maximum sum. 
Calculate the sum of that subset. It is possible that the maximum sum is , the case when all 
elements are negative.

For example, given an array  arr = [-2, 1, 3, -4, 5]
we have the following possible subsets. These exclude the empty subset and single element 
subsets which are also valid.

Subset      Sum
[-2, 3, 5]   6
[-2, 3]      1
[-2, -4]    -6
[-2, 5]      3
[1, -4]     -3
[1, 5]       6
[3, 5]       8
**********************************************************************************************/
//#if 0
#include<iostream>
#include<vector>
#include<algorithm>
#include <string>

int maxElement(int *arr, int size) {
	int maxSum = INT_MIN;
	for (int i = 0; i < size; i++) {
		int sum = 0;
		for (int j = i; j < size; j = j + 2) {
			sum += 
		}
	}
}

int main() {
	int arr[] = { 2, 1, 4, 8, 4 };
	int size = 5;
	int maxElement(int *arr, int size);
	return 0;
}
//#endif