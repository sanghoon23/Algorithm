#include "pch.h"
#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <queue>

using namespace std;

class MyCompare
{
public:
	bool operator()(int a, int b) //@b 가 들어오는 값.
	{
		return a > b;
	}
};

int solution(vector<int> scoville, int K)
{
	priority_queue<int, vector<int>, MyCompare> PQ;
	for (int i = 0; i < scoville.size(); ++i)
	{
		PQ.push(scoville[i]);
	}

	int Result = 0;
	int Min = PQ.top();
	int QueueSize = PQ.size();
	while (Min <= K && QueueSize >= 2)
	{
		int OneValue = PQ.top();
		PQ.pop();
		int TwoValue = PQ.top();
		PQ.pop();

		int MixValue = OneValue + (TwoValue * 2);
		PQ.push(MixValue);

		++Result;

		QueueSize = PQ.size();
		Min = PQ.top();
	}

	if (Result == 0 || Min < K)
		return -1;

	return Result;
}

int main()
{
	int K = 7;
	
	vector<int> Insert;
	Insert.push_back(2);
	Insert.push_back(1);
	Insert.push_back(3);
	Insert.push_back(9);
	Insert.push_back(10);
	Insert.push_back(12);

	int Result = solution(Insert, K);

	return 0;
}

