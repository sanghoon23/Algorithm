#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>

using namespace std;
#define FASTIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define MMAX 1000000001
#define MSIZE 16
int N;
int Add(int Visited, int Curr)
{
	return (Visited | (1 << Curr));
}

bool Check(int Visited, int Curr)
{
	return (Visited & (1 << Curr)) != 0;
}

bool Check_All(int Visited, int Curr)
{
	//unsigned int V = (unsigned int)Visited;
	//return ((~Visited) == 0);
	return Visited == (1 << Curr) - 1;
}

int Solve(vector<vector<int>>& Board, vector<vector<int>>& Dp, int Visited, int Curr)
{
	//if (Check_All(Visited, N))
	//{
	//	if (Dp[Curr][0]) return Dp[Curr][0];
	//	else return MMAX;
	//}
	if (Check_All(Visited, N))
	{
		if (Board[Curr][0]) return Board[Curr][0];
		else return MMAX;
	}

	int& Ret = Dp[Visited][Curr];
	if (Ret != -1) return Ret;
	Ret = MMAX;

	for (int i = 0; i < N; ++i)
	{
		if (Board[Curr][i] == 0) continue;
		if (Check(Visited, i) == true) continue;
		int InsertVisited = Add(Visited, i);
		Ret = min(Ret, Solve(Board, Dp, InsertVisited, i) + Board[Curr][i]);
	}
	return Ret;
}

int main()
{
	FASTIO;
	//int A = (1 << 4) - 1;
	//unsigned int B = A;
	//cout << ~B;

	cin >> N;
	vector<vector<int>> Board(N, vector<int>(N, 0));
	for (int j = 0; j < N; ++j)
		for (int i = 0; i < N; ++i)
			cin >> Board[j][i];

	vector<vector<int>> Dp((1 << N), vector<int>(N, -1));
	cout << Solve(Board, Dp, 1, 0) << '\n';
	return 0;
}

