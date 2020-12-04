#include "pch.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<vector<char>> Temp;
vector<vector<bool>> Visited;
int R = 0, C = 0, Answer = 0;
vector<pair<int, int>> Dir = { {-1, 1}, {0, 1}, {1, 1} };
bool DFS(int Y, int X)
{
	if (Y < 0 || Y >= R || X < 0 || X >= C) return false;
	if (Temp[Y][X] == 'x') return false;
	if (Visited[Y][X] == true) return false;
	Visited[Y][X] = true;

	if (X == C - 1)
	{
		++Answer;
		return true;
	}
	for (int i = 0; i < 3; ++i)
	{
		bool bRet = DFS(Y + Dir[i].first, X + Dir[i].second);
		if (bRet) return true;
	}

	return false;
}

int main()
{
	cin >> R >> C;

	Visited = vector<vector<bool>>(R, vector<bool>(C, false));
	for (int j = 0; j < R; ++j)
	{
		string T;
		cin >> T;
		Temp.push_back(vector<char>());
		for (int i = 0; i < C; ++i)
		{
			Temp[j].push_back(T[i]);
		}
	}

	for (int i = 0; i < R; ++i)
		DFS(i, 0);


	cout << Answer;
	return 0;
}

