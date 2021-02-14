#include "pch.h"
#include <iostream>
#include <vector>
#include <queue>

using namespace std;
#define FASTIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define MSIZE 32001
int N, M, InDegree[MSIZE];
vector<int> Board[MSIZE];

int main()
{
	FASTIO;
	cin >> N >> M;
	for (int i = 0; i < M; ++i)
	{
		int F, S; cin >> F >> S;
		Board[F].push_back(S);
		++InDegree[S];
	}

	queue<int> Que;
	for (int i = 1; i <= N; ++i)
		if (InDegree[i] == 0) Que.push(i);

	while (!Que.empty())
	{
		int Idx = Que.front(); Que.pop();
		cout << Idx << " ";
		for (int Next : Board[Idx])
			if (--InDegree[Next] == 0) Que.push(Next);
	}
	return 0;
}

//#define FASTIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
//#define MSIZE 32001
//int N, M;
//vector<int> Board[MSIZE], Result;
//bool Visited[MSIZE];
//
//void DFS(int Idx)
//{
//	Visited[Idx] = true;
//	for (int Next : Board[Idx])
//	{
//		if(Visited[Next] == false)
//			DFS(Next);
//	}
//	Result.push_back(Idx);
//}
//
//int main()
//{
//	FASTIO;
//	cin >> N >> M;
//	for (int i = 0; i < M; ++i)
//	{
//		int F, S; cin >> F >> S;
//		Board[S].push_back(F);
//	}
//
//	for (int i = 1; i <= N; ++i)
//		if (Visited[i] == false) DFS(i);
//
//	for (int i = 0; i < Result.size(); ++i)
//		cout << Result[i] << " ";
//
//	return 0;
//}

