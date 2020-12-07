#include "pch.h"
#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int T = 0, N = 0, Answer = 0;
bool Visited[3001] = { false, };
vector<int> Node[3001];

void DFS(int Index)
{
	Visited[Index] = true;
	for (int i = 0; i < Node[Index].size(); ++i)
	{
		if (Visited[Node[Index][i]] == false)
		{
			DFS(Node[Index][i]);
		}
	}
}

int main()
{
	int Data[3001][3] = { 0, };

	cin >> T;
	for (int k = 0; k < T; ++k)
	{
		cin >> N;
		Answer = 0;

		memset(Visited, false, sizeof(Visited));

		for (int i = 0; i < N; ++i)
		{
			Node[i].clear(); //@Clear
			cin >> Data[i][0];
			cin >> Data[i][1];
			cin >> Data[i][2];
			
			if (i != 0)
			{
				for (int s = 0; s < i; ++s)
				{
					if ((Data[s][0] - Data[i][0]) * (Data[s][0] - Data[i][0])
						+ (Data[s][1] - Data[i][1]) * (Data[s][1] - Data[i][1])
						<= (Data[s][2] + Data[i][2]) * (Data[s][2] + Data[i][2]))
					{
						Node[i].push_back(s);
						Node[s].push_back(i);
					}
				}
			}
		}

		//@DFS
		for (int j = 0; j < N; ++j)
		{
			if (Visited[j] == false)
			{
				DFS(j);
				++Answer;
			}
		}

		cout << Answer << endl;
	}
	return 0;
}


//@배울게 많은 코드다..

//#include <iostream>
//#define pow(a) (a)*(a)
//using namespace std;
//
//int x[3001], y[3001], r[3001], p[3001];
//
//int getp(int k) {
//	if (k == p[k])
//		return k;
//	return p[k] = getp(p[k]);
//}
//
//bool isable(int a, int b) {
//	return pow(x[a] - x[b]) + pow(y[a] - y[b]) <= pow(r[a] + r[b]);
//}
//
//int main() {
//	int T, n;
//	scanf("%d", &T);
//	for (int t = 0; t < T; t++) {
//		scanf("%d", &n);
//		for (int i = 0; i < n; i++) {
//			scanf("%d %d %d", x + i, y + i, r + i);
//			p[i] = i;
//		}
//		for (int i = 0; i < n; i++)
//			for (int j = i + 1; j < n; j++)
//				if (isable(i, j))
//					p[getp(j)] = getp(i);
//
//		int ans = 0;
//		for (int i = 0; i < n; i++)
//			if (i == p[i])
//				ans++;
//
//		printf("%d\n", ans);
//	}
//	return 0;
//}





//int T = 0, N = 0, Y = 0, X = 0, Length = 0, Answer = 0;
//bool Visited[5002][5002] = { false, };
//vector<pair<int, int>> Node;
//pair<int, int> Dir[8] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1}, {-1, -1}, {1, -1}, {-1, 1}, {1, 1} };
//void InitDFS(int Y, int X, int L, int Count)
//{
//	if (Count > L) return;
//	Visited[Y][X] = true;
//
//	for (int i = 0; i < 8; ++i)
//	{
//		int F = Y + Dir[i].first, S = X + Dir[i].second;
//		if (F < 0 || F >= 5002 || S < 0 || S >= 5002) continue;
//
//		if (Visited[F][S] == false)
//		{
//			InitDFS(F, S, L, Count + 1);
//		}
//	}
//}
//
//void DFS(int Y, int X)
//{
//	Visited[Y][X] = false;
//
//	for (int i = 0; i < 8; ++i)
//	{
//		int F = Y + Dir[i].first, S = X + Dir[i].second;
//		if (F < 0 || F >= 5002 || S < 0 || S >= 5002) continue;
//
//		if (Visited[F][S] == true)
//		{
//			DFS(F, S);
//		}
//	}
//}
//
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin >> T;
//	for (int k = 0; k < T; ++k)
//	{
//		cin >> N;
//		Node.clear();
//		for (int i = 0; i <= 5002; ++i)
//			fill(Visited[i], Visited[i] + 5002, false);
//
//		Answer = N;
//		for (int i = 0; i < N; ++i)
//		{
//			cin >> Y >> X >> Length;
//			Node.push_back({ Y, X });
//			InitDFS(Y, X, Length, 0);
//		}
//
//		for (int j = 0; j < Node.size(); ++j)
//		{
//			if (Visited[Node[j].first][Node[j].second] == false)
//			{
//				--Answer;
//			}
//			else
//			{
//				DFS(Node[j].first, Node[j].second);
//			}
//		}
//		cout << Answer << endl;
//	}
//	cout << endl;
//
//	return 0;
//}

