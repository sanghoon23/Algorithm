#include "pch.h"
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string.h>

using namespace std;
#define FASTIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define MMAX 987654321
#define PII pair<int, int>
int S;
int main()
{
	FASTIO;
	cin >> S;

	vector<vector<int>> Dist(S + 1, vector<int>(S + 1, MMAX));
	Dist[1][0] = 0;
	priority_queue<pair<int, PII>> PQ; //@비용, 클립, 현재화면
	PQ.push({ 0, {0, 1} });
	while (!PQ.empty())
	{
		const int Cost = -(PQ.top().first), Clip = PQ.top().second.first, Curr = PQ.top().second.second;
		PQ.pop();

		if (Curr > S || Curr < 1 || Clip > S) continue;
		if (Dist[Curr][Clip] < Cost) continue;

		if (Curr > 0 && Clip != Curr) //클립보드저장.
		{
			int InsertClip = Curr;
			PQ.push({ -(Cost + 1), {InsertClip, Curr} });
		}
		if (Clip > 0) //화면에붙여넣기
		{
			if (Curr + Clip <= S && Dist[Curr + Clip][Clip] > Cost + 1)
			{
				Dist[Curr + Clip][Clip] = Cost + 1;
				PQ.push({ -(Cost + 1), {Clip, Curr + Clip} });
			}
		}
		if (Curr - 1 > 0) //화면하나삭제
		{
			int InsertCurr = Curr - 1;
			if (InsertCurr <= S && Dist[InsertCurr][Clip] > Cost + 1)
			{
				Dist[InsertCurr][Clip] = Cost + 1;
				PQ.push({ -(Cost + 1), {Clip, InsertCurr} });
			}
		}
	}
	int Answer = MMAX;
	for (int i = 0; i <= S; ++i)
		Answer = min(Answer, Dist[S][i]);

	cout << Answer << '\n';
	return 0;
}

