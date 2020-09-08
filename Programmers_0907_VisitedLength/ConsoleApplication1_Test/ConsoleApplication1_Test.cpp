#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

struct Point
{
	bool bDown = false;
	bool bRight = false;
};

int solution(string dirs)
{
	int Answer = 0;

	vector<vector<Point*>> Pan;
	for (int j = 0; j < 11; ++j)
	{
		vector<Point*> InsertVec;
		for (int i = 0; i < 11; ++i)
		{
			Point* Insert = new Point();
			InsertVec.push_back(Insert);
		}
		Pan.push_back(InsertVec);
	}

	int X = 5;
	int Y = 5;
	for (int j = 0; j < dirs.size(); ++j)
	{
		if (dirs[j] == 'U' && Y - 1 >= 0)
		{
			Pan[X][Y - 1]->bDown = true;
			--Y;
		}
		else if (dirs[j] == 'D' && Y + 1 <= 10)
		{
			Pan[X][Y]->bDown = true;
			++Y;
		}
		else if (dirs[j] == 'L' && X - 1 >= 0)
		{
			Pan[X - 1][Y]->bRight = true;
			--X;
		}
		else if (dirs[j] == 'R' && X + 1 <= 10)
		{
			Pan[X][Y]->bRight = true;
			++X;
		}
	}

	for (int j = 0; j < Pan.size() - 1; ++j)
	{
		for (int i = 0; i < Pan[j].size() - 1; ++i)
		{
			if (Pan[j][i]->bDown == true) ++Answer;
			if (Pan[j][i]->bRight == true) ++Answer;
		}
	}

	for (int s = 0; s < Pan.size() - 1; ++s)
	{
		if (Pan[10][s]->bDown == true) ++Answer;
		if (Pan[s][10]->bRight == true) ++Answer;
	}


	return Answer;
}

int main()
{
	string In;

	////Test Case 1
	//In.push_back('U');
	//In.push_back('L');
	//In.push_back('U');
	//In.push_back('R');
	//In.push_back('R');
	//In.push_back('D');
	//In.push_back('L');
	//In.push_back('L');
	//In.push_back('U');

	//Test Case 2
	In.push_back('L');
	In.push_back('U');
	In.push_back('L');
	In.push_back('L');
	In.push_back('L');
	In.push_back('L');
	In.push_back('L');
	In.push_back('L');
	In.push_back('U');

	int Result = solution(In);

	return 0;
}

