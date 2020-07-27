#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

bool solution(vector<string> phone_book)
{
	sort(phone_book.begin(), phone_book.end());
	for (int i = 0; i < phone_book.size(); ++i) //@비교대상
	{
		for (int j = 0; j < phone_book.size(); ++j) //@전체
		{
			if (i == j) continue;
			int StartNum = phone_book[j].find(phone_book[i]);
			if (StartNum != 0) continue;
			else return false;
		}
	}

	return true;
}

int main()
{

	return 0;
}

