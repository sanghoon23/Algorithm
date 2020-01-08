// ConsoleApplication1_Test.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//
#include "pch.h"
#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <memory.h>

using namespace std;

#define SWAP(x, y, temp) ((temp)=(x), (x)=(y), (y)=(temp))

// Quick Sort Test.
// @ 재귀적 호출
// @ 대표적인 분할 정복의 예.
// 
 // int Partition(vector<int>* vec, int start, int end)
 // {
 //     int first = start;
 //     start++;


 //     int temp = 0;
 //     while(start < end)
 //     {
 //         // pivot = (*vec)[first]
 //         // 1. pivot 보다 큰 값을 찾는다.
 //         while((*vec)[first] > (*vec)[start] && (start < end))
 //         {
 //             start++;
 //         }

 //         // 2. pivot 보다 작은 값을 찾는다.
 //         while(((*vec)[first]) < ((*vec)[start]) && (start < end))
 //         {
 //             end--;
 //         }

 //         if(start < end)
 //             SWAP((*vec)[start], (*vec)[end], temp);
 //         else
 //             break;
 //     }

 //     SWAP((*vec)[first], (*vec)[end], temp);
 //     return end;
 // }

 // void QSorting(vector<int>* vec, int start, int end)
 // {
 //     if(start < end)
 //     {
 //         int index = Partition(vec, start, end);

 //         QSorting(vec, start, index - 1);
 //         QSorting(vec, index + 1, end);
 //     }

 // }

 // struct SubsetData
 // {
 //     int value = 0;
 //     bool visited = false;
 // };

 // bool Compare(SubsetData a, SubsetData b)
 // {
 //     return (a.value < b.value);
 // }

 // bool OverlapCompare(SubsetData a, SubsetData b)
 // {
 //     return (a.value == b.value);
 // }

//void CheckSet(vector<int>* vec, int value, int k)
//{
//	if (vec->empty())
//	{
//		vec->push_back(value);
//		return;
//	}
//
//	for (int j = 0; j < vec->size(); ++j)
//	{
//		// 들어있는 값이 value 와 같다면 break, 중복되고 이미 존재하는 값.
//		if ((*vec)[j] == value) return;
//
//		if (((*vec)[j] + value) % k == 0) return;
//	}
//
//	// 모든 조건을 통과하면 vec 에 push_back.
//	vec->push_back(value);
//}
//
//int nonDivisibleSubset(int k, vector<int> s)
//{
//	vector<int> Calcs;
//	for (int j = 0; j < s.size(); ++j)
//	{
//		for (int i = j + 1; i < s.size(); ++i)
//		{
//			// if(j == i ) continue;
//			int sum = s[i] + s[j];
//			if ((sum % k) > 0)
//			{
//				// SubsetData Data1;
//				// Data1.value = s[i];
//
//				// SubsetData Data2;
//				// Data2.value = s[j];
//
//				Calcs.push_back(s[i]);
//				Calcs.push_back(s[j]);
//			}
//		}
//	}
//
//	// Test Code
//	// std::sort(Calcs.begin(), Calcs.end(), Compare);
//	// QSorting(&Calcs, 0, Calcs.size() - 1);
//	// auto it = unique(Calcs.begin(), Calcs.end(), OverlapCompare);
//
//	// 정렬.
//	std::sort(Calcs.begin(), Calcs.end());
//
//	// 중복제거.
//	auto it = unique(Calcs.begin(), Calcs.end());
//	Calcs.erase(it, Calcs.end());
//
//	// 조건을 만족하는 (value % k != 0) 최대 부분 집합 찾기.
//	vector<int> Results;
//	for (int s = 0; s < Calcs.size(); ++s)
//	{
//		// if(Calcs[s].value == -1) continue;
//		for (int t = s + 1; t < Calcs.size(); ++t)
//		{
//			if ((Calcs[s] + Calcs[t]) % k == 0) continue;
//			CheckSet(&Results, Calcs[s], k);
//			CheckSet(&Results, Calcs[t], k);
//		}
//	}
//
//
//	// Test Code
//	// vector<int> Results;
//	// for(int m = 0; m < Calcs.size(); ++m)
//	// {
//	//     if(Calcs[m].value < 0) continue;
//	//     Results.push_back(Calcs[m].value);
//	// }
//
//
//	return Results.size();
//}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 정답 제출본.

//#include <bits/stdc++.h>
//#include <algorithm>
//
//using namespace std;
//
//string ltrim(const string &);
//string rtrim(const string &);
//vector<string> split(const string &);
//
//#define SWAP(x, y, temp) ((temp)=(x), (x)=(y), (y)=(temp))

/*
 * Complete the 'nonDivisibleSubset' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER k
 *  2. INTEGER_ARRAY s
 */

// 순서쌍을 위한 Paris.
// @ 첫번째 값, 두번째 값
// Ex) k = 5, (1, 4) (2, 3)
// Ex) k = 6, (1, 5) (2, 4) (3, 3)
struct Pairs
{
	int first;
	int seconds;
};

int GetMax(int a, int b)
{
	if (a >= b)
		return a;

	return b;
}

int nonDivisibleSubset(int k, vector<int> vec)
{
	// 쌍 찾기
	vector<Pairs> Sequences;
	for (int i = 1; i <= k / 2; ++i)
	{
		Pairs pair;
		pair.first = i;
		pair.seconds = k - i;

		Sequences.push_back(pair);
	}

	// 계산.
	vector<int> Calc(k, 0);
	for (int s = 0; s < vec.size(); ++s)
	{
		int num = vec[s] % k;
		Calc[num] += 1;
	}

	// 쌍 돌면서 합산
	int ResultCount = 0;
	for (int t = 0; t < Sequences.size(); ++t)
	{
		int One = Sequences[t].first;
		int Two = Sequences[t].seconds;
		if (One == Two)
		{
			++ResultCount;
			continue;
		}

		ResultCount += GetMax(Calc[One], Calc[Two]);
	}
	// 0 처리
	if (Calc[0] > 0)
		++ResultCount;


	return ResultCount;
}

int main()
{
	int k = 5;
	int n = 5;

	vector<int> s(n);
	// Test Code
	//s[0] = 15;
	//s[1] = 15;
	//s[2] = 15;
	//s[3] = 15;
	//s[4] = 15;

	int result = nonDivisibleSubset(k, s);

	return 0;
}



// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.
