#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int N = 0;
vector<vector<int>> Board;
vector<int> Degree;
void Find(int Idx, vector<vector<int>>& Temp, vector<int>& Output)
{
	for (int i = 0; i < Temp[Idx].size(); ++i)
	{
		while (Temp[Idx][i] > 0)
		{
			--Temp[Idx][i];
			--Temp[i][Idx];
			Find(i, Temp, Output);
		}
	}
	Output.push_back(Idx);
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> N;
	Board = vector<vector<int>>(N + 1, vector<int>(N + 1));
	Degree = vector<int>(N + 1);
	for (int j = 1; j <= N; ++j)
	{
		for (int i = 1; i <= N; ++i)
		{
			cin >> Board[j][i];
			Degree[j] += Board[j][i];
			Degree[i] += Board[j][i];
		}
	}

	for (int j = 1; j <= N; ++j)
	{
		Degree[j] /= 2;
		if (Degree[j] % 2 == 1)
		{
			printf("%d", -1);
			return 0;
		}
	}

	vector<int> Output;
	Find(1, Board, Output);
	reverse(Output.begin(), Output.end());
	for (int k = 0; k < Output.size(); ++k)
		printf("%d ", Output[k]);

	return 0;
}

