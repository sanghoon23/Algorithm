#include "pch.h"
#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

const int StartNumber = 65;
const int EndNumber = 90;

//@최소 변경 횟수 리턴
int AlphaHandle(char CurrentChar, char Change)
{
	if (CurrentChar == Change) return 0;

	int CurrentValue = CurrentChar;
	int ChangeValue = Change;

	//@Up
	int UpCount = 0;
	while (1)
	{
		if (CurrentValue == ChangeValue) break;

		if (CurrentValue > EndNumber)
		{
			CurrentValue = StartNumber;
			continue;
		}
		++CurrentValue; //@++
		++UpCount; //@++
	}

	//@Down
	CurrentValue = CurrentChar;
	int DownCount = 0;
	while (1)
	{
		if (CurrentValue == ChangeValue) break;

		if (CurrentValue < StartNumber)
		{
			CurrentValue = EndNumber;
			continue;
		}
		--CurrentValue; //@--
		++DownCount; //@++
	}

	if (UpCount > DownCount) return DownCount;
	else return UpCount;
}

bool CheckA(string& name, int FromIndex, int EndIndex, bool bReverse)
{
	//@Forward
	if (bReverse == false)
	{
		for (int i = FromIndex; i < EndIndex; ++i)
		{
			if (name[i] != 'A') return true;
		}

		return false;
	}
	//@Reverse
	else
	{
		for (int i = FromIndex + 1; i > EndIndex; --i)
		{
			if (name[i] != 'A') return true;
		}

		return false;
	}
}

int GetACount(string& str, int Start, int End)
{
	int Result = 0;
	for (int i = Start; i < End; ++i)
	{
		if (str[i] == 'A') ++Result;
	}

	return Result;
}

int solution(string name)
{
	int Min = 0;

	int size = name.size();

	int StartIndex = 0;
	int EndIndex = size;
	while (1)
	{
		if (EndIndex < 0) break;

		string TempStr(size, 'A');
		int Value = 0;
		int RetIndex = 0;

		int ACount = 0;
		int CurrentIndex = 0;
		Value += AlphaHandle(TempStr[0], name[0]);
		for (int i = StartIndex; i < EndIndex - 1; ++i)
		{
			if (CheckA(name, i + 1, EndIndex, false) == false)
			{
				break;
			}

			CurrentIndex = i + 1;
			Value += 1;
			Value += AlphaHandle(TempStr[i + 1], name[i + 1]);
		}

		//@++CurrentIndex
		Value += CurrentIndex;

		for (int j = size - 1; j >= EndIndex; --j)
		{
			if (CheckA(name, j, EndIndex - 1, true) == false)
				break;

			Value += 1;
			Value += AlphaHandle(TempStr[j], name[j]);
		}


		//@Calc Min
		if (Min == 0) Min = Value;

		if (Min != 0 && Value < Min) Min = Value;

		//@Index
		--EndIndex;
	}

	return Min;
}

int main()
{
	//string Name = "JAA";
	//string Name = "JEROEN";
	//string Name = "AABAAAAA";
	//string Name = "AABA";
	//string Name = "JAZ";
	string Name = "BBAAB";
	//string Name = "CANAAAAANAN";

	int Result = solution(Name);

	return 0;
}

