#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <algorithm>

using namespace std;

int solution(int CacheSize, vector<string> Cities)
{
	if (CacheSize == 0) return Cities.size() * 5;

	int Answer = CacheSize * 5;
	for (int i = 0; i < Cities.size(); ++i)
		transform(Cities[i].begin(), Cities[i].end(), Cities[i].begin(), [](char c) { return tolower(c); });

	vector<string> Temp;
	map<string, int> Map;
	for (int i = 0; i < CacheSize; ++i)
	{
		Map[Cities[i]] += 1;
		Temp.push_back(Cities[i]);
		if (Map[Cities[i]] >= 2) Answer -= 4;
	}

	for (int j = CacheSize; j < Cities.size(); ++j)
	{
		bool bFind = false;
		int Index = 0;
		for (int i = 0; i < Temp.size(); ++i)
		{
			if (Temp[i] == Cities[j]) { bFind = true; Index = i; break; }
		}
		if (bFind) { Temp.erase(Temp.begin() + Index); Answer += 1; }
		else { Temp.erase(Temp.begin() + 0); Answer += 5; }
		Temp.push_back(Cities[j]);
	}

	return Answer;
}

int main()
{

	return 0;
}

