#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//#1119_이분탐색 구현해보기 - (while, 재귀)
/*
현재 while 로 쓰게 되면 시간 안에 통과.
재귀를 쓰게 되면 시간초과.

무슨 차이인가? - 그걸 찾는 것이 너가 할일.
재귀를 너무 많이 타서 비용이 많이 드는 건가..??
아니면 내가 모르는 어느 상황에서 불필요한 재귀가 도는 것인가??

찾아봐라...
재귀를 돌때 Start 를 넣지 않고 0 을 넣어 버렸다..ㅎ
예상했던대로 불필요한 재귀가 돌았다.

추가적으로 함수를 많이 호출하면 미세하게나마 느려지는 것도
while 을 사용해서 이진탐색할 때와, 재귀를 써서 이진탐색할 때 조금의 속도 차이가 존재했다. (엄청난 차이는 아니다.)
*/

bool Compare(string Str1, string Str2)
{
	if (Str1.length() < Str2.length()) return true;
	else if (Str1.length() == Str2.length())
		if ((Str1) < (Str2)) return true; //@str2 가 더 클 때,
	return false; //@str2 가 더 작을 때,
}

int FindIndex(vector<string>& Words, int Start, int End, string Str)
{
	int Mid = (End + Start) / 2;
	if (Mid < 0 || Start >= End)
	{
		return Start;
	}
	if (Mid - 1 >= 0 && Compare(Words[Mid], Str) == false && Compare(Words[Mid - 1], Str) == true)
	{
		return Mid;
	}

	if (Compare(Words[Mid], Str) == true)
	{
		return FindIndex(Words, Mid + 1, End, Str);
	}
	else if (Compare(Words[Mid], Str) == false)
	{
		//return FindIndex(Words, 0, Mid - 1, Str); //@여기인가..?
		return FindIndex(Words, Start, Mid - 1, Str); //@이렇게 되야겠지??ㅎ
	}
}

int WhileFindIndex(vector<string>& Words, int Start, int End, string Str)
{
	int Mid = (End + Start) / 2;
	while(End - Start > 0)
	{
		Mid = (End + Start) / 2;
		if (Mid - 1 >= 0 && Compare(Words[Mid], Str) == false && Compare(Words[Mid - 1], Str) == true)
		{
			return Mid;
		}

		if (Compare(Words[Mid], Str) == true)
		{
			Start = Mid + 1;
		}
		else if (Compare(Words[Mid], Str) == false)
		{
			End = Mid - 1;
		}
	}

	return Start;
}

