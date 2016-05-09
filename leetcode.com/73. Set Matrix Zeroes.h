#ifndef SMZ_73
#define SMZ_73
#include <vector>
#include <iostream>

using namespace std;

/*Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in place.*/


class Solution {
public:

	void printMatrix(const vector<vector<int>>& matrix)
	{
		for (int i = 0; i < matrix.size(); ++i)
		{
			for (int j = 0; j < matrix[i].size(); ++j)
				cout << matrix[i][j] << '\t';
			cout << endl;
		}
	}
	void setZeroes(vector<vector<int>>& matrix) 
	{
		bool exit = false;
		for (int i = 0; i < matrix.size(); ++i)
		{
			for (int j = 0; j < matrix[i].size(); ++j)
			{
				if (matrix[i][j] == 0)
				{
					for (int x = 0; x < matrix[i].size(); ++x)
						matrix[i][x] = 0;
					for (int y = 0; y < matrix.size(); ++y)
						matrix[y][j] = 0;
					exit = true;

				}
				if (exit) break;
			}
			if (exit) break;
		}
	}
};

#endif