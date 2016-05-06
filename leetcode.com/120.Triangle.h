#ifndef TRIANGLE_120
#define TRIANGLE_120
#include <vector>
#include <iostream>

using namespace std;

/*Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.
For example, given the following triangle
[
     [2],
    [3,4],
   [6,5,7],
  [4,1,8,3]
]
The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).
Note:
Bonus point if you are able to do this using only O(n) extra space, where n is the total number of rows in the triangle.*/

class Solution {
private:
	int findMinIndex(const vector<int>& vect)
	{
		int min = 0;
		for (int i = 0; i < vect.size(); ++i)
			if (vect[min] > vect[i]) min = i;
		return min;
	}
	void slideTriangle(const vector<vector<int>> &vec, int level, int index, int &sum)
	{
		sum += vec[level][index];
		if (level == vec.size() - 1) return;
		slideTriangle(vec, level + 1, findMinIndex(vec[level + 1]), sum);
	}

public:
	int minimumTotal(vector<vector<int>>& triangle) 
	{
		int sum = 0;
		slideTriangle(triangle, 0, 0, sum);
		return sum;
	}
};


#endif