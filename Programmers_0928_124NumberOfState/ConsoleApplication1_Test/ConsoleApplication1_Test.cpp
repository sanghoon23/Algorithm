#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

string Str[3] = { "1", "2", "4" };

string solution(int n)
{
	string Answer = "";

	int Temp = n;
	while (Temp >= 0)
	{
		Temp -= 1;
		if (Temp < 0) break;

		int Remain = Temp % 3;
		Temp = Temp / 3;

		Answer.append(Str[Remain]);
	}

	reverse(Answer.begin(), Answer.end());
	return Answer;
}

int main()
{

	return 0;
}

