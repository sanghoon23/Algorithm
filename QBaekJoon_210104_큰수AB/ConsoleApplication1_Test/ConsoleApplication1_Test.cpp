#include "pch.h"
#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
using namespace std;
string A, B;
int Temp[100001] = { 0, };
string Solve(string A, string B)
{
	memset(Temp, 0, sizeof(Temp));

	string Ret;
	if (B.size() > A.size()) swap(A, B);
	reverse(A.begin(), A.end());
	reverse(B.begin(), B.end());

	for (int j = 0; j < A.size(); ++j)
	{
		int R = 0;
		if(j < B.size()) R = (A[j] - '0') + (B[j] - '0') + Temp[j];
		else R = (A[j] - '0') + Temp[j];

		if (R >= 10) ++Temp[j + 1];
		R %= 10;
		Ret.push_back(R + '0');
	}
	if (Temp[A.size()] != 0) Ret.push_back('1');
	reverse(Ret.begin(), Ret.end());
	return Ret;
}
int main()
{
	cin >> A >> B;
	cout << Solve(A, B) << '\n';
	return 0;
}

