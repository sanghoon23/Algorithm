#include "pch.h"
#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

bool Compare(int a, int b)
{
	return (a < b);
}

void Bubble(vector<int>& Input)
{

}

vector<int> solution(vector<int> array, vector<vector<int>> commands) 
{
	vector<int> Answer;

	int First = 0;
	int Second = 0;
	int Num = 0;
	for (int i = 0; i < commands.size(); ++i)
	{
		First = commands[i][0] - 1;
		Second = commands[i][1];
		Num = commands[i][2] - 1;

		vector<int> Temp(array.begin() + First, array.begin() + Second);
		std::sort(Temp.begin(), Temp.end(), Compare);

		Answer.push_back(Temp[Num]);
	}

	return Answer;
}

int main()
{
	/*
	[1, 5, 2, 6, 3, 7, 4]	[[2, 5, 3], [4, 4, 1], [1, 7, 3]]
	*/
	vector<int> Input;
	Input.push_back(1);
	Input.push_back(5);
	Input.push_back(2);
	Input.push_back(6);
	Input.push_back(3);
	Input.push_back(7);
	Input.push_back(4);

	vector<vector<int>> Val;
	vector<int> In1;
	In1.push_back(2);
	In1.push_back(5);
	In1.push_back(3);

	vector<int> In2;
	In2.push_back(4);
	In2.push_back(4);
	In2.push_back(1);

	vector<int> In3;
	In3.push_back(1);
	In3.push_back(7);
	In3.push_back(3);
	
	Val.push_back(In1);
	Val.push_back(In2);
	Val.push_back(In3);

	vector<int> Result = solution(Input, Val);

	return 0;
}
