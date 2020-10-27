#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <queue>
#include <algorithm>

using namespace std;

int MOD = 20170805;

//@위,아래,오른,왼

//int solution(int M, int N, vector<vector<int>> City_Map)
//{
//	vector<vector<int>> Temp(M + 1, vector<int>(N + 1, 0));
//	vector<vector<vector<int>>> Before(M + 1, vector<vector<int>>(N + 1, vector<int>(2, 0)));
//	vector<vector<bool>> Visited(M + 1, vector<bool>(N + 1, false));
//	pair<int, int> Dir[2] = { {1, 0}, {0, 1} }; //0-아래, 1-오른
//
//	Temp[1][1] = 1;
//	Before[1][0][0] = 1;
//	Before[1][0][1] = 1;
//	Before[0][1][0] = 1;
//	Before[0][1][1] = 1;
//	queue<pair<int, int>> Que;
//	Que.push({ 1, 1 });
//	while (!Que.empty())
//	{
//		int QueSize = Que.size();
//		while (QueSize--)
//		{
//			pair<int, int> Poped = Que.front();
//			Que.pop();
//			int First = Poped.first, Second = Poped.second;
//			if (Visited[First][Second] == true) continue;
//			Visited[First][Second] = true;
//
//			for (int i = 0; i < 2; ++i) //0-아래, 1-오른
//			{
//				int NextFirst = First + Dir[i].first;
//				int NextSecond = Second + Dir[i].second;
//				if (NextFirst >= M + 1 || NextSecond >= N + 1) continue;
//
//				if (City_Map[NextFirst - 1][NextSecond - 1] == 1)
//				{
//					Temp[NextFirst][NextSecond] = 0;
//					continue;
//				}
//				else if (City_Map[NextFirst - 1][NextSecond - 1] == 0)
//				{
//					if (City_Map[First - 1][Second - 1] == 2 && Before[First - Dir[i].first][Second - Dir[i].second][i] == 0)
//					{
//						continue;
//					}
//
//					Que.push({NextFirst, NextSecond });
//					Before[First][Second][i] = 1; //@i 로 방향 check
//					Temp[NextFirst][NextSecond] += (Temp[NextFirst - Dir[i].first][NextSecond - Dir[i].second]) % MOD;
//					continue;
//				}
//				else
//				{
//					if (Before[First - Dir[i].first][Second - Dir[i].second][i] == 1)
//					{
//						Que.push({ NextFirst, NextSecond });
//						Before[First][Second][i] = 1; //@i 로 방향 check
//						Temp[NextFirst][NextSecond] += (Temp[NextFirst - Dir[i].first][NextSecond - Dir[i].second]) % MOD;
//					}
//
//					//if (Before[NextFirst - Dir[i].first][NextSecond - Dir[i].second][i] == 1) //@왼쪽에서 온 자동차는 왼쪽으로만.
//					//{
//					//	Que.push({ NextFirst, NextSecond });
//					//	Before[NextFirst][NextSecond][i] = 1; //@i 로 방향 check
//					//	Temp[NextFirst][NextSecond] += Temp[NextFirst - Dir[i].first][NextSecond - Dir[i].second];
//					//}
//				}
//			}//(for)
//
//			//if (First == 1 && Second == 1) Temp[First][Second] = 1;
//			//else if(City_Map[First - 1][Second - 1] == 0) Temp[First][Second] = Temp[First - 1][Second] + Temp[First][Second - 1];
//			//else if (City_Map[First - 1][Second - 1] == 1) Temp[First][Second] = 0;
//			//else
//			//{
//			//	if (Before[First][Second][0] == 1 && Before[First][Second][1] == 1) //@위쪽,왼쪽에서 왔을 때,
//			//		Temp[First][Second] = Temp[First - 1][Second] + Temp[First][Second - 1];
//			//	else if (Before[First][Second][0] == 1 && Before[First][Second][1] == 0) //@위쪽에서만 왔을 때,
//			//		Temp[First][Second] = Temp[First - 1][Second];
//			//	else if (Before[First][Second][0] == 0 && Before[First][Second][1] == 1) //@왼쪽에서만 왔을 때,
//			//		Temp[First][Second] = Temp[First][Second - 1];
//			//}
//		}
//	}
//
//
//	return Temp[M][N] % MOD;
//}

