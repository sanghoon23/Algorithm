#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N = 0;
vector<int> Minus;
vector<int> Plus;
int Input = 0;

int main()
{
	int MaxMinus = 0, MaxPlus = 0;
	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		cin >> Input;
		if (Input <= 0) Minus.push_back(Input);
		else Plus.push_back(Input);
	}
	sort(Minus.begin(), Minus.end());
	sort(Plus.begin(), Plus.end());

	if ((Minus.size()) % 2 == 1)
	{
		MaxMinus += Minus[Minus.size() - 1];
		Minus.erase(Minus.begin() + Minus.size() - 1);
	}
	reverse(Minus.begin(), Minus.end());

	for (int k = Minus.size() - 1; k > 0; --k)
	{
		MaxMinus += (Minus[k] * Minus[k - 1]);
		--k;
	}

	if ((Plus.size()) % 2 == 1)
	{
		MaxPlus += Plus[0];
		Plus.erase(Plus.begin());
	}

	for (int k = Plus.size() - 1; k > 0; --k)
	{
		if (Plus[k] <= 1 || Plus[k - 1] <= 1)
		{
			for (int v = k; v >= 0; --v)
				MaxPlus += Plus[v];

			break;
		}

		MaxPlus += (Plus[k] * Plus[k - 1]);
		--k;
	}

	cout << MaxMinus + MaxPlus;
	return 0;
}

