#include "pch.h"
#include <iostream>
#include <vector>
#include <string.h>

using namespace std;
int N, Input;
bool Solve(int Num)
{
	if (Num == 1) return false;
	for (int i = 2; i <= Num / 2; ++i)
		if (Num % i == 0) return false;
	return true;
}
int main()
{
	cin >> N;
	int Answer = 0;
	for (int i = 0; i < N; ++i)
	{
		cin >> Input;
		if (Solve(Input) == true) ++Answer;
	}
	cout << Answer;
	return 0;
}

