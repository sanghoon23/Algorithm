#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

bool Compare(string A, string B)
{
	string AHour = A.substr(0, 2), BHour = B.substr(0, 2), AMin = A.substr(3, 2), BMin = B.substr(3, 2);
	if (AHour == BHour && AMin == BMin) return false;

	if (stoi(AHour) != stoi(BHour))
		return stoi(AHour) > stoi(BHour);
	else if(stoi(AMin) != stoi(BMin))
		return stoi(AMin) > stoi(BMin);

	return true;
}

string Calc(string In, int MM)
{
	string Ret = "";
	
	int Hour = stoi(In.substr(0, 2)), Min = stoi(In.substr(3, 2));
	Min += MM;
	if (Min >= 0)
	{
		int Temp = Min / 60;
		Hour += Temp;
		Min %= 60;
	}
	else
	{
		Hour -= 1;
		if (Hour < 0) Hour += 24;
		Min += 60;
	}

	string StrHour = to_string(Hour);
	string StrMin = to_string(Min);
	if (Hour < 10)
		StrHour = "0" + StrHour;
	if (Min < 10)
		StrMin = "0" + StrMin;


	Ret += StrHour + ":" + StrMin;
	return Ret;
}

//@N - 셔틀 운행 횟수, T - 셔틀 운행 간격, M - 버스최대수용인원, 
string solution(int N, int T, int M, vector<string> Timetable)
{
	string Answer = "";

	sort(Timetable.begin(), Timetable.end(), Compare);
	string Start = "09:00";
	string Last = Timetable[Timetable.size() - 1];
	for (int i = 0; i < N; ++i)
	{
		if(i != 0)
			Start = Calc(Start, T);

		int Count = 0;
		int Index = Timetable.size() - 1;
		while (!Timetable.empty() && Count < M)
		{
			if (Compare(Timetable[Index], Start) == false)
			{
				Last = Timetable[Index];
				++Count;
				Timetable.erase(Timetable.begin() + Index);
				--Index;
			}
			else break;
		}

		if (Count == M && i == N - 1)
		{
			Answer = Calc(Last, -1);
		}
		else Answer = Start;
	}

	return Answer;
}

int main()
{
	//2	10	2	[09:10, 09:09, 08:00]
	//int N = 2;
	//int T = 10;
	//int M = 2;
	//vector<string> Insert;
	//Insert.push_back("09:10");
	//Insert.push_back("09:09");
	//Insert.push_back("08:00");

	//int N = 1;
	//int T = 1;
	//int M = 5;
	//vector<string> Insert;
	//Insert.push_back("00:01");
	//Insert.push_back("00:01");
	//Insert.push_back("00:01");
	//Insert.push_back("00:01");
	//Insert.push_back("00:01");

	int N = 2;
	int T = 10;
	int M = 2;
	vector<string> Insert;
	Insert.push_back("09:10");
	Insert.push_back("09:09");
	Insert.push_back("08:00");

	string Result = solution(N, T, M, Insert);

	return 0;
}

