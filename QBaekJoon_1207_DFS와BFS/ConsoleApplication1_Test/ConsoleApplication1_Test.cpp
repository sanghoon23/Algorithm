#include "pch.h"
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N = 0, M = 0, Start = 0, F = 0, S = 0;
vector<vector<int>> Temp;
vector<bool> Visited;

void DFS(int Index)
{
	printf("%d ", Index);

	for (int i = 0; i < Temp[Index].size(); ++i)
	{
		if (Visited[Temp[Index][i]] == false)
		{
			Visited[Temp[Index][i]] = true;
			DFS(Temp[Index][i]);
		}
	}
}

void BFS(int Index)
{
	queue<int> Que;
	Que.push(Index);
	while (!Que.empty())
	{
		int Poped = Que.front();
		Que.pop();

		printf("%d ", Poped);

		for (int i = 0; i < Temp[Poped].size(); ++i)
		{
			if (Visited[Temp[Poped][i]] == false)
			{
				Visited[Temp[Poped][i]] = true;
				Que.push(Temp[Poped][i]);
			}
		}
	}
}

int main()
{
	cin >> N >> M >> Start;
	Visited.resize(N + 1);
	Temp.resize(N + 1);

	for (int i = 0; i < M; ++i)
	{
		cin >> F >> S;
		Temp[F].push_back(S);
		Temp[S].push_back(F);
	}

	for (int i = 0; i < N; ++i)
		sort(Temp[i].begin(), Temp[i].end());

	Visited[Start] = true;
	DFS(Start);
	cout << endl;
	fill(Visited.begin(), Visited.end(), false);
	Visited[Start] = true;
	BFS(Start);

	return 0;
}

