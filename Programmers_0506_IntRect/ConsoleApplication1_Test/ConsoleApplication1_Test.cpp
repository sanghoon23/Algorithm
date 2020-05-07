#include "pch.h"
#include <iostream>
#include <vector>
#include <list>

using namespace std;

int solution(vector<vector<int>> triangle)
{
	int Height = triangle.size();
	int** Sum = new int*[Height]();
	for (int j = 0; j < triangle.size(); ++j)
	{
		int* Insert = new int[triangle[j].size()]();
		for (int i = 0; i < triangle[j].size(); ++i)
		{
			if (j == 0) //@꼭대기
			{
				Insert[0] = (triangle[j][i]);
				break;
			}

			if (i == 0) //@첫 번째 인덱스
				Insert[i] = (Sum[j - 1][i] + triangle[j][i]);
			else if (i == triangle[j].size() - 1) //@마지막 인덱스
				Insert[i] = (Sum[j - 1][i - 1] + triangle[j][i]);
			else //@ 그 외 중간 인덱스
			{
				int M = 0;
				(Sum[j - 1][i - 1] > Sum[j - 1][i])
					? M = Sum[j - 1][i - 1]
					: M = Sum[j - 1][i];

				Insert[i] = (M + triangle[j][i]);
			}

		}
		Sum[j] = (Insert);
	}

	int Max = 0;
	for (int t = 0; t < triangle[Height - 1].size(); ++t)
	{
		if (Sum[Height - 1][t] > Max)
			Max = Sum[Height - 1][t];
	}

	return Max;
}

int main()
{
	vector<vector<int>> Input;
	vector<int> In1;
	In1.push_back(7);

	vector<int> In2;
	In2.push_back(3);
	In2.push_back(8);

	vector<int> In3;
	In3.push_back(8);
	In3.push_back(1);
	In3.push_back(0);

	vector<int> In4;
	In4.push_back(2);
	In4.push_back(7);
	In4.push_back(4);
	In4.push_back(4);

	vector<int> In5;
	In5.push_back(4);
	In5.push_back(5);
	In5.push_back(2);
	In5.push_back(6);
	In5.push_back(5);

	Input.push_back(In1);
	Input.push_back(In2);
	Input.push_back(In3);
	Input.push_back(In4);
	Input.push_back(In5);

	solution(Input);

	return 0;
}

