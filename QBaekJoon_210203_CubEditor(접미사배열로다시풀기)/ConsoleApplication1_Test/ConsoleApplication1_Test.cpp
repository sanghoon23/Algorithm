#include "pch.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
#define FASTIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
string Str;

vector<int> GetSuffixArray(string& S)
{
	int N = S.size();
	vector<int> Group(N + 1);
	for (int i = 0; i < N; ++i) Group[i] = S[i];
	Group[N] = -1;

	vector<int> Perm(N);
	for (int i = 0; i < N; ++i) Perm[i] = i;

	int T = 1;
	while(T < N)
	{
		auto Comp = [&](int A, int B)
		{
			if (Group[A] == Group[B]) return Group[A + T] < Group[B + T];
			return Group[A] < Group[B];
		};
		sort(Perm.begin(), Perm.end(), Comp);

		vector<int> NewGroup(N + 1);
		NewGroup[N] = -1;
		for (int i = 1; i < Perm.size(); ++i)
		{
			if (Comp(Perm[i - 1], Perm[i])) NewGroup[Perm[i]] = NewGroup[Perm[i - 1]] + 1;
			else NewGroup[Perm[i]] = NewGroup[Perm[i - 1]];
		}
		Group = NewGroup;
		T <<= 1;
	}
	return Perm;
}

int GetMax(string& S)
{
	vector<int> Suffix = GetSuffixArray(S);
	int Ret = 0, N = S.size();
	auto LCP = [&](int A, int B)->int
	{
		int K = 0;
		while(A < S.size() && B < S.size() && S[A] == S[B])
		{
			++A; ++B; ++K;
		}
		return K;
	};

	for (int i = 1; i < N; ++i)
		Ret = max(Ret, LCP(Suffix[i - 1], Suffix[i]));

	return Ret;
}

int main()
{
	FASTIO;
	cin >> Str;
	cout << GetMax(Str) << '\n';
	return 0;
}

