#include "pch.h"
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N = 0, M = 0;
int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> N >> M;
	vector<vector<int>> Board(N + 1, vector<int>());
	vector<int> Degree(N + 1);
	for (int i = 0; i < M; ++i)
	{
		int F, S;
		cin >> F >> S;
		Board[F].push_back(S);
		++Degree[S];
	}

	priority_queue<int> PQ;
	for (int i = 1; i <= N; ++i)
		if (Degree[i] == 0) PQ.push(-i);

	while (!PQ.empty())
	{
		int Popp = -(PQ.top());
		PQ.pop();

		printf("%d ", Popp);

		for (int i = 0; i < Board[Popp].size(); ++i)
		{
			--(Degree[Board[Popp][i]]);
			if (Degree[Board[Popp][i]] == 0) PQ.push(-(Board[Popp][i]));
		}
	}
	return 0;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////
//@메모리를 많이 잡아먹음(메모리 초과)
// 아래의 방식이 이전의 문제 "최종 순위" 에서 적용되었던 이유는,
// 최종순위 문제에선 1 <= N <= 500 이었다.

//int N = 0, M = 0;
//int main()
//{
//	cin >> N >> M;
//	vector<int> Input(N + 1);
//	for (int i = 1; i <= N; ++i)
//		Input[i] = i;
//
//	vector<vector<int>> Board(N + 1, vector<int>(N + 1));
//	for (int j = 1; j <= N; ++j)
//		for (int i = j + 1; i <= N; ++i)
//			Board[j][i] = 1;
//
//	for (int i = 0; i < M; ++i)
//	{
//		int F, S;
//		cin >> F >> S;
//		swap(Board[F][S], Board[S][F]);
//	}
//
//	for (int j = 1; j <= N; ++j)
//		for (int i = j + 1; i <= N; ++i)
//			if (Board[Input[i]][Input[j]] == 1) swap(Input[j], Input[i]);
//
//	for (int i = 1; i <= N; ++i)
//		printf("%d ", Input[i]);
//
//	return 0;
//}

