#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>
#include <queue>

using namespace std;

//@Dp 해결법 ,, ***근데 시간초과 나옴.
//int solution(vector<int> A, vector<int> B)
//{
//	int Answer = 0;
//
//	sort(A.begin(), A.end());
//	sort(B.begin(), B.end());
//
//	vector<vector<int>> Temp;
//	for (int i = 0; i < A.size() + 1; ++i)
//	{
//		vector<int> Insert(B.size() + 1, 0);
//		Temp.push_back(Insert);
//	}
//
//	for (int j = 0; j < A.size(); ++j)
//	{
//		for (int i = 0; i < B.size(); ++i)
//		{
//			if (A[j] < B[i]) Temp[j][i] = 1;
//			if (j - 1 >= 0 && i - 1 >= 0) Temp[j][i] += Temp[j - 1][i - 1];
//		}
//	}
//
//	for (int i = 0; i < B.size(); ++i)
//		Answer = max(Answer, Temp[i][B.size() - 1]);
//
//	return Answer;
//}

//@단순히 찾으면서 시간을 얼마나 단축시키냐의 문제였음.
//
int solution(vector<int> A, vector<int> B)
{
	int Answer = 0;

	sort(A.begin(), A.end());
	sort(B.begin(), B.end());

	queue<int> Que;
	for (int i = 0; i < B.size(); ++i)
		Que.push(B[i]);

	int Index = 0;
	for (int j = 0; j < A.size(); ++j)
	{
		while (!Que.empty())
		{
			int Poped = Que.front();
			Que.pop();

			if (A[j] < Poped)
			{
				++Answer;
				break;
			}
		}
	}

	return Answer;
}

//@되는 코드
//int solution(vector<int> A, vector<int> B) {
//	int answer = 0;
//	int l = 0;
//	sort(A.begin(), A.end());
//	sort(B.begin(), B.end());
//	for (int i = 0; i < B.size(); i++) {
//		if (A[l] < B[i]) {
//			answer++;
//			l++;
//		}
//	}
//	return answer;
//}

//@erase 때문에 통과하지 못했다.
//int solution(vector<int> A, vector<int> B)
//{
//	int Answer = 0;
//
//	sort(A.begin(), A.end());
//	sort(B.begin(), B.end());
//
//	int Index = 0;
//	for (int j = 0; j < A.size(); ++j)
//	{
//		for (int i = Index; i < B.size(); ++i)
//		{
//			if (A[j] < B[i])
//			{
//				++Answer;
//				B.erase(B.begin() + i); <<<<< ------- 이 부분이 문제.
//				break;
//			}
//			else ++Index;
//		}
//	}
//
//	return Answer;
//}

int main()
{
	vector<int> A;
	A.push_back(5);
	A.push_back(1);
	A.push_back(3);
	A.push_back(7);

	vector<int> B;
	B.push_back(2);
	B.push_back(2);
	B.push_back(6);
	B.push_back(8);

	int Result = solution(A, B);

	return 0;
}

