#include "pch.h"
#include <iostream>

using namespace std;
int N = 0, M = 0, K = 0;
long long Board[1000001], Tree[1000001], Input[3];
void Update(int Idx, int Value)
{
	while (Idx <= N)
	{
		Tree[Idx] += Value;
		Idx = Idx + (Idx & (-Idx));
	}
}

long long Sum(int Idx)
{
	long long Ret = 0;
	while (Idx > 0)
	{
		Ret += Tree[Idx];
		Idx = Idx - (Idx & (-Idx));
	}
	return Ret;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> N >> M >> K;
	for (int i = 1; i <= N; ++i)
	{
		cin >> Board[i];
		Update(i, Board[i]);
	}

	for (int i = 0; i < M + K; ++i)
	{
		cin >> Input[0] >> Input[1] >> Input[2];
		if (Input[0] == 1) //@바꾸기
		{
			Update(Input[1], Input[2] -(Board[Input[1]]));
			Board[Input[1]] = Input[2];
		}
		else if (Input[0] == 2) //@합출력
		{
			cout << Sum(Input[2]) - Sum(Input[1] - 1) << '\n';
		}
	}
	return 0;
}

