#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>
#include <queue>
#include <map>

using namespace std;

//int Calc(vector<vector<int>>& Edges, vector<int>& Temp)
//{
//	vector<int> Ret;
//	for (int j = 0; j < Temp.size(); ++j)
//	{
//		int Start = Temp[j];
//		int End = Temp[(j + 1) % 3];
//		int Count = 0;
//		bool bFind = false;
//		while (bFind == false)
//		{
//			for (int i = 0; i < Edges.size(); ++i)
//			{
//				if (Edges[i][0] == Start)
//				{
//					++Count;
//					if (Edges[i][1] == End)
//					{
//						bFind = true;
//						break;
//					}
//					else
//					{
//						Start = Edges[i][1];
//						break;
//					}
//				}
//				if (Edges[i][1] == Start)
//				{
//					++Count;
//					if (Edges[i][0] == End)
//					{
//						bFind = true;
//						break;
//					}
//					else
//					{
//						Start = Edges[i][0];
//						break;
//					}
//				}
//			}
//		}
//
//
//		Ret.push_back(Count);
//	}
//
//	sort(Ret.begin(), Ret.end());
//	return Ret[1];
//}

////@거리의 중간값의 최댓값을 구하여라. f(1,2,3) 의 2번째,
//int solution(int N, vector<vector<int>> Edges)
//{
//	int Answer = 0;
//
//	//@3개 선택
//	vector<int> Temp;
//	for (int i = 1; i <= N; ++i)
//	{
//		Temp.push_back(i);
//		Temp.push_back((i + 1) % N);
//		Temp.push_back((i + 2) % N);
//
//		do
//		{
//			int Ret = Calc(Edges, Temp);
//			Answer = max(Answer, Ret);
//
//		} while (next_permutation(Temp.begin(), Temp.end()));
//	}
//
//	return Answer;
//}
//

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//#1009_다시 풀어보기
//int Dist(vector<vector<int>>& Temp, int Start, int End, int Count)
//{
//	if (Count > Temp.size() - 1) return -1;
//
//	int Ret = -1;
//	if (Temp[Start - 1][End - 1] == 1)
//		return Count;
//	else
//	{
//		for (int i = 0; i < Temp[Start - 1].size(); ++i)
//		{
//			if (i == End - 1) continue;
//			if (Temp[Start - 1][i] != 0)
//			{
//				int Calc = Dist(Temp, i + 1, End, Count + 1);
//				Ret = max(Ret, Calc);
//			}
//		}
//	}
//
//	return Ret;
//}
//
//int solution(int N, vector<vector<int>> Edges)
//{
//	int Answer = 0;
//
//	vector<vector<int>> Temp;
//	for (int i = 0; i < N; ++i)
//		Temp.push_back(vector<int>(N, 0));
//
//	for (int i = 0; i < Edges.size(); ++i)
//	{
//		Temp[Edges[i][0] - 1][Edges[i][1] - 1] = 1;
//		Temp[Edges[i][1] - 1][Edges[i][0] - 1] = 1;
//	}
//
//	//int Result = Dist(Temp, 3, 5, 1);
//
//	for (int i = 1; i <= N; ++i)
//	{
//		vector<int> Calc;
//		Calc.push_back(i);
//		Calc.push_back((i + 1) % N + 1);
//		Calc.push_back((i + 2) % N + 1);
//
//		do
//		{
//			vector<int> Result;
//			for (int i = 0; i < 3; ++i)
//			{
//				//int Insert = Dist(Temp, Calc[i % 3], Calc[(i + 1) % 3], 1);
//				Result.push_back(Dist(Temp, Calc[i % 3], Calc[(i + 1) % 3], 1));
//			}
//			sort(Result.begin(), Result.end());
//			Answer = max(Answer, Result[1]);
//
//		} while (next_permutation(Calc.begin(), Calc.end()));
//	}
//
//	return Answer;
//}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//@1013_다시 풀어보기

