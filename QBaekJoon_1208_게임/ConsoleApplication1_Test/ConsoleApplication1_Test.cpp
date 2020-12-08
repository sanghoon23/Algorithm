#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int Row = 0, Col = 0, Answer = 0;
pair<int, int> Dir[4] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };
bool Visited[52][52] = { false, };
int Dp[52][52] = { 0, };
vector<string> Board;
int DFS(int Y, int X, int Count)
{
	if (X < 0 || X >= Col || Y < 0 || Y >= Row || Board[Y][X] == 'H') return 0;
	if (Visited[Y][X] == true) //@Loop 체크
	{
		cout << -1 << endl;
		exit(0);
	}
	if (Dp[Y][X]) return Dp[Y][X]; //@다시 들어오는 것을 막아준다.

	Visited[Y][X] = true;
	for (int i = 0; i < 4; ++i)
	{
		int MulY = Dir[i].first * (Board[Y][X] - 48), MulX = Dir[i].second * (Board[Y][X] - 48);
		int YY = Y + MulY, XX = X + MulX;
		Dp[Y][X] = max(Dp[Y][X], DFS(Y + MulY, X + MulX, Count + 1) + 1);
	}
	Visited[Y][X] = false;

	return Dp[Y][X];
}

int main()
{
	cin >> Row >> Col;
	Board.resize(Row);
	for (int i = 0; i < Row; ++i)
		cin >> Board[i];

	cout << DFS(0, 0, 0);
	return 0;
}

//#define SIZE 52
//#define MAX(X, Y) (X) > (Y) ? (X) : (Y)
//using namespace std;
//
//int map[SIZE][SIZE], dp[SIZE][SIZE], visit[SIZE][SIZE];
//int dx[] = { 0, 0, -1, 1 };
//int dy[] = { -1, 1, 0, 0 };
//int N, M;
//
//int dfs(int x, int y) {
//	if (x < 0 || y < 0 || x >= M || y >= N || !map[y][x]) return 0;
//	if (visit[y][x]) { cout << -1 << endl; exit(0); }
//	if (dp[y][x]) return dp[y][x];
//	visit[y][x] = 1;
//	for (int i = 0; i < 4; i++)
//		dp[y][x] = MAX(dp[y][x], dfs(x + map[y][x] * dx[i], y + map[y][x] * dy[i]) + 1);
//	visit[y][x] = 0;
//	return dp[y][x];
//}
//
//int main(void) {
//	cin >> N >> M;
//	for (int i = 0; i < N; i++)
//		for (int j = 0; j < M; j++) {
//			char c;
//			cin >> c;
//			if (c <= '9') map[i][j] = c - '0';
//		}
//
//	cout << dfs(0, 0) << endl;
//
//	return 0;
//}

