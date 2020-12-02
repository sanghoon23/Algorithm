#include "pch.h"
#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <algorithm>

using namespace std;

int N = 0;
int V = 0;

int main()
{
	cin >> N;
	vector<int> Temp(N, 0);
	for (int i = 0; i < N; ++i)
	{
		cin >> Temp[i];
	}
	sort(Temp.begin(), Temp.end());

	int Answer = 0;
	for (int j = 0; j < N; ++j)
	{
		for (int i = 0; i < j + 1; ++i)
		{
			Answer += Temp[i];
		}
	}
	cout << Answer;
	return 0;
}

//int N = 0;
//int V = 0;
//bool Compare(pair<int, int> a, pair<int, int> b)
//{
//	return a.first < b.first;
//}
//
//int main()
//{
//	cin >> N;
//	vector<pair<int, int>> Temp(N, { 0, 0 }); //1-값, 2-인덱스
//	for (int i = 0; i < N; ++i)
//	{
//		cin >> V;
//		Temp[i] = { V, i + 1 };
//	}
//
//	sort(Temp.begin(), Temp.end(), Compare);
//	int Answer = 0;
//
//	for (int j = 0; j < N; ++j)
//	{
//		int C = 0;
//		for (int i = 0; i < j + 1; ++i)
//		{
//			C += Temp[i].first;
//		}
//		Answer += C;
//	}
//	cout << Answer;
//	return 0;
//}

