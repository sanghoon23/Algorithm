#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

////////////////////////////////////////////////////////////////////////////////////////////////////////
//@Disjoint Set 이용.
// 조심해야 할건 next_permutation
// 정렬되어있어야지 재대로 된 순열이 나옴. (오름차순)

//vector<char> Op;
//vector<int> Value;
//long long Calc[1000] = { -1, };
//int Parent[1000] = { 0, };
//
//int Find(int x)
//{
//	if (Parent[x] < 0)
//		return x;
//	else
//	{
//		int y = Find(Parent[x]);
//		Parent[x] = y;
//		return y;
//	}
//}
//
//void Union(int x, int y)
//{
//	x = Find(x);
//	y = Find(y);
//	if (x == y) return;
//
//	if (Parent[x] < Parent[y]) 
//	{
//		Parent[x] += Parent[y];
//		Parent[y] = x;
//	}
//	else 
//	{
//		Parent[y] += Parent[x];
//		Parent[x] = y;
//	}
//}
//
//long long solution(string Expression)
//{
//	long long Max = 0;
//
//	Op.push_back('+');
//	string Temp = "";
//	for (int i = 0; i < Expression.size(); ++i)
//	{
//		if (Expression[i] < 48 || Expression[i] - '0' > 57)
//		{
//			Op.push_back(Expression[i]);
//			Value.push_back(atoi(Temp.c_str()));
//			Temp = "";
//		}
//		else Temp.push_back(Expression[i]);
//	}
//	Value.push_back(atoi(Temp.c_str()));
//
//	string Operate = "*+-"; // 조심해야 할건 정렬되어있어야지 재대로 된 순열이 나옴. (오름차순)
//	sort(Operate.begin(), Operate.end());
//	do
//	{
//		memset(Calc, -1, sizeof(long long) * Op.size());
//		for (int i = 0; i < Op.size(); ++i)
//			Parent[i] = -1;
//
//		for (int j = 0; j < Operate.size(); ++j)
//		{
//			for (int i = 1; i < Op.size(); ++i)
//			{
//				if (Operate[j] == Op[i]) //같은 연산자라면
//				{
//					int Temp = 0;
//					int FirstParentIndex = Find(i - 1), SecondParentIndex = Find(i);
//					long long First = Value[i - 1], Second = Value[i];
//
//					if (Calc[FirstParentIndex] != -1) First = Calc[FirstParentIndex];
//					if (Calc[SecondParentIndex] != -1) Second = Calc[SecondParentIndex];
//
//					Union(i - 1, i);
//					int P = Find(i);
//
//					if (Op[i] == '*')
//					{
//						Calc[P] = First * Second;
//					}
//					else if (Op[i] == '-')
//					{
//						Calc[P] = First + (-1) * Second;
//					}
//					else
//					{
//						Calc[P] = First + Second;
//					}
//				}
//			}
//		}
//
//		int P = Find(0);
//		if (Calc[P] < 0) Calc[P] *= (-1); //@-0보다작다면
//		if (Max < Calc[P]) Max = Calc[P];
//
//	} while (next_permutation(Operate.begin(), Operate.end()));
//
//	return Max;
//}

////////////////////////////////////////////////////////////////////////////////////////////////////////
//@Vector Erase 활용. -> 더 간단히 할 수 있음.

vector<char> Operator;
vector<long long> Value;

long long solution(string Expression)
{
	long long Max = 0;

	Operator.push_back('+');
	string Temp = "";
	for (int i = 0; i < Expression.size(); ++i)
	{
		if (Expression[i] < 48 || Expression[i] - '0' > 57)
		{
			Operator.push_back(Expression[i]);
			Value.push_back(atoll(Temp.c_str()));
			Temp = "";
		}
		else Temp.push_back(Expression[i]);
	}
	Value.push_back(atoll(Temp.c_str()));

	string Operate = "*+-"; // 조심해야 할건 정렬되어있어야지 재대로 된 순열이 나옴. (오름차순)
	sort(Operate.begin(), Operate.end());
	do
	{
		vector<long long> V(Value);
		vector<char> Op(Operator);
		for (int j = 0; j < Operate.size(); ++j)
		{
			for (int i = 1; i < Op.size(); ++i)
			{
				if (Operate[j] == Op[i]) //같은 연산자라면
				{
					long long First = V[i - 1], Second = V[i];
					long long Temp = 0;
					if (Op[i] == '*')
					{
						Temp = First * Second;
					}
					else if (Op[i] == '-')
					{
						Temp = First + (-1) * Second;
					}
					else
					{
						Temp = First + Second;
					}

					V[i - 1] = V[i] = Temp;
					Op.erase(Op.begin() + i);
					V.erase(V.begin() + i);
					--i;
				}
			}
		}

		if (V[0] < 0) V[0] *= (-1); //@-0보다작다면
		if (Max < V[0]) Max = V[0];

	} while (next_permutation(Operate.begin(), Operate.end()));

	return Max;
}

int main()
{
	//string Insert = "100-200*300-500+20";
	string Insert = "50*6-3*2";

	int Result = solution(Insert);
	return 0;
}

