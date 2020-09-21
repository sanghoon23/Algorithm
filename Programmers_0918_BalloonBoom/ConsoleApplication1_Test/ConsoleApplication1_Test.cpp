#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

int PlusRange[1000002] = { 0, };
int MinusRange[1000002] = { 0, };

bool Check(vector<int>& A, int Pivot) //@우선 A.size() 3 이상일때,
{
	int First = Pivot - 1;
	int FirstValue = PlusRange[First];

	int Second = Pivot + 1;
	int SecondValue = MinusRange[Second];

	bool bCheck = false;
	int Ret = min(FirstValue, A[Pivot]);
	if (Ret != A[Pivot])
	{
		Ret = A[Pivot];
		Ret = min(SecondValue, Ret);
		if (Ret != A[Pivot])
			bCheck = true;
	}

	Ret = min(SecondValue, A[Pivot]);
	if (Ret != A[Pivot])
	{
		Ret = A[Pivot];
		Ret = min(FirstValue, Ret);
		if (Ret != A[Pivot] && bCheck == true)
			return false;
	}

	return true;
}

int solution(vector<int> a)
{
	int Answer = a.size();
	if (a.size() == 1) return 1;
	else if (a.size() == 2) return 2;

	PlusRange[0] = a[0];
	for (int j = 1; j < a.size() - 2; ++j)
	{
		int Value = min(PlusRange[j - 1], a[j]);
		PlusRange[j] = Value;
	}

	MinusRange[a.size() - 1] = a[a.size() - 1];
	for (int j = a.size() - 2; j > 0 - 1; --j)
	{
		int Value = min(MinusRange[j + 1], a[j]);
		MinusRange[j] = Value;
	}

	for (int i = 1; i < a.size() - 1; ++i) //@첫번째, 마지막 은 무조건 가능, 따라서 1부터
	{
		if (Check(a, i) == false)
			--Answer;
	}

	return Answer;
}

int main()
{
	//[-16,27,65,-2,58,-92,-71,-68,-61,-33]	6
	vector<int> A;
	A.push_back(-16);
	A.push_back(27);
	A.push_back(65);
	A.push_back(-2);
	A.push_back(58);
	A.push_back(-92);
	A.push_back(-71);
	A.push_back(-68);
	A.push_back(-61);
	A.push_back(-33);

	int Result = solution(A);

	return 0;
}

