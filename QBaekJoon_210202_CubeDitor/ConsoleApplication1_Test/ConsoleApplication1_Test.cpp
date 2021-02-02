#include "pch.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
#define FASTIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
string Str;
int Search(string& Str)
{
	int Ret = 0;
	int StrSize = Str.size();
	int Begin = 1, Match = 0;
	vector<int> Pi(StrSize, 0);
	while (Begin + Match < StrSize)
	{
		if (Str[Begin + Match] == Str[Match])
		{
			++Match;
			Pi[Begin + Match - 1] = Match;
			Ret = max(Ret, Match);

		}
		else
		{
			if (Match == 0) ++Begin;
			else
			{
				Begin += Match - Pi[Match - 1];
				Match = Pi[Match - 1];
			}
		}
	}
	return Ret;
}

int main()
{
	FASTIO;
	cin >> Str;
	int MMax = 0;
	for (int j = 0; j < Str.size(); ++j)
	{
		string Sub = Str.substr(j, Str.size());
		MMax = max(MMax, Search(Sub));
	}
	cout << MMax << '\n';
	return 0;
}

