#include "pch.h"
#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int T = 0, N = 0, M = 0;
int main()
{
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> T;
	while (T--)
	{
		cin >> N;
		vector<int> Input(N + 1);
		for (int i = 1; i <= N; ++i)
			cin >> Input[i];

		vector<vector<int>> Link(N + 1, vector<int>(N + 1));
		vector<int> Degree(N + 1);
		for (int j = 1; j <= N; ++j)
		{
			for (int i = j + 1; i <= N; ++i)
			{
				Link[Input[j]][Input[i]] = 1;
				++Degree[Input[i]];
			}
		}

		cin >> M;
		for (int i = 0; i < M; ++i)
		{
			int F, S;
			cin >> F >> S;
			if (Link[F][S])
			{
				++Degree[F];
				--Degree[S];
			}
			else if (Link[S][F])
			{
				--Degree[F];
				++Degree[S];
			}
			swap(Link[F][S], Link[S][F]);
		}

		vector<int> Answer;
		queue<int> Que;
		for (int i = 1; i <= N; ++i)
			if (Degree[Input[i]] == 0) Que.push(Input[i]);

		while (!Que.empty())
		{
			int Popp = Que.front();
			Que.pop();
			--Degree[Popp];

			Answer.push_back(Popp);

			for (int i = 1; i <= N; ++i)
			{
				if (Link[Popp][i] == 1) --Degree[i];
				if (Degree[i] == 0) Que.push(i);
			}
		}

		if (Answer.size() != N) printf("IMPOSSIBLE");
		else
		{
			for (int k = 0; k < Answer.size(); ++k)
				printf("%d ", Answer[k]);
		}
		printf("\n");
	}
	return 0;
}

