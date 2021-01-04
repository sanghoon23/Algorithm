#include "pch.h"
#include <iostream>
#include <deque>
#include <string>
using namespace std;
int M = 0;
string Str, Input, Answer;
int main()
{
	ios::sync_with_stdio(false); cin.tie(0);
	deque<char> Left, Right;
	cin >> Str;
	for (int i = 0; i < Str.size(); ++i) Left.push_back(Str[i]);

	cin >> M;
	for (int i = 0; i < M; ++i)
	{
		cin >> Input;
		if (Input[0] == 'L' && !Left.empty())//@왼쪽 이동
		{
			char RM = Left.back();
			Left.pop_back();
			Right.push_front(RM);
		}
		else if (Input[0] == 'D' && !Right.empty())//@오른쪽 이동
		{
			char RM = Right.front();
			Right.pop_front();
			Left.push_back(RM);
		}
		else if (Input[0] == 'B' && !Left.empty())//@왼쪽 문자 삭제
		{
			Left.pop_back();
		}
		else if (Input[0] == 'P')//@왼쪽 문자 삽입
		{
			cin >> Input;
			Left.push_back(Input[0]);
		}
	}

	while (!Left.empty()) { Answer += Left.front(); Left.pop_front(); }
	while (!Right.empty()) { Answer += Right.front(); Right.pop_front(); }
	cout << Answer;
	return 0;
}

