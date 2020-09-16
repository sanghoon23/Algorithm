#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

//@Test Case 1
//int solution(int n, vector<int> money)
//{
//	int Answer = 0;
//	vector<int> Values;
//	for (int i = 0; i < money.size(); ++i)
//	{
//		int Temp = money[i];
//		int Multi = 1;
//		while (1)
//		{
//			Temp = money[i];
//			Temp *= Multi;
//			if (Temp > n) break;
//			else Values.push_back(Temp);
//
//			++Multi;
//		}
//	}
//
//	sort(Values.begin(), Values.end());
//
//	int Index = 0;
//	int Value = 0;
//	while (Index < Values.size())
//	{
//		for (int i = Index; i < Values.size(); ++i)
//		{
//			Value += Values[i];
//			if (Value >= n)
//			{
//				if (Value == n)
//					++Answer;
//
//				Value = 0;
//				(Index == i)
//					? Index = i + 1
//					: Index = i;
//				break;
//			}
//		}
//	}
//
//	return Answer;
//}

//@Test Case 2
//static int Answer = 0;
//
//void Check(vector<int>& Money, vector<bool> Visited, int Value, int n, int Index)
//{
//	if (Value >= n)
//	{
//		if (Value == n)
//			++Answer;
//
//		return;
//	}
//
//	for (int i = Index; i < Money.size(); ++i)
//	{
//		int Multi = 1;
//		if (Visited[i] == false)
//		{
//			Visited[i] = true;
//			int Insert = (Money[i] * Multi) + Value;
//			while (Insert <= n)
//			{
//				Insert = (Money[i] * Multi) + Value;
//				Check(Money, Visited, Insert, n, i + 1);
//				++Multi;
//			}
//			Visited[i] = false;
//		}
//	}
//}

//int solution(int n, vector<int> money)
//{
//	vector<bool> Visited(money.size(), false);
//	Check(money, Visited, 0, n, 0);
//
//	return Answer;
//}

//@Test Case 3 - DP

int able[100002] = { 0, };

int solution(int n, vector<int> money)
{
    int Answer = 0;

    able[0] = 1;
    for (int i = 1; i <= n; ++i)
    {
        if (i % money[0] == 0)
            able[i] = 1;
    }

    for (int j = 1; j < money.size(); ++j)
    {
        for (int i = 1; i <= n; ++i)
        {
            if(i >= money[j])
                able[i] += able[i - money[j]];
        }
    }

    return able[n];
}

int main()
{
	int n = 5;

	vector<int> Money;
	Money.push_back(1);
	Money.push_back(2);
	Money.push_back(5);

	int Result = solution(n, Money);

	return 0;
}

