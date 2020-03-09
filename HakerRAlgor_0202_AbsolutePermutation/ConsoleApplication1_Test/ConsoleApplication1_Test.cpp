#include "pch.h"
#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

struct Pair
{
	bool Max = false;
	int Result = 0;

	Pair(bool max, int result)
		: Max(max)
		, Result(result) {}
};

// @ Vector - Result
// @ k - K
// @ Num - 해당 값.
// @ Max - 해당 값이 최솟값인지, 최댓값인지.
void Looping(vector<int>* Vector, int k, int Num, bool Max)
{
	if (Max == true && Num + k < Vector->size())
	{
		int Input = Num + k;
		(*Vector)[Input - 1] = Input + k;
		Input += k;
		Looping(Vector, k, Input, Max);

	}
	else if (Max == false && Num - k > 0)
	{
		int Input = Num - k;
		(*Vector)[Input - 1] = Input - k;
		Input -= k;
		Looping(Vector, k, Input, Max);
	}
}

// Complete the absolutePermutation function below.
vector<int>* absolutePermutation(int n, int k)
{
	std::vector<int>* In = new vector<int>(n);
	for (int j = 0; j < n; ++j)
		(*In)[j] = (j + 1);

	if (k == 0) // K == 0 일 때,
		return In;

	// @ Fail
	vector<int>* Fail = new vector<int>();
	Fail->push_back(-1);

	// @ Result
	vector<int>* Result = new vector<int>(n, -1); // Result

	// @ Calc
	vector<Pair>* Calc = new vector<Pair>(); // Calc
	for (int i = 0; i < Result->size(); ++i)
	{
		int Min = (i + 1) - k;
		int Max = (i + 1) + k;
		if (Min <= 0) // 0 보다 작을 때,
		{
			(*Result)[i] = Max;
			Pair pair(true, Max);
			Calc->push_back(pair);
			continue;
		}
		else if (Max > n) // n 보다 클 때,
		{
			(*Result)[i] = Min;
			Pair pair(false, Min);
			Calc->push_back(pair);
			continue;
		}
		else if (Max > n && Min <= 0) // 선택되지 않으면 제외.
			return Fail;
	}

	for (int s = 0; s < Calc->size(); ++s)
	{
		bool Range = (*Calc)[s].Max;
		Looping(Result, k, (*Calc)[s].Result, Range); // Looping (재귀)
	}


	// Check
	for (int Num : *Result)
	{
		if (Num == -2 || Num > n || Num < 0)
			return Fail;
	}

	return Result;
}

int main()
{
	int n = 10;
	int k = 1;

	vector<int> test = *(absolutePermutation(n, k));

	printf("출력값");

	for (int i = 0; i < test.size(); ++i)
	{
		printf("%d", test[i]);
		
		(i != test.size() - 1)
			? printf(", ")
			: printf("\n");
	}

	return 0;
}

