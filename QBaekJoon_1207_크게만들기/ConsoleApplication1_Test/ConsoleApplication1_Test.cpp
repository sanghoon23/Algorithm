#include "pch.h"
#include <iostream>
#include <string>
#include <deque>

using namespace std;
int N = 0, K = 0;
char Str[500002];
int main()
{
	cin >> N >> K;
	for (int i = 0; i < N; ++i)
		cin >> Str[i];

	string Answer = "";
	deque<char> DQ;
	for (int i = 0; i < N; ++i)
	{
		while (K > 0 && DQ.empty() == false && DQ.back() < Str[i])
		{
			DQ.pop_back();
			--K;
		}

		DQ.push_back(Str[i]);
	}

	for (int i = 0; i < DQ.size() - K; ++i)
	{
		printf("%d", DQ[i] - 48);
	}
	return 0;
}

//int main()
//{
//	cin >> N >> K >> Num;
//
//	string Str = "";
//	vector<char> Temp;
//	int Index = N - 1;
//	while (Index >= 0)
//	{
//		int R = (Num / pow(10, Index));
//		Temp.push_back(R + 48);
//		Str.push_back(R + 48);
//		Num -= (R * pow(10, Index));
//		--Index;
//	}
//	sort(Temp.begin(), Temp.end());
//
//	while (K > 0)
//	{
//		for (int i = 0; i < Str.size(); ++i)
//		{
//			if (Temp[K - 1] == Str[i])
//			{
//				Str.erase(Str.begin() + i);
//				break;
//			}
//		}
//		--K;
//	}
//
//	cout << atoi(Str.c_str());
//	return 0;
//}

