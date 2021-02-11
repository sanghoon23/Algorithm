#include "pch.h"
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string.h>

using namespace std;
#define FASTIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define MSIZE 1001
#define PII pair<int, int>
int N, M, Board[MSIZE][MSIZE];
bool Check[MSIZE][MSIZE];
PII Dir[4] = { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };

bool Comform(int N, int M)
{
	for (int j = 0; j < N; ++j)
		for (int i = 0; i < M; ++i)
			if (Board[j][i] == 0) return true;
	return false;
}

int main()
{
	FASTIO;
	cin >> M >> N;
	queue<pair<int, PII>> Que;
	bool bFinish = false;
	for (int j = 0; j < N; ++j)
		for (int i = 0; i < M; ++i)
		{
			cin >> Board[j][i];
			if (Board[j][i] == 1) Que.push({ 0, {j, i} });
			else if (Board[j][i] == 0) bFinish = true;
		}

	if (bFinish == false) { cout << 0; exit(0); }
	int Answer = 0;
	while (!Que.empty())
	{
		int Day = Que.front().first;
		int Y = Que.front().second.first, X = Que.front().second.second;
		Que.pop();

		Answer = max(Answer, Day);

		for (int k = 0; k < 4; ++k)
		{
			int YY = Y + Dir[k].first, XX = X + Dir[k].second;
			if (YY < 0 || YY >= N || XX < 0 || XX >= M) continue;
			if (Board[YY][XX] == 0)
			{
				Board[YY][XX] = 1;
				Que.push({ Day + 1, {YY, XX} });
			}
		}
	}
	if (Comform(N, M)) cout << -1;
	else cout << Answer;
	return 0;
}

/////////////////////////////////////////////////////////////////////////////////////////////

//int Solve(int N, int M)
//{
//	memset(Check, false, sizeof(Check));
//	int Ret = -1;
//	for(int j = 0; j < N; ++j)
//		for (int i = 0; i < M; ++i)
//		{
//			if (Board[j][i] != 1) continue;
//			if (Check[j][i]) continue;
//			for (int k = 0; k < 4; ++k)
//			{
//				int YY = j + Dir[k].first, XX = i + Dir[k].second;
//				if (YY < 0 || YY >= N || XX < 0 || XX >= M) continue;
//				if (Check[YY][XX]) continue;
//				if (Board[YY][XX] == 0)
//				{
//					Board[YY][XX] = 1;
//					Check[YY][XX] = true;
//					++Ret;
//				}
//			}
//		}
//
//	return Ret;
//}
//
//bool Comform(int N, int M)
//{
//	for (int j = 0; j < N; ++j)
//		for (int i = 0; i < M; ++i)
//			if (Board[j][i] == 0) return true;
//	return false;
//}
//
//int main()
//{
//	FASTIO;
//	cin >> M >> N;
//	for (int j = 0; j < N; ++j)
//		for (int i = 0; i < M; ++i)
//			cin >> Board[j][i];
//
//	int Answer = 1;
//	if (Solve(N, M) == -1) cout << 0;
//	else
//	{
//		while (1)
//		{
//			if (Solve(N, M) == -1) break;
//			++Answer;
//		}
//		if (Comform(N, M)) cout << -1;
//		else cout << Answer;
//	}
//	return 0;
//}

