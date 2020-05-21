#include "pch.h"
#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <algorithm>

using namespace std;

static int Result = 999999;

bool Find(string& A, string& B)
{
	int Size = A.size();
	int Calc = 0;
	for (int i = 0; i < Size; ++i)
	{
		if (A[i] == B[i])
			++Calc;
	}

	if (Calc == Size - 1) return true;
	else return false;
}

#pragma region DFS
//@DFS
void DFS(int N, string Current, string& Target, vector<string>& Words, vector<bool>& bCheck)
{
	if (N >= Words.size() || Current == Target)
	{
		if (N < Result)
		{
			Result = N;
		}

		return;
	}

	for (int i = 0; i < Words.size(); ++i)
	{
		if (bCheck[i] == false && Find(Current, Words[i]) == true)
		{
			bCheck[i] = true;
			DFS(N + 1, Words[i], Target, Words, bCheck);

			//***
			//@False 를 해주어야 기존의 bCheck 값이 유지되서 다음 I 번째에 들어감.
			bCheck[i] = false;

		}
	}
}
#pragma endregion

#pragma region BFS
//@BFS
int BFS(int N, string Current, string& Target, vector<string>& Words, vector<bool>& bCheck)
{
	queue<pair<string, int>> que;
	que.push({ Current, N });

	int Ret = 0;
	while (!que.empty())
	{
		string StrCurr = que.front().first;
		int Value = que.front().second;
		que.pop();

		if (StrCurr == Target)
		{
			Ret = Value;
			break;
		}

		for (int i = 0; i < Words.size(); ++i)
		{
			if (bCheck[i] == false && Find(StrCurr, Words[i]) == true)
			{
				bCheck[i] = true;
				que.push({ Words[i], Value + 1 });
			}

		}
	}

	return Ret;
}

#pragma endregion

int solution(string begin, string target, vector<string> words)
{
	int Size = words.size();
	vector<bool> bCheck(Size, false);

	//@DFS
	//for (int j = 0; j < Size; ++j)
	//{
	//	if (Find(begin, words[j]) == true)
	//	{
	//		std::fill(bCheck.begin(), bCheck.end(), false);
	//		bCheck[j] = true;

	//		DFS(0, words[j], target, words, bCheck);
	//	}
	//}
	//if (Result == 999999) return 0;

	//@BFS
	Result = BFS(0, begin, target, words, bCheck);

	return Result;
}

int main()
{
	string Begin = "hit";
	string Target = "cog";

	vector<string> Input;
	Input.push_back(string("hot"));
	Input.push_back(string("dot"));
	Input.push_back(string("dog"));
	Input.push_back(string("lot"));
	Input.push_back(string("log"));
	Input.push_back(string("cog"));

	int Result = solution(Begin, Target, Input);

	return 0;
}

