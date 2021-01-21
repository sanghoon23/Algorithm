#include "pch.h"
#include <iostream>
#include <vector>

using namespace std;
#define MSIZE 400010
int N, M, SegTree[MSIZE], Lazy[MSIZE];

void Lazy_Update(int Node, int Start, int End)
{
	if (Lazy[Node] != 0)
	{
		SegTree[Node] = (End - Start) + 1 - SegTree[Node];
		if (Start != End)
		{
			Lazy[Node * 2] = !Lazy[Node * 2];
			Lazy[Node * 2 + 1] = !Lazy[Node * 2 + 1];
		}
		Lazy[Node] = 0;
	}
}

void Update(int Node, int Start, int End, int Left, int Right)
{
	Lazy_Update(Node, Start, End);
	if (Start > Right || End < Left) return;
	if (Left <= Start && End <= Right)
	{
		SegTree[Node] = (End - Start) + 1 - SegTree[Node];
		if (Start != End)
		{
			Lazy[Node * 2] = !Lazy[Node * 2];
			Lazy[Node * 2 + 1] = !Lazy[Node * 2 + 1];
		}
		return;
	}

	int Mid = (Start + End) >> 1;
	Update(Node * 2, Start, Mid, Left, Right);
	Update(Node * 2 + 1, Mid + 1, End, Left, Right);
	SegTree[Node] = SegTree[Node * 2] + SegTree[Node * 2 + 1];
}

int Query(int Node, int Start, int End, int Left, int Right)
{
	Lazy_Update(Node, Start, End);
	if (Start > Right || End < Left) return 0;
	if (Left <= Start && End <= Right) return SegTree[Node];

	int Mid = (Start + End) >> 1;
	return Query(Node * 2, Start, Mid, Left, Right) + Query(Node * 2 + 1, Mid + 1, End, Left, Right);
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> N >> M;

	for (int i = 0; i < M; ++i)
	{
		int W, F, S;
		cin >> W >> F >> S;
		if (W == 0) Update(1, 1, N, F, S);
		else cout << Query(1, 1, N, F, S) << '\n';
	}
	return 0;
}

