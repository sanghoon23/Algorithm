#include "pch.h"
#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <string>

using namespace std;

bool Find(int n)
{
	if (n <= 0) return false;
	if (n == 1) return false;

	int last = n / 2;
	for (int i = 2; i < last + 1; ++i)
	{
		if (n % i == 0)
			return false;
	}

	return true;
}

void Loop(vector<string>& InsertedVec, string& CalcStr, vector<int> IndexVec, string InputStr)
{
	string str = InputStr;
	if (IndexVec.size() == CalcStr.length()) return;
	for (int i = 0; i < CalcStr.size(); ++i)
	{
		bool bIndex = false;
		for (int a : IndexVec)
			if (i == a) bIndex = true;
		if (bIndex == true) continue;

		if (InputStr[0] == '0')
			continue;

		string Inserstr = str;
		Inserstr += CalcStr[i];
		InsertedVec.push_back(Inserstr);

		vector<int> Index = IndexVec;
		Index.push_back(i);

		Loop(InsertedVec, CalcStr, Index, Inserstr);
	}
}

int solution(string numbers)
{
	//@조합될 수 있는 숫자들 찾기
	vector<string> AllNumbers;
	vector<int> Temp;
	Loop(AllNumbers, numbers, Temp, "");

	//@Insert
	int Result = 0;
	vector<int> CheckVec; //@중복체크
	for (int i = 0; i < AllNumbers.size(); ++i)
	{
		int Number = stoi(AllNumbers[i]);

		if (Find(Number) == false) continue;

		bool bCheck = false;
		for (int value : CheckVec)
			if (value == Number) bCheck = true;
		if (bCheck == true) continue;


		CheckVec.push_back(Number);
		++Result;
	}

	return Result;
}

int main()
{
	//string str = "7843";
	string str = "1234567";

	int Result = solution(str);

	return 0;
}

