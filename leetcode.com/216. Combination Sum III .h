#ifndef COM_SUM_3
#define COM_SUM_3

#include <vector>
#include <iostream>
/*
Find all possible combinations of k numbers that add up to a number n, given that only numbers from 1 to 9 can be used and each combination should be a unique set of numbers.
Ensure that numbers within the set are sorted in ascending order.

Example 1:
Input: k = 3, n = 7
Output: [[1,2,4]]

Example 2:
Input: k = 3, n = 9
Output: [[1,2,6], [1,3,5], [2,3,4]]
*/

using namespace std;

int  GetVectorSum(const vector<int> &vect);
ostream& operator<<(ostream &ostr,const vector<vector<int>> &vect);
bool     operator==(const vector<int> &vect1, const vector<int> &vect2);
bool	 operator!=(const vector<int> &vect1, const vector<int> &vect2);


class Solution {
private:
	const vector<vector<int>> *currentComb;

	bool exists(const vector<int> &vect)
	{
		for (int i = 0; i < currentComb->size(); ++i)
			if ((*currentComb)[i] == vect)
				return true;
		return false;
	}

	bool recursionPass(vector<int> &vec, int reqSum, int reqQuant, int currIndex, int arrIndex)
	{
		if (vec.size() == reqQuant && GetVectorSum(vec) == reqSum && !(exists(vec)))
			return true;
		if (vec.size() >= reqQuant || GetVectorSum(vec) > reqSum)
			return false;
		for (int i = arrIndex; i < 10; ++i)
		{
			vec.push_back(i);
			if (!recursionPass(vec, reqSum, reqQuant, ++currIndex, i + 1))
			{
				vec.pop_back();
				--currIndex;
			}
			else
				return true;
		}
		return false;
	}
public:
	vector<vector<int>> combinationSum3(int k, int n) 
	{
		vector<vector<int>> combinations;
		currentComb = &combinations;
		while (true)
		{	vector<int> requiredPortion;
			if (!recursionPass(requiredPortion, n, k, 0, 1))
				break;
			combinations.push_back(requiredPortion);
		}
		return combinations;
	}
};
#endif