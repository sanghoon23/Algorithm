#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

static vector<vector<string>> Answer;

bool Compare(string& Banned, string& Str)
{
	if (Banned.size() != Str.size()) return false;

	for (int i = 0; i < Banned.size(); ++i)
	{
		if (Banned[i] == '*') continue;
		if (Banned[i] != Str[i]) return false;
	}

	return true;
}

void DFS(vector<string>& User_Id, vector<string>& Banned_Id, vector<bool>& Checked, vector<string> Result, int Index)
{
	if (Index >= Banned_Id.size())
	{
		sort(Result.begin(), Result.end());
		bool bInning = false;
		for (int j = 0; j < Answer.size(); ++j)
		{
			int Count = 0;
			for (int i = 0; i < Answer[j].size(); ++i)
			{
				if (Answer[j][i] == Result[i]) ++Count;
			}

			if (Count == Answer[j].size())
			{
				bInning = true;
				break;
			}
		}

		if (bInning == false)
		{
			Answer.push_back(Result);
		}

		return;
	}

	for (int i = 0; i < User_Id.size(); ++i)
	{
		if (Compare(Banned_Id[Index], User_Id[i]) == true && Checked[i] == false)
		{
			Checked[i] = true;
			vector<string> Insert = Result;
			Insert.push_back(User_Id[i]);
			int InsertIndex = Index + 1;
			DFS(User_Id, Banned_Id, Checked, Insert, InsertIndex);
			Checked[i] = false;
		}
	}
}

int solution(vector<string> user_id, vector<string> banned_id)
{
	vector<bool> Checked(user_id.size(), false);
	vector<string> Result;
	DFS(user_id, banned_id, Checked, Result, 0);

	return Answer.size();
}

int main()
{
	vector<string> UserID;
	UserID.push_back("frodo");
	UserID.push_back("fradi");
	UserID.push_back("crodo");
	UserID.push_back("abc123");
	UserID.push_back("frodoc");

	vector<string> BannedID;
	BannedID.push_back("*rodo");
	BannedID.push_back("*rodo");
	BannedID.push_back("******");

	int Result = solution(UserID, BannedID);

	return 0;
}

