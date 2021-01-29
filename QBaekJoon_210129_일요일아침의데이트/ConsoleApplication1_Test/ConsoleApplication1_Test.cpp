#include "pch.h"
#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <string.h>

using namespace std;

/*@210129
여기서 중요한 것은 값을 과정에서 구하지 말고
미리 구할 수 있는 값들은 미리 구해서 사용하자. ex) FindAround
첫번째 코드와 밑의 삽질 코드는 이 차이밖에 없었는데,
우선순위 큐 안에서 주변의 'g' 를 구하는 과정에서 내가 파악하지 못한 다른 상황이 발생하는 것으로 추측됨.
이런 과정은 미묘하고 찾기 어려워서 시간이 오래 걸릴거 같다. 지금도 굉장히 시간이 오래 걸렸다.
사전에 방지하자.
*/

#define FASTIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define PII pair<int, int>
#define MSIZE 51
#define MMAX 987654321
int N, M, Around[MSIZE][MSIZE];
char Board[MSIZE][MSIZE];
PII Start, End;
PII Dir[4] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };

struct Node
{
	int SC = 0, Y = 0, X = 0;
	Node(int SCC, int YY, int XX)
	{
		SC = SCC;
		Y = YY;
		X = XX;
	}
};

struct Comp { bool operator()(pair<int, Node> A, pair<int, Node> B) { return A.first > B.first; } };

void FindAround(int Y, int X)
{
	for (int k = 0; k < 4; ++k)
	{
		int YY = Y + Dir[k].first, XX = X + Dir[k].second;
		if (YY < 0 || YY >= N || XX < 0 || XX >= M) continue;
		if (Board[YY][XX] == 'g') { Around[Y][X] = 1; break; }
	}
}

int main()
{
	FASTIO;
	memset(Board, 0, sizeof(Board));
	cin >> N >> M;
	for (int j = 0; j < N; ++j)
	{
		string Str; cin >> Str;
		for (int i = 0; i < M; ++i)
		{
			Board[j][i] = Str[i];
			if (Board[j][i] == 'S') Start = { j, i };
			else if (Board[j][i] == 'F') End = { j, i };
		}
	}

	for (int j = 0; j < N; ++j)
		for (int i = 0; i < M; ++i)
			FindAround(j, i);

	vector<vector<PII>> Dist(N + 1, vector<PII>(M + 1, { MMAX, MMAX }));
	Dist[Start.first][Start.second].first = 0;
	Dist[Start.first][Start.second].second = 0;
	priority_queue<pair<int, Node>, vector<pair<int, Node>>, Comp> PQ;
	PQ.push({ 0, Node(0, Start.first, Start.second) });
	while (!PQ.empty())
	{
		int SS = PQ.top().first, SC = PQ.top().second.SC, Y = PQ.top().second.Y, X = PQ.top().second.X;
		PQ.pop();

		for (int k = 0; k < 4; ++k)
		{
			int YY = Y + Dir[k].first, XX = X + Dir[k].second;
			if (YY < 0 || YY >= N || XX < 0 || XX >= M) continue;

			int NextSS = SS, NextSC = SC;
			if (Board[YY][XX] == 'g') ++NextSS;
			else if(Board[YY][XX] == '.') NextSC += Around[YY][XX];

			if (Dist[YY][XX].first > NextSS)
			{
				Dist[YY][XX].first = NextSS;
				Dist[YY][XX].second = NextSC;
				PQ.push({ NextSS, Node(NextSC, YY, XX) });
			}
			else if (Dist[YY][XX].first == NextSS && Dist[YY][XX].second > NextSC)
			{
				Dist[YY][XX].second = NextSC;
				PQ.push({ NextSS, Node(NextSC, YY, XX) });
			}
		}
	}
	cout << Dist[End.first][End.second].first << " " << Dist[End.first][End.second].second << '\n';
	return 0;
}


///////////////////////////////////////////////////////////////////////////////////////////////////////////
//@삽질
//#define FASTIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
//#define PII pair<int, int>
//#define MSIZE 51
//#define MMAX 987654321
//int N, M;
//char Board[MSIZE][MSIZE];
//PII Start, End;
//PII Dir[4] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
//
//struct Node
//{
//	int SC = 0, Y = 0, X = 0;
//	Node(int SCC, int YY, int XX)
//	{
//		SC = SCC;
//		Y = YY;
//		X = XX;
//	}
//};
//
//struct Comp { bool operator()(pair<int, Node> A, pair<int, Node> B) { return A.first > B.first; } };
//
//int main()
//{
//	FASTIO;
//	cin >> N >> M;
//	for (int j = 0; j < N; ++j)
//	{
//		for (int i = 0; i < M; ++i)
//		{
//			char Input; cin >> Input;
//			Board[j][i] = Input;
//			if (Input == 'F') End = { j, i };
//			else if (Input == 'S') Start = { j, i };
//		}
//	}
//
//	vector<vector<PII>> Dist(N + 1, vector<PII>(M + 1, { MMAX, MMAX })); //@차있는칸, 인접한칸
//	Dist[Start.first][Start.second].first = 0;
//	Dist[Start.first][Start.second].second = 0;
//
//	priority_queue<pair<int, Node>, vector<pair<int, Node>>, Comp> PQ; //@차있는칸(SS),인접한칸(SC), Y,X
//	PQ.push({ 0, Node(0, Start.first, Start.second) });
//	while (!PQ.empty())
//	{
//		int SS = (PQ.top().first), SC = PQ.top().second.SC, Y = PQ.top().second.Y, X = PQ.top().second.X;
//		PQ.pop();
//
//		for (int k = 0; k < 4; ++k)
//		{
//			int YY = Y + Dir[k].first, XX = X + Dir[k].second;
//			if (YY < 0 || YY >= N || XX < 0 || XX >= M) continue;
//
//			int NextSS = SS;
//			int NextSC = SC;
//			if (Board[YY][XX] == 'g') ++NextSS;
//			else if(Board[YY][XX] == '.')
//			{
//				for (int j = 0; j < 4; ++j)
//				{
//					int SCYY = YY + Dir[j].first, SCXX = XX + Dir[j].second;
//					if (SCYY < 0 || SCYY >= N || SCXX < 0 || SCXX >= M) continue;
//					if (Board[SCYY][SCXX] == 'g') { ++NextSC; break; }
//				}
//			}
//
//			if (Dist[YY][XX].first > NextSS)
//			{
//				Dist[YY][XX].first = NextSS;
//				Dist[YY][XX].second = NextSC;
//				PQ.push({ NextSS, Node(NextSC, YY, XX) });
//			}
//			else if (Dist[YY][XX].first == NextSS && Dist[YY][XX].second > NextSC)
//			{
//				Dist[YY][XX].second = NextSC;
//				PQ.push({ NextSS, Node(NextSC, YY, XX) });
//			}
//		}
//	}
//	cout << Dist[(End.first)][(End.second)].first << " " << Dist[(End.first)][(End.second)].second - 1 << '\n';
//	return 0;
//}

