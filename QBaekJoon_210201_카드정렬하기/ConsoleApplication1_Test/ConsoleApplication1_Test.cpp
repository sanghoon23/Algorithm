#include "pch.h"
#include <iostream>
#include <vector>
#include <queue>

using namespace std;
#define FASTIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
int N;
int main()
{
	FASTIO;
	cin >> N;
	priority_queue<int> PQ;
	for (int i = 0; i < N; ++i)
	{
		int Input; cin >> Input;
		PQ.push(-Input);
	}
	int Answer = 0;
	while (!PQ.empty())
	{
		int F = -PQ.top(); PQ.pop();
		int S = 0;
		if (!PQ.empty())
		{
			S = -PQ.top(); PQ.pop();
		}
		int Insert = F + S;
		Answer += Insert;

		if (PQ.empty()) break;
		PQ.push(-(Insert));
	}
	if (N == 1) cout << 0;
	else cout << Answer;
	return 0;
}

