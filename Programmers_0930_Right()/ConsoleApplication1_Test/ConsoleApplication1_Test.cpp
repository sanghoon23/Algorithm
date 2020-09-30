#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>
#include <queue>

using namespace std;

bool solution(string S)
{
	queue<int> Que;
	for (int i = 0; i < S.size(); ++i)
	{
		if (S[i] == '(')
			Que.push(1);
		else
		{
			if (Que.empty()) return false;
			Que.pop();
		}
	}

	if (!Que.empty()) return false;
	return true;
}

int main()
{

	return 0;
}

