/******************************************************************************
Given an array of non-negative integers nums, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Determine if you are able to reach the last index.
Example 1:
Input: nums = [2,3,1,1,4]
Output: true
Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.
Example 2:
Input: nums = [3,2,1,0,4]
Output: false
Explanation: You will always arrive at index 3 no matter what. Its maximum jump length is 0, which makes it impossible 
to reach the last index.

*******************************************************************************/
#if 0
#include<iostream>
#include<vector>
#include<algorithm>
#include <string>

using namespace std;

bool CanJump(vector<int>& nums) {
	bool flag = false;
	int lastInd = nums.size() - 1;
	int length = nums.size();
	//int *numOfJumps = new (nothrow) int[length];
	int numOfJumps[5];
	numOfJumps[0] = 0;

	if (length == 1 && (nums[0] == 0 || nums[0] == 1)) {
		return true;
	}

	for (int i = 1; i < length; i++) {
		numOfJumps[i] = INT_MAX;
		for (int j = 0; j < i; j++) {
			if ((i <= j + nums[j]) && (numOfJumps[j] != INT_MAX)) {
				numOfJumps[i] = min(numOfJumps[i], numOfJumps[j] + 1);
				if (i == lastInd) {
					flag = true;
				}
				break;
			}
		}
	}
	cout << "Number of jumps:" << numOfJumps[lastInd] << endl;

	return flag;
}


int main() {
	vector<int> nums;
	nums.push_back(0);
	nums.push_back(1);
	//nums.push_back(2);
	//nums.push_back(1);
	//nums.push_back(4);

	bool jumpResult = CanJump(nums);
	string result;
	result = jumpResult ? "true" : "false";
	cout << "Jumpresult is :" << result << endl;
}
#endif