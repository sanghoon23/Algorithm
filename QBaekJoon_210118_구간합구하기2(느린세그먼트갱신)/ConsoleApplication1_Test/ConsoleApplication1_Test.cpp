#include "pch.h"
#include <iostream>
#include <vector>
using namespace std;

/*
구간 업데이트 & 구간 쿼리 구현.

*/
#define MSIZE 1000010
#define LL long long
LL N, M, K, SegMul[MSIZE], SegAdd[MSIZE];

void Update(int Idx, LL Mul, LL Add)
{
	while (Idx <= N)
	{
		SegMul[Idx] += Mul;
		SegAdd[Idx] += Add;
		Idx += (Idx & (-Idx));
	}
}

LL GetValue(LL Idx)
{
	LL Mul = 0;
	LL Add = 0;
	LL Start = Idx;

	while (Idx > 0)
	{
		Mul += SegMul[Idx];
		Add += SegAdd[Idx];
		Idx -= (Idx & (-Idx));
	}
	return Mul * Start + Add;
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> N >> M >> K;
	for (LL i = 1; i <= N; ++i)
	{
		int Input; cin >> Input;
		Update(i, Input, -Input * (i - 1));
		Update(i + 1, -Input, Input * i);
	}

	for (LL i = 0; i < M + K; ++i)
	{
		LL A, B, C, D;
		cin >> A;
		if (A == 1)
		{
			cin >> B >> C >> D;
			Update(B, D, -D * (B - 1));
			Update(C + 1, -D, D * C);
		}
		else if (A == 2)
		{
			cin >> B >> C;
			cout << GetValue(C) - GetValue(B - 1) << '\n';
		}
	}
	return 0;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//@느린 세그먼트 트리 갱신 이용.

//#define MSIZE 4000010
//#define LL long long
//LL N, M, K, Board[MSIZE], SegTree[MSIZE], Lazy[MSIZE];
//
//LL Init(LL Node, LL Start, LL End)
//{
//	if (Start == End) { SegTree[Node] = Board[Start]; return SegTree[Node]; }
//	LL Mid = (Start + End) >> 1;
//	SegTree[Node] = Init(Node * 2, Start, Mid) + Init(Node * 2 + 1, Mid + 1, End);
//	return SegTree[Node];
//}
//
//void LazyUpdate(LL Node, LL Start, LL End)
//{
//	if (Lazy[Node] != 0)
//	{
//		SegTree[Node] += (LL)(End - Start + 1) * Lazy[Node];
//		if (Start != End)
//		{
//			Lazy[Node * 2] += Lazy[Node];
//			Lazy[Node * 2 + 1] += Lazy[Node];
//		}
//		Lazy[Node] = 0;
//	}
//}
//
//void Update(LL Node, LL Start, LL End, LL Left, LL Right, LL Value)
//{
//	LazyUpdate(Node, Start, End);
//	if (Start > Right || End < Left) return;
//	if (Left <= Start && End <= Right)
//	{
//		SegTree[Node] += (LL)(End - Start + 1) * Value;
//		if (Start != End)
//		{
//			Lazy[Node * 2] += Value;
//			Lazy[Node * 2 + 1] += Value;
//		}
//		return;
//	}
//
//	LL Mid = (Start + End) >> 1;
//	Update(Node * 2, Start, Mid, Left, Right, Value);
//	Update(Node * 2 + 1, Mid + 1, End, Left, Right, Value);
//	SegTree[Node] = SegTree[Node * 2] + SegTree[Node * 2 + 1];
//}
//
//LL Query(LL Node, LL Start, LL End, LL Left, LL Right)
//{
//	LazyUpdate(Node, Start, End);
//	if (Start > Right || End < Left) return 0;
//	if (Left <= Start && End <= Right)
//		return SegTree[Node];	
//
//	LL Mid = (Start + End) >> 1;
//	LL LeftVal = Query(Node * 2, Start, Mid, Left, Right);
//	LL RightVal = Query(Node * 2 + 1, Mid + 1, End, Left, Right);
//	return LeftVal + RightVal;
//}
//
//int main()
//{
//	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
//	cin >> N >> M >> K;
//	for (LL i = 1; i <= N; ++i)
//		cin >> Board[i];
//
//	Init(1, 1, N);
//
//	for (LL i = 0; i < M + K; ++i)
//	{
//		LL A, B, C, D;
//		cin >> A;
//		if (A == 1)
//		{
//			cin >> B >> C >> D;
//			Update(1, 1, N, B, C, D);
//		}
//		else if (A == 2)
//		{
//			cin >> B >> C;
//			cout << Query(1, 1, N, B, C) << '\n';
//		}
//	}
//	return 0;
//}

