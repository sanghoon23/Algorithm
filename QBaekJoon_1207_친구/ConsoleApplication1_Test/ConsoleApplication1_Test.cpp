#include "pch.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;
#define max(a, b) (((a) > (b)) ? (a) : (b));
int N = 0, Answer = 0;
vector<string> Friends;
int main()
{
	cin >> N;
	Friends.resize(N);
	for (int i = 0; i < N; ++i)
		cin >> Friends[i];

	for (int k = 0; k < N; ++k)
	{
		vector<bool> Visited(N, false);
		for (int j = 0; j < Friends[k].size(); ++j)
		{
			if (Friends[k][j] == 'Y')
			{
				Visited[j] = true;
				for (int i = 0; i < Friends[j].size(); ++i)
				{
					if (Friends[j][i] == 'Y' && Visited[i] == false)
					{
						Visited[i] = true;
					}
				}
			}
		}

		int Count = 0;
		for (int i = 0; i < Visited.size(); ++i)
		{
			if (Visited[i])
				++Count;
		}

		Answer = max(Answer, Count - 1);
	}

	cout << Answer << endl;
	return 0;
}

