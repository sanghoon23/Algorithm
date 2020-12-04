#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N = 0;
long long Answer = 0;
vector<int> Dist;
vector<int> Price;
int main()
{
	cin >> N;
	Dist.resize(N - 1);
	for (int i = 0; i < N - 1; ++i)
		cin >> Dist[i];

	Price.resize(N);
	for (int i = 0; i < N; ++i)
		cin >> Price[i];

	int D = 0, P = Price[0];
	for (int i = 1; i < Price.size(); ++i)
	{
		D += Dist[i - 1];
		if (Price[i] < P && i != Price.size() - 1)
		{
			Answer += (long long)D * (long long)P;
			P = Price[i];
			D = 0;
		}
	}
	Answer += (long long)D * (long long)P;

	cout << Answer;
	return 0;
}

