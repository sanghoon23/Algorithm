#include "pch.h"
#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int N = 0, M = 0;
long long Input = 0, Answer = 0;
struct Compare
{
	bool operator()(long long A, long long B) { return A > B; }
};
int main()
{
	cin >> N >> M;
	priority_queue<long long, vector<long long>, Compare> PQ;
	for (int i = 0; i < N; ++i)
	{
		cin >> Input;
		PQ.push(Input);
	}
	for (int k = 0; k < M; ++k)
	{
		long long F = PQ.top(); PQ.pop();
		long long S = PQ.top(); PQ.pop();
		PQ.push(F + S); PQ.push(F + S);
	}
	while (!PQ.empty())
	{
		Answer += PQ.top();
		PQ.pop();
	}
	cout << Answer;
	return 0;
}

