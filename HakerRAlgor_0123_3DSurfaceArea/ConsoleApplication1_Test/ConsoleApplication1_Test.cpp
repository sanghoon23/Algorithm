#include "pch.h"
#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

int surfaceArea(vector<vector<int>> A)
{
	int R = A.size();
	int C = A[0].size();

	int ResultCount = 0;
	ResultCount += (R * C * 2);

	// 측면
	int RCalcNum = 0;
	for (int j = 0; j < R; ++j)
	{
		int HeightLine = 0; // 최고점
		for (int i = 0; i < C; ++i)
		{
			if (HeightLine < A[j][i])
			{
				RCalcNum += (A[j][i] - HeightLine);
				HeightLine += (A[j][i] - HeightLine);
			}
			else if (HeightLine > A[j][i])
			{
				HeightLine = A[j][i];
			}
		}
	}
	ResultCount += (RCalcNum * 2);

	// 앞뒷면
	int CCalcNum = 0;
	for (int s = 0; s < C; ++s)
	{
		int HeightLine = 0; // 최고점
		for (int t = 0; t < R; ++t)
		{
			if (HeightLine < A[t][s])
			{
				CCalcNum += (A[t][s] - HeightLine);
				HeightLine += (A[t][s] - HeightLine);
			}
			else
			{
				HeightLine = A[t][s];
			}
		}
	}
	ResultCount += (CCalcNum * 2);

	return ResultCount;
}

int main()
{
	vector<vector<int>> A;
	vector<int> test1;
	test1.push_back(1);
	A.push_back(test1);
	//vector<int> test1;
	//test1.push_back(51);
	//A.push_back(test1);

	//test1.clear();
	//test1.push_back(32);
	//A.push_back(test1);

	//test1.clear();
	//test1.push_back(28);
	//A.push_back(test1);

	// test1.clear();
	//test1.push_back(49);
	//A.push_back(test1);

	// test1.clear();
	//test1.push_back(28);
	//A.push_back(test1);

	// test1.clear();
	//test1.push_back(21);
	//A.push_back(test1);

	// test1.clear();
	//test1.push_back(98);
	//A.push_back(test1);

	// test1.clear();
	//test1.push_back(56);
	//A.push_back(test1);

	// test1.clear();
	//test1.push_back(99);
	//A.push_back(test1);

	// test1.clear();
	//test1.push_back(77);
	//A.push_back(test1);


	int Result = surfaceArea(A);
	printf("%d\n", Result);
	cout << Result << endl;


	return 0;
}

