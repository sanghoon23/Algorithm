#include "pch.h"
#include <iostream>
#include <string.h>
#include <string>
#include <algorithm>

using namespace std;
string A, B;
int Dp[1001][1001];
int main()
{
	memset(Dp, 0, sizeof(Dp));
	cin >> A >> B;
	for (int j = 1; j <= A.size(); ++j)
	{
		for (int i = 1; i <= B.size(); ++i)
		{
			if (A[j - 1] == B[i - 1]) Dp[j][i] = Dp[j - 1][i - 1] + 1;
			else Dp[j][i] = max(Dp[j - 1][i], Dp[j][i - 1]);
		}
	}

	string Result = "";
	int Row = A.size(), Col = B.size();
	while (Row - 1 >= 0 && Col - 1 >= 0)
	{
		if (Dp[Row - 1][Col] == Dp[Row][Col]) --Row;
		else if (Dp[Row][Col] == Dp[Row][Col - 1]) --Col;
		else
		{
			Result.push_back(A[Row - 1]);
			--Row; --Col;
		}
	}
	reverse(Result.begin(), Result.end());
	if (Result.size() == 0) cout << 0;
	else cout << Result.size() << endl << Result;
	return 0;
}


///////////////////////////////////////////////////////////////////////////////////////////////////////
//@문자열로 재귀타면서 백트래킹 형식으로 구현해보려했는데.. 시간초과ㅎ
//...

//using namespace std;
//string A, B;
//string Dp[1001][1001];
//string Solve(int Y, int X)
//{
//	if (Y >= A.size() || X >= B.size()) return "";
//
//	string& Ret = Dp[Y][X];
//	if (Ret != "") return Dp[Y][X];
//
//	string Str = "";
//	for (int i = X; i < B.size(); ++i)
//	{
//		string Calc = "";
//		if (A[Y] == B[i]) Calc = A[Y] + Solve(Y + 1, i + 1);
//		else Calc = Solve(Y + 1, i);
//
//		if (Str.size() < Calc.size()) Str = Calc;
//	}
//
//	return Ret = Ret + Str;
//}
//
//int main()
//{
//	cin >> A >> B;
//
//	string Result = Solve(0, 0);
//
//	//string Result = "";
//	//for (int i = 0; i < A.size(); ++i)
//	//{
//	//	if(i == 0) Result = Solve(0, 0);
//	//	else
//	//	{
//	//		string Temp = Solve(i, 0);
//	//		if (Temp.size() > Result.size())
//	//			Result = Temp;
//	//	}
//	//}
//	if (Result.size() == 0) cout << 0;
//	else cout << Result.size() << endl << Result;
//	return 0;
//}

