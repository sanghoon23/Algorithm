#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>

/*
@참고
* https://anz1217.tistory.com/41 -> Lazy Propagation 느린 세그먼트 갱신을 이용하지 않고도 푸는 방법
* 
*/
using namespace std;

#define MMAX 500010
#define LL long long
#define PLL pair<long long, long long>
#define PII pair<int, int>

int N, M, Upper, Val;
LL SegTree[MMAX];

vector<LL> Board[MMAX];
LL Cost[MMAX];
PII Range[MMAX];
int DFS_Num = 0;

void Update(int Idx, LL Val)
{
	while (Idx <= N)
	{
		SegTree[Idx] += Val;
		Idx += (Idx & (-Idx));
	}
}

LL GetValue(int Idx)
{
	LL Ret = 0;
	while (Idx > 0)
	{
		Ret += SegTree[Idx];
		Idx -= (Idx & (-Idx));
	}
	return Ret;
}

void DFS(int Idx, int P)
{
	Range[Idx].first = ++DFS_Num;

	for (int Next : Board[Idx])
	{
		if (Next == P) continue;
		DFS(Next, Idx);
	}
	Range[Idx].second = DFS_Num;
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> N >> M;

	for (int i = 1; i <= N; ++i)
	{
		cin >> Cost[i];
		if (i > 1)
		{
			cin >> Val;
			Board[Val].push_back(i);
		}
	}

	DFS(1, 0);

	for (int i = 1; i <= N; ++i)
	{
		Update(Range[i].first, Cost[i]);
		Update(Range[i].first + 1, -(Cost[i]));
	}

	for (int i = 0; i < M; ++i)
	{
		char Ch;
		cin >> Ch;
		if (Ch == 'p')
		{
			int F = 0, S = 0;
			cin >> F >> S;
			Update(Range[F].first + 1, S);
			Update(Range[F].second + 1, -S);

		}
		else if (Ch == 'u')
		{
			int F; cin >> F;
			printf("%d\n", GetValue(Range[F].first));
		}
	}
	return 0;
}


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//@삽질

//int N, M, Upper, Val;
//vector<vector<int>> Board;
//vector<int> Cost;
//vector<bool> Visited;
//
//void DFS(int Idx, int PlusCount)
//{
//	Visited[Idx] = true;
//	Cost[Idx] += PlusCount;
//	for (int i = 0; i < Board[Idx].size(); ++i)
//	{
//		if (Visited[Board[Idx][i]] == false)
//			DFS(Board[Idx][i], PlusCount);
//	}
//
//}
//
//int main()
//{
//	cin >> N >> M;
//	Board = vector<vector<int>>(N + 1);
//	Cost = vector<int>(N + 1, 0);
//	Visited = vector<bool>(N + 1, false);
//
//	for (int i = 1; i <= N; ++i)
//	{
//		if (i == 1)
//		{
//			cin >> Val; Cost[i] = Val;
//			for (int k = 2; k <= N; ++k)
//				Board[1].push_back(k);
//		}
//		else
//		{
//			cin >> Val;
//			cin >> Upper;
//			Board[Upper].push_back(i);
//			Cost[i] = Val;
//		}
//	}
//
//	for (int i = 0; i < M; ++i)
//	{
//		char Ch;
//		cin >> Ch;
//		int F = 0, S = 0;
//		cin >> F;
//		if (Ch == 'p')
//		{
//			cin >> S;
//			fill(Visited.begin(), Visited.end(), false);
//			Cost[F] -= S;
//			DFS(F, S);
//		}
//		else if (Ch == 'u') printf("%d\n", Cost[F]);
//	}
//	return 0;
//}

