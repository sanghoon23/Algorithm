#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <list>
#include <algorithm>

using namespace std;

////////////////////////////////////////////////////////////////////////////////////////////////////////
//@Map 과 Union, Find 활용 - 메모리 초과오류를 해결하기 위한.

long long Find(map<long long, long long>& Parent, long long X)
{
	if (Parent[X] == 0)
	{
		return X;
	}
	else
	{
		Parent[X] = Find(Parent, Parent[X]);
		return Parent[X];
	}

}

void Union(map<long long, long long>& Parent, long long X, long long Y) {

	X = Find(Parent, X);
	Y = Find(Parent, Y);

	if (X != Y)
		Parent[Y] = X;
}

vector<long long> solution(long long K, vector<long long> Room_Number)
{
	vector<long long> Answer;

	map<long long, long long> Map;
	for (int j = 0; j < Room_Number.size(); ++j)
	{
		long long F = Find(Map, Room_Number[j]);
		Answer.push_back(F);
		Union(Map, F + 1, F);
	}

	return Answer;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
//@Temp(K) 에서 K 가 10 의 12승이라서 너무 큼 - 메모리 초과 오류,

//int Find(vector<int>& Parent, int X)
//{
//	if (X == Parent[X]) return X;
//	else 
//	{
//		Parent[X] = Find(Parent, Parent[X]);
//		return Parent[X];
//	}
//
//}
//
//void Union(vector<int>& Parent, int X, int Y) {
//
//	X = Find(Parent, X);
//	Y = Find(Parent, Y);
//
//	if (X != Y) 
//		Parent[Y] = X;
//}
//
//vector<long long> solution(long long K, vector<long long> Room_Number)
//{
//	vector<long long> Answer;
//
//	vector<int> Temp(K + 1);
//	for (int i = 0; i <= K; ++i)
//		Temp[i] = i;
//
//	for (int j = 0; j < Room_Number.size(); ++j)
//	{
//		int F = Find(Temp, Room_Number[j]);
//		Answer.push_back(F);
//		Union(Temp, F + 1, F);
//	}
//
//	return Answer;
//}

int main()
{
	//10	[1,3,4,1,3,1]
	int k = 10;

	vector<long long> In = { 1, 3, 4, 1, 3, 1 };
	vector<long long> Result = solution(k, In);

	return 0;
}

