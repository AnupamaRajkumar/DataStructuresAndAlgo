/***********************************************************************************
Given an integer array nums, return the length of the longest strictly increasing 
subsequence.

A subsequence is a sequence that can be derived from an array by deleting some or no 
elements without changing the order of the remaining elements. For example, [3,6,2,7] 
is a subsequence of the array [0,3,1,6,2,2,7].

Examples:
Input: nums = [10,9,2,5,3,7,101,18]
Output: 4
Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.

Input: nums = [0,1,0,3,2,3]
Output: 4

*************************************************************************************/
#if 0
#include<iostream>
#include<vector>
#include<algorithm>
#include <string>

int LengthOfLIS(std::vector<int>& nums) {

	std::vector<int> count;
	for (int i = 0; i < nums.size(); i++) {
		int seqLength = 1;
		for (int j = i + 1; j < nums.size(); j++) {
			if (nums[j] > nums[i]) {
				if (nums[j] > nums[j - 1]) {
					seqLength += 1;
				}
				else {
					seqLength = 1;
					continue;
				}
			}
			else {
				continue;
			}
		}
		count.push_back(seqLength);

	}
	std::sort(count.begin(), count.end());
	return(count.back());
}


int main() {
	std::vector<int> sequence;
	sequence.push_back(4);
	sequence.push_back(10);
	sequence.push_back(4);
	sequence.push_back(3);
	sequence.push_back(8);
	sequence.push_back(9);
	//sequence.push_back(7);
	//sequence.push_back(7);
	int length = LengthOfLIS(sequence);
	std::cout << "Length of the longest increasing sequence is:" << length << std::endl;
	return 0;
}
#endif