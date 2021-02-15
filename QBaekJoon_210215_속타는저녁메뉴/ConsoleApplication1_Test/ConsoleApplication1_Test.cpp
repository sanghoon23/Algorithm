#include "pch.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;
#define FASTIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
int N;
string T, P;

vector<int> Search(string& Str)
{
	int NSize = Str.size();
	vector<int> Ret(NSize);
	int Begin = 1, Match = 0;
	while (Begin + Match < NSize)
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

int Find(string& T, string& P)
{
	int Ret = 0;
	vector<int> Pi = Search(P);
	int NT = T.size(), NP = P.size();
	int Begin = 0, Match = 0;
	while (Begin <= NT - NP)
	{
		if (Match < NP && T[Begin + Match] == P[Match])
		{
			++Match;
			if (Match == NP) ++Ret;
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

int GetGCD(int A, int B)
{
	if (B == 0) return A;
	return GetGCD(B, A % B);
}

int main()
{
	FASTIO;
	cin >> N;
	char Input;
	for (int i = 0; i < N; ++i)
	{
		cin >> Input;
		P.push_back(Input);
	}
	for (int i = 0; i < N; ++i)
	{
		cin >> Input;
		T.push_back(Input);
	}
	T = T + T;
	T.pop_back();
	int Upper = Find(T, P), Down = N;
	int R = GetGCD(Upper, Down);
	cout << Upper / R << "/" << Down / R;
	return 0;
}

