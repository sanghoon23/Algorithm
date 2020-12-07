#include "pch.h"
#include <iostream>
#include <vector>

using namespace std;
vector<vector<int>> Network;
bool Visited[102] = { false, };
int N = 0, M = 0, F = 0, S = 0;
int Answer = 0;
int DFS(int Index)
{
	Visited[Index] = true;
	int Count = 1;
	for (int i = 0; i < Network[Index].size(); ++i)
	{
		if (Visited[Network[Index][i]] == false)
		{
			Count += DFS(Network[Index][i]);
		}
	}
	return Count;
}

int main()
{
	cin >> N >> M;
	Network.resize(N + 1);
	for (int i = 0; i < M; ++i)
	{
		cin >> F >> S;
		Network[F].push_back(S);
		Network[S].push_back(F);
	}
	Answer = DFS(1);
	cout << Answer - 1;
	return 0;
}

