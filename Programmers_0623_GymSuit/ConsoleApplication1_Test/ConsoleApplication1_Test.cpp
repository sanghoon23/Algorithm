#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve)
{
	int Answer = n - lost.size();

	vector<int> TempLost;
	vector<bool> Check(reserve.size(), false);
	for (int s = 0; s < lost.size(); ++s)
	{
		for (int t = 0; t < reserve.size(); ++t)
		{
			if (lost[s] == reserve[t])
			{
				Check[t] = true;
				++Answer;
				break;
			}
			else if (t == reserve.size() - 1)
			{
				TempLost.push_back(lost[s]);
			}
		}
	}


	for (int j = 0; j < TempLost.size(); ++j)
	{
		for (int i = 0; i < reserve.size(); ++i)
		{
			if (Check[i] == true) continue;
			if (reserve[i] - 1 == TempLost[j] || reserve[i] + 1 == TempLost[j])
			{
				++Answer;
				Check[i] = true;
				break;
			}
		}
	}

	return Answer;
}

int main()
{
	int N = 5; //@전체 학생 수 

	vector<int> Lost; // 체육복을 잃어버린

	vector<int> Reserve; // 여벌의 체육복을 가진


	int Result = solution(N, Lost, Reserve);

	return 0;
}

