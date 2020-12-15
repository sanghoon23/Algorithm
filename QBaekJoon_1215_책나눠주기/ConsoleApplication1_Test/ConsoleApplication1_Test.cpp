#include "pch.h"
#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>

/////////////////////////////////////////////////////////////////////////////////////////
//@데이터 삽입, 삭제, clear 잘하자 ㅡㅡ 그거 땜에 시간 엄청 날렸잖아 바보야 ㅡㅡ 정신차려..응?
//

using namespace std;
#define PII pair<int, int>
int T = 0, N = 0, M = 0;
vector<PII> Stu;
vector<int> Books;
bool Compare(PII A, PII B)
{
	if (A.second == B.second)
		return A.first < B.first;
	return A.second < B.second;
}
int main()
{
	cin >> T;
	for (int u = 0; u < T; ++u)
	{
		cin >> N >> M;
		Books.clear();
		for (int k = 1; k <= N; ++k)
			Books.push_back(k);

		Stu.clear();
		for (int k = 0; k < M; ++k)
		{
			int F = 0, S = 0;
			cin >> F >> S;
			Stu.push_back({ F, S });
		}
		sort(Stu.begin(), Stu.end(), Compare);

		int Answer = 0;
		for (int j = 0; j < M; ++j)
		{
			if (Books.empty()) break;

			auto It = lower_bound(Books.begin(), Books.end(), Stu[j].first);
			if (It == Books.end()) continue;
			int R = It - Books.begin();
			if (Books[R] >= Stu[j].first && Books[R] <= Stu[j].second)
			{
				Books.erase(Books.begin() + R);
				++Answer;
			}
		}
		cout << Answer << endl;
	}

	return 0;
}

