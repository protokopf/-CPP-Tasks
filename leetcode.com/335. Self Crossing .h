#ifndef SC_335
#define SC_335
#include <vector>
#include <iostream>

using namespace std;
/*You are given an array x of n positive numbers. You start at point (0,0) and moves x[0] metres to the north, then x[1] metres to the west, x[2] metres to the south, x[3] metres to the east and so on. In other words, after each move your direction changes counter-clockwise.
Write a one-pass algorithm with O(1) extra space to determine, if your path crosses itself, or not.

Example 1:
Given x = [2, 1, 1, 2],
┌───┐
│   │
└───┼──>
    │
Return true (self crossing)

Example 2:
Given x = [1, 2, 3, 4],
┌──────┐
│      │
│
│
└────────────>
Return false (not self crossing)
Example 3:

Given x = [1, 1, 1, 1],
┌───┐
│   │
└───┼>
Return true (self crossing)*/

class Solution {
public:
	bool isSelfCrossing(vector<int>& x)
	{
		vector<int> extraMem(4);
		bool isCross = false;
		for (int i = 0; i <= x.size() - 4; ++i)
		{
			for (int j = 0; j < 4; ++j) extraMem[j] = x[i+j];
			if (extraMem[0] >= extraMem[2] && extraMem[3] >= extraMem[1]) return true;
		}
		return false;
	}
};

#endif