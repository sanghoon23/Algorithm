#include "pch.h"
#include <iostream>
#include <string.h>
#include <algorithm>

using namespace std;

const int MMAX = 1e9, MMIN = -1e9;
#define PII pair<int, int> 
int N = 0, M = 0, Board[100001], F = 0, S = 0;
PII Tree[400001];
PII Update(int Start, int End, int Node)
{
	if (Start == End)
	{
		Tree[Node].first = Board[Start];
		Tree[Node].second = Board[Start];
		return Tree[Node];
	}
	int Mid = (Start + End) >> 1; //@ /2
	PII Left = Update(Start, Mid, Node * 2);
	PII Right = Update(Mid + 1, End, Node * 2 + 1);

	Tree[Node].first = min(Left.first, Right.first);
	Tree[Node].second = max(Left.second, Right.second);

	return Tree[Node];
}

PII Find(int Start, int End, int Node, int Left, int Right)
{
	if (Start > Right || End < Left) return { MMAX, MMIN };
	if (Left <= Start && End <= Right) return Tree[Node];

	int Mid = (Start + End) >> 1; //@ /2
	PII L = Find(Start, Mid, Node * 2, Left, Right);
	PII R = Find(Mid + 1, End, Node * 2 + 1, Left, Right);

	PII Ret = { MMAX, MMIN };
	Ret.first = min(L.first, R.first);
	Ret.second = max(L.second, R.second);
	return Ret;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> N >> M;
	for (int i = 1; i <= N; ++i) { Tree[i].first = MMAX; Tree[i].second = MMIN; }

	for (int i = 1; i <= N; ++i)
		cin >> Board[i];

	Update(1, N, 1);

	for (int i = 1; i <= M; ++i)
	{
		cin >> F >> S;
		PII R = Find(1, N, 1, F, S);
		cout << R.first << " " << R.second << '\n';
	}
	return 0;
}

