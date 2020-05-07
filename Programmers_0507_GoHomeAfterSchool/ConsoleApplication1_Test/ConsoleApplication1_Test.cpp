#include "pch.h"
#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

int solution(int m, int n, vector<vector<int>> puddles)
{
	//@n - 행
	//@m - 열

	//@2차원 배열 생성
	int** Map = new int*[n]();
	for (int s = 0; s < n; ++s)
	{
		int* temp = new int[m]();
		temp[0] = 1;

		if (s == 0)
		{
			for (int t = 1; t < m; ++t)
				temp[t] = 1;
		}
		else
		{
			for (int t = 1; t < m; ++t)
				temp[t] = -1;
		}

		Map[s] = temp;
	}

	//@웅덩이 표시
	for (int v = 0; v < puddles.size(); ++v)
	{
		int Row = puddles[v][1];
		int Colum = puddles[v][0];
		Map[Row - 1][Colum - 1] = 0;

		if (Row == 1)
		{
			for (int z = Colum - 1; z < m; ++z)
				Map[0][z] = 0;
		}
		else if (Colum == 1)
		{
			for (int z = Row - 1; z < n; ++z)
				Map[z][0] = 0;
		}
	}

	//@계산
	for (int j = 1; j < n; ++j)
	{
		for (int i = 1; i < m; ++i)
		{
			if (Map[j][i] == 0)
				continue;

			Map[j][i] = (Map[j - 1][i] + Map[j][i - 1]) % 1000000007;
		}
	}

	return (Map[n - 1][m - 1]);
}

int main()
{
	int m = 4; //@열
	int n = 3; //@행

	vector<vector<int>> Input;
	vector<int> In1;
	In1.push_back(2);
	In1.push_back(2);

	Input.push_back(In1);

	solution(m, n, Input);

	return 0;
}

