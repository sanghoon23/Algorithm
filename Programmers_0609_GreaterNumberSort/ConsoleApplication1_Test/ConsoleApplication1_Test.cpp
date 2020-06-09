#include "pch.h"
#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <string>

using namespace std;

//bool Compare(int a, int b)
//{
//	vector<int> TempA;
//	vector<int> TempB;
//
//	for (int i = 3; i >= 0; --i)
//	{
//		int P = pow(10, i);
//
//		if (a >= P)
//			TempA.push_back((a / P) % 10);
//
//		if (b >= P)
//			TempB.push_back((b / P) % 10);
//	}
//
//	int IndexA = 0;
//	int IndexB = 0;
//	while (1)
//	{
//		if (TempA[IndexA] > TempB[IndexB]) return true;
//		if (TempA[IndexA] < TempB[IndexB]) return false;
//
//		if (TempA[IndexA] == TempB[IndexB])
//		{
//			if (IndexA + 1 < TempA.size())
//				++IndexA;
//
//			if (IndexB + 1 < TempB.size())
//				++IndexB;
//		}
//
//		if (IndexA == TempA.size() - 1 && IndexB == TempB.size() - 1)
//			break;
//	}
//
//	return TempA[IndexA] > TempB[IndexB];
//}

/* stringA + stringB , stringB + stringA 를 비교 */
bool Compare(int a, int b)
{
	string A = std::to_string(a);
	string B = std::to_string(b);

	string TempA = A;
	TempA.append(B);

	string TempB = B;
	TempB.append(A);

	int IntegerA = atoi(TempA.c_str());
	int IntegerB = atoi(TempB.c_str());

	return IntegerA > IntegerB;
}

string solution(vector<int> numbers)
{
	sort(numbers.begin(), numbers.end(), Compare);

	string Answer = "";
	for (int i = 0; i < numbers.size(); ++i)
	{
		Answer.append(std::to_string(numbers[i]));
	}

	if (Answer[0] == '0') //@첫번째가 0 이라면 예외처리,
		return "0";

	return Answer;
}

int main()
{
	//vector<int> Input;
	//Input.push_back(6);
	//Input.push_back(10);
	//Input.push_back(2);

	vector<int> Input;
	Input.push_back(3);
	Input.push_back(30);
	Input.push_back(34);
	Input.push_back(5);
	Input.push_back(9);

	string Result = solution(Input);

	return 0;
}
