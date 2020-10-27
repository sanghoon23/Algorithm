#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <list>
#include <algorithm>

using namespace std;

//int Temp[51][51] = { 0, };
//int CheckNode[51] = { 10000, };
//int solution(int N, vector<vector<int> > Road, int K)
//{
//	for (int j = 0; j < Road.size(); ++j)
//	{
//		if (Temp[Road[j][0]][Road[j][1]] == 0)
//			Temp[Road[j][0]][Road[j][1]] = Road[j][2];
//		else Temp[Road[j][0]][Road[j][1]] = min(Temp[Road[j][0]][Road[j][1]], Road[j][2]);
//	}
//
//	for (int j = 1; j <= N; ++j)
//	{
//		for (int i = j + 1; i <= N; ++i)
//		{
//			if (Temp[j][i] != 0)
//			{
//				if (j == 1) CheckNode[i] = min(CheckNode[i], Temp[j][i]);
//
//				int Calc = Temp[j][i];
//				for (int k = 1; k <= N; ++k)
//					if (Temp[i][k] != 0) CheckNode[k] = min(CheckNode[k], Temp[i][k] + Calc);
//			}
//		}
//	}
//
//	int Result = 0;
//	for (int i = 2; i <= N; ++i)
//	{
//		if (CheckNode[i] <= K) ++Result;
//	}
//	return Result + 1; //@1은 무조건 됨.
//}

//int Temp[51][51] = { 0, };
//bool Visited[51][51] = { false, };
//int Mini[51] = { 0, };
//int Num = 0, PossibleNum = 0;
//void DFS(int Index, int Current)
//{
//	for (int i = 1; i <= Num; ++i)
//	{
//		if (Visited[Index][i] == false && Temp[Index][i] != 0)
//		{
//			Visited[Index][i] = true, Visited[i][Index] = true;
//			if(Mini[i] > Current + Temp[Index][i])
//				Mini[i] = Current + Temp[Index][i];
//			else if(Mini[i] == 0) Mini[i] = Current + Temp[Index][i];
//
//			DFS(Index + 1, Current + Temp[Index][i]);
//			Visited[Index][i] = false, Visited[i][Index] = false;
//		}
//	}
//}

//int Temp[6][6] = { 0, };
//int Dp[6][6] = { 0, };
//int solution(int N, vector<vector<int> > Road, int K)
//{
//	for (int j = 0; j < Road.size(); ++j)
//	{
//		if (Temp[Road[j][0]][Road[j][1]] == 0)
//		{
//			Temp[Road[j][0]][Road[j][1]] = Road[j][2];
//			Temp[Road[j][1]][Road[j][0]] = Road[j][2];
//		}
//		else
//		{
//			Temp[Road[j][0]][Road[j][1]] = min(Temp[Road[j][0]][Road[j][1]], Road[j][2]);
//			Temp[Road[j][1]][Road[j][0]] = min(Temp[Road[j][1]][Road[j][0]], Road[j][2]);
//		}
//	}
//
//	for (int j = 2; j <= N; ++j)
//	{
//		Dp[j][1] = Temp[1][j];
//		if (Temp[1][j] != 0)
//		{
//			for (int i = j + 1; i <= N; ++i)
//			{
//				if (Temp[i][j] != 0)
//				{
//					if(Dp[i][j] != 0 && Dp[i][j] > Temp[i][j] + Temp[1][j])
//						Dp[i][j] = Temp[i][j] + Temp[1][j];
//					else Dp[i][j] = Temp[i][j] + Temp[1][j];
//
//					for (int k = j + 1; k <= i; ++k)
//					{
//						if(Dp[i][k] != 0 && Dp[i][k] > Dp[i][j] + Temp[i][k])
//							Dp[i][k] = Dp[i][j] + Temp[i][k];
//						else Dp[i][k] = Dp[i][j] + Temp[i][k];
//					}
//				}
//			}
//		}
//	}
//
//	int Result = 0;
//	for (int j = 1; j <= N; ++j)
//	{
//		for (int i = 1; i <= j - 1; ++i)
//		{
//			if (Dp[j][i] <= K && Dp[j][i] != 0)
//			{
//				++Result;
//				break;
//			}
//		}
//	}
//
//	return Result + 1;
//}

