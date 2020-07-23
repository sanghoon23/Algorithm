#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>
#include <queue>

using namespace std;

int solution(string arrangement)
{
	int Answer = 0;

	queue<char> Que;
	int Remain = 0;
	for (int i = 0; i < arrangement.size(); ++i)
	{
		if (arrangement[i] == '(' && arrangement[i + 1] == ')' && i != arrangement.size() - 1) continue;
		else if (i == 0)
		{
			Que.push(arrangement[i]);
			continue;
		}

		if (arrangement[i - 1] == '('&& arrangement[i] == ')')
		{
			Answer += (Que.size() + Remain);
			Remain = 0;
		}
		else if (arrangement[i - 1] == ')' && arrangement[i] == ')')
		{
			++Remain;
			Que.pop();
		}
		else Que.push(arrangement[i]);
	}

	return Answer + Remain;
}

int main()
{

	return 0;
}

