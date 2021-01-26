#include "pch.h"
#include <iostream>
#include <vector>

using namespace std;
#define FASTIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define MSIZE 100010
#define LL long long
#define PII pair<int, int>
int N, M;
LL SegTree[MSIZE], DFS_Num = 0;
vector<int> Link[MSIZE];
PII Board[MSIZE];
bool Visited[MSIZE];
void DFS(int Idx)
{
	if (Visited[Idx] == true) return;
	Visited[Idx] = true;

	Board[Idx].first = ++DFS_Num;
	for (int Next : Link[Idx])
		DFS(Next);

	Board[Idx].second = DFS_Num;
}

void Update(int Idx, LL Val)
{
	while (Idx <= N)
	{
		SegTree[Idx] += Val;
		Idx += (Idx & (-Idx));
	}
}

LL Query(int Idx)
{
	LL Ret = 0;
	while (Idx > 0)
	{
		Ret += SegTree[Idx];
		Idx -= (Idx & -(Idx));
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

	for (int i = 0; i < M; ++i)
	{
		int A, B, C;
		cin >> A >> B;
		if (A == 1)
		{
			cin >> C;
			Update(Board[B].first, C);
			Update(Board[B].second + 1, -C);
		}
		else cout << Query(Board[B].first) << '\n';
	}
	return 0;
}

