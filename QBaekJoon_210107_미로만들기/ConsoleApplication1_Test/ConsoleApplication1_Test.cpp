#include "pch.h"
#include <iostream>
#include <string>
#include <queue>
#include <vector>

using namespace std;
#define PII pair<int, int>
int N = 0;
string Input;
PII Dir[4] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
int Solve(vector<vector<int>>& Board, int Size)
{
	vector<vector<int>> Dist(Size, vector<int>(Size, 100000));
	Dist[0][0] = 0;

	priority_queue<pair<int, PII>> PQ;
	PQ.push({ 0, {0, 0} });
	while (!PQ.empty())
	{
		int Cost = -(PQ.top().first), Y = PQ.top().second.first, X = PQ.top().second.second;
		PQ.pop();
		
		for (int k = 0; k < 4; ++k)
		{
			int YY = Y + Dir[k].first, XX = X + Dir[k].second;
			if (YY < 0 || YY >= Size || XX < 0 || XX >= Size) continue;

			int NC = Cost;
			if (Board[YY][XX] == 0) ++NC;
			if (Dist[YY][XX] > NC)
			{
				Dist[YY][XX] = NC;
				PQ.push({ -(NC), {YY, XX} });
			}
		}
	}
	return Dist[Size - 1][Size - 1];
}

int main()
{
	cin >> N;
	vector<vector<int>> Board(N, vector<int>(N));
	for (int j = 0; j < N; ++j)
	{
		cin >> Input;
		for (int i = 0; i < N; ++i)
			Board[j][i] = Input[i] - '0';
	}
	cout << Solve(Board, N) << '\n';
	return 0;
}

