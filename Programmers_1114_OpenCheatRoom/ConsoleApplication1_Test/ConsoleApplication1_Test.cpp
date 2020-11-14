#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <algorithm>

using namespace std;

map<string, string> Map; //@UserID, NickName
vector<string> Temp; //@UserID

void Calc(string Str)
{
	string Data[3] = { "", };
	int Index = 0;
	for (int j = 0; j < 2; ++j)
	{
		for (int i = Index; i < Str.size(); ++i)
		{
			if (Str[i] == ' ') { Data[j] = Str.substr(Index, i - Index); Index = i + 1; break; }
		}
	}
	Data[2] = Str.substr(Index, Str.size());

	if (Data[0] == "Enter") Temp.push_back(Data[1]);
	else if (Data[0] == "Leave") return;

	Map[Data[1]] = Data[2];
}

string Print(string Str)
{
	string Data[3] = { "", };
	int Index = 0;
	for (int j = 0; j < 2; ++j)
	{
		for (int i = Index; i < Str.size(); ++i)
		{
			if (Str[i] == ' ') { Data[j] = Str.substr(Index, i - Index); Index = i + 1; break; }
		}
	}
	Data[2] = Str.substr(Index, Str.size());
	string Ret = "";
	if (Data[0] == "Enter") Ret += (Map[Data[1]] + "님이 들어왔습니다.");
	else if (Data[0] == "Leave") Ret += (Map[Data[2]] + "님이 나갔습니다.");
	return Ret;
}

vector<string> solution(vector<string> Record)
{
	vector<string> Answer;

	for (int i = 0; i < Record.size(); ++i)
		Calc(Record[i]);

	for (int i = 0; i < Record.size(); ++i)
	{
		if (Record[i][0] == 'C') continue;
		Answer.push_back(Print(Record[i]));
	}

	return Answer;
}

int main()
{
	/*
	"Enter uid1234 Muzi",
	"Enter uid4567 Prodo",
	"Leave uid1234",
	"Enter uid1234 Prodo",
	"Change uid4567 Ryan"
	*/

	vector<string> In;
	In.push_back("Enter uid1234 Muzi");
	In.push_back("Enter uid4567 Prodo");
	In.push_back("Leave uid1234");
	In.push_back("Enter uid1234 Prodo");
	In.push_back("Change uid4567 Ryan");

	vector<string> Result = solution(In);

	return 0;
}

