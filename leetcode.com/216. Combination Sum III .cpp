#include "216. Combination Sum III .h"

int  GetVectorSum(const vector<int> &vect)
{
	int sum = 0;
	for (int mem : vect)
		sum += mem;
	return sum;
}

ostream& operator<<(ostream &ostr, const vector<vector<int>> &vect)
{
	ostr << "[";
	for (int i = 0; i < vect.size(); ++i)
	{
		ostr << "[";
		for (int j = 0; j < vect[i].size(); ++j)
			ostr << vect[i][j] << ",";
		ostr << "], ";
	}
	ostr << "]";
	return ostr;
}
bool     operator==(const vector<int> &vect1, const vector<int> &vect2)
{
	if (vect1.size() != vect2.size())
		return false;
	for (int i = 0; i < vect1.size(); ++i)
		if (vect1[i] != vect2[i])
			return false;
	return true;
}
bool	 operator!=(const vector<int> &vect1, const vector<int> &vect2)
{
	return !(vect1 == vect2);
}