#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define FASTIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define LL long long
LL N, M;
LL Solve(vector<LL>& Board, LL Start, LL End)
{
	if (Start >= End) return End;
	LL Mid = (Start + End) >> 1;
	LL Result = 0;
	for (int i = 1; i <= N; ++i)
	{
		if (Board[i] - Mid > 0)
			Result += Board[i] - Mid;
	}
	if (Result < M) return Solve(Board, Start, Mid - 1);
	return Solve(Board, Mid + 1, End);
}

int main()
{
	FASTIO;
	cin >> N >> M;
	LL MaxHeight = 0;
	vector<LL> Board(N + 1);
	for (int i = 1; i <= N; ++i)
	{
		cin >> Board[i];
		MaxHeight = max(MaxHeight, Board[i]);
	}
	//@while 이분탐색
	/*
	//LL Start = 0, End = MaxHeight;
	//while (Start <= End)
	//{
	//	LL Mid = (Start + End) >> 1;
	//	LL Result = 0;
	//	for (int i = 1; i <= N; ++i)
	//	{
	//		if (Board[i] - Mid > 0)
	//			Result += Board[i] - Mid;
	//	}
	//	if (Result < M) End = Mid - 1;
	//	else Start = Mid + 1;
	//}
	//cout << Start - 1 << '\n';
	*/
	cout << Solve(Board, 0, MaxHeight) << '\n';
	return 0;
}


//#define FASTIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
//#define LL long long
//LL N, M;
//LL Solve(vector<LL>& Board, LL Start, LL End)
//{
//	if (Start == End) return Start - 1;
//	LL Mid = (Start + End) >> 1;
//	LL Result = 0;
//	for (int i = 1; i <= N; ++i)
//	{
//		if (Board[i] - Mid > 0)
//			Result += Board[i] - Mid;
//	}
//	if (Result < M) return Solve(Board, Start, Mid);
//	return Solve(Board, Mid + 1, End);
//}
//
//int main()
//{
//	FASTIO;
//	cin >> N >> M;
//	LL MaxHeight = 0;
//	vector<LL> Board(N + 1);
//	for (int i = 1; i <= N; ++i)
//	{
//		cin >> Board[i];
//		MaxHeight = max(MaxHeight, Board[i]);
//	}
//	cout << Solve(Board, 0, MaxHeight) << '\n';
//	return 0;
//}