vector<int> solution(vector<string> Words, vector<string> Queries)
{
	vector<int> Answer;
	sort(Words.begin(), Words.end(), Compare);
	vector<string> ReverseWords = Words;
	transform(ReverseWords.begin(), ReverseWords.end(), ReverseWords.begin(),
		[](string Str) { reverse(Str.begin(), Str.end()); return Str; });

	sort(ReverseWords.begin(), ReverseWords.end(), Compare);

	for (int j = 0; j < Queries.size(); ++j)
	{
		string LowerTemp = Queries[j];
		string HeightTemp = Queries[j];
		if (Queries[j][0] != '?')
		{
			for (int i = LowerTemp.size() - 1; i >= 0; --i)
			{
				if (LowerTemp[i] != '?') break;
				LowerTemp[i] = 'a';
				HeightTemp[i] = 'z';
			}
			int L = WhileFindIndex(Words, 0, Words.size(), LowerTemp);
			int H = WhileFindIndex(Words, 0, Words.size(), HeightTemp);
			Answer.push_back(H - L);
		}
		else
		{
			reverse(LowerTemp.begin(), LowerTemp.end());
			reverse(HeightTemp.begin(), HeightTemp.end());
			for (int i = 0; i < LowerTemp.size(); ++i)
			{
				if (LowerTemp[i] == '?')
				{
					LowerTemp[i] = 'a';
					HeightTemp[i] = 'z';
				}
			}
			int L = WhileFindIndex(ReverseWords, 0, ReverseWords.size(), LowerTemp);
			int H = WhileFindIndex(ReverseWords, 0, ReverseWords.size(), HeightTemp);
			Answer.push_back(H - L);
		}
	}

	return Answer;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//@STL - lower_bound, upper_bound 사용

//bool Compare(string Str1, string Str2)
//{
//	if (Str1.length() < Str2.length()) return true;
//	else if (Str1.length() == Str2.length())
//		if((Str1) < (Str2)) return true;
//	return false;
//}
//
//vector<int> solution(vector<string> Words, vector<string> Queries)
//{
//	vector<int> Answer;
//	sort(Words.begin(), Words.end(), Compare);
//	vector<string> ReverseWords = Words;
//	transform(ReverseWords.begin(), ReverseWords.end(), ReverseWords.begin(),
//		[](string Str) { reverse(Str.begin(), Str.end()); return Str; });
//
//	sort(ReverseWords.begin(), ReverseWords.end(), Compare);
//
//	for (int j = 0; j < Queries.size(); ++j)
//	{
//		string LowerTemp = Queries[j];
//		string HeightTemp = Queries[j];
//		if (Queries[j][0] != '?')
//		{
//			for (int i = LowerTemp.size() - 1; i >= 0; --i)
//			{
//				if (LowerTemp[i] != '?') break;
//				LowerTemp[i] = 'a';
//				HeightTemp[i] = 'z';
//			}
//			int L = lower_bound(Words.begin(), Words.end(), LowerTemp, Compare) - Words.begin();
//			int H = upper_bound(Words.begin(), Words.end(), HeightTemp, Compare) - Words.begin();
//			Answer.push_back(H - L);
//		}
//		else
//		{
//			reverse(LowerTemp.begin(), LowerTemp.end());
//			reverse(HeightTemp.begin(), HeightTemp.end());
//			for (int i = 0; i < LowerTemp.size(); ++i)
//			{
//				if (LowerTemp[i] == '?')
//				{
//					LowerTemp[i] = 'a';
//					HeightTemp[i] = 'z';
//				}
//			}
//			int L = lower_bound(ReverseWords.begin(), ReverseWords.end(), LowerTemp, Compare) - ReverseWords.begin();
//			int H = upper_bound(ReverseWords.begin(), ReverseWords.end(), HeightTemp, Compare) - ReverseWords.begin();
//			Answer.push_back(H - L);
//		}
//	}
//
//	return Answer;
//}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//@순차 탐색 - 무조건 시간초과.

//vector<int> solution(vector<string> Words, vector<string> Queries)
//{
//	vector<int> Answer(Queries.size(), 0);
//
//	for (int i = 0; i < Queries.size(); ++i)
//		Temp[Queries[i].size()].push_back({ Queries[i], i });
//
//	for (int j = 0; j < Words.size(); ++j)
//	{
//		int WS = Words[j].size();
//		for (int i = 0; i < Temp[WS].size(); ++i)
//		{
//			string Value = Temp[WS][i].first;
//			bool bFind = true;
//			for (int k = 0; k < Value.size(); ++k)
//			{
//				if (Value[k] == '?') continue;
//				if (Value[k] != Words[j][k]) { bFind = false; break; }
//			}
//			if (bFind == true) ++(Answer[Temp[WS][i].second]);
//		}
//	}
//
//	return Answer;
//}

int main()
{
	/*
	["frodo", "front", "frost", "frozen", "frame", "kakao"]	["fro??", "????o", "fr???", "fro???", "pro?"]

	*/
	vector<string> Word = { "frodo", "front", "frost", "frozen", "frame", "kakao", };
	vector<string> Query = { "fro??", "????o", "fr???", "fro???", "pro?", };

	vector<int> Result = solution(Word, Query);

	return 0;
}

