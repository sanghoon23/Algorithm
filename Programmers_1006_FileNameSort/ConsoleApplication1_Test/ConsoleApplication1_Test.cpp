#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

struct File
{
	string Head = "";
	int Number = 0;
	string Tail = "";
	string Origin = "";
};

File Change(string Str)
{
	File Ret;
	Ret.Origin = Str;

	int EndHead = 0, IndexNumber = 0, EndNumber = Str.size() - 1, IndexTail = Str.size();
	for (int i = 0; i < Str.size(); ++i) //@Head
	{
		Str[i] = tolower(Str[i]);
		if (Str[i] >= '0' && Str[i] <= '9')
		{
			EndHead = i;
			IndexNumber = i;
			break;
		}
	}

	for (int i = IndexNumber; i < Str.size(); ++i) //@Number
	{
		if (Str[i] < '0' || Str[i] > '9')
		{
			EndNumber = i - IndexNumber;
			IndexTail = i;
			break;
		}
	}

	while (1)
	{
		if (Str[IndexNumber] != '0' || IndexNumber + 1 == IndexTail) break;
		else ++IndexNumber, --EndNumber;
	}

	Ret.Head = Str.substr(0, EndHead);
	string StrNum = Str.substr(IndexNumber, EndNumber);
	Ret.Number = atoi(StrNum.c_str());
	Ret.Tail = Str.substr(IndexTail, Str.size() - IndexTail);
	return Ret;
}

bool Compare(File A, File B)
{
	if (A.Head != B.Head)
		return A.Head < B.Head;

	if (A.Number != B.Number)
		return A.Number < B.Number;

	return false;
}

vector<string> solution(vector<string> Files)
{
	vector<string> Answer;

	vector<File> Temp;
	for (int i = 0; i < Files.size(); ++i)
	{
		File Insert = Change(Files[i]);
		Temp.push_back(Insert);
	}

	stable_sort(Temp.begin(), Temp.end(), Compare); //@@@@@@@@@@@@@@@Stable Sort...
	for (int i = 0; i < Temp.size(); ++i)
		Answer.push_back(Temp[i].Origin);

	return Answer;
}

int main()
{
	/*
	foo9.txt	foo	9	.txt
	foo010bar020.zip	foo	010	bar020.zip
	F-15	F-	15	(빈 문자열)
	*/

	vector<string> Insert;
	Insert.push_back("foo9.txt");
	Insert.push_back("Foo010bar020.zip");
	Insert.push_back("F-15");

	vector<string> Result = solution(Insert);

	return 0;
}

