#include "pch.h"
#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;
bool Compare(char a, char b)
{
	return (a < b);
}

// Complete the biggerIsGreater function below.
string biggerIsGreater(string w)
{
	// * Ex) 2 4 3 1 로 예시

	// 1. 바뀔 Index 값 찾기
	int ChangeIndex = -1;
	vector<char> charContainer;
	for (int i = 0; i < w.size(); ++i)
	{
		if (i != 0
			&& w[i - 1] < w[i])
		{
			ChangeIndex = i - 1; // *중요. ChangeIndex 는 큰 값의 바로 앞 숫자. Ex) 여기선 2.
			charContainer.clear();
		}

		charContainer.push_back(w[i]);
	}

	if (ChangeIndex == -1)
		return "no answer";

	// ChangeIndex 까지 ResultStr 잡아 놓고,
	// * 여기서 ChangeIndex + 1 . 
	// Ex) 2까지.
	string ResultStr(w, 0, ChangeIndex + 1);

	// w[ChangeIndex] 의 '바로 다음 큰 숫자' 를 구한다.
	// Ex) chMin = 3 이 된다.
	char chMin;
	for (int j = 0; j < charContainer.size(); ++j)
	{
		if (j == 0) chMin = charContainer[j];

		if (j != 0 && w[ChangeIndex] < charContainer[j])
		{
			chMin = min(chMin, charContainer[j]);
		}
	}

	// 위에서 구한 chMin 을 ChangeIndex 와 Swap 한다.
	// 그러고 난후, charContainer 의 문자열들은 정렬해서
	// ResultStr 에 붙인다.
	char Temp = ResultStr[ChangeIndex];
	ResultStr[ChangeIndex] = chMin;
	auto it = find(charContainer.begin(), charContainer.end(), chMin);
	(*it) = Temp;

	// 정렬
	sort(charContainer.begin(), charContainer.end(), Compare);

	// Print
	for (int v = 0; v < charContainer.size(); ++v)
	{
		ResultStr.push_back(charContainer[v]);
	}

	return ResultStr;
}

int main()
{

	string w = "2431";
	string result = biggerIsGreater(w);

	cout << result.c_str() << endl;

	return 0;
}
