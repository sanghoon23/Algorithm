#include "pch.h"
#include <iostream>
#include <algorithm>
using namespace std;
int N = 0, Board[3], MMax = -1e8, MMin = 1e8, MaxDp[3], BeMaxDp[3], MinDp[3], BeMinDp[3];
int main()
{
	cin >> N;
	cin >> Board[0] >> Board[1] >> Board[2];
	MaxDp[0] = MinDp[0] = Board[0];
	MaxDp[1] = MinDp[1] = Board[1];
	MaxDp[2] = MinDp[2] = Board[2];
	for (int i = 1; i < N; ++i)
	{
		cin >> Board[0] >> Board[1] >> Board[2];
		BeMaxDp[0] = MaxDp[0], BeMaxDp[1] = MaxDp[1], BeMaxDp[2] = MaxDp[2];
		BeMinDp[0] = MinDp[0], BeMinDp[1] = MinDp[1], BeMinDp[2] = MinDp[2];

		MaxDp[0] = max(BeMaxDp[0] + Board[0], BeMaxDp[1] + Board[0]);
		MaxDp[1] = max(BeMaxDp[0] + Board[1], max(BeMaxDp[1] + Board[1], BeMaxDp[2] + Board[1]));
		MaxDp[2] = max(BeMaxDp[2] + Board[2], BeMaxDp[1] + Board[2]);

		MinDp[0] = min(BeMinDp[0] + Board[0], BeMinDp[1] + Board[0]);
		MinDp[1] = min(BeMinDp[0] + Board[1], min(BeMinDp[1] + Board[1], BeMinDp[2] + Board[1]));
		MinDp[2] = min(BeMinDp[2] + Board[2], BeMinDp[1] + Board[2]);
	}
	MMax = max(MaxDp[0], max(MaxDp[1], MaxDp[2]));
	MMin = min(MinDp[0], min(MinDp[1], MinDp[2]));
	cout << MMax << " " << MMin;
	return 0;
}


////@메모리 초과
//int N = 0, Board[100001][3], MMax = -1e8, MMin = 1e8;
//int Dp[100001][3];
//int Solve(int Idx, int L, bool bMax)
//{
//	if (Idx >= N) return 0;
//
//	int& Ret = Dp[Idx][L];
//	if (Ret != -1) return Ret;
//
//	int C = Board[Idx][L];
//
//	if (bMax == false) Ret = 1e8;
//	if (L == 0)
//	{
//		(bMax == true)
//			? Dp[Idx][L] = max(Dp[Idx][L], max(Solve(Idx + 1, L, 1) + C, Solve(Idx + 1, L + 1, 1) + C))
//			: Dp[Idx][L] = min(Dp[Idx][L], min(Solve(Idx + 1, L, 0) + C, Solve(Idx + 1, L + 1, 0) + C));
//	}
//	else if (L == 1)
//	{
//		(bMax == true)
//			? Dp[Idx][L] = max(Dp[Idx][L], max(Solve(Idx + 1, L, 1) + C, max(Solve(Idx + 1, L + 1, 1) + C, Solve(Idx + 1, L - 1, 1) + C)))
//			: Dp[Idx][L] = min(Dp[Idx][L], min(Solve(Idx + 1, L, 0) + C, min(Solve(Idx + 1, L + 1, 0) + C, Solve(Idx + 1, L - 1, 0) + C)));
//	}
//	else if (L == 2)
//	{
//		(bMax == true)
//			? Dp[Idx][L] = max(Dp[Idx][L], max(Solve(Idx + 1, L, 1) + C, Solve(Idx + 1, L - 1, 1) + C))
//			: Dp[Idx][L] = min(Dp[Idx][L], min(Solve(Idx + 1, L, 0) + C, Solve(Idx + 1, L - 1, 0) + C));
//	}
//	return Ret;
//}
//
//int main()
//{
//	cin >> N;
//	for (int i = 0; i < N; ++i)
//		cin >> Board[i][0] >> Board[i][1] >> Board[i][2];
//
//	memset(Dp, -1, sizeof(Dp));
//	for (int i = 0; i < 3; ++i)
//		MMax = max(MMax, Solve(0, i, 1));
//
//	memset(Dp, -1, sizeof(Dp));
//	for (int i = 0; i < 3; ++i)
//		MMin = min(MMin, Solve(0, i, 0));
//
//	cout << MMax << " " << MMin;
//	return 0;
//}

