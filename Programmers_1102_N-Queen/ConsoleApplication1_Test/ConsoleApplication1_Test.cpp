#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
//@백트래킹 - 근본적으로 시간을 줄이는 방법

//int Answer = 0;
//int Left[100001] = { 0, };
//int Stright[100001] = { 0, };
//int Right[100001] = { 0, };
//
//void DFS(int N, pair<int, int> Curr, int QueenCount)
//{
//	if (Left[(N + Curr.first - Curr.second)] || Stright[Curr.second] || Right[(Curr.first + Curr.second)]) return;
//	if (QueenCount >= N) { ++Answer; return; }
//
//	Left[(N + Curr.first - Curr.second)] = Stright[Curr.second] = Right[(Curr.first + Curr.second)] = 1;
//
//	for (int i = 1; i <= N; ++i)
//		DFS(N, { Curr.first + 1, i }, QueenCount + 1);
//
//	Left[(N + Curr.first - Curr.second)] = Stright[Curr.second] = Right[(Curr.first + Curr.second)] = 0;
//}
//
//int solution(int N)
//{
//	for (int i = 1; i <= N; ++i)
//		DFS(N, { 1, i }, 1);
//
//	return Answer;
//}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//@DFS (최대한 시간 줄이는 방법)
int Answer = 0;
pair<int, int> Dir[3] = { {-1, -1}, {-1, 1}, {-1, 0} };

bool Find(int N, pair<int, int> Curr, vector<vector<bool>> Visited)
{
	for (int j = 0; j < 3; ++j)
	{
		int Row = Curr.first, Col = Curr.second;
		int X = Dir[j].first, Y = Dir[j].second;
		while (1)
		{
			Row += X;
			Col += Y;
			if (Row < 0 || Row >= N || Col < 0 || Col >= N) break;
			if (Visited[Row][Col] == true) return false;
		}
	}

	return true;
}

void DFS(int N, vector<vector<bool>>& Visited, pair<int, int> Curr, int QueenCount)
{
	if (Find(N, { Curr.first, Curr.second }, Visited) == false) return;

	if (QueenCount >= N)
	{
		++Answer;
		return;
	}

	Visited[Curr.first][Curr.second] = true;

	for (int i = 0; i < N; ++i)
	{
		DFS(N, Visited, { Curr.first + 1, i }, QueenCount + 1);
	}

	Visited[Curr.first][Curr.second] = false;
}

int solution(int N)
{
	for (int i = 0; i < N; ++i)
	{
		vector<vector<bool>> Visit(N, vector<bool>(N, false));
		DFS(N, Visit, { 0, i }, 1);
	}

	return Answer;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
//@이전 코드 (시간초과)

//int Answer = 0;
//pair<int, int> Dir[8] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1}, {1, 1}, {-1, 1}, {1, -1}, {-1, -1} };
//
//void DFS(int N, vector<vector<bool>> Visited, pair<int, int> Curr, int QueenCount)
//{
//	if (QueenCount >= N)
//	{
//		++Answer;
//		return;
//	}
//
//	for (int j = 0; j < 8; ++j) <<<<<<<<<<<<<<<<--------- 모든 경우를 Visited = true 하기 위해 돌려버림.
//	{
//		int Row = Curr.first, Col = Curr.second;
//		int X = Dir[j].first, Y = Dir[j].second;
//		while (1)
//		{
//			Row += X;
//			Col += Y;
//			if (Row < 0 || Row >= N || Col < 0 || Col >= N) break;
//			Visited[Row][Col] = true;
//		}
//	}
//
//	for (int j = 0; j < N; ++j) <<<<<<<<<<<<<<<<--------- 모든 경우를 0부터 다 찾음.
//	{
//		for (int i = 0; i < N; ++i)
//		{
//			if (Visited[j][i] == true) continue;
//			Visited[j][i] = true;
//			DFS(N, Visited, { j, i }, QueenCount + 1);
//			Visited[j][i] = false;
//		}
//	}
//}

int main()
{
	int Result = solution(4);
	return 0;
}

