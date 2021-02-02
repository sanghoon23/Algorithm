#include "pch.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;
#define FASTIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
int N;
string Str;
vector<int> Search(string& Str)
{
	int StrSize = Str.size();
	int Begin = 1, Match = 0;
	vector<int> Ret(StrSize, 0);
	while (Begin + Match < StrSize)
	{
		if (Str[Begin + Match] == Str[Match])
		{
			++Match;
			Ret[Begin + Match - 1] = Match;
		}
		else
		{
			if (Match == 0) ++Begin;
			else
			{
				Begin += Match - Ret[Match - 1];
				Match = Ret[Match - 1];
			}
		}
	}
	return Ret;
}

int main()
{
	FASTIO;
	cin >> N; cin >> Str;
	vector<int> Result = Search(Str);
	cout << N - Result[N - 1] << '\n';
	return 0;
}

