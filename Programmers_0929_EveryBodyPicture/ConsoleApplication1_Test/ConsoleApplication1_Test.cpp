#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

/*
멍청하게 Value + 1 을 안했다.......
30분 넘게 보고 있었는데....
*/

int FindIndex(vector<char>& Temp, char Ch)
{
	for (int i = 0; i < Temp.size(); ++i)
	{
		if (Temp[i] == Ch)
			return i;
	}
	return -1;
}

bool Check(vector<string>& Data, vector<char>& Temp)
{
	int Num = 0;
	while (Num < Data.size())
	{
		char First = Data[Num][0], Second = Data[Num][2], Comp = Data[Num][3];
		int Value = Data[Num][4] - '0';
		int FirstIndex = FindIndex(Temp, First), SecondIndex = FindIndex(Temp, Second);
		int Calc = SecondIndex - FirstIndex;
		Calc = abs(Calc);

		if (Comp == '=' && Calc != Value + 1) //@같음
			return false;
		else if (Comp == '<' && Calc >= Value + 1) //@미만 
			return false;
		else if (Comp == '>' && Calc <= Value + 1) //* 문제의 근원지.... +1 을 안 붙였다..?ㅎ 그냥 위에 Value 선언시 +1 을 해버리는게 속편한거 같다. 오류를 적게 하기 위해서
			return false;

		++Num;
	}

	return true;
}

int solution(int N, vector<string> Data)
{
	int Answer = 0;
	vector<char> Temp = { 'A', 'C', 'F', 'J', 'M', 'N', 'R', 'T' };
	do
	{
		if (Check(Data, Temp) == true) //@적용된다면
			++Answer;

	} while (next_permutation(Temp.begin(), Temp.end()));

	return Answer;
}

int main()
{
	int N = 2;
	vector<string> Insert;
	Insert.push_back("N~F=0");
	Insert.push_back("R~T>2");

	int Result = solution(N, Insert);

	return 0;
}

