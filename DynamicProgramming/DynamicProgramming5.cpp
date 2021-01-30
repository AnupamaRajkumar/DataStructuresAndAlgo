/**********************************************************************************
You are given coins of different denominations and a total amount of money. 
Write a function to compute the fewest number of coins that you need to make up that amount. 
If that amount of money cannot be made up by any combination of the coins, return -1.

You may assume that you have an infinite number of each kind of coin.

Example 1 :
Input: coins = [1,2,5], amount = 11
Output: 3
Explanation: 11 = 5 + 5 + 1

Example 2:
Input: coins = [2], amount = 3
Output: -1

Example 3: 
Input: coins = [1], amount = 0
Output: 0
************************************************************************************/

#if 0
#include<iostream>
#include<vector>
#include<algorithm>
#include <string>

using namespace std;


int coinChange(vector<int>& coins, int amount) {
	int coinCount = 0;
	if (amount == 0) {
		coinCount = 0;
	}
	int *d = new (nothrow) int[amount+1];
	//int d[11];
	d[0] = 0;
	for (int i = 0; i < coins.size(); i++)
	{
		for (int j = 1; j <= amount; j++) {
			int min_val = INT_MAX;
			for (int k = 0; k < j; k++) {
					//cout << "Before" << endl;
					int val = (int)(j / coins[i]);
					if (j%coins[i] != 0) {
						val = val + 1;				
					}
					//cout << k << ": " << min_val << " " << val + d[j - k - 1] << endl;
					min_val = std::min(min_val, val + d[j - k - 1]);
					//cout << "After" << endl;
					//cout << k << ": " << min_val << endl;
			}
			d[j] = min_val;
		}
	}
	return(d[amount]);
}


int main() {
	vector<int> coins;
	coins.push_back(1);
	coins.push_back(2);
	coins.push_back(5);
	int amount = 12;
	int coinCount = coinChange(coins, amount);
	cout << "Coin count for amount " << amount << " is:" << coinCount << endl;;
	return 0;
}
#endif