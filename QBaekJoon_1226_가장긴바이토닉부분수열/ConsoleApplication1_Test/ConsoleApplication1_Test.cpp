#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N = 0;
void Find(vector<int>& Board, vector<int>& Temp, bool bRe)
{
	vector<int> Values;
	for (int i = 0; i < N; ++i)
	{
		if (Values.empty()) Values.push_back(Board[i]);
		else
		{
			if (Values[Values.size() - 1] < Board[i]) Values.push_back(Board[i]);
			else
			{
				int R = lower_bound(Values.begin(), Values.end(), Board[i]) - Values.begin();
				Values[R] = Board[i];
			}
		}
		if(bRe == false) Temp[i] = Values.size();
		else Temp[N - i - 1] = Values.size();
	}
}

int main()
{
	cin >> N;
	vector<int> Board(N, 0);
	for (int i = 0; i < N; ++i)
		cin >> Board[i];

	vector<int> Forward(N, 0);
	Find(Board, Forward, false);

	reverse(Board.begin(), Board.end());
	vector<int> Reverse(N, 0);
	Find(Board, Reverse, true);

	int Answer = 0;
	//for (int k = 0; k < N - 1; ++k) 이것도 된다.
	//{
	//	if(Reverse[k] != Reverse[k + 1])
	//		Answer = max(Answer, Forward[k] + Reverse[k + 1]);
	//}
	for (int k = 0; k < N; ++k)
		Answer = max(Answer, Forward[k] + Reverse[k] - 1);

	cout << max(Answer, max(Forward[N - 1], Reverse[0]));
	return 0;
}

