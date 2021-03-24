#include "pch.h"
#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>
using namespace std;
#define FASTIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define MSIZE 1000001
int N, M, Dp[2][MSIZE];
string AnsStr, OrgStr;

int Solve()
{
	int AnsStrSize = AnsStr.size(), OrgStrSize = OrgStr.size();
	bool Row = false;
	for (int i = 0; i <= OrgStrSize; ++i) Dp[Row][i] = i;

	for (int j = 1; j <= AnsStrSize; ++j)
	{
		Row = !Row;
		Dp[Row][0] = j;
		for (int i = 1; i <= OrgStrSize; ++i)
		{
			if (AnsStr[j] != OrgStr[i]) Dp[Row][i] = min(Dp[!Row][i - 1], min(Dp[Row][i - 1], Dp[!Row][i])) + 1;
			else Dp[Row][i] = Dp[!Row][i - 1];

			if (AnsStr[j] == 'i' && (OrgStr[i] == 'j' || OrgStr[i] == 'l')
				|| AnsStr[j] == 'v' && OrgStr[i] == 'w')
			{
				Dp[Row][i] = Dp[!Row][i - 1];
			}
		}
	}
	return Dp[AnsStrSize % 2][OrgStrSize];
}

int main()
{
	FASTIO;
	cin >> N >> M >> AnsStr >> OrgStr;
	AnsStr = " " + AnsStr;
	OrgStr= " " + OrgStr;
	cout << Solve();
	return 0;
}

