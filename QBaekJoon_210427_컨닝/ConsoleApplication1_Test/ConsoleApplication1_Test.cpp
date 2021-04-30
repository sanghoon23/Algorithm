#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <string.h>

using namespace std;
#define FASTIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define PII pair<int, int>
int T, N, M, Board[11][11], Dp[11][1 << 10];
string Input;

bool Adj_Check(int Bit, int W)
{
	for (int i = 0; i < W - 1; ++i)
	{
		int Val = (3 << i);
		if ((Bit & Val) == Val) return false;
	}
	return true;
}

bool Seat_Check(int Board[][11], int Row, int Bit)
{
	int A = 0;
	for (int j = 0; j < M; ++j)
		if (Board[Row][j] && (Bit & (1 << j)))
			return true;

	return false;
}

bool Fwd_Check(int Bit, int FBit, int W)
{
	for (int i = 0; i < W; ++i)
	{
		if (((FBit & (1 << i))))
		{
			if ((Bit & (1 << i + 1))) return false;
			if ((Bit & 1 << i - 1) && i > 0) return false;
		}
	}
	return true;
}

int main()
{
	FASTIO;
	cin >> T;
	while (T--)
	{
		cin >> N >> M;
		memset(Dp, 0, sizeof(Dp));
		memset(Board, 0, sizeof(Board));
		for (int j = 1; j <= N; ++j)
		{
			cin >> Input;
			for (int i = 0; i < M; ++i)
			{
				if (Input[i] == '.') Board[j][i] = 0;
				else Board[j][i] = 1;
			}
		}

		vector<PII> Bits_Set;
		for (int Bit = 0; Bit < (1 << M); ++Bit)
		{
			if (Adj_Check(Bit, M))
			{
				int Cnt = 0;
				for (int i = 0; i < M; ++i)
				{
					if ((1 << i) & Bit) ++Cnt;
				}
				Bits_Set.push_back({ Bit, Cnt });
			}
		}

		int Answer = 0;
		for (int i = 1; i <= N; ++i)
		{
			for (PII Bit : Bits_Set)
			{
				if (Seat_Check(Board, i, Bit.first)) continue;
				for (PII FBit : Bits_Set)
				{
					if (Fwd_Check(Bit.first, FBit.first, M))
					{
						Dp[i][Bit.first] = max(Dp[i][Bit.first], Dp[i - 1][FBit.first] + Bit.second);
					}
					Answer = max(Answer, Dp[i][Bit.first]);
				}
			}
		}
		cout << Answer << '\n';
	}
	return 0;
}

//using namespace std;
//#define FASTIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
//int T, N, M, Board[11][11], Dp[11][11];
//string Input;
//int main()
//{
//	FASTIO;
//	cin >> T;
//	while (T--)
//	{
//		cin >> N >> M;
//		memset(Dp, 0, sizeof(Dp));
//		memset(Board, 0, sizeof(Dp));
//		for (int j = 1; j <= N; ++j)
//		{
//			cin >> Input;
//			for (int i = 1; i <= M; ++i)
//			{
//				if (Input[i - 1] == '.') Board[j][i] = 1;
//				else Board[j][i] = 0;
//			}
//		}
//
//		for (int j = 1; j <= N; ++j)
//		{
//			for (int i = 1; i <= M; ++i)
//			{
//				if (Board[j][i]) Dp[j][i] = Dp[j - 1][i] + 1;
//				else Dp[j][i] = Dp[j - 1][i];
//			}
//		}
//
//		int Answer = 0;
//		for (int j = 0; j < 2; ++j)
//		{
//			int Calc = 0;
//			for (int i = 1 + j; i <= M; i += 2)
//			{
//				Calc += Dp[N][i];
//			}
//			Answer = max(Answer, Calc);
//		}
//		cout << Answer << '\n';
//	}
//	return 0;
//}

