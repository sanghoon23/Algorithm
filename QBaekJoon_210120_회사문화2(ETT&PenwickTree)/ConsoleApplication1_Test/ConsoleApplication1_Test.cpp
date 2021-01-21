#include "pch.h"
#include <iostream>
#include <vector>

using namespace std;
#define PII pair<int, int>
#define MSIZE 100010
int N, M, SegTree[MSIZE], DFS_Num = 0;
PII Board[MSIZE];
bool Visited[MSIZE];
vector<int> Link[MSIZE];
void DFS(int Idx, int P)
{
	if (Visited[Idx] == true) return;

	Board[Idx].first = ++DFS_Num;
	Visited[Idx] = true;

	for (int Next : Link[Idx])
	{
		if (Next == P) continue;
		DFS(Next, Idx);
	}

	Board[Idx].second = DFS_Num;
}

void Update(int Idx, int Val)
{
	while (Idx <= N)
	{
		SegTree[Idx] += Val;
		Idx += (Idx & (-Idx));
	}
}

int Query(int Idx)
{
	int Ret = 0;
	while (Idx > 0)
	{
		Ret += SegTree[Idx];
		Idx -= (Idx & (-Idx));
	}
	return Ret;
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> N >> M;
	for (int i = 1; i <= N; ++i)
	{
		int Input; cin >> Input;
		if (Input == -1) continue;
		Link[Input].push_back(i);
	}
	DFS(1, 0);

	for (int i = 1; i <= M; ++i)
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

