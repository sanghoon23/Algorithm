#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int N = 0, K = 0, Answer = 0;

bool Check(vector<int>& Holl, int A)
{
	for (int i = 0; i < Holl.size(); ++i)
	{
		if (Holl[i] == A) return true;
	}
	return false;
}

int FindIndex(vector<int>& V, int A, int Index)
{
	for (int i = Index; i < V.size(); ++i)
	{
		if (V[i] == A)
			return i;
	}
	return V.size();
}

int main()
{
	cin >> N >> K;

	vector<int> V(K);
	for (int i = 0; i < K; ++i)
		cin >> V[i];

	vector<int> Holl;
	for (int j = 0; j < V.size(); ++j)
	{
		if (Check(Holl, V[j]) == false && Holl.size() < N)
		{
			Holl.push_back(V[j]);
		}
		else if (Check(Holl, V[j]) == false && Holl.size() >= N)
		{
			int Max = 0, MI = 0;
			for (int k = 0; k < Holl.size(); ++k)
			{
				int T = FindIndex(V, Holl[k], j + 1);
				if (Max < T)
				{
					Max = T; MI = k;
				}
			}
			Holl[MI] = V[j];
			++Answer;
		}
	}

	cout << Answer;
	return 0;
}

