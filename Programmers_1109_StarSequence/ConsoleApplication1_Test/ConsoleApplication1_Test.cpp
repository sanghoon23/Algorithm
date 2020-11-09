#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <algorithm>

using namespace std;

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//#1109_

int Temp[500001] = { 0, };

int solution(std::vector<int> A)
{
	if (A.size() < 2) return 0;

	vector<int> Values;
	for (int j = 0; j < A.size(); ++j)
	{
		if (Temp[A[j]] == 0) Values.push_back(A[j]);
		if (j - 1 >= 0 && A[j] != A[j - 1] || j + 1 < A.size() && A[j] != A[j + 1]) //*조건
			Temp[A[j]] += 1;
	}

	int Max = 0, MaxIndex = 0;
	for (int j = 0; j < Values.size(); ++j)
	{
		if (Max < Temp[Values[j]])
		{
			Max = Temp[Values[j]];
			MaxIndex = j;
		}
	}

	int Count = 0, CurrIndex = -1;     //@Values[MaxIndex] -> *(조건을 만족하는) 최대로 많이 나온 갯수의 값.
	for (int j = 0; j < A.size(); ++j)
	{
		if (j - 1 >= 0 && A[j] == Values[MaxIndex] && A[j - 1] != Values[MaxIndex] && CurrIndex < j - 1)
		{
			++Count;
			CurrIndex = j;
		}
		else if (j + 1 < A.size() && A[j] == Values[MaxIndex] && A[j + 1] != Values[MaxIndex] && CurrIndex < j)
		{
			++Count;
			CurrIndex = j + 1;
		}

	}

	return Count * 2;
}

//int solution(std::vector<int> A)
//{
//	if (A.size() < 2) return 0;
//
//	vector<int> Values;
//	for (int j = 0; j < A.size(); ++j)
//	{
//		if (Temp[A[j]] == 0) Values.push_back(A[j]);
//		Temp[A[j]] += 1;
//	}
//
//	int Result = 0;
//	for (int j = 0; j < Values.size(); ++j)
//	{
//		int Count = 0;
//		int CurrIndex = -1;
//		map<int, int> Map;
//		for (int i = 0; i < A.size(); ++i)
//		{
//			if (Temp[Values[i]] <= Count) break;
//
//			if (i - 1 >= 0 && A[i] == Values[j] && A[i - 1] != Values[j]
//				&& Map[A[i - 1]] < 2 && CurrIndex < i - 1)
//			{
//				Map[A[i - 1]] += 1;
//				++Count;
//				CurrIndex = i;
//			}
//			else if (i + 1 < A.size() && A[i] == Values[j] && A[i + 1] != Values[j]
//				&& Map[A[i + 1]] < 2 && CurrIndex < i)
//			{
//				Map[A[i + 1]] += 1;
//				++Count;
//				CurrIndex = i + 1;
//				++i;
//			}
//		}
//		if (Result < Count) Result = Count;
//	}
//
//	return Result * 2;
//}


//int Temp[500001] = { 0, }; //@해당 숫자 갯수
//int Visited[500001] = { -1, }; //@해당 숫자 선택된 곳
//
//int solution(std::vector<int> A)
//{
//	vector<vector<bool>> Select(A.size() + 1, vector<bool>(A.size() + 1, false)); //@{2, 3}, {3, 2} 만
//	for (int i = 0; i < A.size(); ++i)
//	{
//		if (i - 1 >= 0 && A[i - 1] != A[i] && Visited[A[i]] != i - 1 && Select[A[i - 1]][A[i]] == false)
//		{
//			Visited[A[i]] = i - 1;
//			Select[A[i - 1]][A[i]] = true;
//			Temp[A[i]] += 1;
//		}
//		if (i + 1 < A.size() && A[i + 1] != A[i] && Visited[A[i]] != i + 1 && Select[A[i]][A[i + 1]] == false)
//		{
//			Visited[A[i]] = i + 1;
//			Select[A[i]][A[i + 1]] = true;
//			Temp[A[i]] += 1;
//		}
//	}
//
//	int Max = 0;
//	for (int i = 0; i < A.size(); ++i)
//	{
//		if (Temp[A[i]] > Max) Max = Temp[A[i]];
//	}
//
//	return Max * 2;
//}

