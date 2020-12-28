#include "pch.h"
#include <iostream>
using namespace std;
int N = 0, A = 1;
int main()
{
	cin >> N;
	if (N == 1) { cout << 1; exit(0); }
	for (int i = 1; ; ++i)
	{
		A += (6 * i);
		if (N <= A) { cout << i + 1; break; }
	}
	return 0;
}

