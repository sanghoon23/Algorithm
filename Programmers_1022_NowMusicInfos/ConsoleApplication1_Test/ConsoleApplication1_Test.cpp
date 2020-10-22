#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

struct Music
{
	int Index = 0, PlayTime = 0;
	string Name = "", Sheet = "";
};

int TimeCalc(string Time)
{
	int HourTime = (Time[0] - '0') * 600 + (Time[1] - '0') * 60;
	int MinTime = (Time[3] - '0') * 10 + (Time[4] - '0');
	return HourTime + MinTime;
}

Music Find(string Str)
{
	Music Ret;
	string EndTime = Str.substr(6, 5), StartTime = Str.substr(0, 5), MusicName = "";
	int FIndex = 0;
	for (int i = 12; i < Str.size(); ++i)
	{
		if (Str[i] == ',') { FIndex = i + 1; break; }
		else MusicName.push_back(Str[i]);
	}
	Ret.PlayTime = TimeCalc(EndTime) - TimeCalc(StartTime);
	Ret.Name = MusicName;
	Ret.Sheet = Str.substr(FIndex, Str.size());
	return Ret;
}

string solution(string M, vector<string> MusicInfos)
{
	vector<Music> Temp;
	for (int j = 0; j < MusicInfos.size(); ++j)
	{
		Music Muse = Find(MusicInfos[j]);
		Muse.Index = j;

		string Sheet = "";
		int Idx = 0, Count = 0;
		while (Count <= Muse.PlayTime) //*마지막에 ABC# 일 수 있다. 그래서 # 도 포햄해줘야함. (<= 인 이유)
		{
			Sheet.push_back(Muse.Sheet[Idx % Muse.Sheet.size()]);
			++Idx;
			if (Muse.Sheet[Idx % Muse.Sheet.size()] != '#') ++Count;
		}

		for (int i = 0; i < Sheet.size(); ++i)
		{
			bool bFind = true;
			if (M[0] == Sheet[i] && Sheet[i] != '#')
			{
				int MIndex = i;
				for (int k = 0; k < M.size(); ++k)
				{
					if (M[k] != Sheet[(k + i) % Sheet.size()]) { bFind = false; break; }
				}
				int LastIndex = i + M.size();
				if (bFind == true)
				{
					if (Sheet[(LastIndex) % Sheet.size()] != '#') { Temp.push_back(Muse); break; }
					else continue;
				}
			}
		}

		//if (Muse.PlayTime >= Muse.Sheet.size())
		//{
		//	for (int i = 0; i < Sheet.size(); ++i)
		//	{
		//		bool bFind = true;
		//		if (M[0] == Sheet[i])
		//		{
		//			int MIndex = i;
		//			for (int k = i; k < Sheet.size() + i; ++k)
		//			{
		//				if (k - MIndex >= M.size()) break;
		//				if (M[(k - MIndex) % M.size()] != Sheet[k % Sheet.size()]) { bFind = false; break; }
		//			}
		//			if (bFind == true) { Temp.push_back(Muse); break; }
		//		}
		//	}
		//}
		//else
		//{
		//	bool bFind = true;
		//	for (int i = 0; i < Sheet.size(); ++i)
		//	{
		//		if (i >= M.size()) break;
		//		if (M[i] != Sheet[i]) { bFind = false; break; }
		//	}
		//	if (bFind == true) { Temp.push_back(Muse); }
		//}
	}

	if(Temp.size() == 0) return "(None)";
	else if (Temp.size() == 1) return Temp[0].Name;

	Music Ret = Temp[0];
	for (int i = 1; i < Temp.size(); ++i)
	{
		if (Temp[i].PlayTime > Ret.PlayTime) Ret = Temp[i];
		else if(Temp[i].PlayTime == Ret.PlayTime)
		{
			if (Temp[i].Index < Ret.Index) Ret = Temp[i];
		}
	}
	return Ret.Name;
}

int main()
{
	//string M = "ABCDEFG";
	//vector<string> Insert = { "12:00,12:14,HELLO,CDEFGAB", "13:00,13:05,WORLD,ABCDEF" };

	//string M = "ABC";
	//vector<string> Insert = { "12:00,12:14,HELLO,C#DEFGAB", "13:00,13:05,WORLD,ABCDEF" };

	string M = "CCB";
	vector<string> Insert = { "03:00,03:10,FOO,CCB#CCB", "04:00,04:08,BAR,ABC" };

	solution(M, Insert);

	return 0;
}

