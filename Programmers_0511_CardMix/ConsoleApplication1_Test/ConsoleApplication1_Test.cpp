#include "pch.h"
#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

using namespace std;

int solution(vector<int> left, vector<int> right)
{
	//@초기화
	int size = left.size();
	int** Temp = new int*[size + 1];
	for (int j = 0; j < size + 1; ++j)
	{
		int* InsertTemp = new int[size + 1];
		for (int i = 0; i < size + 1; ++i)
		{
			InsertTemp[i] = 0;
		}
		Temp[j] = InsertTemp;
	}

	for (int j = size - 1; j >= 0; --j) //@left
	{
		for (int i = size - 1; i >= 0; --i) //@right
		{
			if (left[j] > right[i])
			{
				Temp[j][i] = Temp[j][i + 1] + right[i];
			}
			else
			{
				Temp[j][i] = max(Temp[j + 1][i], Temp[j + 1][i + 1]);
			}
		}
	}

	return Temp[0][0];
}

//@시행착오 코드
/*
static int Max = 0;

void Compare(int value)
{
	if (value > Max)
		Max = value;
}

int solution(vector<int> left, vector<int> right)
{
	int TotalSize = left.size();

	vector<int> CalcVec(TotalSize, 0);

	//@right 가 모두 다 비워져야 최댓값이 나옴.
	int LIndex = 0;
	int Result = 0;
	for (int j = 0; j < right.size(); ++j)
	{
		bool bCheck = false;
		for (int i = LIndex; i < left.size(); ++i)
		{
			if (right[j] < left[i])
			{
				LIndex = i;
				bCheck = true;
				Result += right[j];
				break;
			}
		}

		//@left > right 가 없는 수라면 PASS
		if (bCheck == false)
			++LIndex;

		if (LIndex >= left.size())
		{
			Compare(Result);
			Result = 0;
			LIndex = j;
		}

	}

	Compare(Result);

	return Max;
}
*/

int main()
{
	//vector<int> Left;
	//Left.push_back(1);
	//Left.push_back(1);
	//Left.push_back(9);
	//Left.push_back(1);
	//Left.push_back(1);
	//Left.push_back(1);
	//Left.push_back(1);

	//vector<int> Right;
	//Right.push_back(8);
	//Right.push_back(9);
	//Right.push_back(3);
	//Right.push_back(3);
	//Right.push_back(3);
	//Right.push_back(3);
	//Right.push_back(3);

	vector<int> Left;
	Left.push_back(3);
	Left.push_back(3);
	Left.push_back(3);

	vector<int> Right;
	Right.push_back(2);
	Right.push_back(2);
	Right.push_back(2);

	//vector<int> Left;
	//Left.push_back(3);
	//Left.push_back(2);
	//Left.push_back(5);
	//Left.push_back(1);
	//Left.push_back(1);

	//vector<int> Right;
	//Right.push_back(2);
	//Right.push_back(6);
	//Right.push_back(4);
	//Right.push_back(7);
	//Right.push_back(1);

	int Result = solution(Left, Right);

	return 0;
}

