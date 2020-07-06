#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

int solution(int n, vector<vector<int>> results)
{
	int Answer = 0;

	vector<vector<int>> Calc;
	for (int t = 0; t < n; ++t)
	{
		vector<int> Insert(n, 0);
		Calc.push_back(Insert);
	}

	for (int s = 0; s < results.size(); ++s)
	{
		int Win = results[s][0] - 1;
		int Lose = results[s][1] - 1;
		Calc[Win][Lose] = 1;
		Calc[Lose][Win] = -1;
	}

	for (int j = 0; j < Calc.size(); ++j)
	{
		for (int i = 0; i < Calc[j].size(); ++i)
		{
			if (Calc[j][i] == 1)
			{
				for (int k = 0; k < Calc[j].size(); ++k)
				{
					if (Calc[j][k] == -1)
					{
						Calc[i][k] = -1;
						Calc[k][i] = 1;
					}
				}
			}
		}
	}

	for (int r = 0; r < Calc.size(); ++r)
	{
		for (int v = 0; v < Calc[r].size(); ++v)
		{
			if (r != v && Calc[r][v] == 0) break;

			if (v == Calc[r].size() - 1) ++Answer;
		}
	}

	return Answer;
}

int main()
{
	vector<vector<int>> Insert;

	int n = 5;
	vector<int> In1;
	In1.push_back(4);
	In1.push_back(3);

	vector<int> In2;
	In2.push_back(4);
	In2.push_back(2);

	vector<int> In3;
	In3.push_back(3);
	In3.push_back(2);

	vector<int> In4;
	In4.push_back(1);
	In4.push_back(2);

	vector<int> In5;
	In5.push_back(2);
	In5.push_back(5);

	Insert.push_back(In1);
	Insert.push_back(In2);
	Insert.push_back(In3);
	Insert.push_back(In4);
	Insert.push_back(In5);

	//*****************************************
	//int n = 5;

	//vector<int> In1;
	//In1.push_back(1);
	//In1.push_back(2);

	//vector<int> In2;
	//In2.push_back(2);
	//In2.push_back(3);

	//vector<int> In3;
	//In3.push_back(3);
	//In3.push_back(4);

	//vector<int> In4;
	//In4.push_back(4);
	//In4.push_back(5);


	//Insert.push_back(In1);
	//Insert.push_back(In2);
	//Insert.push_back(In3);
	//Insert.push_back(In4);

	int Result = solution(n, Insert);

	return 0;
}