//int Temp[6][6] = { 0, };
//int Dp[6][6] = { 0, };
//int solution(int N, vector<vector<int> > Road, int K)
//{
//	for (int j = 0; j < Road.size(); ++j)
//	{
//		if (Temp[Road[j][0]][Road[j][1]] == 0)
//		{
//			Temp[Road[j][0]][Road[j][1]] = Road[j][2];
//			Temp[Road[j][1]][Road[j][0]] = Road[j][2];
//		}
//		else
//		{
//			Temp[Road[j][0]][Road[j][1]] = min(Temp[Road[j][0]][Road[j][1]], Road[j][2]);
//			Temp[Road[j][1]][Road[j][0]] = min(Temp[Road[j][1]][Road[j][0]], Road[j][2]);
//		}
//	}
//
//	for (int j = 2; j <= N; ++j)
//	{
//		Dp[j][1] = Temp[1][j];
//		Dp[1][j] = Temp[1][j];
//		if (Temp[1][j] != 0)
//		{
//			for (int i = j + 1; i <= N; ++i)
//			{
//				if (Temp[i][j] != 0)
//				{
//					if (Dp[i][j] != 0 && Dp[i][j] > Temp[i][j] + Temp[1][j])
//					{
//						Dp[i][j] = Temp[i][j] + Temp[1][j];
//						Dp[j][i] = Temp[i][j] + Temp[1][j];
//					}
//					else
//					{
//						Dp[i][j] = Temp[i][j] + Temp[1][j];
//						Dp[j][i] = Temp[i][j] + Temp[1][j];
//					}
//
//					for (int k = 1; k <= N; ++k)
//					{
//						if (k == i) continue;
//
//						if (Dp[i][k] != 0 && Dp[i][k] > Dp[i][j] + Temp[i][k])
//						{
//							Dp[i][k] = Dp[i][j] + Temp[i][k];
//							Dp[k][i] = Dp[i][j] + Temp[i][k];
//						}
//						else
//						{
//							Dp[i][k] = Dp[i][j] + Temp[i][k];
//							Dp[k][i] = Dp[i][j] + Temp[i][k];
//						}
//					}
//				}
//			}
//		}
//	}
//
//	int Result = 0;
//	for (int j = 1; j <= N; ++j)
//	{
//		for (int i = 1; i <= N; ++i)
//		{
//			if (Dp[j][i] <= K && Dp[j][i] != 0)
//			{
//				++Result;
//				break;
//			}
//		}
//	}
//
//	return Result + 1;
//}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//@BFS

//int Temp[51][51] = { 0, };
//bool Visited[51][51] = { false, };
//int CheckNode[51] = { 0, };
//int solution(int N, vector<vector<int> > Road, int K)
//{
//	for (int j = 0; j < Road.size(); ++j)
//	{
//		if (Temp[Road[j][0]][Road[j][1]] != 0)
//		{
//			if (Temp[Road[j][0]][Road[j][1]] > Road[j][2])
//			{
//				Temp[Road[j][0]][Road[j][1]] = Road[j][2];
//				Temp[Road[j][1]][Road[j][0]] = Road[j][2];
//			}
//		}
//		else
//		{
//			Temp[Road[j][0]][Road[j][1]] = Road[j][2];
//			Temp[Road[j][1]][Road[j][0]] = Road[j][2];
//		}
//	}
//
//	cout << CheckNode[3] << endl;
//	priority_queue<pair<int, int>> Que;
//	Que.push({ 1, 0 });
//
//	while (!Que.empty())
//	{
//		int QueSize = Que.size();
//		while (QueSize--)
//		{
//			pair<int, int> Poped = Que.top();
//			Que.pop();
//			if (CheckNode[Poped.first] != 0)
//			{
//				if (CheckNode[Poped.first] > Poped.second)
//					CheckNode[Poped.first] = Poped.second;
//			}
//			else CheckNode[Poped.first] = Poped.second;
//
//			for (int i = 1; i <= N; ++i)
//			{
//				if (i == Poped.first) continue;
//				if (Temp[Poped.first][i] != 0 && Visited[Poped.first][i] == false)
//				{
//					Visited[Poped.first][i] = true;
//					Que.push({ i, Poped.second + Temp[Poped.first][i] });
//				}
//			}
//		}
//	}
//
//	int Answer = 0;
//	for (int i = 2; i <= N; ++i)
//	{
//		if (CheckNode[i] <= K) ++Answer;
//	}
//
//	return Answer + 1;
//}

