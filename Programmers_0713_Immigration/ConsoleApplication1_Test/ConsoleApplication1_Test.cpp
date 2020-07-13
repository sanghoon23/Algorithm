#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

//@ 시행 착오
//long long solution(int n, vector<int> times)
//{
//	sort(times.begin(), times.end());
//
//	long long Start = 0;
//	long long End = times[times.size() - 1] * n;
//	long long Mid = 0;
//
//	long long Calc = 0;
//
//	while (1)
//	{
//		Mid = Start + (End - Start) / 2;
//
//		Calc = 0;
//		//int SameNum = 0;
//		for (int i = 0; i < times.size(); ++i)
//		{
//			//if (i != 0 && times[i - 1] != times[i]) continue;
//			Calc += Mid / times[i];
//			//if (i != 0 && times[i - 1] != times[i]) SameNum += (Mid / times[i]);
//		}
//
//		if (Calc == n || Mid == n) break;
//		else if (Calc > n) End = Mid - 1;
//		else if (Calc < n) Start = Mid + 1;
//	}
//
//	//@나머지 계산(제일 가까운 수 구하기) - ex)'29' 도 가능할 때, -->> 필요가 없었다.
//	//결국, 결과값은 times 의 배수.
//	long Min = 0;
//	for (int j = 0; j < times.size(); ++j)
//	{
//		long Rest = Mid % times[j];
//		if (j == 0) Min = Rest;
//		if (Min > Rest) Min = Rest;
//	}
//
//	return Mid - Min;
//}

long long solution(int n, vector<int> times)
{
	sort(times.begin(), times.end());

	long long Start = 1;
	long long End = static_cast<long long>(times[times.size() - 1]) * static_cast<long long>(n);
	long long Mid = 0;

	long long Calc = 0;

	while (Start < End)
	{
		Mid = (Start + End) / 2;

		Calc = 0;
		for (int i = 0; i < times.size(); ++i)
		{
			Calc += (Mid / static_cast<long long>(times[i]));
		}

		if (Calc >= n) End = Mid;
		else if (Calc < n) Start = Mid + 1;
	}

	return End;
}

int main()
{
	int n = 2;

	vector<int> In;
	In.push_back(1);
	In.push_back(2);
	In.push_back(2);
	In.push_back(2);
	In.push_back(100);

	long long Result = solution(n, In);

	return 0;
}

