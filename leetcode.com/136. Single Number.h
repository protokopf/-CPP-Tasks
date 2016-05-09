#ifndef SN_136
#define SN_136

/*
Given an array of integers, every element appears twice except for one. Find that single one.
Note:
Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
*/
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
	int singleNumber(vector<int>& nums) 
	{
		int number = 0;
		for (int i = 0; i < nums.size(); ++i)
			number ^= nums[i];
		return number;
	}
};


#endif