//int Temp[500001] = { 0, }; //@해당 숫자 갯수
//int Visited[500001] = { -1, }; //@해당 숫자 선택된 곳
//
//int solution(std::vector<int> A)
//{
//	//vector<vector<bool>> Select(A.size(), vector<bool>(A.size(), false)); //@{2, 3}, {3, 2} 만
//	for (int i = 0; i < A.size(); ++i)
//	{
//		if (i - 1 >= 0 && A[i - 1] != A[i] && Visited[A[i]] != i - 1)
//		{
//			Visited[A[i]] = i - 1;
//			Temp[A[i]] += 1;
//		}
//		else if (i + 1 < A.size() && A[i + 1] != A[i] && Visited[A[i]] != i + 1)
//		{
//			Visited[A[i]] = i + 1;
//			Temp[A[i]] += 1;
//		}
//	}
//
//	int Max = 0;
//	for (int i = 0; i < A.size(); ++i)
//	{
//		if (Temp[A[i]] > Max) Max = Temp[A[i]];
//	}
//
//	return Max * 2;
//}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//#1107_ 삽질

//int Temp[500001] = { 0, };
//
//bool Compare(int A, int B)
//{
//	return Temp[A] > Temp[B];
//}
//
//int solution(std::vector<int> A)
//{
//	vector<int> Values;
//	for (int j = 0; j < A.size(); ++j)
//	{
//		if (Temp[A[j]] == 0) Values.push_back(A[j]);
//
//		if(j + 1 < A.size() && A[j] != A[j + 1] || j - 1 >= 0 && A[j] != A[j - 1])
//			Temp[A[j]] += 1;
//	}
//
//	int MaxNum = 0, MaxValue = 0;
//	for (int j = 0; j < Values.size(); ++j)
//	{
//		if (MaxNum < Temp[Values[j]])
//		{
//			MaxNum = Temp[Values[j]];
//			MaxValue = Values[j];
//		}
//	}
//
//	sort(Values.begin(), Values.end(), Compare);
//
//	int Max = 0;
//	map<int, int> Map;
//	for (int j = 0; j < Values.size(); ++j)
//	{
//		int Count = 0;
//		for (int i = 0; i < A.size() - 1; ++i)
//		{
//			if (Temp[Values[j]] <= Count) break;
//
//			if (i - 1 >= 0 && A[i - 1] != Values[j] && A[i] == Values[j] && Map[A[i - 1]] < 2) //@앞
//			{
//				++Count;
//				Map[A[i - 1]] += 1;
//				++i;
//			}
//			else if (i - 1 >= 0 && A[i - 1] == Values[j] && A[i] != Values[j] && Map[A[i]] < 2) //@앞
//			{
//				++Count;
//				Map[A[i]] += 1;
//				++i;
//			}
//			else if (i + 1 < A.size() && A[i + 1] != Values[j] && A[i] == Values[j] && Map[A[i + 1]] < 2) //@뒤
//			{
//				++Count;
//				Map[A[i + 1]] += 1;
//				++i;
//			}
//			else if (i + 1 < A.size() && A[i] != Values[j] && A[i + 1] == Values[j] && Map[A[i]] < 2) //@뒤
//			{
//				++Count;
//				Map[A[i]] += 1;
//				++i;
//			}
//		}
//
//		if (Max < Count) Max = Count;
//	}
//
//	return Max * 2;
//}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//int Temp[500001] = { 0, };
//
//int solution(std::vector<int> A)
//{
//	vector<int> Values;
//	for (int i = 0; i < A.size(); ++i)
//	{
//		if (Temp[A[i]] == 0) Values.push_back(A[i]);
//		Temp[A[i]] += 1;
//	}
//
//	int Max = 0;
//	for (int j = 0; j < Values.size(); ++j)
//	{
//		int Count = 0;
//		map<int, int> Map;
//		for (int i = 0; i < A.size(); ++i)
//		{
//			if (Temp[Values[j]] <= Count) break;
//
//			if (i + 1 < A.size() && A[i] == Values[j] && A[i + 1] != Values[j] && Map[A[i + 1]] < 2)
//			{
//				++Count;
//				Map[A[i + 1]] += 1;
//				++i;
//				continue;
//			}
//			else if (i - 1 >= 0 && A[i] == Values[j] && A[i - 1] != Values[j] && Map[A[i - 1]] < 2)
//			{
//				++Count;
//				Map[A[i - 1]] += 1;
//			}
//		}
//		int Result = 0;
//		if (Temp[Values[j]] < Count) Result = Temp[Values[j]];
//		else Result = Count;
//
//		if (Max < Result) Max = Result;
//	}
//
//	return Max * 2;
//}

int main()
{
	vector<int> A = { 0, 3, 3, 0, 7, 2, 0, 2, 2, 0, };
	//vector<int> A = { 5, 2, 3, 3, 5, 3, };

	int Result = solution(A);

	return 0;
}
