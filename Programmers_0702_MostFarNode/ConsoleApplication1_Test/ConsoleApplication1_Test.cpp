#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>
#include <queue>

using namespace std;

void Find(vector<vector<int>>& Edge, vector<bool>& Check, queue<int>& Que, int Value)
{
	for (int i = 0; i < Edge.size(); ++i)
	{
		if (Edge[i][0] == Value && Check[Edge[i][1] - 1] == false) //@첫번째가 같은 경우
		{
			Check[Edge[i][1] - 1] = true;
			Que.push(Edge[i][1]);
		}
		else if (Edge[i][1] == Value && Check[Edge[i][0] - 1] == false) //@두번째가 같은 경우
		{
			Check[Edge[i][0] - 1] = true;
			Que.push(Edge[i][0]);
		}
	}
}

int solution(int n, vector<vector<int>> edge)
{
	int Answer = 0;

	queue<int> Que;
	vector<bool> Check(n, false);
	Check[0] = true; //@첫 방문 '1'
	Find(edge, Check, Que, 1);

	while (1)
	{
		Answer = Que.size();
		queue<int> Temp; //@임시 큐 생성
		while (!Que.empty())
		{
			int Poped = Que.front();
			Que.pop();
			Find(edge, Check, Temp, Poped); //@Que 의 Value 를 이용해 Temp 에 넣기
		}

		if (Temp.empty()) break;
		else swap(Que, Temp); //@Temp 데이터 Origin(Que) 에 옮기기
	}

	return Answer;
}

int main()
{

	return 0;
}

