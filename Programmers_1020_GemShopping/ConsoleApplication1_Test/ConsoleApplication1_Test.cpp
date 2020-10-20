#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <algorithm>

using namespace std;

//vector<int> solution(vector<string> Gems)
//{
//	vector<int> Answer(2);
//
//	map<string, vector<int>> Map;
//
//	pair<int, int> Calc = { 0, Gems.size() - 1 };
//	for (int i = 0; i < Gems.size(); ++i)
//		Map[Gems[i]].push_back(i);
//
//	while (Calc.second >= 0)
//	{
//		bool bFind = false;
//		for (int i = Map[Gems[Calc.second]].size() - 1; i >= 0; --i)
//		{
//			if (Map[Gems[Calc.second]][i] < Calc.second)
//			{
//				bFind = true;
//				--Calc.second;
//				break;
//			}
//		}
//
//		if (bFind == false) break;
//	}
//
//	while (Calc.first < Calc.second - 1)
//	{
//		bool bFind = false;
//		for (int i = 0; i < Map[Gems[Calc.first]].size(); ++i)
//		{
//			if (Map[Gems[Calc.first]][i] > Calc.first && Map[Gems[Calc.first]][i] < Calc.second)
//			{
//				bFind = true;
//				++Calc.first;
//				break;
//			}
//		}
//
//		if (bFind == false) break;
//	}
//
//
//	Answer[0] = Calc.first + 1;
//	Answer[1] = Calc.second + 1;
//	return Answer;
//}

//vector<int> solution(vector<string> Gems)
//{
//	vector<int> Answer(2);
//	Answer[0] = 1;
//	Answer[1] = Gems.size();
//
//	map<string, int> Map, Temp;
//	for (int i = 0; i < Gems.size(); ++i)
//		Map[Gems[i]] += 1;
//
//	int TotalSize = Map.size(), Dist = Gems.size() - 1;
//	int Start = 0, End = 0;
//	while (End < Gems.size())
//	{
//		Temp[Gems[End]] += 1;
//
//		if (TotalSize == Temp.size())
//		{
//			while (1)
//			{
//				Temp[Gems[Start]] -= 1;
//				if (Temp[Gems[Start]] <= 0) break;
//				++Start;
//			}
//
//			while (1)
//			{
//				Temp[Gems[End]] -= 1;
//				if (Temp[Gems[End]] <= 0) break;
//				--End;
//			}
//
//			if (End - Start < Dist)
//			{
//				Answer[0] = Start + 1;
//				Answer[1] = End + 1;
//				Dist = End - Start;
//			}
//			Temp.clear();
//			++End;
//			Start = End;
//			continue;
//		}
//
//		++End;
//	}
//
//	return Answer;
//}
//
//vector<int> solution(vector<string> Gems)
//{
//	vector<int> Answer(2);
//	Answer[0] = 1;
//	Answer[1] = Gems.size();
//
//	map<string, int> Map, Temp;
//	for (int i = 0; i < Gems.size(); ++i)
//		Map[Gems[i]] += 1;
//
//	int TotalSize = Map.size(), Dist = Gems.size() - 1;
//	int Start = 0, End = 0;
//	int I = 0;
//	while (I < Gems.size())
//	{
//		Start = I;
//		End = I;
//		while (End < Gems.size())
//		{
//			Temp[Gems[End]] += 1;
//			if (Temp.size() == TotalSize)
//			{
//				if (End - Start < Dist)
//				{
//					Answer[0] = Start + 1;
//					Answer[1] = End + 1;
//					Dist = End - Start;
//				}
//				break;
//			}
//			++End;
//		}
//
//		Temp.clear();
//		++I;
//	}
//
//	return Answer;
//}

vector<int> solution(vector<string> Gems)
{
	vector<int> Answer(2);
	Answer[0] = 1;
	Answer[1] = Gems.size();

	map<string, int> Map, Temp;
	for (int i = 0; i < Gems.size(); ++i)
		Map[Gems[i]] += 1;

	int TotalSize = Map.size(), Dist = Gems.size() - 1;
	int Start = 0, End = 0;
	while (1)
	{
		if (Temp.size() == TotalSize)
		{
			while (1)
			{
				Temp[Gems[Start]] -= 1;
				if (Temp[Gems[Start]] <= 0)
				{
					Temp.erase(Gems[Start]);
					++Start;
					break;
				}
				++Start;
			}

			if (End - Start < Dist)
			{
				Answer[0] = Start;
				Answer[1] = End;
				Dist = End - Start;
			}
		}
		else
		{
			Temp[Gems[End]] += 1;
			++End;
		}

		if (End > Gems.size() - 1 && Temp.size() != TotalSize) break;
	}

	return Answer;
}

int main()
{
	vector<string> Insert;
	//Insert.push_back("XYZ");
	//Insert.push_back("XYZ");
	//Insert.push_back("XYZ");

	//Insert.push_back("A");
	//Insert.push_back("B");
	//Insert.push_back("C");
	//Insert.push_back("B");
	//Insert.push_back("D");

	//Insert.push_back("D");
	//Insert.push_back("R");
	//Insert.push_back("R");
	//Insert.push_back("D");
	//Insert.push_back("D");
	//Insert.push_back("E");
	//Insert.push_back("S");
	//Insert.push_back("D");

	Insert.push_back("A");
	Insert.push_back("B");
	Insert.push_back("B");
	Insert.push_back("B");
	Insert.push_back("C");
	Insert.push_back("A");
	Insert.push_back("B");
	Insert.push_back("C");

	vector<int> Result = solution(Insert);

	return 0;
}

