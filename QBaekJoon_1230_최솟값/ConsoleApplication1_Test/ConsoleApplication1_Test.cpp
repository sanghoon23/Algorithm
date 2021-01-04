#include "pch.h"
#include <iostream>
#include <algorithm>
using namespace std;
int N = 0, M = 0, F = 0, S = 0, Board[100001], Tree[400001];

int Update(int Start, int End, int Node)
{
	if (Start == End)
	{
		Tree[Node] = Board[Start];
		return Tree[Node];
	}

	int Mid = (Start + End) >> 1;
	Tree[Node] = 1e10;
	Tree[Node] = min(Tree[Node], Update(Start, Mid, Node * 2));
	Tree[Node] = min(Tree[Node], Update(Mid + 1, End, Node * 2 + 1));
	return Tree[Node];
}

/* 찾는 과정 */
int Find(int Left, int Right, int Start, int End, int Node)
{
	if (Start > Right || End < Left) return 1e10;
	if (Start <= Left && Right <= End) return Tree[Node];

	int Mid = (Left + Right) >> 1;
	int Ret = 1e10;
	Ret = min(Ret, Find(Left, Mid, Start, End, Node * 2));
	Ret = min(Ret, Find(Mid + 1, Right, Start, End, Node * 2 + 1));
	return Ret;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> N >> M;
	for (int i = 1; i <= N; ++i)
		cin >> Board[i];

	Update(1, N, 1);
	for (int i = 0; i < M; ++i)
	{
		cin >> F >> S;
		cout << Find(1, N, F, S, 1) << '\n'; //@1~N 까지의 범위를 찾는 과정임.
	}
	return 0;
}

