#include "pch.h"
#include <iostream>
using namespace std;
#define FASTIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define PII pair<int, int>
PII BaGuNi;
int N, M, J, Answer = 0;
int main()
{
	FASTIO;
	cin >> N >> M >> J;
	BaGuNi = { 1, M };
	for (int i = 0; i < J; ++i)
	{
		int Input; cin >> Input;
		if (BaGuNi.first >= Input && BaGuNi.second <= Input) continue;
		if (BaGuNi.first > Input)
		{
			Answer += BaGuNi.first - Input;
			BaGuNi.first = Input;
			BaGuNi.second = Input + M - 1;
		}
		else if (BaGuNi.second < Input)
		{
			Answer += Input - BaGuNi.second;
			BaGuNi.second = Input;
			BaGuNi.first = Input - M + 1;
		}
	}
	cout << Answer;
	return 0;
}