//bool Visited[250001] = { false, };
//
//int solution(int N, vector<vector<int>> Edges)
//{
//	//모두 트리이다. -> 연결되어있다.
//	queue<int> Que;
//	Visited[Edges[0][0]] = true;
//	Que.push(Edges[0][1]);
//
//	int Answer = 0;
//	int LastCount = Que.size();
//	int Count = 0;
//	while (!Que.empty())
//	{
//		int QueSize = Que.size();
//		LastCount = QueSize;
//		while (QueSize--)
//		{
//			int Poped = Que.front();
//			Que.pop();
//			for (int j = 1; j < Edges.size(); ++j)
//			{
//				if (Edges[j][0] == Poped && Visited[Edges[j][1]] == false)
//				{
//					Visited[Edges[j][0]] = true;
//					Que.push(Edges[j][1]);
//				}
//				if (Edges[j][1] == Poped && Visited[Edges[j][0]] == false)
//				{
//					Visited[Edges[j][1]] = true;
//					Que.push(Edges[j][0]);
//				}
//			}
//		}
//
//		++Count;
//		if (Que.size() == 0 && LastCount > 1)
//		{
//			Answer = Count;
//		}
//		else Answer = Count - 1;
//	}
//
//	return Answer;
//}
/////////////////////////////////////////////////////////////////////////////////////////////

