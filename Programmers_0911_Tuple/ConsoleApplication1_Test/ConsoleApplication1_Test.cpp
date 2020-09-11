#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

bool Compare(vector<int>& A, vector<int>& B)
{
	return A.size() < B.size();
}

vector<int> solution(string s)
{
	vector<int> Answer;

	vector<vector<int>> Temp;

	int Index = 1;
	while (s.size() > Index)
	{
		if (s[Index] == '{')
		{
			++Index;
			vector<int> Insert;
			string str = "";
			for (int i = Index; i < s.size() - 1; ++i) //@문자에서 숫자만 구별
			{
				if (s[i] == '}')
				{
					Insert.push_back(atoi(str.c_str()));
					Temp.push_back(Insert);
					Index = i;
					break;
				}
				else if (s[i] == ',')
				{
					Insert.push_back(atoi(str.c_str()));
					str = "";
				}
				if (s[i] - '0' >= 0 && s[i] - '0' <= 9)
					str.push_back(s[i]);
			}
		}
		++Index;
	}

	sort(Temp.begin(), Temp.end(), Compare);
	Answer.push_back(Temp[0][0]);
	for (int j = 0; j < Temp.size(); ++j)
	{
		for (int i = 0; i < Temp[j].size(); ++i)
		{
			auto it = find(Answer.begin(), Answer.end(), Temp[j][i]);
			if (it == Answer.end()) Answer.push_back(Temp[j][i]);
		}
	}

	return Answer;

}

int main()
{
	//string s = "{{2},{2,1},{2,1,3},{2,1,3,4}}";

	string s = "{{20,111},{111}}";

	vector<int> Result = solution(s);

	return 0;
}

