#include "pch.h"
#include <iostream>
#include <vector>

using namespace std;
int G = 0, P = 0, V = 0, Answer = 0;
vector<int> Parent;
int Find(int X)
{
	if (X <= 0 || Parent[X] == X) return X;
	Parent[X] = Find(Parent[X]);
	return Parent[X];
}

void Union(int X, int Y) //@Parent[X] = Y;
{
	X = Find(X);
	Y = Find(Y);
	if (X != Y) Parent[X] = Y;
}

int main()
{
	Parent.push_back(0);
	cin >> G >> P;
	for (int i = 0; i < G; ++i)
		Parent.push_back(i + 1);

	for (int i = 0; i < P; ++i)
	{
		cin >> V;
		if (Find(V) == 0) break;
		
		++Answer;
		int R = Find(V);
		Union(R, R - 1);
	}
	cout << Answer;
	return 0;
}

