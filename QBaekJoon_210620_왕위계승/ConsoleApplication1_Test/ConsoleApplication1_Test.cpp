#include "pch.h"
#include <iostream>
#include <string.h>
#include <vector>
#include <queue>
#include <string>
#include <map>
#include <algorithm>

using namespace std;
#define FASTIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

int N, M;
double Dp[151];
map<string, int> IdxMap;
vector<int> Board[151];
string Found;

double Solve(int Idx)
{
	double& Ret = Dp[Idx];
	if (Ret != -1.0) return Ret;
	Ret = 0.0;

	double L = 0, R = 0;
	if (!Board[Idx].empty())
	{
		L = Solve(Board[Idx][0]);
		R = Solve(Board[Idx][1]);
	}

	Ret = (L + R) / 2;

	/*
	@왜 아래 계산법은 틀렸는가??
	*/
	//if (L <= 0 || R <= 0) Ret *= 4.0;
	//else if (L > 0 && R > 0) Ret *= 0.5;

	return Ret;
}

int main()
{
	FASTIO;
	cin >> N >> M;
	for (int i = 0; i <= 150; ++i) Dp[i] = -1.0;

	int Idx = 1;
	string Found;  cin >> Found;
	IdxMap[Found] = Idx++;
	Dp[1] = 1;

	for (int i = 0; i < N; ++i)
	{
		string W, F, S; cin >> W >> F >> S;
		if (IdxMap.find(W) == IdxMap.end()) IdxMap[W] = Idx++;
		if (IdxMap.find(F) == IdxMap.end()) IdxMap[F] = Idx++;
		if (IdxMap.find(S) == IdxMap.end()) IdxMap[S] = Idx++;

		Board[IdxMap[W]].push_back(IdxMap[F]);
		Board[IdxMap[W]].push_back(IdxMap[S]);
	}

	string Result;
	double MMax = 0;
	for (int i = 0; i < M; ++i)
	{
		string Input; cin >> Input;
		double Calc = Solve(IdxMap[Input]);
		if (Calc != 0 && MMax < Calc)
		{
			MMax = Calc;
			Result = Input;
		}
	}
	cout << Result << '\n';
	return 0;
}

