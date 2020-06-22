#include "pch.h"
#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

bool Compare(int a, int b)
{
	return a < b;
}

void Loop(vector<int>& Calc, vector<bool>& Check, int Value, vector<int>& Result)
{
	int Temp = Value;
	for (int i = 0; i < Calc.size(); ++i)
	{
		if (Check[i] == false)
		{
			Check[i] = true;
			Result.push_back(Temp + Calc[i]);
			Loop(Calc, Check, Temp + Calc[i], Result);
			Check[i] = false;
		}
	}
}

/* 존재하지 않으면 true */
bool Check(int Result, vector<int>& Calc)
{
	int Temp = Result;
	for (int i = Calc.size() - 1; i >= 0; --i)
	{
		if (Result >= Calc[i])
		{
			Temp -= Calc[i];
		}

		if (Temp < 0) Temp += Calc[i];
		else if (Temp == 0) return false;
	}

	return true;
}

int solution(vector<int> weight)
{
	int Answer = 1;

	sort(weight.begin(), weight.end());
	for (int i = 0; i < weight.size(); i++)
	{
		if (Answer < weight[i]) break;
		else Answer += weight[i];
	}

	return Answer;
}

int main()
{
	vector<int> Input;
	Input.push_back(3);
	Input.push_back(1);
	Input.push_back(6);
	Input.push_back(2);
	Input.push_back(7);
	Input.push_back(30);
	Input.push_back(1);

	int Result = solution(Input);

	return 0;
}

