#include "pch.h"
#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;
#define PII pair<int, int>
int N = 0, M = 0, Board[101][101], Visited[101][101];
string Str;
PII Dir[4] = { {0, 1}, {1, 0}, {-1, 0}, {0, -1} };
int main()
{
	cin >> N >> M;
	for (int j = 0; j < N; ++j)
	{
		cin >> Str;
		for (int i = 0; i < Str.size(); ++i)
			Board[j][i] = Str[i] - '0';
	}

	queue<PII> Que;
	Que.push({ 0, 0 });
	int Answer = 0, Count = 1;
	while (Answer == 0)
	{
		vector<PII> Next;
		while (!Que.empty())
		{
			PII Poped = Que.front();
			Que.pop();

			int Y = Poped.first, X = Poped.second;
			if (Y == N - 1 && X == M - 1)
			{
				Answer = Count; break;
			}

			for (int k = 0; k < 4; ++k)
			{
				int YY = Y + Dir[k].first, XX = X + Dir[k].second;
				if (YY < 0 || YY >= N || XX < 0 || XX >= M) continue; //@범위체크를 먼저.해주는 습관.
				if (Visited[YY][XX] == true) continue;
				if (Board[YY][XX] == 0) continue;

				Visited[YY][XX] = true;
				Next.push_back({ YY, XX });
			}
		}
		for (int i = 0; i < Next.size(); ++i)
			Que.push(Next[i]);

		++Count;
	}
	cout << Answer;
	return 0;
}

