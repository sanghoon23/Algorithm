#include "pch.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;
string Str;
bool Visited[51];
vector<int> Answer;
void Solve(int Idx, vector<int> Vec)
{
	if (Idx >= Str.size())
	{
		for (int k = 0; k < Vec.size(); ++k)
			if (Visited[Vec[k] - 1] == false) return;

		Answer = Vec;
		return;
	}
	int F = Str[Idx] - '0';
	if (Visited[F] == false)
	{
		if (F != 0)
		{
			Visited[F] = true;
			Vec.push_back(Str[Idx] - '0');
			Solve(Idx + 1, Vec);
			Vec.pop_back();
			Visited[F] = false;
		}
	}
	if (Idx + 1 < Str.size())
	{
		int S = Str[Idx + 1] - '0';
		S = F * 10 + S;
		if (S <= 50 && Visited[S] == false)
		{
			Visited[S] = true;
			Vec.push_back(S);
			Solve(Idx + 2, Vec);
			Vec.pop_back();
			Visited[S] = false;
		}
	}
}

int main()
{
	cin >> Str;
	Visited[0] = true;
	Solve(0, vector<int>());
	for (int i = 0; i < Answer.size(); ++i)
		cout << Answer[i] << " ";
	return 0;
}

