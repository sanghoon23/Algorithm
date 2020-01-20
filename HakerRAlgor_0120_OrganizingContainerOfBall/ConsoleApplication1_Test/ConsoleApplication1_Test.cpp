#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

string organizingContainers(vector<vector<int>> container)
{
	int size = container.size();

	list<int> XSumResult;
	list<int> YSumResult;

	// XSumResult
	for (int j = 0; j < size; ++j)
	{
		int XSum = 0;
		for (int i = 0; i < size; ++i)
		{
			XSum += container[j][i];
		}
		XSumResult.push_back(XSum);
	}

	// YSumResult
	for (int i = 0; i < size; ++i)
	{
		int YSum = 0;
		for (int j = 0; j < size; ++j)
		{
			YSum += container[j][i];
		}
		YSumResult.push_back(YSum);
	}

	auto it = XSumResult.begin();
	for (; it != XSumResult.end(); ++it)
	{
		if (find(YSumResult.begin(), YSumResult.end(), (*it)) == YSumResult.end())
		{
			return "Impossible";
		}
	}

	return "Possible";
}

int main()
{
	int q = 1; // 총 경우의 수
	int n = 2; // n x n 행렬

	vector<vector<int>> container(n); // Container
	container[0][0] = 1;
	container[0][1] = 1;
	container[1][0] = 1;
	container[1][1] = 2;

	// Possible & ImPossible String Result
	string result = organizingContainers(container);
	
	return 0;
}

