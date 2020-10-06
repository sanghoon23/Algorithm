#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

string Find(int N, int Number)
{
	if (Number == 0) return "0";

	string Ret = "";
	while (Number > 0)
	{
		int Temp = Number % N;
		(Temp < 10)
			? Ret.push_back(Temp + '0')
			: Ret.push_back(Temp + '7');
		Number /= N;
	}
	reverse(Ret.begin(), Ret.end());

	return Ret;
}

//@N - 진법, T - 숫자의 갯수, M - 인원, P - 튜브의 순서
string solution(int N, int T, int M, int P)
{
	string Answer = "";

	string Calc = "";
	int Count = 0;
	while (Calc.size() <= M * T)
	{
		string Ret = Find(N, Count);
		Calc.append(Ret);
		++Count;
	}

	for (int i = 0; i < T; ++i)
	{
		Answer.push_back(Calc[(P - 1) + (i * M)]);
	}

	return Answer;
}

int main()
{
	int N = 2;
	int T = 4;
	int M = 2;
	int P = 1;

	string Result = solution(N, T, M, P);

	return 0;
}

