#include "pch.h"
#include <iostream>
#include <string.h>
#include <stack>
#include <algorithm>
using namespace std;

////////////////////////////////////////////////////////////////////////////////////////////////////////////
//@스택을 이용한 풀이.

#define LL long long
LL N = 0, Answer = 0;
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	stack<pair<LL, LL>> Stack;
	while (1)
	{
		cin >> N;
		if (N == 0) break;
		Answer = 0; //@초기화해주자..제발..ㅎ
		for (LL i = 0; i <= N; ++i)
		{
			LL Input = 0;
			if (i < N)
			{
				cin >> Input;
				Answer = max(Answer, Input);
			}

			LL Idx = i;
			while (!Stack.empty() && Stack.top().first > Input)
			{
				Answer = max(Answer, Stack.top().first * ((LL)i - (Stack.top().second)));
				Idx = Stack.top().second;
				Stack.pop();
			}

			Stack.push({ Input, Idx });
		}
		cout << Answer << '\n';
	}
	return 0;
}



/////////////////////////////////////////////////////////////////////////////////////////
//@분할정복.
//#define LL long long
//LL N = 0, Board[100001];
//LL Solve(LL Start, LL End)
//{
//	if (Start == End) return Board[Start];
//
//	LL Mid = (Start + End) / 2;
//	LL Ret = max(Solve(Start, Mid), Solve(Mid + 1, End));
//
//	LL Curr = Mid, Next = Mid + 1;
//	LL H = min(Board[Curr], Board[Next]);
//	Ret = max(Ret, H * 2);
//
//	while (Start < Curr || Next < End)
//	{
//		if (Next < End && (Curr == Start || Board[Curr - 1] < Board[Next + 1]))
//		{
//			++Next;
//			H = min(H, Board[Next]);
//		}
//		else
//		{
//			--Curr;
//			H = min(H, Board[Curr]);
//		}
//		Ret = max(Ret, H * (Next - Curr + 1));
//		int A = 0;
//	}
//	return Ret;
//}
//
//int main()
//{
//	ios_base::sync_with_stdio(0); cin.tie(0);
//	while (1)
//	{
//		cin >> N;
//		if (N == 0) break;
//
//		memset(Board, 0, sizeof(Board));
//		for (int i = 1; i <= N; ++i)
//			cin >> Board[i];
//
//		cout << Solve(1, N) << '\n';
//	}
//	return 0;
//}

////////////////////////////////////////////////////////////////////////////////////////////////////
//@삽질
//#define LL long long
//LL N = 0, Answer = 0, Board[100001], Tree[400001];
//LL Update(LL Start, LL End, LL Node)
//{
//	if (Start == End)
//	{
//		Tree[Node] = Start;
//		return Tree[Node];
//	}
//
//	LL Mid = (Start + End) >> 1;
//
//	LL Left = Update(Start, Mid, Node * 2);
//	LL Right = Update(Mid + 1, End, Node * 2 + 1);
//
//
//	LL Width = min(Board[Left], Board[Right]) * (End - Start + 1);
//	Answer = max(Answer, Width);
//
//	if (Board[Left] < Board[Right]) Tree[Node] = Left;
//	else Tree[Node] = Right;
//
//	return Tree[Node];
//}
//
//int main()
//{
//	ios_base::sync_with_stdio(0); cin.tie(0);
//
//	while (1)
//	{
//		cin >> N;
//		if (N == 0) break;
//
//		memset(Tree, 0, sizeof(Tree));
//		memset(Board, 0, sizeof(Board));
//		Answer = 0;
//		for (int i = 1; i <= N; ++i)
//			cin >> Board[i];
//
//		Update(1, N, 1);
//		//for (int j = 1; j <= 4 * N; ++j)
//		//{
//		//	for (int i = j; i <= N; ++i)
//		//	{
//		//		LL R = Find(1, N, 1, j, i);
//		//		Answer = max(Answer, R * (i - j + 1));
//		//	}
//		//}
//
//		cout << Answer << '\n';
//	}
//	return 0;
//}

//LL Find(LL Start, LL End, LL Node, LL Left, LL Right)
//{
//	if (Start > Right || End < Left) return 1e10;
//	if (Left <= Start && End <= Right) return Tree[Node];
//
//	LL Mid = (Start + End) >> 1;
//
//	LL Ret = 1e10;
//	Ret = min(Ret, Find(Start, Mid, Node * 2, Left, Right));
//	Ret = min(Ret, Find(Mid + 1, End, Node * 2 + 1, Left, Right));
//	return Ret;
//}

///////////////////////////////////////////////////////////////////////////////////////////
//using namespace std;
//long long N = 0, Answer = 0, Board[100001], Tree[400001];
//long long Update(long long Start, long long End, long long Node)
//{
//	if (Start == End)
//	{
//		if(Board[Start] != 0) Tree[Node] = Board[Start];
//		else Tree[Node] = 1e10;
//
//		return Tree[Node];
//	}
//
//	long long Mid = (Start + End) >> 1;
//	Tree[Node] = 1e10;
//	Tree[Node] = min(Tree[Node], Update(Start, Mid, Node * 2));
//	Tree[Node] = min(Tree[Node], Update(Mid + 1, End, Node * 2 + 1));
//
//	if(Tree[Node] < 1e10)
//		Answer = max(Answer, Tree[Node] * (End - Start + 1));
//	return Tree[Node];
//}
//
//int main()
//{
//	while (1)
//	{
//		cin >> N;
//		if (N == 0) break;
//
//		memset(Tree, 0, sizeof(Tree));
//		memset(Board, 0, sizeof(Board));
//		Answer = 0;
//
//		for (int i = 1; i <= N; ++i)
//			cin >> Board[i];
//
//		Update(1, N, 1);
//		cout << Answer << '\n';
//	}
//	return 0;
//}

