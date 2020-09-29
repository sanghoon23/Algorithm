#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

/*
아래 코드의 문제점
[[1, 2, 3, 4], [3, 2, 100, 1], [3, 4, 5, 6], [1, 2, 3, 1000]]

위 예시에선 안된다.
처음에는 내가 for 문에서 Index 로 4가지의 상황을 넣어줘서 가능했는데,
문제는 4배열이 넘어가면 특정 상황(max 값이 선택한 상황) 만 Check 하게 된다.
문제는 이 상황이 항상 최댓값을 가지는건 아니라는 것이다.

문제 예시에서도 3행까지만 나와있어서 혼란했다.
재귀로 돌린다면 시간이 너무 걸리고
결국, 4가지 상황 에서의 최댓값을 저장할 수 있는 방법 DP 가 제일 효율적이다.

*/

//int Check(vector<vector<int>>& Land, int BeforeIndex, int Column, int Value)
//{
//	if (Column >= Land.size())
//	{
//		return Value;
//	}
//
//	int TempIndex = 0;
//	int Max = Value;
//	for (int i = 0; i < 4; ++i)
//	{
//		if (i == BeforeIndex) continue;
//		if (Land[Column][i] + Value > Max)
//		{
//			TempIndex = i;
//			Max = Land[Column][i] + Value;
//		}
//	}
//
//	return Check(Land, TempIndex, Column + 1, Max);
//}
//
//int solution(vector<vector<int> > land)
//{
//	int Answer = 0;
//
//	for (int i = 0; i < 4; ++i)
//	{
//		int Result = Check(land, i, 1, land[0][i]);
//		Answer = max(Answer, Result);
//	}
//
//	return Answer;
//}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//@DP 를 활용한 방법.

int Comp(int a, int b, int c)
{
	int Max = max(a, b);
	Max = max(Max, c);
	return Max;
}

int solution(vector<vector<int> > land)
{
	int Answer = 0;

	for (int j = 1; j < land.size(); ++j)
	{
		land[j][0] = Comp(land[j - 1][1] + land[j][0], land[j - 1][2] + land[j][0], land[j - 1][3] + land[j][0]);
		land[j][1] = Comp(land[j - 1][0] + land[j][1], land[j - 1][2] + land[j][1], land[j - 1][3] + land[j][1]);
		land[j][2] = Comp(land[j - 1][0] + land[j][2], land[j - 1][1] + land[j][2], land[j - 1][3] + land[j][2]);
		land[j][3] = Comp(land[j - 1][0] + land[j][3], land[j - 1][1] + land[j][3], land[j - 1][2] + land[j][3]);
	}

	for (int i = 0; i < 4; ++i)
		Answer = max(Answer, land[land.size() - 1][i]);

	return Answer;
}

int main()
{

	return 0;
}

