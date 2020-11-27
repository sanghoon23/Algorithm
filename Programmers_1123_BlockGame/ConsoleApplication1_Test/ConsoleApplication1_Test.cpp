#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

int Answer = 0;
vector<pair<int, int>> Temp[5];

bool OnSomething(vector<vector<int>>& Board, int X, int Y)
{
	while (Y - 1 >= 0)
	{
		if (Board[Y - 1][X] != 0) return true;
		--Y;
	}
	return false;
}

bool Check(vector<vector<int>>& Board, int x, int y)
{
	int Size = Board.size();
	int V = Board[y][x];
	for (int j = 0; j < 5; ++j)
	{
		bool bFind = true;
		for (int i = 1; i < Temp[j].size(); ++i)
		{
			int DirX = Temp[j][i].first, DirY = Temp[j][i].second;
			int RX = x + DirX, RY = y + DirY;
			if (RX >= Size || RX < 0 || RY >= Size || RY < 0) { bFind = false; break; }

			if (i <= 3)
			{
				if (Board[RY][RX] != V) { bFind = false; break; }
			}
			else
			{
				if (Board[RY][RX] != 0) { bFind = false; break; }
				if (OnSomething(Board, RX, RY) == true) { bFind = false; break; }
			}
		}

		if (bFind == true)
		{
			for (int i = 0; i < Temp[j].size(); ++i)
			{
				int DirX = Temp[j][i].first, DirY = Temp[j][i].second;
				int RX = x + DirX, RY = y + DirY;
				Board[RY][RX] = 0;
			}
			++Answer;
			return true;
		}
	}//for(j)

	return false;
}

int solution(vector<vector<int>> Board)
{
	Temp[0] = { {0, 0}, {0, 1}, {1, 1}, {2, 1},  {1, 0},  {2, 0} };
	Temp[1] = { {0, 0}, {0, 1}, {0, 2}, {-1, 2}, {-1, 0}, {-1, 1} };
	Temp[2] = { {0, 0}, {0, 1}, {0, 2}, {1, 2},  {1, 0},  {1, 1} };
	Temp[3] = { {0, 0}, {0, 1}, {-1, 1},{-2, 1}, {-2, 0}, {-1, 0} };
	Temp[4] = { {0, 0}, {0, 1}, {1, 1}, {-1, 1}, {-1, 0}, {1, 0} };

	int Count = 1;
	while (Count > 0)
	{
		Count = 0;

		for (int j = 0; j < Board.size(); ++j)
		{
			for (int i = 0; i < Board[j].size(); ++i)
			{
				if (Board[j][i] == 0) continue;
				if (Check(Board, i, j) == true)
				{
					++Count; break;
				}
			}
		}
	}
	return Answer;
}

int main()
{

	return 0;
}

