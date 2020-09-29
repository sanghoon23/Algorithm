#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <queue>
#include <algorithm>

using namespace std;

int DirY[4] = { 1, -1, 0, 0 };
int DirX[4] = { 0, 0, 1, -1 };

bool Check(vector<vector<int>>& Picture, vector<vector<bool>>& Visited, int First, int Second, int Value)
{
	int FirstSize = Visited.size();
	int SecondSize = Visited[0].size();
	if (First >= 0 && First < FirstSize && Second >= 0 && Second < SecondSize
		&& Visited[First][Second] == false && Picture[First][Second] == Value)
		return true;

	return false;
}

vector<int> solution(int m, int n, vector<vector<int>> picture)
{
	int number_of_area = 0;
	int max_size_of_one_area = 0;

	vector<vector<bool>> Visited; //@방문
	for (int i = 0; i < m; ++i)
	{
		vector<bool> Insert(n, false);
		Visited.push_back(Insert);
	}

	for (int j = 0; j < m; ++j)
	{
		for (int i = 0; i < n; ++i)
		{
			if (Visited[j][i] == false && picture[j][i] != 0) //1. 방문하지 않았거나, 2. 0 이 아닐 때,
			{
				Visited[j][i] = true;
				++number_of_area;
				int Size = 1, Value = picture[j][i];
				queue<pair<int, int>> Que;
				Que.push(make_pair(j, i));
				while (!Que.empty())
				{
					int i = Que.size();
					while (i--)
					{
						pair<int, int> Poped = Que.front();
						Que.pop();

						for (int i = 0; i < 4; ++i)
						{
							if (Check(picture, Visited, Poped.first + DirY[i], Poped.second + DirX[i], Value) == true)
							{
								Visited[Poped.first + DirY[i]][Poped.second + DirX[i]] = true;
								Que.push(make_pair(Poped.first + DirY[i], Poped.second + DirX[i]));
							}
						}
					}//i--
					if (!Que.empty())
						Size += Que.size();
				}//Que
				max_size_of_one_area = max(max_size_of_one_area, Size); //@최댓값 비교
			}
		}
	}

	vector<int> Answer;
	Answer.push_back(number_of_area);
	Answer.push_back(max_size_of_one_area);
	return Answer;
}

int main()
{
	//6	4	[[1, 1, 1, 0], [1, 2, 2, 0], [1, 0, 0, 1], [0, 0, 0, 1], [0, 0, 0, 3], [0, 0, 0, 3]]

	int M = 6;
	int N = 4;

	vector<vector<int>> Insert;
	Insert.push_back({ 1, 1, 1, 0 });
	Insert.push_back({ 1, 2, 2, 0 });
	Insert.push_back({ 1, 0, 0, 1 });
	Insert.push_back({ 0, 0, 0, 1 });
	Insert.push_back({ 0, 0, 0, 3 });
	Insert.push_back({ 0, 0, 0, 3 });

	vector<int> Result = solution(M, N, Insert);

	return 0;
}

