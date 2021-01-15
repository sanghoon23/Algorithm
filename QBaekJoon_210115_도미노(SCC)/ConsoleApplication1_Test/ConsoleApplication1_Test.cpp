#include "pch.h"
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <string.h>

using namespace std;
#define MMSIZE 1e5 + 1
vector<vector<int>> Board;
vector<int> Discoverd, SccId, Degree;
int T, N, M, VertexCount = 0, SccCount = 0;
stack<int> Stack;
int SccSolve(int Idx)
{
	int Ret = Discoverd[Idx] = VertexCount++;
	Stack.push(Idx);

	for (int i = 0; i < Board[Idx].size(); ++i)
	{
		int Next = Board[Idx][i];
		if (Discoverd[Next] == -1) Ret = min(Ret, SccSolve(Next));
		else if (SccId[Next] == -1) Ret = min(Ret, Discoverd[Next]);
	}

	if (Discoverd[Idx] == Ret)
	{
		while (1)
		{
			int Popp = Stack.top();
			Stack.pop();
			SccId[Popp] = SccCount; //@너 여기 왜 SccCount++ 해놨냐..? 미첬지? 정신차려..
			if (Popp == Idx) break;
		}
		++SccCount;
	}
	return Ret;
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> T;
	Board = vector<vector<int>>(MMSIZE, vector<int>());
	Discoverd = vector<int>(MMSIZE, -1);
	SccId = vector<int>(MMSIZE, -1);
	Degree = vector<int>(MMSIZE, 0);

	while (T--)
	{
		cin >> N >> M;
		for (int i = 0; i <= N; ++i)
		{
			Board[i].clear();
			Discoverd[i] = -1;
			SccId[i] = -1;
			Degree[i] = 0;
		}
		VertexCount = SccCount = 0;

		for (int i = 0; i < M; ++i)
		{
			int F, S;
			cin >> F >> S;
			Board[F].push_back(S);
		}

		for (int i = 1; i <= N; ++i)
			if (Discoverd[i] == -1) SccSolve(i);

		for (int j = 1; j <= N; ++j)
		{
			for (int i = 0; i < Board[j].size(); ++i)
			{
				int Link = Board[j][i];
				if (SccId[j] != SccId[Link])
					++Degree[SccId[Link]];
			}
		}

		int Answer = 0;
		for (int j = 0; j < SccCount; ++j)
			if (Degree[j] == 0) { ++Answer; }
		cout << Answer << '\n';
	}
	return 0;
}

