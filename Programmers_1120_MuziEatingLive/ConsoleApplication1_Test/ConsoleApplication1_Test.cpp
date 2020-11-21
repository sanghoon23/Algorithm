#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <algorithm>
#include <queue>

using namespace std;

struct Food
{
	int Value = 0;
	int Index = 0;
};

bool Compare(Food F1, Food F2)
{
	return F1.Value < F2.Value;
}

int solution(vector<int> Food_Times, long long K)
{
	int Answer = 0;

	long long Max = 0;	//@예외처리
	map<long long, long long> Map;	//@갯수를 빼주기 위함.
	vector<Food> Temp;	//@마지막에 원소 찾을 곳
	vector<long long> Uq;		//@중복되지 않은 데이터
	for (int i = 0; i < Food_Times.size(); ++i)
	{
		Food In;
		In.Value = Food_Times[i];
		In.Index = i;
		Temp.push_back(In);
		if (Map[Food_Times[i]] == 0) Uq.push_back(Food_Times[i]);

		Map[Food_Times[i]] += 1;
		Max += Food_Times[i];
	}
	stable_sort(Temp.begin(), Temp.end(), Compare);
	sort(Uq.begin(), Uq.end());

	if (Max <= K) return -1;

	long long BFVal = 0, Index = 0, Size = Temp.size();
	while (Index < Uq.size() && Size > 0)
	{
		if (K - (Size * (Uq[Index] - BFVal)) < 0)
		{
			K = K % (Size);
			break;
		}
		else
		{
			K = K - (Size * (Uq[Index] - BFVal));
			Size = Size - Map[Uq[Index]];
			BFVal = Uq[Index];
			++Index;
		}
	}

	long long RIndex = 0, Count = 0;
	for (int i = 0; i < Food_Times.size(); ++i)
	{
		if (Uq[Index] <= Food_Times[i])
		{
			if (Count == K)
			{
				RIndex = i;
				break;
			}
			else ++Count;
		}
	}

	return RIndex + 1;
}

/*
		if (K - (Size * (Temp[0].Value - BFValue)) <= 0)
		{
			K = (K % Size) - 1;
			break;
		}
		else
		{
			K = K - (Size * (Temp[0].Value - BFValue));
			BFValue = Temp[0].Value;
			Temp.erase(Temp.begin());
		}
*/

int main()
{
	//long long K = 27;
	//vector<int> In = { 4, 2, 3, 6, 7, 1, 5, 8, };

	//long long K = 16;
	//vector<int> In = { 4, 2, 3, 6, 7, 1, 5, 8, };

	long long K = 5;
	vector<int> In = { 2, 3, 3 };

	//long long K = 5;
	//vector<int> In = { 3, 1, 2 };

	//long long K = 5;
	//vector<int> In = { 3, 3, 3 };

	//long long K = 10;
	//vector<int> In = { 2, 1, 3, 3, 2 };

	int Result = solution(In, K);
	return 0;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//@삽질

//struct Food
//{
//	int Value = 0;
//	int Index = 0;
//};
//
//struct Compare
//{
//	bool operator()(Food F1, Food F2) { return F1.Value > F2.Value; }
//};
//
//int solution(vector<int> Food_Times, long long K)
//{
//	int Answer = 0;
//
//	priority_queue<Food, vector<Food>, Compare> PQ;
//	vector<Food> Temp;
//	for (int j = 0; j < Food_Times.size(); ++j)
//	{
//		Food In;
//		In.Value = Food_Times[j];
//		In.Index = j;
//		Temp.push_back(In);
//		PQ.push(In);
//	}
//
//	int BeforeValue = 0;
//	while (!PQ.empty())
//	{
//		Food Poped = PQ.top();
//		int Size = PQ.size();
//		if (K - ((Poped.Value) * (Size - BeforeValue)) < 0)
//		{
//			break;
//		}
//		else K -= (Poped.Value) * (Size - BeforeValue);
//
//		//int Calc = Poped.Value;
//		BeforeValue = Poped.Value;
//		PQ.pop();
//		Temp.erase(Temp.begin() + Poped.Index);
//		while (1)
//		{
//			Food Pop = PQ.top();
//			if (Pop.Value == BeforeValue)
//			{
//				PQ.pop();
//				Temp.erase(Temp.begin() + Pop.Index);
//			}
//			else break;
//		}
//	}
//
//	return Temp[K - 1].Index;
//}

//int solution(vector<int> Food_Times, long long K)
//{
//	int Answer = 0;
//
//	map<long long, int> Map;
//	for (int j = 0; j < Food_Times.size(); ++j)
//	{
//		Map[Food_Times[j]] += 1;
//	}
//
//	vector<int> Temp = Food_Times;
//	sort(Temp.begin(), Temp.end());
//	Temp.erase(unique(Temp.begin(), Temp.end()), Temp.end());
//
//	int Calc = Food_Times.size(), Index = 0;
//	while (K >= Calc && Index < Temp.size())
//	{
//		K -= Calc;
//		if (Calc - Map[Temp[Index]] <= 0) break;
//		else Calc -= Map[Temp[Index]];
//
//		++Index;
//	}
//
//	int Count = 0;
//	for (int i = 0; i < Food_Times.size(); ++i)
//	{
//		if (Food_Times[i] == Temp[Index])
//		{
//			if (K == Count) return i + 1;
//			else ++Count;
//		}
//	}
//
//	return -1;
//}

//int solution(vector<int> Food_Times, long long K)
//{
//	int Answer = 0;
//
//	map<long long, int> Map;
//	for (int j = 0; j < Food_Times.size(); ++j)
//	{
//		Map[Food_Times[j]] += 1;
//	}
//
//	vector<int> Temp = Food_Times;
//	sort(Temp.begin(), Temp.end());
//	Temp.erase(unique(Temp.begin(), Temp.end()), Temp.end());
//
//	int Calc = Food_Times.size(), Index = 0;
//	K -= Calc;
//	while (K >= 0)
//	{
//		if (K < Calc) break;
//
//		//Calc -= Map[Temp[Index]];
//		if (Calc > Map[Temp[Index]])
//			Calc -= Map[Temp[Index]];
//		else
//			return K % Calc;
//
//		if (Index - 1 >= 0)
//			K -= Calc * (Temp[Index] - Temp[Index - 1]);
//		else
//			K -= Calc * (Temp[Index]);
//
//		++Index;
//	}
//
//	int Count = 0;
//	for (int i = 0; i < Food_Times.size(); ++i)
//	{
//		if (Food_Times[i] > Temp[Index])
//		{
//			++Count;
//		}
//		if (Count == K)
//			return i + 1;
//	}
//
//	return -1;
//}

