#include "pch.h"
#include <iostream>
#include <queue>
using namespace std;
#define FASTIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define LL long long
int N;
int main()
{
	FASTIO;
	cin >> N;
	priority_queue<LL> PQ;
	for (int i = 0; i < N; ++i)
	{
		LL Input; cin >> Input;
		PQ.push(Input);
	}
	LL Answer = 0, Count = 0;
	while (!PQ.empty())
	{
		LL Cost = PQ.top();
		PQ.pop();
		LL Sum = Cost - Count;
		if (Sum <= 0) break;
		Answer += Sum;
		++Count;
	}
	cout << Answer;
	return 0;
}

