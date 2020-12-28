#include "pch.h"
#include <iostream>
#include <string.h>
#include <algorithm>

using namespace std;
int N = 0, Board[301], Dp[301];
int main()
{
	memset(Dp, 0, sizeof(Dp));
	cin >> N;
	for (int i = 1; i <= N; ++i)
		cin >> Board[i];

	Dp[1] = Board[1];
	Dp[2] = max(Board[1] + Board[2], Board[2]);
	Dp[3] = max(Board[1] + Board[3], Board[2] + Board[3]);
	for (int i = 4; i <= N; ++i)
		Dp[i] = max(Dp[i - 2] + Board[i], Dp[i - 3] + Board[i - 1] + Board[i]);

	cout << Dp[N] << '\n';
	return 0;
}


//using namespace std;
//const int MMIN = -1e10;
//int N = 0, Board[301], Dp[301];
//
//int Solve(int Idx, int Val, int Seq)
//{
//
//	if (Idx == N) return Val;
//
//	int& Ret = Dp[Idx];
//	if (Ret != -1) return Ret;
//
//	Ret = Val;
//	if (Seq < 2 && Idx + 1 <= N)
//		Ret = max(Ret, Solve(Idx + 1, Val + Board[Idx + 1], Seq + 1));
//	if(Idx + 2 <= N)
//		Ret = max(Ret, Solve(Idx + 2, Val + Board[Idx + 2], 1));
//	return Ret;
//}
//
//int main()
//{
//	memset(Dp, -1, sizeof(Dp)); 
//	cin >> N;
//	for (int i = 1; i <= N; ++i)
//		cin >> Board[i];
//
//	int R = Solve(0, 0, 0);
//	cout << R << '\n';
//
//	return 0;
//}

//using namespace std;
//const int MMIN = -1e10;
//int N = 0, Board[301], Dp[301];
//
//int Solve(int Idx, int Val)
//{
//	if (Idx > N - 1) return MMIN;
//
//	int& Ret = Dp[Idx];
//	if (Ret != 0) return Ret;
//
//	Ret = Val;
//	Ret = max(Ret, Solve(Idx + 3, Val + Board[Idx + 1] + Board[Idx + 3]));
//	Ret = max(Ret, Solve(Idx + 3, Val + Board[Idx + 2] + Board[Idx + 3]));
//	return Ret;
//}
//
//int main()
//{
//	memset(Dp, 0, sizeof(Dp));
//	cin >> N;
//	for (int i = 0; i < N; ++i)
//		cin >> Board[i];
//
//	int R = Solve(0, Board[0]);
//	if (N == 1) cout << Board[0];
//	else if (N == 2) cout << Board[1];
//	else cout << R << '\n';
//	return 0;
//}

