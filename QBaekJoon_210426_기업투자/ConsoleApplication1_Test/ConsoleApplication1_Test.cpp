#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>

using namespace std;
#define FASTIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
int N, M, Row, Board[301][21], Dp[301][21], Ord[301][21];

int main()
{
	FASTIO;
	cin >> N >> M;
	for (int j = 1; j <= N; ++j)
	{
		cin >> Row;
		for (int i = 1; i <= M; ++i)
			cin >> Board[Row][i];
	}

	for (int j = 1; j <= M; ++j)
	{
		for (int i = 1; i <= N; ++i)
		{
			//Dp[i][j] = max(Dp[i][j - 1], Board[i][j]);
			for (int k = 0; k <= i; ++k)
			{
				//Dp[i][j] = max(Dp[i][j], Dp[k][j - 1] + Board[i - k][j]);
				if (Dp[i][j] < Dp[k][j - 1] + Board[i - k][j])
				{
					Dp[i][j] = Dp[k][j - 1] + Board[i - k][j];
					Ord[i][j] = i - k;
				}
			}
		}
	}
	cout << Dp[N][M] << '\n';

	vector<int> Result;
	int Calc = N;
	for (int j = M; j > 0; --j)
	{
		Result.push_back(Ord[Calc][j]);
		Calc -= Ord[Calc][j];
	}
	reverse(Result.begin(), Result.end());
	for (int i = 0; i < Result.size(); ++i) cout << Result[i] << " ";
	return 0;
}

/*
			Dp[i][j] = max(Dp[i][j], Board[i][j]);
			for (int k = 0; k <= i - 1; ++k)
			{
				Dp[i][j] = max(Dp[i][j], Board[k][j] + Dp[i - k][j - 1]);
			}

*/

//using namespace std;
//#define FASTIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
//#define MMIN -987654321
//int N, M, Row, Board[301][21], Dp[301][21];
//
//int Solve(int Mny, int Cnt)
//{
//	if (Cnt > M)
//	{
//		if (Mny == N) return 0;
//		else return MMIN;
//	}
//
//	int& Ret = Dp[Mny][Cnt];
//	if (Ret != -1) return Ret;
//	Ret = 0;
//
//	for (int j = 0; j <= N; ++j)
//	{
//		if (Mny + j > N) break;
//		Ret = max(Ret, Solve(Mny + j, Cnt + 1) + Board[j][Cnt]);
//	}
//	return Ret;
//}
//
//int main()
//{
//	FASTIO;
//	memset(Dp, -1, sizeof(Dp));
//	cin >> N >> M;
//	for (int j = 1; j <= N; ++j)
//	{
//		cin >> Row;
//		for (int i = 1; i <= M; ++i)
//			cin >> Board[Row][i];
//	}
//
//	int Result = Solve(0, 1);
//	cout << Result << '\n';
//	int Calc = Result;
//	vector<int> RVec;
//	for (int j = M; j > 0; --j)
//	{
//		for (int i = 0; i <= N; ++i)
//		{
//			if (Dp[i][j] == Calc)
//			{
//				RVec.push_back(i);
//				Calc -= Board[i][j];
//				break;
//			}
//		}
//	}
//	reverse(RVec.begin(), RVec.end());
//	for (int i = 0; i < RVec.size(); ++i) cout << RVec[i] << " ";
//	return 0;
//}


/*
	if (Cnt == M) Ret = Board[N - Mny][Cnt];
	else
	{
		for (int j = 1; j <= N; ++j)
		{
			Ret = max(Ret, Solve(Mny + j, Cnt + 1) + Board[j][Cnt]);
		}
	}
*/


//using namespace std;
//#define FASTIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
//int N, M, Board[21][301], Dp[21][301], Idx[21][301];
//vector<int> Ans;
//int Solve(int Cnt, int Mny)
//{
//	if (Cnt > M) return 0;
//
//	int& Ret = Dp[Cnt][Mny];
//	if (Ret != -1) return Ret;
//	Ret = 0;
//	int MMM = 0;
//	for (int j = 0; j <= N; ++j)
//	{
//		if (Mny + j <= N)
//		{
//			int Temp = Ret;
//			Ret = max(Ret, Solve(Cnt + 1, Mny + j) + Board[Cnt][j]);
//			if (Temp != Ret) MMM = Ret;
//		}
//	}
//	Idx[Cnt][Mny] = MMM;
//	return Ret;
//}
//
//int main()
//{
//	FASTIO;
//	memset(Dp, -1, sizeof(Dp));
//	cin >> N >> M;
//	for (int j = 1; j <= N; ++j)
//	{
//		int NN; cin >> NN;
//		for (int i = 1; i <= M; ++i)
//		{
//			cin >> Board[i][j];
//		}
//	}
//	cout << Solve(0, 0) << '\n';
//
//	for (int j = 1; j <= M; ++j)
//	{
//		int MMax = 0, MIdx = 0;
//		for (int i = 0; i <= N; ++i)
//		{
//			if (Dp[j][i] > MMax)
//			{
//				MMax = Dp[j][i];
//				MIdx = Idx[j][i];
//			}
//		}
//		cout << MIdx << " ";
//	}
//	return 0;
//}

