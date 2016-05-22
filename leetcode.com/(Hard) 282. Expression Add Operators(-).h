/*Given a string that contains only digits 0-9 and a target value, 
return all possibilities to add binary operators (not unary) +, -, or * between the digits so they evaluate to the target value.

Examples: 
"123", 6 -> ["1+2+3", "1*2*3"] 
"232", 8 -> ["2*3+2", "2+3*2"]
"105", 5 -> ["1*0+5","10-5"]
"00", 0 -> ["0+0", "0-0", "0*0"]
"3456237490", 9191 -> []*/

#include <vector>

using namespace std;

//class Solution
//{
//private:
//	vector<vector<int>> mParsedValues;
//	vector<char> operators;
//
//
//	void parseString(const string &str, int initPos, vector<int> &values, int &sumLength)
//	{
//		if (sumLength == str.size())
//		{
//			mParsedValues.push_back(values);
//			return;
//		}
//		for (int i = 1; i <= (str.size() - initPos); ++i)
//		{
//			string val = str.substr(initPos, i);
//			values.push_back(atoi(val.c_str()));
//			sumLength += val.size();
//			parseString(str, initPos + i, values, sumLength);
//			sumLength -= val.size();
//			values.pop_back();
//		}
//	}
//	//void makeExpression(string &str,char nextOp,)
//
//	void cleanSingleValues()
//	{
//		for (int i = mParsedValues.size() - 1; i >= 0; --i)
//			if (mParsedValues[i].size() == 1)
//				mParsedValues.erase(mParsedValues.begin() + i);
//	}
//public:
//	Solution()
//	{
//		
//	}
//
//	vector<string> check(string str, int target)
//	{
//		vector<int> values;
//		int sumLength = 0;
//		parseString(str, 0, values, sumLength);
//		cleanSingleValues();
//
//		vector<string> result;
//
//
//		return result;
//	}
//};

struct Lexem
{
	int value = 0;
	bool isSign = false;
	Lexem(int v, bool sign) : isSign(sign)
	{
		value = (isSign) ? (v) : (v - 48);
	}
};

class Solution
{
private:
	vector<vector<Lexem>> mParsedValues;
	vector<vector<Lexem>> mPreparedLexems;
	vector<char> operators;
	int expectedSize = 0;


	void parseString(const string &str, int initPos, vector<Lexem> &values, int &sumLength)
	{
		if (sumLength == str.size())
		{
			mParsedValues.push_back(values);
			return;
		}
		for (int i = 1; i <= (str.size() - initPos); ++i)
		{
			string val = str.substr(initPos, i);
			values.emplace_back(atoi(val.c_str()),false);
			sumLength += val.size();
			parseString(str, initPos + i, values, sumLength);
			sumLength -= val.size();
			values.pop_back();
		}
	}

	void addAllSigns()
	{
		for (int i = 0, pos = 1; i < mParsedValues.size(); ++i, pos += 2)
		{
			expectedSize = (mParsedValues.size() * 2) - 1;
			makeExpression(mParsedValues[i], 1,0);
		}
	}
	void makeExpression(vector<Lexem> &values, int pos, int posOp)
	{
		if (values.size() == expectedSize)
		{
			mPreparedLexems.push_back(values);
			return;
		}
		for (int i = posOp; i < operators.size(); ++i)
		{
			auto it = values.begin() + pos;
			values.insert(it, { operators[i], true });
			makeExpression(values, pos + 2, i + 1);
			values.erase(it);
		}

	}

	void cleanSingleValues()
	{
		for (int i = mParsedValues.size() - 1; i >= 0; --i)
			if (mParsedValues[i].size() == 1)
				mParsedValues.erase(mParsedValues.begin() + i);
	}
public:
	Solution()
	{

	}

	vector<string> check(string str, int target)
	{
		vector<Lexem> values;
		int sumLength = 0;
		parseString(str, 0, values, sumLength);
		cleanSingleValues();
		addAllSigns();

		vector<string> result;


		return result;
	}
};
