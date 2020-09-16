#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

long long Febo(int n)
{
	if (n == 1) return 1;
	else
	{
		return n * Febo(n - 1);
	}
}

/* next_permutation  사용 */
vector<int> solution(int n, long long k)
{
	vector<int> Answer;

	vector<int> Temp;
	vector<bool> Check(n, false);
	for (int i = 1; i <= n; ++i)
	{
		Temp.push_back(i);
	}

	long long Index = 0;
	long long InsertK = k;
	
	while (n > 0)
	{
		Index = (InsertK - 1) / (Febo(n) / n);
		Answer.push_back(Temp[Index]);

		InsertK = InsertK % (Febo(n) / n); //@여긴 왜 그냥 K

		Temp.erase(Temp.begin() + Index);

		if (InsertK == 0)
			InsertK = Index;

		--n;
	}

	return Answer;
}

//void Febo(vector<int>& Result, vector<int>& Temp, vector<bool>& Checked, long long k, int n)
//{
//	long long Total = 1;
//	if (n - 1 <= 0) return;
//	else
//	{
//		for (int i = 2; i <= n - 1; ++i)
//			Total *= static_cast<long long>(i);
//	}
//
//	int Index = static_cast<int>(k / Total);
//	long long InsertK = k % Total;
//	if (InsertK == 0)
//	{
//		Index -= 1;
//	}
//
//	Checked[Index] = true;
//	Result.push_back(Temp[Index]);
//
//	Febo(Result, Temp, Checked, InsertK, n - 1);
//}
//
//vector<int> solution(int n, long long k)
//{
//	vector<int> Temp;
//	vector<bool> Check(n, false);
//	for (int i = 1; i <= n; ++i)
//	{
//		Temp.push_back(i);
//	}
//
//	if (k == 1) return Temp;
//
//	vector<int> Answer;
//	Febo(Answer, Temp, Check, k, n);
//	for (int i = 0; i < Check.size(); ++i)
//	{
//		if (Check[i] == false)
//		{
//			Answer.push_back(Temp[i]);
//			break;
//		}
//	}
//
//	return Answer;
//}

int main()
{
	int n = 3;
	int k = 5;

	vector<int> Result = solution(n, k);

	return 0;
}

