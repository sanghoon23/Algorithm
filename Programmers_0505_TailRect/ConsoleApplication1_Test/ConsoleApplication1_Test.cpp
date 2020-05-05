#include "pch.h"
#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

//@첫번째 풀이
long long solution(int N)
{
	long long Answer = 0;

	if (N == 1)
	{
		return 1;
	}

	long v1 = 1;
	long v2 = 1;
	long v3 = 2;

	for (int i = 0; i < N - 2; ++i)
	{
		v1 = v2;
		v2 = v3;
		v3 = v1 + v2;
	}

	return (v2 + v3) * 2;
}

//@두번째 풀이
long long solution(int N)
{
	long long Answer = 0;

	vector<long> Vec(N + 1, 0);
	Vec[0] = 1;
	Vec[1] = 1;

	if (N == 1)
	{
		return 1;
	}

	//@2부터 N + 1 만큼
	for (int i = 2; i < N + 1; ++i)
	{
		Vec[i] = (Vec[i - 2] + Vec[i - 1]);
	}

	Answer = (Vec[N - 1] + Vec[N]) * 2;

	return Answer;
}

int main()
{

	return 0;
}