//@최대거리가 될 수 있는 값을 구해야함.
//왜 3번을 돌려야 정답이 되는가.
int solution5(int N, vector<vector<int>> Edges)
{
	int Answer = 0;

	map<int, vector<int>> Map;
	for (int i = 0; i < Edges.size(); ++i)
	{
		Map[Edges[i][0]].push_back(Edges[i][1]);
		Map[Edges[i][1]].push_back(Edges[i][0]);
	}

	int LastNumber = 1;
	for (int i = 1; i <= 3; ++i)
	{
		int Calc = 0;
		vector<bool> Visited(N + 1, false);
		queue<int> Que;
		Que.push(LastNumber);
		Visited[LastNumber] = true;
		int Count = 0, LastCount = 0;
		while (!Que.empty())
		{
			int QueSize = Que.size();
			if (QueSize > 0)
				LastCount = QueSize;

			while (QueSize--)
			{
				int Poped = Que.front();
				Que.pop();
				for (int i = 0; i < Map[Poped].size(); ++i)
				{
					if (Visited[Map[Poped][i]] == true) continue;

					Visited[Map[Poped][i]] = true;
					LastNumber = Map[Poped][i];
					Que.push(Map[Poped][i]);
				}
			}

			if (!Que.empty()) ++Count;
		}

		if (LastCount > 1)
			Calc = Count;
		else
			Calc = Count - 1;

		Answer = max(Answer, Calc);
	}

	return Answer;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
//#1021_ 다시 정리하기. 속도를 줄여보자.

//int MaxLength = 0, MaxIndex = 0;
//vector<int> Same;
//void DFS(map<int, vector<int>>& Map, vector<bool>& Visited, int Start, int Count, bool bCheck)
//{
//	for (int i = 0; i < Map[Start].size(); ++i)
//	{
//		if (Visited[Map[Start][i]] == true) continue;
//
//		Visited[Map[Start][i]] = true;
//		DFS(Map, Visited, Map[Start][i], Count + 1, bCheck);
//		Visited[Map[Start][i]] = false;
//	}
//
//	if (Count > MaxLength)
//	{
//		MaxLength = Count;
//		MaxIndex = Start;
//		Same.clear();
//	}
//	if (Count == MaxLength)
//	{
//		Same.push_back(Start);
//	}
//}
//
//int solution(int N, vector<vector<int>> Edges)
//{
//	map<int, vector<int>> Map;
//	for (int i = 0; i < Edges.size(); ++i)
//	{
//		Map[Edges[i][0]].push_back(Edges[i][1]);
//		Map[Edges[i][1]].push_back(Edges[i][0]);
//	}
//
//	vector<bool> Visited(N + 1, false);
//	Visited[1] = true;
//	DFS(Map, Visited, 1, 0, false);
//
//	Visited.assign(N + 1, false);
//	Visited[MaxIndex] = true;
//	MaxLength = 0;
//	Same.clear();
//	DFS(Map, Visited, MaxIndex, 0, false);
//
//	if (Same.size() > 1) return MaxLength;
//	else
//	{
//		Visited.assign(N + 1, false);
//		Visited[MaxIndex] = true;
//		MaxLength = 0;
//		Same.clear();
//		DFS(Map, Visited, MaxIndex, 0, true);
//	}
//
//	if (Same.size() > 1) return MaxLength;
//	return MaxLength - 1;
//}

///////////////////////////////////////////////////////////////////////////////////////////////
// 위에서 쓸데없이 map 을 사용함. 고쳐보자.
//@1021_ DFS 로 짜보기.
//
vector<vector<int>> Temp;
vector<bool> Visited;
vector<int> Same;

int MaxLength = 0, MaxIndex = 1;
void DFS(int StartValue, int Count)
{
	if (Visited[StartValue] == true) return;
	
	if (Count > MaxLength)
	{
		MaxLength = Count;
		MaxIndex = StartValue;
		Same.clear();
	}
	if (Count == MaxLength)
	{
		Same.push_back(StartValue);
	}

	//#else if 로 바꾸려면 <<-- 이게 더 빠르다.
	{
		//if (Count > MaxLength)
		//{
		//	MaxLength = Count;
		//	MaxIndex = StartValue;
		//	Same.clear();
		//	Same.push_back(StartValue);
		//}
		//else if (Count == MaxLength)
		//{
		//	Same.push_back(StartValue);
		//}
	}

	Visited[StartValue] = true;
	for (int i = 0; i < Temp[StartValue].size(); ++i)
	{
		DFS(Temp[StartValue][i], Count + 1);
	}
}

void Init(int N)
{
	Visited.assign(N + 1, false);
	//fill(Visited.begin(), Visited.end(), false);
	Same.clear();
	MaxLength = 0;
}

int solution2(int N, vector<vector<int>> Edges)
{
	Temp = vector<vector<int>>(N + 1);
	Visited = vector<bool>(N + 1);

	for (int i = 0; i < Edges.size(); ++i)
	{
		Temp[Edges[i][0]].push_back(Edges[i][1]);
		Temp[Edges[i][1]].push_back(Edges[i][0]);
	}

	DFS(1, 0);
	Init(N);
	DFS(MaxIndex, 0);
	if (Same.size() >= 2) return MaxLength;

	Visited.assign(N + 1, false);
	Init(N);
	DFS(MaxIndex, 0);
	if (Same.size() >= 2) return MaxLength;
	return MaxLength - 1;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//@1021_ 기존에 BFS 사용한 것 고쳐보기.

//vector<vector<int>> Temp;
//vector<bool> Visited;

int MaxLength = 0, LastIndex = 1, LastNum = 0;
void BFS(int StartValue, int Count)
{
	queue<int> Que;
	Que.push(StartValue);
	int Last = 0;
	while (!Que.empty())
	{
		++Count;
		int QueSize = Que.size();
		Last = QueSize;
		while (QueSize--)
		{
			int Poped = Que.front();
			Que.pop();
			Visited[Poped] = true;
			LastIndex = Poped; //@LastIndex
			for (int i = 0; i < Temp[Poped].size(); ++i)
			{
				if (Visited[Temp[Poped][i]] == true) continue;
				Visited[Temp[Poped][i]] = true;
				Que.push(Temp[Poped][i]);
			}
		}
	}

	LastNum = Last;
	if (Count - 1 > MaxLength) MaxLength = Count - 1;
}

int solution(int N, vector<vector<int>> Edges)
{
	Temp = vector<vector<int>>(N + 1);
	Visited = vector<bool>(N + 1);

	for (int i = 0; i < Edges.size(); ++i)
	{
		Temp[Edges[i][0]].push_back(Edges[i][1]);
		Temp[Edges[i][1]].push_back(Edges[i][0]);
	}

	BFS(1, 0);
	Visited.assign(N + 1, false);

	BFS(LastIndex, 0);
	if (LastNum >= 2) return MaxLength;

	Visited.assign(N + 1, false);
	BFS(LastIndex, 0);
	if (LastNum >= 2) return MaxLength;
	return MaxLength - 1;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main()
{
	int N = 3;
	vector<vector<int>> Insert;
	Insert.push_back({ 1, 2 });

	//int N = 4;
	//vector<vector<int>> Insert;
	//Insert.push_back({ 1, 2 });
	//Insert.push_back({ 2, 3 });
	//Insert.push_back({ 3, 4 });

	//int N = 5;
	//vector<vector<int>> Insert;
	//Insert.push_back({ 1, 5 });
	//Insert.push_back({ 2, 5 });
	//Insert.push_back({ 3, 5 });
	//Insert.push_back({ 4, 5 });
	//Insert.push_back({ 4, 3 });

	//int N = 5;
	//vector<vector<int>> Insert;
	//Insert.push_back({ 1, 5 });
	//Insert.push_back({ 2, 5 });
	//Insert.push_back({ 3, 5 });
	//Insert.push_back({ 4, 5 });

	//int N = 5;
	//vector<vector<int>> Insert;
	//Insert.push_back({ 1, 2 });
	//Insert.push_back({ 2, 3 });
	//Insert.push_back({ 3, 4 });
	//Insert.push_back({ 4, 5 });

	int Result = solution(N, Insert);

	return 0;
}

