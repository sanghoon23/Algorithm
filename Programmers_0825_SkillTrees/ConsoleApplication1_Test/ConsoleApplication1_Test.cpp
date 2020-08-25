#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

struct Skill
{
	char Name = ' ';
	int Index = 999;
};

bool Compare(Skill A, Skill B)
{
	return A.Index < B.Index;
}

int solution(string skill, vector<string> skill_trees)
{
	int Answer = 0;

	for (int j = 0; j < skill_trees.size(); ++j)
	{
		vector<Skill> Temp;
		for (int i = 0; i < skill.size(); ++i)
		{
			Skill Insert;
			Insert.Name = skill[i];

			int Found = skill_trees[j].find(skill[i]);
			if (Found == std::string::npos)
			{
				Insert.Index = 999 + i;
			}
			else Insert.Index = Found;

			Temp.push_back(Insert);
		}

		sort(Temp.begin(), Temp.end(), Compare);
		bool bPossible = true;
		for (int s = 0; s < Temp.size(); ++s)
		{
			if (Temp[s].Name != skill[s]) bPossible = false;
		}

		if (bPossible) ++Answer;
	}

	return Answer;
}

int main()
{
	//"CBD"	["BACDE", "CBADF", "AECB", "BDA"]	2

	string InStr = "CBD";

	vector<string> In;

	//@Test Case - 1
	In.push_back("BACDE");
	In.push_back("CBADF");
	In.push_back("AECB");
	In.push_back("BDA");

	//@Test Case - 2
	//In.push_back("BACDE");
	//In.push_back("CBADF");
	//In.push_back("AECB");
	//In.push_back("BDA");
	//In.push_back("AQWER");

	//@Test Case - 3
	In.push_back("AFG");

	int Result = solution(InStr, In);


	return 0;
}

