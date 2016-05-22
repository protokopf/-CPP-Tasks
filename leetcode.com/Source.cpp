#define _CRT_SECURE_NO_WARNING
#include "(Medium) 347. Top K Frequent Elements.h"

using namespace std;


int main()
{
	Solution s;
	vector<int> el = { 1, 1, 2,2,2,1, 2, 2, 3,3,3,3,3,4 };
	auto vec = s.topKFrequent(el, 2);
	for (auto el : vec)
		cout << el << " ";
	return 0;
}


