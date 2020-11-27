#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

struct Tree
{
	char Ch;
	int Num = 0;
	struct Tree* Next[26] = { nullptr, };
public:
	Tree(char C) { Ch = C; ++Num; }

	Tree* InsertNext(char C)
	{
		int Cnu = C - 'a';
		if (Next[Cnu] == nullptr) Next[Cnu] = new Tree(C);
		else ++(Next[Cnu]->Num);

		return Next[Cnu];
	}

	Tree* GetNext(char C)
	{
		int Cnu = C - 'a';
		if (Next[Cnu] == nullptr) return nullptr;
		return Next[Cnu];
	}

	int GetNum() { return Num; }

};

struct Tree* Root[26] = { nullptr, };

void Insert(string Str)
{
	int Index = 0, Cnu = Str[Index] - 'a';
	struct Tree* Rt = nullptr;
	if (Root[Cnu] == nullptr) Root[Cnu] = new Tree(Str[Index]);
	else (Root[Cnu]->Num)++;
	Rt = Root[Cnu];
	while (1)
	{
		++Index;
		if (Index >= Str.size()) break;
		Rt = Rt->InsertNext(Str[Index]);
	}
}

int Check(string Str)
{
	int Index = 0, Cnu = Str[Index] - 'a';
	struct Tree* Rt = Root[Cnu];
	if (Rt->Num == 1) return Index + 1;
	while (1)
	{
		++Index;
		if (Index >= Str.size()) break;
		Rt = Rt->GetNext(Str[Index]);
		if (Rt->GetNum() == 1)
			return Index + 1;
	}
	return Index;
}

int solution(vector<string> Words)
{
	int Answer = 0;

	for (int i = 0; i < Words.size(); ++i)
		Insert(Words[i]);

	for (int i = 0; i < Words.size(); ++i)
		Answer += Check(Words[i]);

	return Answer;
}

int main()
{

	return 0;
}

