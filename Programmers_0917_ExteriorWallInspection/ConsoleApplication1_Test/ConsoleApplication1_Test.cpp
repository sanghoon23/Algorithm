#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;
//
//int N = 0;
//bool WeakVisited[15] = { false, };
//
//void VisistedInit(int WeakSize)
//{
//	for (int i = 0; i < WeakSize; ++i)
//		WeakVisited[i] = false;
//}
//
//bool CheckVisited(int WeakSize)
//{
//	for (int i = 0; i < WeakSize; ++i)
//	{
//		if (WeakVisited[i] == false) return false;
//	}
//	return true;
//}
//
//vector<int> WeakInit(vector<int>& Weak, int N)
//{
//	vector<int> Ret;
//	Ret.push_back(Weak[0]);
//	for (int i = 1; i < Weak.size(); ++i)
//	{
//		int Value = Weak[i];
//		if (Weak[i - 1] > Weak[i])
//		{
//			Value += N;
//		}
//		Ret.push_back(Value);
//	}
//
//	return Ret;
//}
//
//void Check(vector<int>& Weak, vector<int>& Dist, int DistIndex, int& Num)
//{
//	if (CheckVisited(Weak.size()) == true)
//		return;
//
//	if (Dist.size() == DistIndex)
//	{
//		Num = -1;
//		return;
//	}
//
//	for (int j = 0; j < Weak.size(); ++j)
//	{
//		int i = j;
//		int Value = Dist[DistIndex];
//		if (WeakVisited[j] == false && Weak[(j + 1) % N] - Weak[j] <= Value)
//		{
//			WeakVisited[j] = true;
//			Value -= Weak[(j + 1) % N] - Weak[j];
//			++j;
//			++Num; //@가능할 때, 카운트 늘려줌
//			while (j < Weak.size())
//			{
//				if (Weak[(j + 1) % N] - Weak[j] <= Value)
//				{
//					Value -= Weak[(i + 1) % N] - Weak[i];
//					WeakVisited[j] = true;
//				}
//				else break;
//
//				++j;
//			}
//			Check(Weak, Dist, DistIndex + 1, Num);
//			WeakVisited[j] = false;
//		}//if
//	}
//}
//
//int solution(int n, vector<int> weak, vector<int> dist)
//{
//	N = n;
//	int Answer = dist.size() + 1;
//
//	sort(dist.begin(), dist.end());
//
//	for (int j = 0; j < weak.size(); ++j)
//	{
//		int Temp = weak[0];
//		weak.erase(weak.begin());
//		weak.push_back(Temp);
//
//		vector<int> Insert = WeakInit(weak, n); //@Weak
//		do
//		{
//			int DistIndex = 0;
//			int WeakIndex = 0;
//
//			while (DistIndex < dist.size() && WeakIndex < weak.size())
//			{
//				int Start = dist[DistIndex];
//				int End = weak[WeakIndex] + dist[DistIndex];
//
//				while (WeakIndex < weak.size())
//				{
//					//if(weak[WeakIndex] <= End)
//				}
//			}
//
//
//		} while (next_permutation(dist.begin(), dist.end()));
//	}
//
//	if (Answer == dist.size() + 1) return -1; //모두 점검 X
//	return Answer;
//}

void WeakInit(vector<int>& Weak, int N)
{
	for (int i = 1; i < Weak.size(); ++i)
	{
		if (Weak[i - 1] > Weak[i])
		{
			Weak[i] += N;
		}
	}
}

int solution(int n, vector<int> weak, vector<int> dist)
{
	int Answer = -1;

	sort(dist.begin(), dist.end());
	for (int i = 0; i < weak.size(); ++i)
	{
		int Temp = weak[0];
		weak.erase(weak.begin());
		weak.push_back(Temp);

		WeakInit(weak, n);

		int a = 0;
		do
		{
			int WeakIndex = 0;
			int DistIndex = 0;
			while (WeakIndex < weak.size() && DistIndex < dist.size())
			{
				int End = weak[WeakIndex] + dist[DistIndex];

				++WeakIndex;
				while (WeakIndex < weak.size())
				{
					if (weak[WeakIndex] <= End)
						++WeakIndex;
					else break;
				}
				++DistIndex;
			}

			if (WeakIndex >= weak.size())
			{
				if (Answer == -1)
					Answer = DistIndex + 1;
				else
					Answer = min(Answer, DistIndex);
			}

		} while (next_permutation(dist.begin(), dist.end()));

	}//for(weak)

	return Answer;
}

int main()
{
	//TestCase 1
	//int N = 12;

	//vector<int> Weak;
	//Weak.push_back(1);
	//Weak.push_back(5);
	//Weak.push_back(6);
	//Weak.push_back(10);

	//vector<int> Dist;
	//Dist.push_back(1);
	//Dist.push_back(2);
	//Dist.push_back(3);
	//Dist.push_back(4);

	//TestCase 2

	int N = 12;

	vector<int> Weak;
	Weak.push_back(1);
	Weak.push_back(3);
	Weak.push_back(4);
	Weak.push_back(9);
	Weak.push_back(10);

	vector<int> Dist;
	Dist.push_back(3);
	Dist.push_back(5);
	Dist.push_back(7);

	int Result = solution(N, Weak, Dist);

	return 0;
}

