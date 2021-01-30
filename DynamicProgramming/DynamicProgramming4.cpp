/*****************************************************************************
A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach 
the bottom-right corner of the grid (marked 'Finish' in the diagram below).

How many possible unique paths are there?

Input: m = 3, n = 2
Output: 3
Explanation:
From the top-left corner, there are a total of 3 ways to reach the bottom-right corner:
1. Right -> Down -> Down
2. Down -> Down -> Right
3. Down -> Right -> Down
******************************************************************************/

#if 0
#include<iostream>
#include<vector>
#include<algorithm>
#include <string>

using namespace std;

int UniquePaths(int m, int n) {
	/*
	m : rows, n : cols
	*/
	int** costArr = new int*[m];
	for (int i = 0; i < m; ++i)
		costArr[i] = new int[n];

	for (int r = 0; r < m; r++) {
		costArr[r][0] = 1;
	}
	for (int c = 0; c < n; c++) {
		costArr[0][c] = 1;
	}
	for (int r = 1; r < m; r++) {
		for (int c = 1; c < n; c++) {
			costArr[r][c] = costArr[r - 1][c] + costArr[r][c - 1];
		}
	}
	return costArr[m-1][n-1];
}


int main() {
	int m, n, totalPaths;
	m = 3;
	n = 7;
	totalPaths = UniquePaths(m, n);
	cout << "Total number of paths:" << totalPaths << endl;
	return 0;
}
#endif
