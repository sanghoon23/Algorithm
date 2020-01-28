#include "pch.h"
#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;
bool StrCompareNum(int Num, int CompareNum)
{
	if (Num > pow((CompareNum - 1), 2)
		&& Num <= pow((CompareNum), 2))
	{
		return true;
	}

	return false;
}

// Complete the encryption function below.
string encryption(string s)
{
	int strSize = s.length();

	// Grid(행렬) Size 구하기.
	int GridNum = 0;
	for (int i = 1; i < 10; ++i)
	{
		if (StrCompareNum(strSize, i))
		{
			GridNum = i;
			break;
		}
	}

	// 행렬로 나누기(GridNum) - 열기준 CalcStr[colum] 기준으로 집어넣기.
	// colum = j % GridNum;
	vector<string> CalcStr(GridNum, "");
	string ResultStr = "";
	for (int j = 0; j < strSize; ++j)
	{
		int colum = j % GridNum;
		CalcStr[colum].push_back(s[j]);
	}

	// Print - 열 기준으로 출력.
	for (int p = 0; p < GridNum; ++p)
	{
		ResultStr.append(CalcStr[p]);
		if (p != GridNum - 1)
			ResultStr.append(" ");
	}

	return ResultStr;
}

int main()
{
	string s = "gigidofkcjvlxs";

	string result = encryption(s);

	cout << result.c_str() << endl;

	return 0;
}

