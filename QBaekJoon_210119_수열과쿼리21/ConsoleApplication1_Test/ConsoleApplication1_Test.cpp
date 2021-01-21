#include "pch.h"
#include <iostream>

using namespace std;
#define MSIZE 100010
#define LL long long
LL N, M, TMul[MSIZE], TAdd[MSIZE];

void Update(int Idx, LL Mul, LL Add)
{
	while (Idx <= N)
	{
		TMul[Idx] += Mul;
		TAdd[Idx] += Add;
		Idx += (Idx & (-Idx));
	}
}

LL GetValue(int Idx)
{
	LL MMul = 0;
	LL MAdd = 0;
	LL Start = Idx;
	while (Idx > 0)
	{
		MMul += TMul[Idx];
		MAdd += TAdd[Idx];
		Idx -= (Idx & (-Idx));
	}
	return MMul * Start + MAdd;
}

void MappingUpdate(int Idx, LL Val)
{
	Update(Idx, Val, -Val * (Idx - 1));
	Update(Idx + 1, -Val, Val * Idx);
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 1; i <= N; ++i)
	{
		LL Input; cin >> Input;
		MappingUpdate(i, Input);
	}

	cin >> M;
	for (int i = 0; i < M; ++i)
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
			cin >> B;
			cout << GetValue(B) - GetValue(B - 1) << '\n';
		}
	}
	return 0;
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//@이 코드와 차이점은 무엇인가??
//...

/*
void Update(int Idx, LL Value)
{
	while (Idx <= N)
	{
		SegTree[Idx] += Value;
		Idx += (Idx & (-Idx));
	}
}

LL GetValue(int Idx)
{
	LL Ret = 0;
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
	cin >> N;
	for (int i = 1; i <= N; ++i)
	{
		int Input; cin >> Input;
		Update(i, Input);
		Update(i + 1, -Input);
	}

	cin >> M;
	for (int i = 0; i < M; ++i)
	{
		LL A, B, C, D;
		cin >> A;
		if (A == 1)
		{
			cin >> B >> C >> D;
			Update(B, D);
			Update(C + 1, -D);
		}
		else if (A == 2)
		{
			cin >> B;
			cout << GetValue(B) << '\n';
		}
	}
	return 0;
}

*/
