#include "pch.h"
#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <cmath>
#include <string>

using namespace std;

static int MiniNum = 9;
static char operat[4] = { '+', '-', '*', '/' };
int Loop(int N, int number, vector<int>* vec, int Count, int PlusCount)
{
	int InitCount = Count + PlusCount;
	int LoopCount = Count + PlusCount;

	if (number == N + 1 || number == N - 1)
	{
		int Result = Count + PlusCount + 2;
		if (MiniNum > Result)
		{
			MiniNum = Result;
		}
	}

	if (N == number)
	{
		MiniNum = Count + PlusCount;
		return MiniNum;
	}

	int c1 = 0;
	int c2 = 0;
	int c3 = 0;
	int c4 = 0;

	for (int i = 0; i < vec->size(); ++i)
	{
		if (LoopCount > 8)
			break;

		for (int j = 0; j < 4; ++j)
		{
			if (operat[j] == '+')
			{
				// @C1 '+'
				c1 = N + (*vec)[i];
				if (c1 > 0 && c1 != number)
				{
					int param = LoopCount + 1;
					if (param + i > 8)
					{
						continue;
					}
					int result = Loop(c1, number, vec, param, i);
				}
				else  if (c1 > 0 && c1 == number)
				{
					if (MiniNum > InitCount + 1 + i)
					{
						MiniNum = InitCount + 1 + i;
						continue;
					}
				}//@C1
			}//@'+'
			else if (operat[j] == '-')
			{
				// @C2 '-'
				c2 = N - (*vec)[i];
				if (c2 > 0 && c2 != number)
				{
					int param = LoopCount + 1;
					if (param + i > 8)
					{
						continue;
					}
					int result = Loop(c2, number, vec, param, i);
				}
				else  if (c2 > 0 && c2 == number)
				{
					if (MiniNum > InitCount + 1 + i)
					{
						MiniNum = InitCount + 1 + i;
						continue;
					}
				}//@C2
			}//@'-'
			else if (operat[j] == '*')
			{
				// @C3 '*'
				c3 = N * (*vec)[i];
				if (c3 > 0 && c3 != number)
				{
					int param = LoopCount + 1;
					if (param + i > 8)
					{
						continue;
					}
					int result = Loop(c3, number, vec, param, i);
				}
				else  if (c3 > 0 && c3 == number)
				{
					if (MiniNum > InitCount + 1 + i)
					{
						MiniNum = InitCount + 1 + i;
						continue;
					}
				}//@C3
			}//@'*'
			else if (operat[j] == '/')
			{
				// @C4 '/'
				c4 = N / (*vec)[i];
				if (c4 > 0 && c4 != number)
				{
					int param = LoopCount + 1;
					if (param + i > 8)
					{
						continue;
					}
					int result = Loop(c4, number, vec, param, i);
				}
				else  if (c4 > 0 && c4 == number)
				{
					if (MiniNum > InitCount + 1 + i)
					{
						MiniNum = InitCount + 1 + i;
						continue;
					}
				}//@C4
			}//@'/'
		}//for(j)
	}//for(i)

	return InitCount;
}

int Volum[5] = { 1, 11, 111, 1111, 11111 };
int solution(int N, int number)
{
	vector<int>* InsertArray = new vector<int>();
	for (int j = 0; j < 5; ++j)
	{
		int InsertNum = N * Volum[j];
		if (InsertNum > 32000) break;

		InsertArray->push_back(InsertNum);
	}

	// @Calc
	vector<int> Calc;
	for (int s = 0; s < InsertArray->size(); ++s)
	{
		Loop((*InsertArray)[s], number, InsertArray, 1, s);
		if (MiniNum < 9)
		{
			Calc.push_back(MiniNum);
		}
		MiniNum = 9;
	}

	// @Result
	if (Calc.empty()) return -1;

	int Result = 0;
	for (int i = 0; i < Calc.size(); ++i)
	{
		if (i == 0) Result = Calc[i];
		if (Result > Calc[i]) Result = Calc[i];
	}

	return Result;
}

int main()
{
	int Result = 0;

	Result = solution(5, 150);
	printf("Result : %d\n", Result);

	return 0;
}
