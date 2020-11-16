#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <algorithm>

using namespace std;

vector<int> solution(string Msg)
{
	vector<int> Answer;
	int Index = 1;
	map<string, int> Temp;
	for (int i = 0; i < 26; ++i)
	{
		string In;
		In.push_back(i + 65);
		Temp[In] = Index;
		++Index;
	}

	int StartIndex = 0;
	int P = 2;
	while (1)
	{
		P = 2;
		bool bFinish = false;
		while (1)
		{
			string Calc = Msg.substr(StartIndex, P);
			if (StartIndex + P - 1 >= Msg.size())
			{
				Answer.push_back(Temp[Calc]);
				bFinish = true;
				break;
			}
			if (Temp[Calc] == 0)
			{
				Temp[Calc] = Index;
				++Index;

				string Before = Msg.substr(StartIndex, P - 1);
				Answer.push_back(Temp[Before]);

				StartIndex += (P - 1);
				break;
			}
			++P;
		}

		if (bFinish) break;
	}

	return Answer;
}

int main()
{
	string Msg = "KAKAO";

	vector<int> Result = solution(Msg);

	return 0;
}