//@BFS
//vector<pair<int, int>> Temp[52];
//bool Visited[52][52] = { false, };
//int CheckNode[52] = { 0, };
//int solution(int N, vector<vector<int> > Road, int K)
//{
//	for (int j = 0; j < Road.size(); ++j)
//	{
//		Temp[Road[j][0]].push_back({ Road[j][1], Road[j][2] });
//		Temp[Road[j][1]].push_back({ Road[j][0], Road[j][2] });
//	}
//
//	queue<pair<int, int>> Que;
//	Que.push({ 1, 0 });
//
//	while (!Que.empty())
//	{
//		int QueSize = Que.size();
//		while (QueSize--)
//		{
//			pair<int, int> Poped = Que.front();
//			Que.pop();
//			int PopFirst = Poped.first, PopSecond = Poped.second;
//			if (PopSecond > K) continue;
//
//			for (int i = 0; i < Temp[PopFirst].size(); ++i)
//			{
//				if (PopSecond + Temp[PopFirst][i].second > K) continue;
//				if (Visited[PopFirst][Temp[PopFirst][i].first] == false)
//				{
//					Visited[PopFirst][Temp[PopFirst][i].first] = true;
//					(CheckNode[Temp[PopFirst][i].first] == 0)
//						? CheckNode[Temp[PopFirst][i].first] = PopSecond + Temp[PopFirst][i].second
//						: CheckNode[Temp[PopFirst][i].first] = min(CheckNode[Temp[PopFirst][i].first], PopSecond + Temp[PopFirst][i].second);
//					Que.push({ Temp[PopFirst][i].first, PopSecond + Temp[PopFirst][i].second });
//				}
//				else
//				{
//					/*
//					방문했을 때에도 확인해주고 Que 에 넣어주어야 함. 
//					다시 방문했을 경우 그 값이 더 작을 수 있음.
//					[1,2,100], [1,5,1], [5,2,1], [2,3,1] 의 경우임.
//					*/
//					if (CheckNode[Temp[PopFirst][i].first] != 0 && CheckNode[Temp[PopFirst][i].first] > PopSecond + Temp[PopFirst][i].second)
//					{
//						CheckNode[Temp[PopFirst][i].first] = PopSecond + Temp[PopFirst][i].second;
//						Que.push({ Temp[PopFirst][i].first, PopSecond + Temp[PopFirst][i].second });
//					}
//				}
//			}
//		}
//	}
//
//	int Answer = 0;
//	for (int i = 2; i <= N; ++i)
//	{
//		if (CheckNode[i] <= K && CheckNode[i] != 0)
//			++Answer;
//	}
//
//	return Answer + 1;
//}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//@DFS

int Temp[51][51] = { 0, };
bool Visited[51] = { false, }; /* 굳이 2차원으로 쓸 필요없다. */
int CheckNode[51] = { 0, };

void DFS(int Index, int Dist, int N, int K)
{
	for (int j = 1; j <= N; ++j)
	{
		if (Index == j) continue;
		if (Temp[Index][j] == 0) continue;
		if (Visited[j] == false)
		{
			Visited[j] = true;
			(CheckNode[j] != 0)
				? CheckNode[j] = min(CheckNode[j], Dist + Temp[Index][j])
				: CheckNode[j] = Dist + Temp[Index][j];
			DFS(j, Dist + Temp[Index][j], N, K);
		}
		else //@이미 방문했을 때,
		{
			if (Dist + Temp[Index][j] > K) continue;
			if (CheckNode[j] > Dist + Temp[Index][j])
			{
				CheckNode[j] = Dist + Temp[Index][j];
				DFS(j, Dist + Temp[Index][j], N, K);
			}
		}
	}
}

int solution(int N, vector<vector<int> > Road, int K)
{
	for (int j = 0; j < Road.size(); ++j)
	{
		if (Temp[Road[j][0]][Road[j][1]] != 0)
		{
			Temp[Road[j][0]][Road[j][1]] = min(Temp[Road[j][0]][Road[j][1]], Road[j][2]);
			Temp[Road[j][1]][Road[j][0]] = Temp[Road[j][0]][Road[j][1]];
		}
		else
		{
			Temp[Road[j][0]][Road[j][1]] = Road[j][2];
			Temp[Road[j][1]][Road[j][0]] = Road[j][2];
		}
	}

	DFS(1, 0, N, K);

	int Result = 0;
	for (int i = 2; i <= N; ++i)
	{
		if (CheckNode[i] <= K && CheckNode[i] != 0) ++Result;
	}
	return Result + 1;
}

int main()
{
	int N = 5, K = 3;
	vector<vector<int>> Insert;
	Insert.push_back({ 1, 2, 1 });
	Insert.push_back({ 2, 3, 3 });
	Insert.push_back({ 5, 2, 2 });
	Insert.push_back({ 1, 4, 2 });
	Insert.push_back({ 5, 3, 1 });
	Insert.push_back({ 5, 4, 2 });

	//int N = 6, K = 4;
	//vector<vector<int>> Insert;
	//Insert.push_back({ 1, 2, 1 });
	//Insert.push_back({ 1, 3, 2 });
	//Insert.push_back({ 2, 3, 2 });
	//Insert.push_back({ 3, 4, 3 });
	//Insert.push_back({ 3, 5, 2 });
	//Insert.push_back({ 3, 5, 3 });
	//Insert.push_back({ 5, 6, 1 });

	int Result = solution(N, Insert, K);

	return 0;
}

