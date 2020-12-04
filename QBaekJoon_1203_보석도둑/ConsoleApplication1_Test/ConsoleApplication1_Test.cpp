#include "pch.h"
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define pii pair<int, int>
using namespace std;
int N = 0, K = 0;
long long Answer = 0;

int main()
{
	cin >> N >> K;

	vector<pii> J;
	int M = 0, V = 0;
	for (int i = 0; i < N; ++i)
	{
		cin >> M >> V;
		J.push_back({ M, V }); //@무게, 가치
	}

	vector<int> B;
	int C = 0;
	for (int i = 0; i < K; ++i)
	{
		cin >> C;
		B.push_back(C);
	}

	sort(J.begin(), J.end()); //@보석
	sort(B.begin(), B.end()); //@가방

	priority_queue<int> PQ;
	int Index = 0;
	for (int i = 0; i < B.size(); ++i)
	{
		for (int k = Index; k < J.size(); ++k)
		{
			if (J[k].first <= B[i])
			{
				PQ.push(J[k].second);
				//++Index;
				Index = k + 1;
			}
			else break;
		}

		if (PQ.empty() == false)
		{
			Answer += (long long)PQ.top();
			PQ.pop();
		}
	}

	cout << Answer;
	return 0;
}

