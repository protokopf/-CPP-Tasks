#ifndef SN_260
#define SN_260
#include <vector>
#include <iostream>
#include <iterator>

using namespace std;

/*
Given an array of numbers nums, in which exactly two elements appear only once and all the other elements appear exactly twice. Find the two elements that appear only once.
For example:
Given nums = [1, 2, 1, 3, 2, 5], return [3, 5].
Note:
The order of the result is not important. So in the above example, [5, 3] is also correct.
Your algorithm should run in linear runtime complexity. Could you implement it using only constant space complexity?
*/

template<typename Type>
ostream& operator<<(ostream &ost, const vector<Type> &vect)
{
	std::ostream_iterator<Type> iterat(ost,",");
	copy(vect.begin(), vect.end(), iterat);
	return ost;
}

class Solution {
public:
	vector<int> singleNumber(vector<int>& nums) 
	{
		int maxSize = nums[0];
		for (int i = 0; i < nums.size(); ++i)
			if (nums[i] > maxSize)
				maxSize = nums[i];

		vector<int> result;
		vector<bool> indexes(maxSize);
		for (int i = 0; i < nums.size(); ++i)
			indexes[nums[i] - 1] = (indexes[nums[i] - 1]) ? false : true;
		for (int i = 0; i < indexes.size(); ++i)
			if (indexes[i])
				result.push_back(i + 1);
		return result;
	}

	vector<int> singleNumberV2(vector<int>& nums)
	{
		vector<int> result;



		return result;
	}
};


#endif