#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

//int Change(int A)
//{
//	string Ret = "";
//	int Ret = 0;
//	for (int i = 19; i >= 0; --i)
//	{
//		int Pw = pow(2, i);
//		if (A >= Pw)
//		{
//			A -= Pw;
//			Ret.push_back('1');
//		}
//		else Ret.push_back('0');
//	}
//	return Ret;
//}

int Change(int A)
{
	int Ret = 0;
	for (int i = 19; i >= 0; --i)
	{
		int Pw = pow(2, i);
		if (A >= Pw)
		{
			A -= Pw;
			++Ret;
		}
		else continue;
	}
	return Ret;
}

int solution(int N)
{
	int Answer = 0;

	int Value = Change(N);
	while (1)
	{
		++N;
		if (Value == Change(N))
		{
			Answer = N;
			break;
		}
	}

	return Answer;
}

int main()
{
	int N = 78;
	solution(N);

	return 0;
}

