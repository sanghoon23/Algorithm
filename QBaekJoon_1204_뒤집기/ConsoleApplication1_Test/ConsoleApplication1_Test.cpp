#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int Result[2] = { 0, };
int Answer = 0;
int main()
{
	string Str;
	cin >> Str;
	
	char CHVal = Str[0];
	Result[CHVal - 48] += 1;
	for (int i = 1; i < Str.size(); ++i)
	{
		if (CHVal == Str[i]) continue;
		CHVal = Str[i];
		Result[CHVal - 48] += 1;
	}
	Answer = min(Result[0], Result[1]);

	cout << Answer;
	return 0;
}

