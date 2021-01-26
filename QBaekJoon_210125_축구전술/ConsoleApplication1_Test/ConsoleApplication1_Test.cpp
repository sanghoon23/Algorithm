#include "pch.h"
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;
#define FASTIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define MSIZE 100005
int T, N, M, Scc[MSIZE], Discovered[MSIZE], InDegree[MSIZE], Discov_Num, Scc_Num;
vector<int> Board[MSIZE];
stack<int> Stack;

int SccFunc(int Idx)
{
	int Ret = Discovered[Idx] = ++Discov_Num;
	Stack.push(Idx);

	for (int Next : Board[Idx])
	{
		if (Discovered[Next] == -1) Ret = min(Ret, SccFunc(Next));
		else if (Scc[Next] == -1) Ret = min(Ret, Discovered[Next]);
	}

	if (Ret == Discovered[Idx])
	{
		while (1)
		{
			int Popp = Stack.top();
			Stack.pop();
			Scc[Popp] = Scc_Num;
			if (Popp == Idx) break;
		}
		++Scc_Num;
	}
	return Ret;
}

int main()
{
	FASTIO;
	cin >> T;
	while (T--)
	{
		cin >> N >> M;
		Discov_Num = 0; Scc_Num = 1;
		for (int i = 0; i <= N; ++i)
		{
			Board[i].clear();
			Discovered[i] = -1;
			Scc[i] = -1;
			InDegree[i] = 0;
		}

		for (int i = 0; i < M; ++i)
		{
			int F, S;
			cin >> F >> S;
			++F; ++S;
			Board[F].push_back(S);
		}

		for (int i = 1; i <= N; ++i)
			if (Discovered[i] == -1) { SccFunc(i); }

		for (int j = 1; j <= N; ++j)
		{
			for (int Next : Board[j])
				if (Scc[j] != Scc[Next]) { ++InDegree[Scc[Next]]; }
		}

		int Count = 0;
		for (int i = 1; i < Scc_Num; ++i)
			if (InDegree[i] == 0) { ++Count; }

		if (Count > 1) cout << "Confused" << '\n';
		else
		{
			vector<int> Answer;
			for (int i = 1; i <= N; ++i)
			{
				if (InDegree[Scc[i]] == 0)
					Answer.push_back(i);
			}

			for (int k = 0; k < Answer.size(); ++k)
				cout << Answer[k] - 1 << '\n';
		}
		cout << '\n';
	}
	return 0;
}

