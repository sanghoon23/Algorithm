#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int N = 0, Total = 0;
vector<vector<int>> Temp;
vector<vector<bool>> Visited;
vector<int> Answer;
pair<int, int> Dir[4] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
int DFS(int Y, int X)
{
	Visited[Y][X] = true;

	int Count = 1;
	for (int i = 0; i < 4; ++i)
	{
		int H = Y + Dir[i].first, W = X + Dir[i].second;
		if (H < 0 || H >= N || W < 0 || W >= N) continue;
		if (Temp[H][W] != 0 && Visited[H][W] == false)
		{
			Count += DFS(H, W);
		}
	}

	return Count;
}

int main()
{
	cin >> N;
	Temp.resize(N);
	for (int i = 0; i < N; ++i)
	{
		string  T;
		cin >> T;
		for (int k = 0; k < T.size(); ++k)
		{
			Temp[i].push_back(T[k] - 48);
		}
	}

	Visited.resize(N, vector<bool>(N, false));
	for (int j = 0; j < N; ++j)
	{
		for (int i = 0; i < N; ++i)
		{
			if (Temp[j][i] != 0 && Visited[j][i] == false)
			{
				++Total;
				Answer.push_back(DFS(j, i));
			}
		}
	}

	cout << Total << endl;
	sort(Answer.begin(), Answer.end());
	for (int i = 0; i < Answer.size(); ++i)
		cout << Answer[i] << endl;

	return 0;
}

