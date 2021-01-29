#include "pch.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;
#define FASTIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
int N;
bool Check(vector<int>& Temp, vector<int>& Board)
{
	for (int i = 0; i < N; ++i)
		if (Temp[i] != Board[i]) return false;

	return true;
}

int Solve(vector<int>& Temp, vector<int>& Board)
{
	int Ret = 0;
	for (int j = 1; j < N; ++j)
	{
		if (Temp[j - 1] == Board[j - 1]) continue;
		Temp[j] = !Temp[j];
		Temp[j - 1] = !Temp[j - 1];
		if(j != N - 1) Temp[j + 1] = !Temp[j + 1];

		++Ret;
	}
	return Ret;
}

int main()
{
	FASTIO;
	cin >> N;
	vector<int> Origin(N);
	string Str;
	cin >> Str;
	for (int i = 0; i < N; ++i)//@원본
		(Str[i] == '0') ? Origin[i] = 0 : Origin[i] = 1;

	vector<int> Board(N);//@변화
	cin >> Str;
	for(int i = 0; i < N; ++i)
		(Str[i] == '0') ? Board[i] = 0 : Board[i] = 1;

	int Answer = 0;
	vector<int> Temp = Origin;
	Answer += Solve(Temp, Board);
	if (Check(Temp, Board) == true) { cout << Answer; exit(0); }
	else
	{
		Temp = Origin;
		Answer = 1;
		Temp[0] = !Temp[0];
		Temp[1] = !Temp[1];
		Answer += Solve(Temp, Board);
		if (Check(Temp, Board) == true) cout << Answer;
		else cout << -1;
	}
	return 0;
}

