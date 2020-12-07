#include "pch.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int N = 0, Answer = 0;
string Str = "";

int main()
{
	cin >> N >> Str;
	Answer = N;
	bool bFind = false;
	for (int i = 0; i < Str.size(); ++i)
	{
		if (Str[i] == 'L') { --Answer; ++i; bFind = true; }
	}
	if (bFind) ++Answer;

	cout << Answer;
	return 0;
}

