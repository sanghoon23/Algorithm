#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define FASTIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define MMAX 987654321
#define PII pair<int, int>
int N, C, M;

bool Compare(pair<int, PII> A, pair<int, PII> B)
{
	if (A.first == B.first) return A.second.second < B.second.second;
	else return A.first < B.first;
}

int main()
{
	FASTIO;
	cin >> N >> C >> M;
	vector<pair<int, PII>> Board;
	for (int i = 0; i < M; ++i)
	{
		int F, S, W;
		cin >> F >> S >> W;
		Board.push_back({ S, {F,W} });
	}
	sort(Board.begin(), Board.end(), Compare);

	int Answer = 0;
	vector<int> Temp(N + 1, C);
	for (int j = 0; j < M; ++j)
	{
		int End = Board[j].first, Start = Board[j].second.first, Weight = Board[j].second.second;
		int MMin = MMAX;
		for (int k = Start; k < End; ++k)
			MMin = min(MMin, Temp[k]);

		if (MMin < Weight) Weight = MMin;

		Answer += Weight;
		for (int k = Start; k < End; ++k)
			Temp[k] -= Weight;
	}
	cout << Answer << '\n';
	return 0;
}


///////////////////////////////////////////////////////////////////////////////////////////////////////////
//@삽질
//#define FASTIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
//#define PII pair<int, int>
//int N, C, M;
//
//int main()
//{
//	FASTIO;
//	cin >> N >> C >> M;
//	vector<vector<PII>> Board(N + 1, vector<PII>());
//	for (int i = 0; i < M; ++i)
//	{
//		int F, S, W;
//		cin >> F >> S >> W;
//		Board[F].push_back({ S, W });
//	}
//
//	for (int i = 1; i <= N; ++i)
//		sort(Board[i].begin(), Board[i].end());
//
//	int Answer = 0, Curr = 0;
//	for (int k = 1; k <= N; ++k)
//	{
//		int Result = 0;
//		priority_queue<PII> PQ;
//		for (int j = k; j <= N; ++j)
//		{
//			while (!PQ.empty())
//			{
//				int NextIdx = -(PQ.top().first), DownCost = PQ.top().second;
//				if (NextIdx != j) break;
//				PQ.pop();
//				Curr -= DownCost;
//			}
//
//			for (int i = 0; i < Board[j].size(); ++i)
//			{
//				int Next = Board[j][i].first, Weight = Board[j][i].second;
//				if (Curr < C)
//				{
//					int Add = Weight;
//					if (Curr + Add > C) { Add -= (Add + Curr - C); }
//					Curr += Add;
//					Result += Add;
//					PQ.push({ -Next, Add });
//				}
//				else break;
//			}
//		}
//		Answer = max(Answer, Result);
//	}
//	cout << Answer;
//	return 0;
//}

