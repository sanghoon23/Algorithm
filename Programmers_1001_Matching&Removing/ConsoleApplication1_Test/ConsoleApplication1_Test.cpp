#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <stack>
#include <algorithm>

using namespace std;

string Merge(string S)
{
	string Str = S;
	for (int i = 0; i < Str.size() - 1; ++i)
	{
		if (Str[i] == Str[i + 1])
		{
			Str.erase(i, 2);
			if (Str == "") break;
		}
	}
	return Str;
}

//int solution(string S)
//{
//	//제거만되면 가능한것인가 모두 제거해야되는건가
//	bool Answer = 0;
//
//	while (S.size() > 0)
//	{
//		string Temp = S;
//		string Result = Merge(S);
//		if (Result == Temp) return false;
//		else S = Result;
//	}
//
//	return true;
//}

int solution(string S)
{
	stack<char> Stack;
	Stack.push(S[0]);
	for (int i = 1; i < S.size(); ++i)
	{
		if (Stack.empty())
		{
			Stack.push(S[i]);
			continue;
		}

		int Top = Stack.top();
		if (Top == S[i]) Stack.pop();
		else
		{
			Stack.push(S[i]);
		}
	}

	if (Stack.empty()) return true;
	return false;
}

int main()
{
	string Insert = "baabaa";
	int Result = solution(Insert);

	return 0;
}

