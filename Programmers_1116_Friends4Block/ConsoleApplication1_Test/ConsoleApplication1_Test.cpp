#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

int solution(int M, int N, vector<string> Board)
{
	int Answer = 0;

	int Count = 1;
	while (Count > 0)
	{
		Count = 0;
		vector<vector<bool>> Visited(M, vector<bool>(N, false));
		for (int j = 0; j < M; ++j)
		{
			for (int i = 0; i < N; ++i)
			{
				if (j + 1 >= M || i + 1 >= N) continue;
				if (Board[j][i] == 0) continue;
				if (Board[j][i] == Board[j + 1][i] &&
					Board[j + 1][i] == Board[j][i + 1] &&
					Board[j][i + 1] == Board[j + 1][i + 1])
				{
					Visited[j][i] = true;
					Visited[j + 1][i] = true;
					Visited[j][i + 1] = true;
					Visited[j + 1][i + 1] = true;
					++Count;
				}
			}
		}

		for (int i = 0; i < N; ++i)
		{
			vector<char> Temp;
			for (int j = 0; j < M; ++j)
			{
				if (Visited[j][i] == true) { ++Answer; continue; }
				Temp.push_back(Board[j][i]);
			}

			int Calc = M - (Temp.size());
			for (int j = M - 1; j >= 0; --j)
			{

				if (j - Calc < 0)
				{
					Board[j][i] = 0;
					continue;
				}
				else if(j - Calc >= 0)
					Board[j][i] = Temp[j - (M - Temp.size())];
			}
		}
	}

	return Answer;
}

int main()
{
	////[CCBDE, AAADE, AAABF, CCBBF]
	//int M = 4, N = 5;
	//vector<string> In;
	//In.push_back("CCBDE");
	//In.push_back("AAADE");
	//In.push_back("AAABF");
	//In.push_back("CCBBF");

	//[TTTANT, RRFACC, RRRFCC, TRRRAA, TTMMMF, TMMTTJ]
	int M = 6, N = 6;
	vector<string> In;
	In.push_back("TTTANT");
	In.push_back("RRFACC");
	In.push_back("RRRFCC");
	In.push_back("TRRRAA");
	In.push_back("TTMMMF");
	In.push_back("TMMTTJ");

	int Result = solution(M, N, In);


	return 0;
}

