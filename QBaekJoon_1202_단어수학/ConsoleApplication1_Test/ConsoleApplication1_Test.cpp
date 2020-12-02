#include "pch.h"
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//@DFS

//int N = 0;
//int main()
//{
//	int Answer = 0;
//	vector<int> Alpha(26, 0);
//	cin >> N;
//	vector<string> Temp(N);
//	for (int i = 0; i < N; ++i)
//	{
//		cin >> Temp[i];
//		for (int k = 0; k < Temp[i].size(); ++k)
//			Alpha[Temp[i][k] - 'A'] += 1;
//	}
//
//	vector<char> A;
//	for (int i = 0; i < 26; ++i)
//	{
//		if (Alpha[i] >= 1) A.push_back(i + 'A');
//	}
//	sort(A.begin(), A.end());
//
//	do
//	{
//		map<char, int> Map;
//		int Val = 9;
//		for (int i = 0; i < A.size(); ++i)
//		{
//			Map[A[i]] = Val;
//			--Val;
//		}
//
//		int Calc = 0;
//		for (int j = 0; j < Temp.size(); ++j)
//		{
//			string C = "";
//			for (int i = 0; i < Temp[j].size(); ++i)
//			{
//				C.push_back(Map[Temp[j][i]] + 48);
//			}
//			Calc += atoi(C.c_str());
//		}
//
//		if (Answer < Calc)
//			Answer = Calc;
//		
//	} while (next_permutation(A.begin(), A.end()));
//
//	cout << Answer;
//	return 0;
//}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//@Greedy (그리디)

//int N = 0;
//bool Compare(int A, int B)
//{
//	return A > B;
//}
//int main()
//{
//	int Answer = 0;
//	vector<int> Alpha(26, 0);
//	cin >> N;
//	vector<string> Temp(N);
//	for (int i = 0; i < N; ++i)
//	{
//		cin >> Temp[i];
//		string T = Temp[i];
//		reverse(T.begin(), T.end());
//		for (int k = 0; k < T.size(); ++k)
//		{
//			Alpha[(T[k] - 'A')] += pow(10, k);
//		}
//	}
//	sort(Alpha.begin(), Alpha.end(), Compare);
//	int Val = 9;
//	for (int i = 0; i < 26; ++i)
//	{
//		if (Alpha[i] == 0) break;
//		Answer += (Alpha[i] * Val);
//		--Val;
//	}
//
//	cout << Answer;
//	return 0;
//}
//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//int N = 0;
//int Alpha[26] = { 0, };
//bool Compare(string A, string B)
//{
//	if (A.size() == B.size())
//	{
//		int CntA = 0, CntB = 0;
//		for (int i = 1; i < A.size(); ++i)
//		{
//			if (A[0] == A[i]) ++CntA;
//			if (B[0] == B[i]) ++CntB;
//		}
//		return CntA < CntB;
//	}
//	return A.size() > B.size();
//}
//int main()
//{
//	cin >> N;
//	vector<string> Temp(N);
//	for (int i = 0; i < N; ++i)
//	{
//		cin >> Temp[i];
//	}
//	sort(Temp.begin(), Temp.end(), Compare);
//
//	vector<vector<char>> Calc(8);
//	for (int j = 0; j < Temp.size(); ++j)
//	{
//		string T = Temp[j];
//		reverse(T.begin(), T.end());
//		for (int k = 0; k < T.size(); ++k)
//		{
//			Calc[k].push_back(T[k]);
//		}
//	}
//
//	int Answer = 0;
//	int Val = 9;
//	for (int j = Calc.size() - 1; j >= 0; --j)
//	{
//		for (int i = 0; i < Calc[j].size(); ++i)
//		{
//			if (Val < 0) continue;
//			if (Alpha[Calc[j][i] - 'A'] == 0)
//			{
//				Alpha[Calc[j][i] - 'A'] = Val;
//				--Val;
//			}
//		}
//	}
//
//	for (int j = 0; j < Temp.size(); ++j)
//	{
//		string C = "";
//		for (int i = 0; i < Temp[j].size(); ++i)
//		{
//			C.push_back(Alpha[Temp[j][i] - 'A'] + 48);
//		}
//		Answer += atoi(C.c_str());
//	}
//
//	cout << Answer;
//	return 0;
//}

