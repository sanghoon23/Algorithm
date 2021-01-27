#include "pch.h"
//...
/*
다익스트라 를 반대로 실행한다..
*/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <string.h>

using namespace std;
#define FASTIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define LL long long
#define PII pair<int, int>
#define MMAX 987654321
#define MSIZE 25
int N, M, T, D, Board[MSIZE][MSIZE];
PII Dir[4] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
int Change(char InputCh)
{
	if (InputCh >= 'A' && InputCh <= 'Z') return InputCh - 'A';
	else return (InputCh - 'a') + 26;
}

vector<vector<LL>> Dijkstra(int Y, int X)
{
	vector<vector<LL>> Dist(N, vector<LL>(M, MMAX));
	Dist[Y][X] = 0;
	priority_queue<pair<LL, PII>> PQ;
	PQ.push({ 0, {Y, X} });
	while (!PQ.empty())
	{
		LL Cost = -(PQ.top().first);
		int Y = PQ.top().second.first, X = PQ.top().second.second;
		PQ.pop();

		for (int i = 0; i < 4; ++i)
		{
			int YY = Y + Dir[i].first, XX = X + Dir[i].second;
			if (YY < 0 || YY >= N || XX < 0 || XX >= M) continue;

			LL HVal = abs(Board[Y][X] - Board[YY][XX]);
			if (HVal > T) continue;

			LL MoreHeight = Cost + (HVal * HVal);
			if (Board[Y][X] < Board[YY][XX] && Dist[YY][XX] > MoreHeight)
			{
				Dist[YY][XX] = MoreHeight;
				PQ.push({ -(MoreHeight), {YY, XX} });
			}
			else if(Board[Y][X] >= Board[YY][XX] && Dist[YY][XX] > Cost + 1)
			{
				Dist[YY][XX] = Cost + 1;
				PQ.push({ -(Cost + 1), {YY, XX} });
			}
		}
	}
	return Dist;
}

vector<vector<LL>> RevDijkstra(int Y, int X)
{
	vector<vector<LL>> Dist(N, vector<LL>(M, MMAX));
	Dist[Y][X] = 0;
	priority_queue<pair<LL, PII>> PQ;
	PQ.push({ 0, {Y, X} });
	while (!PQ.empty())
	{
		LL Cost = -(PQ.top().first);
		int Y = PQ.top().second.first, X = PQ.top().second.second;
		PQ.pop();

		for (int i = 0; i < 4; ++i)
		{
			int YY = Y + Dir[i].first, XX = X + Dir[i].second;
			if (YY < 0 || YY >= N || XX < 0 || XX >= M) continue;

			LL HVal = abs(Board[Y][X] - Board[YY][XX]);
			if (HVal > T) continue;

			LL MoreHeight = Cost + (HVal * HVal);
			if (Board[Y][X] <= Board[YY][XX] && Dist[YY][XX] > Cost + 1)
			{
				Dist[YY][XX] = Cost + 1;
				PQ.push({ -(Cost + 1), {YY, XX} });
			}
			else if (Board[Y][X] > Board[YY][XX] && Dist[YY][XX] > MoreHeight)
			{
				Dist[YY][XX] = MoreHeight;
				PQ.push({ -(MoreHeight), {YY, XX} });
			}
		}
	}
	return Dist;
}

int main()
{
	FASTIO;
	cin >> N >> M >> T >> D; //N-행, M-열, T-높이차이, D-어두어지는시간
	for (int j = 0; j < N; ++j)
	{
		string Input;
		cin >> Input;
		for (int i = 0; i < M; ++i)
			Board[j][i] = Change(Input[i]);
	}

	int Answer = 0;
	vector<vector<LL>> StartResult = Dijkstra(0, 0);
	vector<vector<LL>> RevResult = RevDijkstra(0, 0);
	for (int j = 0; j < N; ++j)
	{
		for (int i = 0; i < M; ++i)
		{
			if (StartResult[j][i] + RevResult[j][i] <= D)
			{
				Answer = max(Answer, Board[j][i]);
			}
		}
	}
	cout << Answer << '\n';
	return 0;
}

