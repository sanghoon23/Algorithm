#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

//string Compress(string S, string CompStr, int Index) //@원본, 비교할 문자열, 비교할 대상 Index
//{
//	string Ret = S;
//	int Num = CompStr.size();
//	int EraseNum = 0;
//	int Idx = Index;
//	while (Idx + Num <= S.size())
//	{
//		Idx += Num;
//		string Temp = S.substr(Idx, Num);
//		if (Temp != CompStr) break;
//
//		//@같다면,
//		++EraseNum;
//	}
//
//	if (EraseNum == 0) return S; //@지워지지 않았따면,
//
//	Ret[Idx - Num - 1] = (EraseNum + 1) + '0';
//	Ret.erase(Ret.begin() + Index, Ret.begin() + Idx - Num - 1);
//
//	return Ret;
//}
//
//int solution(string S)
//{
//	int Answer = S.size();
//
//	for (int j = 1; j <= S.size() / 2; ++j) //@나눌 숫자 (Count)
//	{
//		string Temp = S;
//		int Index = 0;
//		//if (Temp.size() % j != 0) continue;
//		while (Index < Temp.size())
//		{
//			string CurrStr = Temp.substr(Index, j);
//			Temp = Compress(Temp, CurrStr, Index);
//			Index += j + 1;
//		}
//
//		int Size = Temp.size();
//		Answer = min(Answer, Size);
//	}//for
//
//	//string Result = Compress(S, "ab", 0);
//
//	return Answer;
//}

string ToStr(int A)
{
	string Ret;
	if (A >= 10)
	{
		Ret.push_back((A / 10) + '0');
	}
	Ret.push_back((A % 10) + '0');

	return Ret;
}

int solution(string S)
{
	int Answer = S.size();

	for (int j = 1; j <= S.size() / 2; ++j) //@나눌 숫자 (Count)
	{
		string Str = "";
		int Index = 0, CompressCnt = 1;
		string CurrStr = S.substr(Index, j);
		Index += j;
		while (1)
		{
			if (Index > S.size())
			{
				Str.append(CurrStr);
				break;
			}

			string Value = S.substr(Index, j);
			if (CurrStr == Value)
				++CompressCnt;
			else
			{
				string Temp = CurrStr;
				if (CompressCnt > 1)
				{
					string Cnt = ToStr(CompressCnt);
					Temp = Cnt + CurrStr;
					CompressCnt = 1;
				}
				Str.append(Temp);
				CurrStr = Value;
			}

			Index += j;
		}

		int Len = Str.size();
		Answer = min(Answer, Len);
	}//for

	return Answer;
}

// TODO : 단위로 다시 짜자.
int main()
{
	//string Insert = "ababab";
	
	//"xababcdcdababcdcd"
	//string Insert = "xababcdcdababcdcd";

	//abcabcabcabcdededededede"
	string Insert = "xxxxxxxxxxyyy";


	int Result = solution(Insert);

	return 0;
}

