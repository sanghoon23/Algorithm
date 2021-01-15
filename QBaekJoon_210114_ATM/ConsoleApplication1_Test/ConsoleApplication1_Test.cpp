#include "pch.h"
#include <iostream>
#include <stack>
#include <vector>
#include <queue>
#include <algorithm>
#include <string.h>

using namespace std;
#define PII pair<int, int>
int N = 0, M = 0, S = 0, P = 0, DiscovCount = 0, SccCount = 1;
vector<vector<int>> Board, LinkScc;
vector<int> Discoverd, SccId, SumScc, Cost, InDegree;
vector<bool> Resto, Visited;
stack<int> St;
int SccFunc(int Idx)
{
	int Ret = Discoverd[Idx] = DiscovCount++;
	St.push(Idx);

	for (int k = 0; k < Board[Idx].size(); ++k)
	{
		int There = Board[Idx][k];
		if (Discoverd[There] == -1) Ret = min(Ret, SccFunc(Board[Idx][k]));
		else if (SccId[There] == -1) Ret = min(Ret, Discoverd[There]);
	}

	if (Ret == Discoverd[Idx])
	{
		int Sum = 0;
		while (1)
		{
			int Popp = St.top();
			St.pop();
			Sum += Cost[Popp];
			SccId[Popp] = SccCount;
			if (Popp == Idx) break;
		}
		SumScc[SccCount] = Sum;
		++SccCount;
	}
	return Ret;
}

int TopologySort()
{
	int Answer = 0;
	queue<int> Que;
	for (int i = 1; i < SccCount; ++i)
	{
		Cost[i] = SumScc[i];
		if (i == SccId[S]) Visited[i] = true;
		if (InDegree[i] == 0) Que.push(i);
	}

	while (!Que.empty())
	{
		int Curr = Que.front();
		Que.pop();

		for (auto& Next : LinkScc[Curr])
		{
			if (Visited[Curr] == true)
			{
				Cost[Next] = max(Cost[Next], Cost[Curr] + SumScc[Next]);
				Visited[Next] = true;
			}
			if (--InDegree[Next] == 0) Que.push(Next);
		}
	}

	for (int i = 1; i < SccCount; ++i)
		if (Resto[i] == true && Visited[i] == true) Answer = max(Answer, Cost[i]);

	return Answer;
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> N >> M;
	Discoverd = vector<int>(N + 1, -1);
	Cost = vector<int>(N + 1);
	SccId = vector<int>(N + 1, -1);
	SumScc = vector<int>(N + 1, 0);

	Board = vector<vector<int>>(N + 1, vector<int>());
	LinkScc = vector<vector<int>>(N + 1, vector<int>());
	InDegree = vector<int>(N + 1, 0);
	for (int i = 0; i < M; ++i)
	{
		int F, S;
		cin >> F >> S;
		Board[F].push_back(S);
	}

	for (int i = 1; i <= N; ++i)
		cin >> Cost[i];

	for (int i = 1; i <= N; ++i)
		if (Discoverd[i] == -1) SccFunc(i);


	for (int j = 1; j <= N; ++j)
	{
		for (auto& Next : Board[j])
		{
			if (SccId[j] == SccId[Next]) continue;
			LinkScc[SccId[j]].push_back(SccId[Next]);
			++InDegree[SccId[Next]];

		}
	}

	cin >> S >> P;
	Resto = vector<bool>(N + 1, false);
	Visited = vector<bool>(N + 1, false);

	for (int i = 0; i < P; ++i)
	{
		int Input;
		cin >> Input;
		Resto[SccId[Input]] = true;
	}
	cout << TopologySort();
	return 0;
}

