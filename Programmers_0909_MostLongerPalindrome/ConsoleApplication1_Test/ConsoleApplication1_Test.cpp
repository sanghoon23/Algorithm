#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>
#include <stack>

using namespace std;

bool Check(string A)
{
	if (A == "") return false;

	stack<char> Stack;
	for (int i = 0; i < A.size(); ++i)
		Stack.push(A[i]);

	int i = 0;
	while (!Stack.empty())
	{
		char Poped = Stack.top();
		Stack.pop();

		if (A[i] != Poped) return false;
		++i;
	}

	return true;
}

void FindStrSizeBase(vector<string>& Out, string Origin, int Size)
{
	int Index = 0;
	while (1)
	{
		if (Size + Index > Origin.size()) break;

		string Insert;
		for (int i = Index; i < Size + Index; ++i)
		{
			Insert.push_back(Origin[i]);
		}
		Out.push_back(Insert);

		++Index;
	}
}

//@여기까지 뻘짓 
///////////////////////////////////////////////////////////////////////////////////////////

//@다시 생각한 답
int FindMax_OddNumber(string& S, int Index)
{
	int Start = Index;
	int End = Index;

	int Ret = 1;
	while (1)
	{
		--Start;
		++End;

		if (Start < 0 || End >= S.size()) break;

		if (S[Start] == S[End]) Ret += 2;
		else break;
	}

	return Ret;
}

int FindMax_EvenNumber(string& S, int Index)
{
	if (Index == 0) return 1;

	int Start = Index - 1;
	int End = Index;

	if (S[Start] != S[End]) return 1;

	int Ret = 2;
	while (1)
	{
		--Start;
		++End;

		if (Start < 0 || End >= S.size()) break;

		if (S[Start] == S[End]) Ret += 2;
		else break;
	}

	return Ret;
}

int solution(string s)
{
	int Answer = 1;

	for (int j = 0; j < s.size(); ++j)
	{
		Answer = max(Answer, FindMax_OddNumber(s, j));
		Answer = max(Answer, FindMax_EvenNumber(s, j));
		//if (j % 2 == 1)
		//{
		//	Answer = max(Answer, FindMax_OddNumber(s, j));
		//}
		//else if (j % 2 == 0)
		//{
		//	Answer = max(Answer,FindMax_EvenNumber(s, j));
		//}
	}


	return Answer;

	//@ 완전 뻘짓 ㅡ.ㅡ
	//string CpyStr = s;
	//int CpyStrSize = s.size();
	//for (int r = CpyStrSize; r > 1; --r)
	//{
	//	vector<string> Finding;
	//	FindStrSizeBase(Finding, s, r);
	//	for (int t = 0; t < Finding.size(); ++t)
	//	{
	//		for (int j = r; j > 0; --j)
	//		{
	//			string TempStr = Finding[t].substr(0, j);
	//			if (Check(TempStr) == true)
	//			{
	//				Answer = max(Answer, j);
	//				break;
	//			}
	//		}

	//		for (int i = 0; i < r - 1; ++i)
	//		{
	//			string TempStr = Finding[t].substr(i, r);
	//			if (Check(TempStr) == true)
	//			{
	//				Answer = max(Answer, r - i);
	//				break;
	//			}
	//		}
	//	}

	//}//(r)

	//for (int j = CpyStrSize - 1; j > 1; ++j) 	//@Size
	//{
	//	string Temp = s;
	//	for (int i = j; i > 0; --i) //@Start
	//	{
	//		Temp = CpyStr.substr(0, i);
	//		if (Check(Temp) == true)
	//		{
	//			Answer = i;
	//			break;
	//		}
	//	}

	//	for (int u = 0; u < Temp.size() - 1; ++u) //@End
	//	{
	//		Temp = CpyStr.substr(u, CpyStr.size());
	//		if (Check(Temp) == true)
	//		{
	//			Answer = max(Answer, u);
	//		}
	//	}
	//}
}

int main()
{
	//string In = "abcdcba";
	//string In = "aaaa";
	string In = "abcabcdcbae";

	int Result = solution(In);

	return 0;
}

