// DynamicProgramming1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
/*****************************************************************************
You are given a bag of size W kg and you are provided costs of packets different weights of oranges in array cost[] 
where cost[i] is basically the cost of ‘i’ kg packet of oranges. Where cost[i] = -1 means that ‘i’ kg packet of orange 
is unavailable
Find the minimum total cost to buy exactly W kg oranges and if it is not possible to buy exactly W kg oranges then 
print -1. It may be assumed that there is an infinite supply of all available packet types.

Example:
Input  : W = 5, cost[] = {20, 10, 4, 50, 100}
Output : 14
We can choose two oranges to minimize cost. First
orange of 2Kg and cost 10. Second orange of 3Kg
and cost 4.

*********************************************************************************/
#if 0
// C++ program to find minimum cost to get exactly
// W Kg with given packets
#include <iostream>
#include <vector>
#include <algorithm>
#include <new>
#define INF 1000000

using namespace std;


/********************Approach 1 - No dynamic programming***************************/

#if 0
// cost[] initial cost array including unavailable packet
// W capacity of bag
int MinimumCost(int cost[], int n, int W)
{
	// val[] and wt[] arrays
	// val[] array to store cost of 'i' kg packet of orange
	// wt[] array weight of packet of orange
	vector<int> val, wt;

	// traverse the original cost[] array and skip
	// unavailable packets and make val[] and wt[]
	// array. size variable tells the available number
	// of distinct weighted packets
	int size = 0;
	for (int i = 0; i < n; i++)
	{
		if (cost[i] != -1)
		{
			val.push_back(cost[i]);
			wt.push_back(i + 1);
			size++;
		}
	}
	n = size;

	/*declaring size of an array dynamically in C++11*/
	int rowCount = n + 1;
	int colCount = W + 1;

	int** min_cost = new int*[rowCount];
	for (int i = 0; i < rowCount; ++i)
		min_cost[i] = new int[colCount];
	//int min_cost[6][9];

	// fill 0th row with infinity
	for (int i = 0; i <= W; i++)
		min_cost[0][i] = INF;

	// fill 0'th column with 0
	for (int i = 1; i <= n; i++)
		min_cost[i][0] = 0;

	// now check for each weight one by one and fill the
	// matrix according to the condition
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= W; j++)
		{
			// wt[i-1]>j means capacity of bag is
			// less then weight of item
			if (wt[i - 1] > j) {
				cout << min_cost[i - 1][j] << endl;
				min_cost[i][j] = min_cost[i - 1][j];
			}
				

			// here we check we get minimum cost either
			// by including it or excluding it
			else {
				cout << min_cost[i - 1][j] << " " << min_cost[i][j - wt[i - 1]] << " " << val[i - 1] << endl;
				min_cost[i][j] = std::min(min_cost[i - 1][j], min_cost[i][j - wt[i - 1]] + val[i - 1]);
				
			}
			cout << "min_cost:" << min_cost[i][j] << endl;
		}
		
	}

	// exactly weight W can not be made by given weights
	return (min_cost[n][W] == INF) ? -1 : min_cost[n][W];
}

// Driver program to run the test case
int main()
{
	int cost[] = { 20, 10, 40, 50, 100 } , W = 8;
	int n = sizeof(cost) / sizeof(cost[0]);

	cout << MinimumCost(cost, n, W);
	return 0;
}
#endif


/********************Approach 2 - Dynamic programming***************************/
//#if 0
/* Returns the best obtainable price for
   a rod of length n and price[] as prices
   of different pieces */
int minCost(int cost[], int n, int W)
{
	int *dp = new (nothrow) int[n + 1];
	dp[0] = 0;

	// Build the table val[] in bottom up 
	// manner and return the last entry 
	// from the table 
	for (int i = 1; i <= n; i++)
	{
		cout << i << endl;
		int min_cost = INT_MAX;
		for (int j = 0; j < i; j++) {
			min_cost = min(min_cost, cost[j] + dp[i - j - 1]);
			cout << j << ": " << min_cost << endl;
		}
			
		dp[i] = min_cost;
		cout << "dp[i]:" << dp[i] << endl;
	}

	return dp[n];
}

/* Driver program to test above functions */
int main()
{
	int cost[] = { 20, 10, 40, 50, 100 };
	//int cost[] = { 1, 10, 4, 50, 100 };
	int n = sizeof(cost) / sizeof(cost[0]);
	int W = 8;
	cout << minCost(cost, n, W);
	return 0;
}
//#endif
#endif