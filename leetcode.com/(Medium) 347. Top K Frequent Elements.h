/*
Given a non-empty array of integers, return the k most frequent elements.

For example,
Given [1,1,1,2,2,3] and k = 2, return [1,2].

Note:
You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
Your algorithm's time complexity must be better than O(n log n), where n is the array's size.
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class Solution {
private:
	vector<int> UniqueElements(vector<int> nums)
	{
		auto it = unique(nums.begin(), nums.end());
		nums.resize(distance(nums.begin(), it));
		return nums;
	}
	int findUniqueElement(const vector<int> &num)
	{
		int maxIndex = 0;
		int max = 0;
		int curr = 0;
		for (int i = 0; i < num.size(); ++i)
		{
			curr = 0;
			for (int j = i; j < num.size(); ++j)
				if (num[i] == num[j])
					++curr;
			if (curr > max)
			{
				max = curr;
				maxIndex = i;
			}

		}
		return maxIndex;
	}
public:
	vector<int> topKFrequent(vector<int> nums, int k) 
	{
		vector<int> uniqueNums = UniqueElements(nums);
		if (!(k >= 1 && k <= uniqueNums.size()))
			return nums;
		vector<int> kElements(k);
		for (int i = 0; i < k; ++i)
		{
			int index = findUniqueElement(nums);
			int value = nums[index];
			kElements[i] = value;
			remove_if(nums.begin(), nums.end(), [&index, &value](int x){ return x == value; });
		}
		return kElements;
	}
};