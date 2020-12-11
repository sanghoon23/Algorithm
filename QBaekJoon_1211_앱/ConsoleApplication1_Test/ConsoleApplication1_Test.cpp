#include "pch.h"
#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>

using namespace std;

#define MAX 100001
int N = 0, M = 0;
int Dp[101][MAX] = { 0, };
vector<int> Memory;
vector<int> Price;
int Solve(int Index, int Pri)
{
	if (Index >= N) return 0;
	int& Ret = Dp[Index][Pri];
	if (Ret != -1) return Ret;

	Ret = Solve(Index + 1, Pri);

	if (Pri >= Price[Index])
		Ret = max(Ret, Memory[Index] + Solve(Index + 1, Pri - Price[Index]));

	return Ret;
}
int main()
{
	cin >> N >> M;
	memset(Dp, -1, sizeof(Dp));
	Memory.resize(N);
	for (int i = 0; i < N; ++i)
		cin >> Memory[i];

	Price.resize(N);
	for (int i = 0; i < N; ++i)
		cin >> Price[i];

	int P = 0;
	while (1)
	{
		if ((Solve(0, P)) >= M)
		{
			cout << P;
			break;
		}
		++P;
	}
	return 0;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//@참고

//int n, m, d[110], c[110], dp[110][10101];
//
//int main()
//{
//	scanf("%d %d", &n, &m);
//	for (int i = 1; i <= n; i++) scanf("%d", &d[i]);
//	for (int i = 1; i <= n; i++) scanf("%d", &c[i]);
//
//	for (int i = 1; i <= n; i++)
//	{
//		for (int j = 0; j < 10101; j++)
//		{
//			dp[i][j] = dp[i - 1][j];
//			if (j >= c[i]) dp[i][j] = max(dp[i][j], dp[i - 1][j - c[i]] + d[i]);
//		}
//	}
//
//	for (int j = 0; j < 10101; j++)
//	{
//		if (dp[n][j] >= m)
//		{
//			printf("%d", j);
//			return 0;
//		}
//	}
//}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//@삽질
//#define MAX 100001
//#define Pii pair<int, int>
//int N = 0, M = 0;
//int Dp[MAX] = { 0, };
//vector<Pii> Apps;
//void DFS(int Index, int Memo, int Pri)
//{
//	if (Memo >= M)
//	{
//		Dp[Pri] = 1;
//		return;
//	}
//	for (int i = Index + 1; i < N; ++i)
//	{
//		if (Dp[Pri + Apps[i].second] == 1) break;
//
//		DFS(i, Memo + Apps[i].first, Pri + Apps[i].second);
//	}
//}
//int main()
//{
//	cin >> N >> M;
//	memset(Dp, -1, sizeof(Dp));
//	vector<int> Memory(N);
//	for (int i = 0; i < N; ++i)
//		cin >> Memory[i];
//
//	vector<int> Price(N);
//	for (int i = 0; i < N; ++i)
//		cin >> Price[i];
//
//	for (int i = 0; i < N; ++i)
//		Apps.push_back({ Memory[i], Price[i] });
//
//	sort(Apps.begin(), Apps.end());
//	for (int i = 0; i < N; ++i)
//		DFS(i, Apps[i].first, Apps[i].second);
//	
//	int Answer = 0;
//	for (int i = 1; i <= MAX; ++i)
//	{
//		if (Dp[i] == 1)
//		{
//			Answer = i;
//			break;
//		}
//	}
//	cout << Answer;
//	return 0;
//}

