#include "pch.h"
#include <iostream>
#include <vector>
#include <string.h>

using namespace std;
int T = 0, M = 0, N = 0, K = 0, Board[51][51] = { 0, };
bool Visited[51][51] = { false, };
pair<int, int> Dir[4] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };
vector<int> Answer;
void DFS(int Y, int X)
{
	if (Y < 0 || Y >= N || X < 0 || X >= M) return;
	if (Board[Y][X] == 0) return;
	Visited[Y][X] = true;

	for (int i = 0; i < 4; ++i)
	{
		int YY = Y + Dir[i].first, XX = X + Dir[i].second;
		if (Visited[YY][XX] == false)
			DFS(YY, XX);
	}
}

int main()
{
	cin >> T;
	for (int u = 0; u < T; ++u)
	{
		memset(Board, 0, sizeof(Board));
		memset(Visited, false, sizeof(Visited));
		cin >> M >> N >> K;
		int X = 0, Y = 0;
		for (int i = 0; i < K; ++i)
		{
			cin >> X >> Y;
			Board[Y][X] = 1;
		}

		int Calc = 0;
		for (int j = 0; j < N; ++j)
		{
			for (int i = 0; i < M; ++i)
			{
				if (Visited[j][i] == false && Board[j][i] == 1)
				{
					DFS(j, i);
					++Calc;
				}
			}
		}//for
		Answer.push_back(Calc);
	}

	for (int k = 0; k < Answer.size(); ++k)
		cout << Answer[k] << endl;
	return 0;
}

