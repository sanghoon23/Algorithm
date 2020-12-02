#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N = 0;
int F = 0, S = 0;

bool Compare(pair<int, int> A, pair<int, int> B)
{
	if (A.second == B.second)
	{
		return A.first < B.first;
	}
	return (A.second) < (B.second);
}

int main()
{
	cin >> N;
	vector<pair<int, int>> Temp;
	for (int i = 0; i < N; ++i)
	{
		cin >> F;
		cin >> S;
		Temp.push_back({ F,S });
	}
	sort(Temp.begin(), Temp.end(), Compare);

	int Answer = 1;
	int V = Temp[0].second;
	for (int k = 1; k < N; ++k)
	{
		if (Temp[k].first < V) continue;

		V = Temp[k].second;
		++Answer;
	}

	cout << Answer;
	return 0;
}

