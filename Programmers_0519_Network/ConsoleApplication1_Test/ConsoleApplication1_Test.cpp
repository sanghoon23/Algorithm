#include "pch.h"
#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <queue>

using namespace std;


//@Disjoint Set 방법
#pragma region DisjointSet
//
//int Find(vector<int>& Parent, int Value)
//{
//	if (Value == Parent[Value])
//		return Value;
//	else
//	{
//		int Ret = Find(Parent, Parent[Value]);
//		Parent[Value] = Ret;
//		return Ret;
//	}
//}
//
//bool Marge(vector<int>& Parent, int A, int B)
//{
//	A = Find(Parent, A);
//	B = Find(Parent, B);
//
//	if (A != B)
//	{
//		Parent[B] = A;
//		return true;
//	}
//
//	return false;
//}
//
//int solution(int n, vector<vector<int>> computers)
//{
//	int Result = n;
//
//	vector<int> Parent;
//	for (int t = 0; t < n; ++t)
//	{
//		Parent.push_back(t);
//	}
//
//	int Calc = 0;
//	for (int j = 0; j < n; ++j)
//	{
//		for (int i = 0; i < n; ++i)
//		{
//			if (i == j) continue;
//
//			if (computers[j][i] == 1)
//			{
//				if (Marge(Parent, j, i) == true)
//					++Calc;
//			}
//		}
//	}
//
//	return Result - Calc;
//}

#pragma endregion


//@DFS 방법
#pragma region DFS
using namespace std;

bool DFS(vector<vector<int>>& Computers, int Index)
{
	if (Computers[Index][Index] == 0) return false;
	Computers[Index][Index] = 0;

	for (int i = 0; i < Computers.size(); ++i)
	{
		if (Computers[Index][i] == 1)
			DFS(Computers, i);
	}

	return true;
}

int solution(int n, vector<vector<int>> computers)
{
	int Result = 0;
	for (int i = 0; i < n; ++i)
	{
		if (computers[i][i] == 1 && DFS(computers, i) == true)
			++Result;
	}

	return Result;
}

#pragma endregion

int main()
{
	vector<vector<int>> InsertVec;


	vector<int> In1;
	In1.push_back(1);
	In1.push_back(1);
	In1.push_back(0);

	vector<int> In2;
	In2.push_back(1);
	In2.push_back(1);
	In2.push_back(0);

	vector<int> In3;
	In3.push_back(0);
	In3.push_back(0);
	In3.push_back(1);

	InsertVec.push_back(In1);
	InsertVec.push_back(In2);
	InsertVec.push_back(In3);

	solution(3, InsertVec);

	return 0;
}

