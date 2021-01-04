#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N = 0, K = 0, Answer = 0;
int main()
{
	cin >> N >> K;
	if (N <= K) { cout << Answer; exit(0); }
	vector<int> Board(N, 0);
	for (int i = 0; i < N; ++i)
		cin >> Board[i];

	sort(Board.begin(), Board.end());

	vector<int> Dist;
	for (int i = 0; i < N - 1; ++i)
		Dist.push_back(Board[i + 1] - Board[i]);

	sort(Dist.begin(), Dist.end());
	for (int i = 0; i < N - K; ++i)
		Answer += Dist[i];
	cout << Answer << '\n';
	return 0;
}

