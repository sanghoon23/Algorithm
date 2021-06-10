#include "pch.h"
#include <iostream>
#include <string.h>

using namespace std;
#define FASTIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
int N, K, S, Board[401][401];

int main()
{
	FASTIO;
	cin >> N >> K;
	for (int i = 0; i < K; ++i)
	{
		int F, S; cin >> F >> S;
		Board[F][S] = 1;
	}
	cin >> S;


	for (int k = 1; k <= N; ++k)
		for (int j = 1; j <= N; ++j)
			for (int i = 1; i <= N; ++i)
				if (Board[j][k] && Board[k][i]) Board[j][i] = 1;

	for (int i = 0; i < S; ++i)
	{
		int F, S; cin >> F >> S;
		if (Board[F][S]) cout << -1 << '\n';
		else if (Board[S][F]) cout << 1 << '\n';
		else cout << 0 << '\n';
	}
	return 0;
}

//using namespace std;
//#define FASTIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
//int N, K, S, Board[401][401][2];
//
//int main()
//{
//	FASTIO;
//	cin >> N >> K;
//	for (int i = 0; i < K; ++i)
//	{
//		int F, S; cin >> F >> S;
//		Board[F][S][0] = 1;
//		Board[S][F][1] = 1;
//	}
//	cin >> S;
//
//
//	for (int k = 1; k <= N; ++k)
//		for (int j = 1; j <= N; ++j)
//			for (int i = 1; i <= N; ++i)
//			{
//				if (Board[j][k][0] && Board[k][i][0])
//				{
//					Board[j][i][0] = 1;
//					Board[i][j][1] = 1;
//				}
//			}
//
//	for (int i = 0; i < S; ++i)
//	{
//		int F, S; cin >> F >> S;
//		if (Board[F][S][0]) cout << -1 << '\n';
//		else if (Board[F][S][1]) cout << 1 << '\n';
//		else cout << 0 << '\n';
//	}
//	return 0;
//}

