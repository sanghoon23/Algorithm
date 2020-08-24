#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

//double FindTime(string Insert)
//{
//	int Hour = atoi(Insert.substr(11, 12).c_str());
//	int Min = atoi(Insert.substr(14, 15).c_str());
//	double Sec = atof(Insert.substr(17, 22).c_str());
//
//	//double TestHour = static_cast<float>(Hour * 60 * 60);
//	//double TestMin = static_cast<float>(Min * 60);
//
//	return static_cast<double>(Hour * 60 * 60) + static_cast<double>(Min * 60) + Sec;
//}
//
//double FindSec(string Insert)
//{
//	return atof(Insert.substr(24, Insert.size() - 2).c_str());
//}
//
//int solution(vector<string> lines)
//{
//	int Answer = 1;
//	for (int j = 0; j < lines.size(); ++j)
//	{
//		int Result = 1;
//		//@끝
//		double Start = FindTime(lines[j]);
//		double End = Start + 1.0;
//		for (int i = 0; i < lines.size(); ++i)
//		{
//			if (i == j) continue;
//			double TempEnd = FindTime(lines[i]);
//			double TempStart = FindTime(lines[i]) - FindSec(lines[i]);
//			
//			if (Start < TempEnd && End > TempEnd || Start < TempStart && End > TempStart
//				|| TempStart < Start && TempEnd > End || Start < TempEnd && End > TempEnd && Start < TempStart && End > TempStart)
//			{
//				++Result;
//			}
//		}
//		Answer = max(Result, Answer);
//
//		//@시작
//		Result = 1;
//		Start = FindTime(lines[j]) - FindSec(lines[j]);
//		End = Start + 1.0;
//		for (int i = 0; i < lines.size(); ++i)
//		{
//			if (i == j) continue;
//			double TempEnd = FindTime(lines[i]);
//			double TempStart = FindTime(lines[i]) - FindSec(lines[i]);
//			if (Start < TempEnd && End > TempEnd || Start < TempStart && End > TempStart
//				|| TempStart < Start && TempEnd > End || Start < TempEnd && End > TempEnd && Start < TempStart && End > TempStart)
//			{
//				++Result;
//			}
//		}
//		Answer = max(Result, Answer);
//	}
//
//	return Answer;
//}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//@참고 코드

#define BUFF_SIZE 86400000

int buff[BUFF_SIZE] = { 0 };

int solution(vector<string> lines) {
	int answer = 0;


	for (int i = 0; i < lines.size(); i++)
	{
		int end = 0;
		int elapsed_time;
		int y, m, d, hh, mm, ss, zzz;
		double elapsed_double;
		/* SDL 검사 - 아니오 */
		sscanf(lines[i].c_str(), "%d-%d-%d %d:%d:%d.%d %lfs", &y, &m, &d, &hh, &mm, &ss, &zzz, &elapsed_double);
		elapsed_time = (int)(elapsed_double * 1000);

		end += hh * 60;
		end += mm;
		end *= 60;
		end += ss;
		end *= 1000;
		end += zzz;

		for (int j = end - (elapsed_time - 1) - 999; j <= end; j++)
		{
			if (j < 0 || j >= BUFF_SIZE)
				continue;
			buff[j] += 1;
			answer = max(answer, buff[j]);
		}
	}

	return answer;
}

int main()
{
	vector<string> In;

	//@Test Case - 1
	In.push_back(string("2016-09-15 20:59:57.421 0.351s")); //1
	In.push_back(string("2016-09-15 20:59:58.233 1.181s")); //2
	In.push_back(string("2016-09-15 20:59:58.299 0.8s")); //3
	In.push_back(string("2016-09-15 20:59:58.688 1.041s")); //4
	In.push_back(string("2016-09-15 20:59:59.591 1.412s"));
	In.push_back(string("2016-09-15 21:00:00.464 1.466s"));
	In.push_back(string("2016-09-15 21:00:00.741 1.581s"));
	In.push_back(string("2016-09-15 21:00:00.748 2.31s"));
	In.push_back(string("2016-09-15 21:00:00.966 0.381s"));
	In.push_back(string("2016-09-15 21:00:02.066 2.62s"));

	//@Test Case - 2
	//In.push_back(string("2016-09-15 01:00:04.002 2.0s"));
	//In.push_back(string("2016-09-15 01:00:07.000 2s"));

	int Result = solution(In);

	return 0;
}

