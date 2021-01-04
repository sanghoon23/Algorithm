#include "pch.h"
#include <iostream>
#include <vector>
using namespace std;
long long Fac[21];
int N = 0, K = 0;
bool Visited[21];
int main()
{
	Fac[0] = 1;
	for (long long i = 1; i <= 20; ++i)
		Fac[i] = Fac[i - 1] * i;

	cin >> N >> K;
	if (K == 1)
	{
		long long Num = 0;
		cin >> Num;
		vector<int> Answer;
		for (int j = 1; j <= N; ++j)
		{
			for (int i = 1; i <= N; ++i)
			{
				if (Visited[i] == true) continue;

				if (Num > Fac[N - j])
				{
					Num -= Fac[N - j];
				}
				else
				{
					Answer.push_back(i);
					Visited[i] = true;
					break;
				}
			}
		}

		for (int i = 0; i < Answer.size(); ++i)
			cout << Answer[i] << ' ';
		cout << '\n';
	}
	else //@K == 2
	{
		long long Answer = 1;
		vector<int> Board(N + 1, 0);
		for (int i = 1; i <= N; ++i)
			cin >> Board[i];

		for (int j = 1; j <= N; ++j)
		{
			for (int i = 1; i < Board[j]; ++i)
			{
				if (Visited[i] == false)
				{
					Answer += Fac[N - j];
				}
			}
			Visited[Board[j]] = true;
		}
		cout << Answer << '\n';
	}
	return 0;
}

