#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>
#include <cstdlib>

using namespace std;

void Find(string& Number, int Index, int k, string& Result)
{
	if (Number.size() <= Index + k)
	{
		if (k > 0) return;
		for (int i = Index; i < Number.size(); ++i)
		{
			Result.push_back(Number[i]);
		}

		return;
	}

	int CalcIndex = Index;
	char Max = Number[Index];
	for (int i = Index; i < Index + k + 1; ++i)
	{
		if (Max < Number[i])
		{
			Max = Number[i];
			CalcIndex = i;
		}
	}

	Result.push_back(Number[CalcIndex]);

	Find(Number, CalcIndex + 1, k - (CalcIndex - Index), Result); //@재귀로 Greedy 하게,
}

string solution(string number, int k)
{
	//@직관적 코드
	string answer = "";
	answer = number.substr(k);
	for (int i = k - 1; i >= 0; i--) {
		int j = 0;
		do {
			if (number[i] >= answer[j]) {
				char temp = answer[j];
				answer[j] = number[i];
				number[i] = temp;
				j++;
			}
			else {
				break;
			}
		} while (1);
	}



	return answer;

	//string Result = ""; //@결과값

	//int RemoveCount = 0;
	//int Index = 0;

	//Find(number, 0, k, Result);

	//return Result;
}

int main()
{
	string Num = "1924"; //"94"
	int k = 2;

	//string Num = "1231234"; // "3234"
	//int k = 3;

	//string Num = "1111"; // "11"
	//int k = 2;

	string Result = solution(Num, k);

	return 0;
}