//int solution(int M, int N, vector<vector<int>> City_Map)
//{
//	vector<vector<int>> Temp(M + 1, vector<int>(N + 1, 0));
//	vector<vector<vector<int>>> Before(M + 1, vector<vector<int>>(N + 1, vector<int>(2, 0)));
//	vector<vector<bool>> Visited(M + 1, vector<bool>(N + 1, false));
//	pair<int, int> Dir[2] = { {1, 0}, {0, 1} }; //0-아래, 1-오른
//
//	Temp[1][1] = 1;
//	Before[1][0][0] = 1;
//	Before[1][0][1] = 1;
//	Before[0][1][0] = 1;
//	Before[0][1][1] = 1;
//	queue<pair<int, int>> Que;
//	Que.push({ 1, 1 });
//	while (!Que.empty())
//	{
//		int QueSize = Que.size();
//		while (QueSize--)
//		{
//			pair<int, int> Poped = Que.front();
//			Que.pop();
//			int First = Poped.first, Second = Poped.second;
//			if (Visited[First][Second] == true) continue;
//			Visited[First][Second] = true;
//
//			for (int i = 0; i < 2; ++i) //0-아래, 1-오른
//			{
//				int NextFirst = First + Dir[i].first, NextSecond = Second + Dir[i].second;
//				int DirFir = Dir[i].first, DirSec = Dir[i].second;
//
//				if (City_Map[First - 1][Second - 1] == 0) //@현재 자리가 0 인 경우 - (통과)
//				{
//					
//					if (NextFirst <= M && NextSecond <= N)
//						Que.push({NextFirst, NextSecond });
//
//					Before[First][Second][i] = 1; //@i 로 방향 check
//					if (Before[First - DirFir][Second - DirSec][i] == 1)
//					{
//						Temp[First][Second] += (Temp[First - DirFir][Second - DirSec]) % MOD;
//						Temp[First][Second] %= MOD;
//
//						if (First - DirFir - 1 >= 0 && Second - DirSec - 1 >= 0 && City_Map[First - DirFir - 1][Second - DirSec - 1] == 2)
//						{
//							Temp[First][Second] -= Temp[First - 1][Second - 1] % MOD;
//							Temp[First][Second] %= MOD;
//						}
//					}
//				}
//				else if (City_Map[First - 1][Second - 1] == 1) //@현재 자리가 1 인 경우 - (금지)
//				{
//					Temp[First][Second] = 0;
//				}
//				else if (City_Map[First - 1][Second - 1] == 2) //@현재 자리가 2 인 경우 - (조건)
//				{
//					if (Before[First - DirFir][Second - DirSec][i] == 1)
//					{
//						if (NextFirst <= M && NextSecond <= N)
//							Que.push({ NextFirst, NextSecond });
//						else Temp[First][Second] -= (Temp[First - Dir[i].first][Second - Dir[i].second]) % MOD;
//
//						Before[First][Second][i] = 1; //@i 로 방향 check
//						Temp[First][Second] += (Temp[First - Dir[i].first][Second - Dir[i].second]) % MOD;
//						Temp[First][Second] %= MOD;
//					}
//				}
//
//			}//(for)
//		}
//	}
//	return Temp[M][N] % MOD;
//}

//int Temp[2][501][501]; //0-아래, 1-오른
int solution(int M, int N, vector<vector<int>> City_Map)
{
	vector<vector<vector<int>>> Temp(2, vector<vector<int>>(501, vector<int>(501, 0)));

	//for (int j = 0; j < 501; ++j)
	//{
	//	memset(Temp[0][j], 0, 501);
	//	memset(Temp[1][j], 0, 501);
	//}

	Temp[0][1][1] = 1;
	Temp[1][1][1] = 1;
	for (int j = 1; j <= M; ++j)
	{
		for (int i = 1; i <= N; ++i)
		{
			if (City_Map[j - 1][i - 1] == 1)
			{
				Temp[0][j][i] = 0;
				Temp[0][j][i] = 0;
			}
			else if (City_Map[j - 1][i - 1] == 0)
			{
				Temp[0][j][i] += Temp[0][j - 1][i] + Temp[1][j][i - 1];
				Temp[1][j][i] += Temp[0][j - 1][i] + Temp[1][j][i - 1];
			}
			else if (City_Map[j - 1][i - 1] == 2)
			{
				Temp[0][j][i] = Temp[0][j - 1][i];
				Temp[1][j][i] = Temp[1][j][i - 1];
			}
		}
	}

	return Temp[0][M][N];
}

int main()
{
	//[[0, 2, 0, 0, 0, 2], [0, 0, 2, 0, 1, 0], [1, 0, 0, 2, 2, 0]]
	vector<vector<int>> Insert;
	Insert.push_back({ 0, 2, 0, 0, 0, 2});
	Insert.push_back({ 0, 0, 2, 0, 1, 0 });
	Insert.push_back({ 1, 0, 0, 2, 2, 0 });
	int M = 3, N = 6;

	//vector<vector<int>> Insert;
	//Insert.push_back({ 0, 0, 0 });
	//Insert.push_back({ 0, 0, 0 });
	//Insert.push_back({ 0, 0, 0 });
	//int M = 3, N = 3;

	int Result = solution(M, N, Insert);

	return 0;
}

