#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <queue>
#include <algorithm>

using namespace std;

#define pii pair<int,int>

struct Node
{
	int BeforeDir = -1;
	int Line = 0;
	int Coner = 0;
};

pii Dir[4] = { {-1, 0}, {1, 0}, {0, 1}, {0, -1} }; //@위, 아래, 오른, 왼
int TempMin[26][26] = { 0, };

int solution(vector<vector<int>> Board)
{
	int Size = Board.size();

	queue<pair<pii, Node>> Que;
	Que.push({ { 0, 0 }, { -1, 0, 0 } });
	while (!Que.empty())
	{
		pair<pii, Node> Poped = Que.front();
		int First = Poped.first.first, Second = Poped.first.second;
		int Line = Poped.second.Line, Coner = Poped.second.Coner, BeforeDir = Poped.second.BeforeDir;
		Que.pop();

		for (int i = 0; i < 4; ++i)
		{
			int NextF = First + Dir[i].first, NextS = Second + Dir[i].second;
			if (NextF < 0 || NextS < 0 || NextF >= Size || NextS >= Size) continue;
			if (Board[NextF][NextS] != 0) continue;
			Node NextNode = { i, Line, Coner };
			if (BeforeDir == -1 || BeforeDir == i) NextNode.Line += 1;
			else
			{
				NextNode.Line += 1;
				NextNode.Coner += 1;
			}

			int Cost = (NextNode.Line * 100) + (NextNode.Coner * 500);
			if (TempMin[NextF][NextS] != 0 && TempMin[NextF][NextS] < Cost) continue;

			TempMin[NextF][NextS] = Cost;

			Que.push({ {NextF, NextS}, NextNode });
		}

	}

	return TempMin[Size - 1][Size - 1];
}

int main()
{
	//vector<vector<int>> Insert;
	//Insert.push_back({ 0, 0, 0 });
	//Insert.push_back({ 0, 0, 0 });
	//Insert.push_back({ 0, 0, 0 });

	//[[0, 0, 0, 0, 0, 0], [0, 1, 1, 1, 1, 0], [0, 0, 1, 0, 0, 0], [1, 0, 0, 1, 0, 1], [0, 1, 0, 0, 0, 1], [0, 0, 0, 0, 0, 0]]

	vector<vector<int>> Insert;
	Insert.push_back({ 0, 0, 0, 0, 0, 0 });
	Insert.push_back({ 0, 1, 1, 1, 1, 0 });
	Insert.push_back({ 0, 0, 1, 0, 0, 0 });
	Insert.push_back({ 1, 0, 0, 1, 0, 1 });
	Insert.push_back({ 0, 1, 0, 0, 0, 1 });
	Insert.push_back({ 0, 0, 0, 0, 0, 0 });

	//	[[0, 0, 1, 0], [0, 0, 0, 0], [0, 1, 0, 1], [1, 0, 0, 0]]

	//vector<vector<int>> Insert;
	//Insert.push_back({ 0, 0, 1, 0 });
	//Insert.push_back({ 0, 0, 0, 0 });
	//Insert.push_back({ 0, 1, 0, 1 });
	//Insert.push_back({ 1, 0, 0, 0 });

	int Result = solution(Insert);

	return 0;
}

