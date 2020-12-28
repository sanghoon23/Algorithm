#include "pch.h"
#include <iostream>
using namespace std;
long long A = 0, B = 0, C = 0;
int main()
{
	cin >> A >> B >> C;
	if (C - B <= 0) { cout << -1; exit(0); }
	cout << (A / (C - B)) + 1;
	return 0;
}

