#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define FASTIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define MSIZE 100001
#define PII pair<int, int>
int N, Parent[MSIZE];
struct Comet { int X = 0, Y = 0, Z = 0, Idx = 0; };
vector<Comet> Board;

int Find(int X)
{
	if (Parent[X] == X) return X;
	Parent[X] = Find(Parent[X]);
	return Parent[X];
}

void Marge(int X, int Y)
{
	X = Find(X); Y = Find(Y);
	if (X == Y) return;
	Parent[Y] = X;
}

int main()
{
	FASTIO;
	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		Comet Insert;
		cin >> Insert.X >> Insert.Y >> Insert.Z;
		Insert.Idx = i;
		Board.push_back(Insert);
		Parent[i] = i;
	}

	auto XComp = [&](Comet A, Comet B)->bool { return A.X < B.X; };
	auto YComp = [&](Comet A, Comet B)->bool { return A.Y < B.Y; };
	auto ZComp = [&](Comet A, Comet B)->bool { return A.Z < B.Z; };

	vector<pair<int, PII>> Result;
	sort(Board.begin(), Board.end(), XComp);
	for (int i = 1; i < Board.size(); ++i)
		Result.push_back({ abs(Board[i - 1].X - Board[i].X), {Board[i - 1].Idx, Board[i].Idx} });

	sort(Board.begin(), Board.end(), YComp);
	for (int i = 1; i < Board.size(); ++i)
		Result.push_back({ abs(Board[i - 1].Y - Board[i].Y), {Board[i - 1].Idx, Board[i].Idx} });

	sort(Board.begin(), Board.end(), ZComp);
	for (int i = 1; i < Board.size(); ++i)
		Result.push_back({ abs(Board[i - 1].Z - Board[i].Z), {Board[i - 1].Idx, Board[i].Idx} });

	int Answer = 0;
	sort(Result.begin(), Result.end());
	for (int i = 0; i < Result.size(); ++i)
	{
		int F = Result[i].second.first, S = Result[i].second.second;
		if (Find(F) != Find(S))
		{
			Marge(F, S);
			Answer += Result[i].first;
		}
	}
	cout << Answer;
	return 0;
}

////////////////////////////////////////////////////////////////////////////////////

//#define FASTIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
//#define LL long long
//#define MSIZE 100001
//#define PII pair<LL, LL>
//int N, X[MSIZE], Y[MSIZE], Z[MSIZE];
//LL Board[MSIZE][MSIZE];
//bool Visited[MSIZE];
//int main()
//{
//	FASTIO;
//	cin >> N;
//	for (int i = 1; i <= N; ++i)
//		cin >> X[i] >> Y[i] >> Z[i];
//
//	for(int j = 1; j <= N; ++j)
//		for (int i = 1; i <= N; ++i)
//		{
//			if (i == j) continue;
//			Board[j][i] = min(X[j] - X[i], min(Y[j] - Y[i], Z[j] - Z[i]));
//		}
//
//	LL Answer = 0;
//	priority_queue<PII> PQ;
//	PQ.push({ 0, 1 });
//	while (!PQ.empty())
//	{
//		int Cost = -(PQ.top().first), Idx = PQ.top().second;
//		PQ.pop();
//
//		if (Visited[Idx] == true) continue;
//		Visited[Idx] = true;
//		Answer += Cost;
//
//		for (int i = 1; i <= N; ++i)
//		{
//			if (Visited[i] == false)
//			{
//				PQ.push({ -(Cost + Board[Idx][i]), i });
//			}
//		}
//	}
//	cout << Answer << '\n';
//	return 0;
//}

