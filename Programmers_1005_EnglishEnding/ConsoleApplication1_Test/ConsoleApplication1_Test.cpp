#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>
#include <map>

using namespace std;

vector<int> solution(int N, vector<string> Words)
{
	vector<int> Answer = { 0, 0 };

	bool bFail = false;
	int Count = 0;
	map<string, int> Map;
	++Map[Words[0]];
	for (int i = 1; i < Words.size(); ++i)
	{
		++Count;
		++Map[Words[i]];
		if (Words[i][0] != Words[i - 1][Words[i - 1].size() - 1]
			|| Words[i].size() <= 1 || Map[Words[i]] > 1)
		{
			bFail = true;
			break;
		}
	}

	//@번호, 차례,
	if (bFail)
	{
		Answer[0] = (Count % N) + 1;
		Answer[1] = (Count / N) + 1;
	}

	return Answer;
}

int main()
{
	int N = 3;
	//[tank, kick, know, wheel, land, dream, mother, robot, tank]
	vector<string> Insert;
	Insert.push_back("tank");
	Insert.push_back("kick");
	Insert.push_back("know");
	Insert.push_back("wheel");
	Insert.push_back("land");
	Insert.push_back("dream");
	Insert.push_back("mother");
	Insert.push_back("robot");
	Insert.push_back("tank");

	vector<int> Result = solution(N, Insert);

	return 0;
}

