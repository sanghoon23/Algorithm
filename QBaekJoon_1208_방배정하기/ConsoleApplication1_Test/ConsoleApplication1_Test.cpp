#include "pch.h"
#include <iostream>
#include <vector>

using namespace std;

//@DP
//...
int Dp[501];
int main()
{
	int A, B, C, N;
	cin >> A >> B >> C >> N;
	Dp[0] = 1;
	for (int i = 0; i < N; i++)
	{
		if (!Dp[i]) continue;
		Dp[i + A] = Dp[i + B] = Dp[i + C] = 1;
	}
	cout << Dp[N];
}

//bool Check[301] = { false, };
//
//int Insil[3] = { 0, };
//int Div[3] = { 0, };
//int Num = 0;
//int main()
//{
//	cin >> Insil[0] >> Insil[1] >> Insil[2] >> Num;
//
//	for (int i = 0; i < 3; ++i)
//		Div[i] = Num / Insil[i];
//
//	bool bFind = false;
//	for (int k = 0; k <= Div[0]; ++k)
//	{
//		for (int j = 0; j <= Div[1]; ++j)
//		{
//			for (int i = 0; i <= Div[2]; ++i)
//			{
//				if (k * Insil[0] + j * Insil[1] + i * Insil[2] == Num)
//				{
//					bFind = true;
//					break;
//				}
//			}
//		}
//	}
//
//	if (bFind) cout << 1;
//	else cout << 0;
//
//	return 0;
//}
