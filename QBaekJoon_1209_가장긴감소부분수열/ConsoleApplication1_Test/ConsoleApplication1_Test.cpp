#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//@2차
int N = 0, In = 0;
vector<int> Num;
int main()
{
	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		cin >> In;
		In *= -1;
		if (Num.empty() || !Num.empty() && Num[Num.size() - 1] < In) Num.push_back(In);
		else Num[lower_bound(Num.begin(), Num.end(), In) - Num.begin()] = In;

	}
	cout << Num.size();
	return 0;
}

//@1차
//int N = 0;
//int Value[1001] = { 0, };
//int main()
//{
//	cin >> N;
//	for (int i = 0; i < N; ++i)
//		cin >> Value[i];
//	
//	reverse(Value, Value + N);
//	vector<int> Num;
//	for (int i = 0; i < N; ++i)
//	{
//		if (Num.empty() || !Num.empty() && Num[Num.size() - 1] < Value[i])
//			Num.push_back(Value[i]);
//		else
//		{
//			int Idx = lower_bound(Num.begin(), Num.end(), Value[i]) - Num.begin();
//			Num[Idx] = Value[i];
//		}
//	}
//
//	cout << Num.size();
//	return 0;
//}

