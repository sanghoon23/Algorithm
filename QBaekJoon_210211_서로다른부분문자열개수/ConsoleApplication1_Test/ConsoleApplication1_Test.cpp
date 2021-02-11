#include "pch.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <string.h>

using namespace std;
#define FASTIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
string Str;

/*
Hashing - Map 을 이용해서 풀어보기
*/

vector<int> GetSuffixArray(string& Str)
{
	int NSize = Str.size();
	vector<int> Group(NSize + 1, 0);
	for (int i = 0; i < NSize; ++i) Group[i] = Str[i];
	Group[NSize] = -1;
	vector<int> Perm(NSize);
	for (int i = 0; i < NSize; ++i) Perm[i] = i;

	int T = 1;
	while (T < NSize)
	{
		auto Comp = [&](int A, int B)
		{
			if (Group[A] != Group[B]) return Group[A] < Group[B];
			else return Group[A + T] < Group[B + T];
		};
		sort(Perm.begin(), Perm.end(), Comp);

		vector<int> NewGroup(NSize + 1);
		NewGroup[NSize] = -1;
		for (int i = 1; i < NSize; ++i)
		{
			if (Comp(Perm[i - 1], Perm[i])) NewGroup[Perm[i]] = NewGroup[Perm[i - 1]] + 1;
			else NewGroup[Perm[i]] = NewGroup[Perm[i - 1]];
		}
		Group = NewGroup;
		T <<= 1;
	}
	return Perm;
}

int Solve(string& Str)
{
	int NSize = Str.size();
	int Ret = 0;
	vector<int> Pi = GetSuffixArray(Str);
	auto FindLCP = [&](int A, int B)->int
	{
		int K = 0;
		while (A < NSize && B < NSize && Str[A] == Str[B])
		{
			++A; ++B; ++K;
		}
		return K;
	};
	for (int i = 1; i < Pi.size(); ++i)
		Ret += FindLCP(Pi[i - 1], Pi[i]);

	return (NSize * (NSize + 1) / 2) - Ret;
}

int main()
{
	FASTIO;
	cin >> Str;
	cout << Solve(Str);
	return 0;
}

