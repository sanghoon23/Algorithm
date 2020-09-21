#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

void Check(vector<int>& Result, int N, int S)
{
	int Half = S / N;
	if (Half == 0)
	{
		int Remain = S % N;
		for (int i = 0; i < Remain; ++i)
		{
			Result[i] += 1;
		}
	}
	else
	{
		for (int i = 0; i < N; ++i)
		{
			Result[i] += Half;
		}
		Check(Result, N, S - (N * Half));
	}
}

vector<int> solution(int n, int s)
{
	vector<int> Answer;

	vector<int> Result(n, 0);
	Check(Result, n, s);

	if (Result[n - 1] == 0)
	{
		Answer.push_back(-1);
		return Answer;
	}
	else
	{
		Answer = Result;
	}

	return Answer;
}

int main()
{
	int N = 3;
	int S = 8;

	vector<int> Result = solution(N, S);

	return 0;
}

