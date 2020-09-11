#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <stack>
#include <algorithm>

using namespace std;

bool CheckRight(string& Str)
{
	stack<char> Stack;
	for (int i = 0; i < Str.size(); ++i)
	{
		if (Str[i] == '(')
			Stack.push(Str[i]);
		else
		{
			if (Stack.empty()) return false;
			else Stack.pop();
		}
	}

	return true;
}

bool CheckBalance(string& Str)
{
	if (Str == "") return false;
	int FirstCount = 0;
	int SecondCount = 0;
	for (int i = 0; i < Str.size(); ++i)
	{
		if (Str[i] == '(') ++FirstCount;
		else ++SecondCount;
	}

	if (FirstCount == SecondCount) return true;
	else return false;
}

void Division(string& Origin, string& U, string& V)
{
	string Str = "";
	int Index = 0;
	for (int i = 0; i < Origin.size(); ++i)
	{
		if (CheckBalance(Str) == false)
		{
			Str.push_back(Origin[i]);
			continue;
		}
		else V.push_back(Origin[i]);
	}

	U = Str;

	//string Str = "";
	//int Index = 0;
	//for (int i = 1; i <= Origin.size(); ++i)
	//{
	//	Str = Origin.substr(0, i);
	//	if (CheckBalance(Str) == false) continue;
	//	else
	//	{
	//		Index = i;
	//		break;
	//	}
	//}

	//U = Origin.substr(0, Index);
	//(Index >= Origin.size())
	//	? V = ""
	//	: V = Origin.substr(Index, Origin.size());
}

string Check(string& P)
{
	string Str;
	int FirstCount = 0;
	int SecondCount = 0;
	bool bRight = true;
	for (int i = 0; i < P.size(); ++i)
	{
		if (P[i] == '(') ++FirstCount;
		else if(P[i] == ')')
		{
			++SecondCount;
			if (FirstCount < SecondCount) bRight = false;
		}

		if (FirstCount == SecondCount)
		{
			string U = P.substr(0, i + 1);
			string V = P.substr(i + 1, P.size());
			if (bRight == true)
			{
				Str += U;
				Str += Check(V);
			}
			else if(bRight == false)
			{
				Str += "(";
				Str += Check(V);
				Str += ")";

				for (int i = 1; i < U.size() - 1; ++i)
				{
					(U[i] == '(')
						? Str.push_back(')')
						: Str.push_back('(');
				}
			}

			break;
		}
	}

	return Str;
}

string solution(string p)
{
	string Answer = "";

	if (p == "") return p;
	int FirstCount = 0;
	int SecondCount = 0;
	bool bCheck = false;
	for (int i = 0; i < p.size(); ++i)
	{
		if (p[i] == '(') ++FirstCount;
		else if (p[i] == ')')
		{
			++SecondCount;
			if (FirstCount < SecondCount)
			{
				bCheck = true;
				break;
			}

		}
	}
	if (bCheck == false) return p;

	Answer = Check(p);

	return Answer;
}

//string solution(string p) {
//	//u와 v로 문자열을 분해하되, u는 더 이상 분할할 수 없는 문자열로 만들어야 한다.
//	string answer = "";
//	int left = 0, right = 0; // 왼쪽 괄호, 오른쪽 괄호 개수를 세기 위한 변수
//	bool check = false; // 올바른 괄호 문자열인지 판단하기 위한 변수
//	if (p.length() == 0) return ""; //분할한 문자열이 빈 문자열일 경우 빈 문자열 반환
//	for (int i = 0; i < p.length(); i++) {
//		if (p[i] == '(') left++;
//		if (p[i] == ')') right++;
//		if (right > left) check = true;
//		//오른쪽 괄호 수가 더 커지는 순간 이미 올바른 문자열이 아니기 때문에 check를 해준다
//		if (left == right) { // 개수가 같아질 때가 균형잡힌 문자열 u가 만들어지는 순간
//			if (check == true) { //u가 올바른 문자열이 아닐 경우
//				answer += '(';
//				answer += solution(p.substr(i + 1, p.length() - i - 1));
//				answer += ')';
//				for (int j = 1; j < i; j++) {
//					if (p[j] == ')') answer += '(';
//					if (p[j] == '(') answer += ')';
//				}
//				return answer;
//			}
//			else { //u가 올바른 문자열일 경우
//				answer += p.substr(0, i + 1);
//				answer += solution(p.substr(i + 1, p.length() - i - 1));
//				return answer;
//			}
//		}
//	}
//}

int main()
{
	//string P = ")(";
	string P = ")()()()(";
	//string P = "(()())()";
	//string P = ")()()()(";
	//string P = "))))((((";

	string Result = solution(P);

	return 0;
}

