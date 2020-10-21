#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

//@메모이제이션
//int Calc[600001] = { 0, };
//int solution2(int N)
//{
//	int Answer = 0;
//	Calc[1] = 1;
//	Calc[2] = 2;
//	for (int i = 3; i <= N; ++i)
//		Calc[i] = (Calc[i - 1] + Calc[i - 2]) % 1000000007;
//
//	return Calc[N];
//}
//////////////////////////////////////////////////////////////////////////////////////////////////////////

// 직접 팩토리얼을 구해서 조합을 구하려하면 거의 못푼다고 보면 된다.
// 메모이제이션을 이용하자.
//int Factorial(int Num)
//{
//	int Ret = 1;
//	for (int i = 2; i <= Num; ++i)
//	{
//		Ret = Ret * i;
//	}
//	return Ret;
//}
//
//long long Combi(int Total, int Select) // 이거 못푼다.
//{
//	if (Select == 0 || Total == Select) return 1;
//	return (Factorial(Total) / (Factorial(Select) * Factorial(Total - Select)));
//}
//
//int solution(int N) //가로의 길이
//{
//	long long Answer = 0;
//	int Width = N / 2;
//	for (int i = Width; i > 0; --i) // 가로의 갯수
//	{
//		int Height = N - (i * 2); //세로의 갯수
//		int Total = i + Height;
//		Answer += Combi(Total, i);
//		Answer %= 1000000007;
//	}
//
//	return (Answer + 1); //모두가 세로일 때 + 1
//}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//@조합을 메모이제이션으로도 구해봤다.
// 하지만, 문제에서 시간초과가 났다. 계산이 오래걸릴 것이다.
vector<vector<long long>> Calc;

long long Combi(int Total, int Select)
{
	if (Select == 0 || Total == Select) return 1;
	if (Calc[Total][Select] != 0) return Calc[Total][Select];

	Calc[Total][Select] = Combi(Total - 1, Select - 1) + Combi(Total - 1, Select);
	return Calc[Total][Select] % 1000000007;
}

int solution(int N)
{
	long long Answer = 0;
	Calc = vector<vector<long long>>(N, vector<long long>(N));

	int Width = N / 2;
	for (int i = Width; i > 0; --i) // 가로의 갯수
	{
		int Height = N - (i * 2); //세로의 갯수
		int Total = i + Height;
		Answer += Combi(Total, i);
		Answer %= 1000000007;
	}

	return (Answer + 1) % 1000000007; //모두가 세로일 때 + 1
}

int main()
{
	int N = 5;
	int Result = solution(N);
	return 0;
}

