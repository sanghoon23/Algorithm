#include "pch.h"
#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <string>

using namespace std;

struct DataPair
{
	int Colum = 0;
	int Row = 0;
};

//@Make 4 way (up, down, left, right, self) to '.'
void Search(int j, int i, vector<string>& grid, int ColumNum, int RowNum)
{
	grid[j][i] = '.';
	if (j - 1 >= 0)
	{
		grid[j - 1][i] = '.';
	}

	if (j + 1 < ColumNum)
	{
		grid[j + 1][i] = '.';
	}

	if (i - 1 >= 0)
	{
		grid[j][i - 1] = '.';
	}

	if (i + 1 < RowNum)
	{
		grid[j][i + 1] = '.';
	}
}


void Loop(vector<string>& grid, int Colum, int Row, int LoopNumber)
{
	vector<DataPair> Pairs;
	Pairs.reserve(Colum * Row);

	for (int Num = 0; Num < LoopNumber; ++Num)
	{
		//@Set Pair & All grid value make to 'O'
		for (int j = 0; j < Colum; ++j)
		{
			for (int i = 0; i < Row; ++i)
			{
				if (grid[j][i] == 'O')
				{
					DataPair P;
					P.Colum = j;
					P.Row = i;
					Pairs.emplace_back(P);
				}

				grid[j][i] = 'O';
			}//for(i)
		}//for(j)

		 //@Calc Pair
		for (int N = 0; N < Pairs.size(); ++N)
		{
			int J = Pairs[N].Colum;
			int I = Pairs[N].Row;
			Search(J, I, grid, Colum, Row);
		}
		Pairs.clear();

	}//for(Num)
}

// Complete the bomberMan function below.
vector<string> bomberMan(int n, vector<string> grid)
{
	// vector<string> Grid = grid;
	int colum = grid.size();
	int row = grid[0].size();

	//@Initial,
	if (n == 1)
		return grid;

	//@Full - 'O'
	if (n % 2 == 0)
	{
		for (int j = 0; j < colum; ++j)
		{
			for (int i = 0; i < row; ++i)
			{
				grid[j][i] = 'O';
			}//for(i)
		}//for(j)

		return grid;
	}//if(n % 2 == 0)

	//@터진 상황
	if ((n - 3) % 4 == 0)
	{
		Loop(grid, colum, row, 1); //@Loop Once
	}
	else if ((n - 5) % 4 == 0)
	{
		Loop(grid, colum, row, 2); //@Loop Twice
	}

	return grid;
}

int main()
{

	string s1 = ".......";
	string s2 = "...0...";
	string s3 = "....0..";
	string s4 = ".......";
	string s5 = "00.....";
	string s6 = "00.....";

	vector<string> grid;
	grid.push_back(s1);
	grid.push_back(s2);
	grid.push_back(s3);
	grid.push_back(s4);
	grid.push_back(s5);
	grid.push_back(s6);

	vector<string> result = bomberMan(3, grid);

	return 0;
}

