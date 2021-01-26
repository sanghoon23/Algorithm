#include "pch.h"
#include <iostream>
#include <vector>

using namespace std;
#define FASTIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define MSIZE 100005
#define PII pair<int, int>
int N, M, SegTree[MSIZE], RevSegTree[MSIZE], DFS_Num = 0;
vector<int> Link[MSIZE];
PII Board[MSIZE];
void DFS(int Idx)
{
	Board[Idx].first = ++DFS_Num;
	for (int Next : Link[Idx])
		DFS(Next);

	Board[Idx].second = DFS_Num;
}

void Update(int Vec[], int Idx, int Val)
{
	while (Idx <= N)
	{
		Vec[Idx] += Val;
		Idx += (Idx & (-Idx));
	}
}

int Query(int Vec[], int Idx)
{
	int Ret = 0;
	while (Idx > 0)
	{
		Ret += Vec[Idx];
		Idx -= (Idx & (-Idx));
	}
	return Ret;
}

int main()
{
	FASTIO;
	cin >> N >> M;
	for (int i = 1; i <= N; ++i)
	{
		int Input; cin >> Input;
		if (Input == -1) continue;
		Link[Input].push_back(i);
	}
	DFS(1);
	bool bReverse = false;
	for (int i = 1; i <= M; ++i)
	{
		int A, B, C;
		cin >> A;
		if (A == 1)
		{
			cin >> B; cin >> C;
			if (bReverse == false)
			{
				Update(SegTree, Board[B].first, C);
				Update(SegTree, Board[B].second + 1, -C);
			}
			else Update(RevSegTree, Board[B].first, C);
		}
		else if (A == 2)
		{
			cin >> B;
			//int F = Query(SegTree, Board[B].first);
			//int S = Query(RevSegTree, Board[B].second) - Query(RevSegTree, Board[B].first - 1);
			cout << Query(SegTree, Board[B].first) + Query(RevSegTree, Board[B].second) - Query(RevSegTree, Board[B].first - 1) << '\n';
		}
		else bReverse = !bReverse;
	}
	return 0;
}

