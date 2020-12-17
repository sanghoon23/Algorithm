#include "pch.h"
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

/////////////////////////////////////////////////////////////////////////////////////////////////////
//@미친 코드..쩐다..

//pair<int, int> p[2000000];
//int r, s, n;
//int main()
//{
//	scanf("%d", &n);
//	for (int i = 0, x, y; i < n; i++)
//	{
//		scanf("%d%d", &x, &y);
//
//		p[i] = { x,1 };
//		p[i + n] = { y,-1 };
//	}
//
//	sort(p, p + 2 * n);
//
//	for (int i = 0; i < 2 * n; i++)
//	{
//		s += p[i].second;
//		r = max(r, s);
//	}
//	printf("%d", r);
//	return 0;
//}

///////////////////////////////////////////////////////////////////////////////////////////////////
//@제출

#define PII pair<int, int>
int N = 0, F = 0, S = 0, Answer = 1;
vector<PII> Val;
int main()
{
	cin >> N;
	priority_queue<int, vector<int>, greater<int>> PQ;
	for (int i = 0; i < N; ++i)
	{
		cin >> F >> S;
		Val.push_back({ F, S });
	}
	sort(Val.begin(), Val.end());
	PQ.push(Val[0].second);
	int Idx = 1;
	while (Idx < Val.size())
	{
		if (PQ.top() <= Val[Idx].first) { PQ.pop(); PQ.push(Val[Idx].second); }
		else PQ.push(Val[Idx].second);
		++Idx;
	}
	cout << PQ.size();
	return 0;
}

///////////////////////////////////////////////////////////////////////////////////////////////
//@삽질

//#define PII pair<long long, long long>
//int N = 0, Answer = 1;
//struct Compare
//{
//	bool operator()(PII& A, PII& B)
//	{
//		return (A.first) < (B.first);
//		//if (A.first == B.first) return (A.second) < (B.second);
//		//else return (A.first) < (B.first);
//	}
//};
//int main()
//{
//	cin >> N;
//	priority_queue<PII, vector<PII>> PQ;
//	for (int i = 0; i < N; ++i)
//	{
//		long long F = 0, S = 0;
//		cin >> F >> S;
//		PQ.push({ S, F });
//	}
//	PII Val = PQ.top(); PQ.pop();
//	int MM = 1;
//	while (!PQ.empty())
//	{
//		PII Poped = PQ.top(); PQ.pop();
//		int A = 0;
//		//PII Poped = PQ.top(); PQ.pop();
//		//if (Val.second > Poped.first)
//		//{
//		//	Val.first = Poped.first;
//		//	MM++;
//		//}
//		//else
//		//{
//		//	Val = Poped;
//		//	Answer = max(Answer, MM);
//		//	MM = 1;
//		//}
//	}
//	cout << Answer;
//	return 0;
//}

