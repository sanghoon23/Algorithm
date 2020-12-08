#include "pch.h"
#include <iostream>
#include <vector>

using namespace std;

int N = 0;
double Answer = 0.0;
double Percentage[4] = { 0.0, };
pair<int, int> Dir[4] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };
bool Visited[50][50] = { false, };

void DFS(int Y, int X, double Percent, int Count)
{
	if (Count >= N)
	{
		Answer += Percent;
		return;
	}

	for (int i = 0; i < 4; ++i)
	{
		int YY = Y + Dir[i].first, XX = X + Dir[i].second;
		if (X < 0 || X >= 50 || Y < 0 || Y >= 50) continue;
		if (Visited[YY][XX] == false)
		{
			Visited[YY][XX] = true;
			DFS(YY, XX, Percent * Percentage[i], Count + 1);
			Visited[YY][XX] = false;
		}
	}
}

int main()
{
	cin >> N;
	for (int i = 0; i < 4; ++i)
	{
		double In;
		cin >> In;
		Percentage[i] = In * 0.01;
	}

	Visited[N][N] = true;
	DFS(N, N, 1.0, 0);

	cout.precision(10); //@소수점 고정.
	cout << Answer << endl;
	//printf("%.9f", Answer);
	return 0;
}

