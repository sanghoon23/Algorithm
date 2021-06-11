#include "pch.h"
#include <iostream>
#include <vector>

using namespace std;
#define FASTIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define PII pair<int, int>
int N, M, Parent[1001];

int Find(int A)
{
	if (Parent[A] == A) return A;
	return Parent[A] = Find(Parent[A]);
}

void Marge(int A, int B)
{
	int AA = Find(A), BB = Find(B);
	if (AA != BB) Parent[AA] = BB;
}

int main()
{
	FASTIO;
	cin >> N >> M;

	vector<PII> LL, RR;
	for (int i = 0; i < M + 1; ++i)
	{
		int F, S, W; cin >> F >> S >> W;
		if (W == 0) LL.push_back({ F, S });
		else RR.push_back({ F, S });
	}

	int LL_Calc = 0, RR_Calc = 0;
	for (int i = 0; i <= N; ++i) Parent[i] = i;
	for (int i = 0; i < LL.size(); ++i)
	{
		if (Find(LL[i].first) != Find(LL[i].second))
		{
			Marge(LL[i].first, LL[i].second);
			++LL_Calc;
		}
	}

	for (int i = 0; i <= N; ++i) Parent[i] = i;
	for (int i = 0; i < RR.size(); ++i)
	{
		if (Find(RR[i].first) != Find(RR[i].second)) Marge(RR[i].first, RR[i].second);
	}
	for (int i = 0; i < LL.size(); ++i)
	{
		if (Find(LL[i].first) != Find(LL[i].second))
		{
			Marge(LL[i].first, LL[i].second);
			++RR_Calc;
		}
	}

	cout << (LL_Calc * LL_Calc) - (RR_Calc * RR_Calc);
	return 0;
}

