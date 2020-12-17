#include "pch.h"
#include <iostream>
#include <string>

using namespace std;
char Temp[4] = { 'U', 'C', 'P', 'C' };
int main()
{
	string Str = "";
	getline(cin, Str);

	int Idx = 0;
	bool bFind = false;
	for (int i = 0; i < Str.size(); ++i)
	{
		if (Str[i] == Temp[Idx]) ++Idx;
		if (Idx >= 4) { bFind = true; break; }
	}
	if (bFind) cout << "I love UCPC";
	else cout << "I hate UCPC";
	return 0;
}

