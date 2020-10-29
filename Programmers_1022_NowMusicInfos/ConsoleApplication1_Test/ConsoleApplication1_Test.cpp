#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <algorithm>

using namespace std;

//struct Music
//{
//	int Index = 0, PlayTime = 0;
//	string Name = "", Sheet = "";
//};
//
//int TimeCalc(string Time)
//{
//	int HourTime = (Time[0] - '0') * 600 + (Time[1] - '0') * 60;
//	int MinTime = (Time[3] - '0') * 10 + (Time[4] - '0');
//	return HourTime + MinTime;
//}
//
//Music Find(string Str)
//{
//	Music Ret;
//	string EndTime = Str.substr(6, 5), StartTime = Str.substr(0, 5), MusicName = "";
//	int FIndex = 0;
//	for (int i = 12; i < Str.size(); ++i)
//	{
//		if (Str[i] == ',') { FIndex = i + 1; break; }
//		else MusicName.push_back(Str[i]);
//	}
//	Ret.PlayTime = TimeCalc(EndTime) - TimeCalc(StartTime);
//	Ret.Name = MusicName;
//	Ret.Sheet = Str.substr(FIndex, Str.size());
//	return Ret;
//}
//
//string solution(string M, vector<string> MusicInfos)
//{
//	vector<Music> Temp;
//	for (int j = 0; j < MusicInfos.size(); ++j)
//	{
//		Music Muse = Find(MusicInfos[j]);
//		Muse.Index = j;
//
//		string Sheet = "";
//		int Idx = 0, Count = 0;
//		while (Count <= Muse.PlayTime) //*마지막에 ABC# 일 수 있다. 그래서 # 도 포햄해줘야함. (<= 인 이유)
//		{
//			Sheet.push_back(Muse.Sheet[Idx % Muse.Sheet.size()]);
//			++Idx;
//			if (Muse.Sheet[Idx % Muse.Sheet.size()] != '#') ++Count;
//		}
//
//		for (int i = 0; i < Sheet.size(); ++i)
//		{
//			bool bFind = true;
//			if (M[0] == Sheet[i] && Sheet[i] != '#')
//			{
//				int MIndex = i;
//				for (int k = 0; k < M.size(); ++k)
//				{
//					if (M[k] != Sheet[(k + i) % Sheet.size()]) { bFind = false; break; }
//				}
//				int LastIndex = i + M.size();
//				if (bFind == true)
//				{
//					if (Sheet[(LastIndex) % Sheet.size()] != '#') { Temp.push_back(Muse); break; }
//					else continue;
//				}
//			}
//		}
//	}
//
//	if(Temp.size() == 0) return "(None)";
//	else if (Temp.size() == 1) return Temp[0].Name;
//
//	Music Ret = Temp[0];
//	for (int i = 1; i < Temp.size(); ++i)
//	{
//		if (Temp[i].PlayTime > Ret.PlayTime) Ret = Temp[i];
//		else if(Temp[i].PlayTime == Ret.PlayTime)
//		{
//			if (Temp[i].Index < Ret.Index) Ret = Temp[i];
//		}
//	}
//	return Ret.Name;
//}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//#1029_ Token 화 시켜서 다시 풀기.

//string SingSheet[12] = { "C", "C#", "D", "D#", "E", "F", "F#", "G", "G#", "A", "A#", "B" };
pair<char, int> SingSheet[5] = { {'C',33}, {'D',34}, {'F',35}, {'G',36}, {'A',37}, };
map<char, int> Map;

struct Music
{
	int Index = 0, PlayTime = 0;
	string Name = "", Sheet = "";
};

int TimeCalc(string Time)
{
	return ((Time[0] - '0') * 600 + (Time[1] - '0') * 60) + ((Time[3] - '0') * 10 + (Time[4] - '0'));
}

string ChangeFlat(string Str)
{
	string Ret;
	int Index = 0;
	while(Index < Str.size())
	{
		if (Index + 1 < Str.size() && Str[Index + 1] == '#')
		{
			Ret.push_back(Map[Str[Index]]);
			++Index;
		}
		else Ret.push_back(Str[Index]);
		++Index;
	}
	return Ret;
}

Music Find(string Str)
{
	Music Ret;
	string StartTime = Str.substr(0, 5), EndTime = Str.substr(6, 5);
	Ret.PlayTime = TimeCalc(EndTime) - TimeCalc(StartTime);
	int FIndex = 0;
	for (int i = 12; i < Str.size(); ++i)
	{
		if (Str[i] == ',') { FIndex = i + 1; break; }
		Ret.Name.push_back(Str[i]);
	}
	Ret.Sheet = ChangeFlat(Str.substr(FIndex, Str.size()));
	return Ret;
}

string solution(string M, vector<string> MusicInfos)
{
	for (int i = 0; i < 5; ++i)
		Map[SingSheet[i].first] = SingSheet[i].second;

	string FlatM = ChangeFlat(M);

	vector<Music> Temp;
	for (int j = 0; j < MusicInfos.size(); ++j)
	{
		Music Muse = Find(MusicInfos[j]);
		Muse.Index = j;

		string PlaySing = "";
		for (int i = 0; i < Muse.PlayTime; ++i)
			PlaySing.push_back(Muse.Sheet[i % Muse.Sheet.size()]);

		for (int j = 0; j < PlaySing.size(); ++j)
		{
			if (PlaySing[j] == FlatM[0])
			{
				bool bFind = true;
				for (int i = 1; i < FlatM.size(); ++i)
				{
					if (PlaySing[j + i] != FlatM[i])
					{
						bFind = false;
						break;
					}
				}
				if (bFind == true)
				{
					Temp.push_back(Muse);
					break;
				}
			}
		}
	}

	if (Temp.size() == 0) return "(None)";
	Music Result = Temp[0];
	for (int i = 1; i < Temp.size(); ++i)
	{
		if (Temp[i].PlayTime > Result.PlayTime)
			Result = Temp[i];
		else if (Temp[i].PlayTime == Result.PlayTime)
		{
			if (Temp[i].Index < Result.Index)
				Result = Temp[i];
		}
	}

	return Result.Name;
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

