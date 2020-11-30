#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

int Answer = 0;

void DFS(int N, int Count)
{
	if (N <= 3 || N < pow(3, (Count / 2)))
	{
		if (N == 3 && Count == 2)
			++Answer;

		return;
	}

	if (Count >= 2 && N % 3 == 0)
		DFS(N / 3, Count - 2);


	DFS(N - 1, Count + 1);
}

int solution(int N)
{
	Answer = 0;

	DFS(N - 2, 2);

	return Answer;
}

//int Answer = 0;
//int Height = 0;
//
//int FindRange(int N)
//{
//	int i = 1;
//	while (1)
//	{
//		int K = pow(3, i) + (2 * i);
//		if (K <= N) { ++i; continue; }
//		else break;
//	}
//
//	return i - 1;
//}
//
//void Check1(int Index, int Size, int Calc, int Total) //Index - 끝자리
//{
//	if (Index > Total - 2) return;
//
//	if (Index + 1 > Total - (2 * Size))
//	{
//		--Size; ++Index;
//	}
//	else
//		++Index;
//
//	Calc += pow(3, Size) - 1;
//	if (Calc == Height)
//		++Answer;
//
//	Check1(Index, Size, Calc, Total);
//}
//
//void Check2(int Index, int Calc, int Total, int Num)
//{
//	if (Index <= 1) return;
//
//	int R = Total - (Num * 2) - (Num - 1);
//	int P = (2 * pow(3, Num - 1));
//	for (int i = Index + 1; i <= R; ++i)
//	{
//		Calc += P;
//		if (Calc == Height) 
//			++Answer;
//	}
//
//	Check2(Index - 1, Calc, Total, Num + 1);
//}
//
//int solution(int N)
//{
//	Answer = 0;
//
//	Height = N;
//	int Range = FindRange(N); //범위
//	int Total = Range * 3; //총 칸 개수
//
//	int Calc = pow(3, Range) + (2 * Range);
//	if (Calc == Height) ++Answer;
//
//	Check1(Range - 1, Range - 1, Calc, Total - 1);
//	Check2(Range - 1, Calc, Total - 1, 1);
//
//
//	return Answer;
//}

int main()
{
	int N = 15;
	int Result = solution(N);

	return 0;
}

