#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>
#include <map>

using namespace std;

struct Web
{
	double Score = 0, GiveLinkSc = 0;
	string Name = "";
	vector<string> LinkStr;
};

string FindHttp(string& Page, int Index, int Plus)
{
	string Ret;
	bool bFind = false;
	for (int i = Index + Plus; i < Page.size(); ++i)
	{
		if (Page[i] == '"' && bFind == false) { bFind = true; continue; }
		if (Page[i] == '"' && bFind == true) break;
		if (bFind == true)
			Ret.push_back(Page[i]);
	}
	return Ret;
}

int solution(string word, vector<string> pages)
{
	int Answer = 0;
	transform(word.begin(), word.end(), word.begin(), ::tolower);

	vector<Web> Temp;
	for (int i = 0; i < pages.size(); ++i)
	{
		transform(pages[i].begin(), pages[i].end(), pages[i].begin(), ::tolower);

		Web Insert;

		/*
		*find("...") 한 부분은 sprintf 로 긁어오는 방법도 있겠다.
		또한 사소하지만 find 할 때, '"' 를 집어넣을 때 앞에 \ 를 붙여야 "" 과는 다른 문자열로 인식한다.
		기억하자.
		*/

		//@웹이름저장
		int IndexName = pages[i].find("<meta property=\"og:url\" content=\"https://", 0);
		Insert.Name = FindHttp(pages[i], IndexName, 30);

		//@링크
		int IndexLink = 0;
		while (pages[i].find("<a href=\"https:", IndexLink) != string::npos)
		{
			IndexLink = pages[i].find("<a href=\"https:", IndexLink);
			IndexLink += 6;
			string Ret = FindHttp(pages[i], IndexLink, 0);
			Insert.LinkStr.push_back(Ret);
		}

		//@word 찾기
		int IndexWord = 0;
		while (pages[i].find(word, IndexWord) != string::npos)
		{
			IndexWord = pages[i].find(word, IndexWord);
			//if (IndexWord != 0)
			//{
			//	if (pages[i][IndexWord - 1] < 97 || pages[i][IndexWord - 1] > 122)
			//	{
			//		if (pages[i][IndexWord + word.size()] <= pages[i].size())
			//		{
			//			if (pages[i][IndexWord + word.size()] < 97 || pages[i][IndexWord + word.size()] > 122)
			//			{
			//				if (pages[i].find(word, IndexWord + word.size()) != IndexWord + word.size()
			//					&& pages[i].find(word, IndexWord - word.size()) == IndexWord)
			//					Insert.Score += 1.0;
			//			}
			//		}
			//	}
			//}
			//@위에껀 쓸데없는 조건이 많다.
			/*
			1. 인덱스 체크(처음,끝) - 하지 않아도 됨.
			- 문제의 조건에서 word 의 길이는 최대 12 이고 앞 뒤로 오바될 일이 없다.
			2. find 를 이용해서 앞뒤로 같은 글자가 오는지 Index 체크 - 하지 않아도 됨.
			- 위의 조건 @ < 97, @ > 122 는 알파벳이 아닐 때의 조건이다. 즉, 단어로 체크됨.
			*/

			if (pages[i][IndexWord - 1] < 97 || pages[i][IndexWord - 1] > 122)
			{
				if (pages[i][IndexWord + word.size()] < 97 || pages[i][IndexWord + word.size()] > 122)
				{
					Insert.Score += 1.0;
				}
			}

			IndexWord += word.size();
		}

		if (Insert.LinkStr.size() != 0) //@다른 웹한테 줄 링크점수
			Insert.GiveLinkSc = Insert.Score / static_cast<double>(Insert.LinkStr.size());

		Temp.push_back(Insert); //@push_back
	}

	map<string, double> Map;
	for (int j = 0; j < Temp.size(); ++j) //@링크 계산
	{
		Map[Temp[j].Name] += Temp[j].Score;
		for (int i = 0; i < Temp[j].LinkStr.size(); ++i)
		{
			Map[Temp[j].LinkStr[i]] += Temp[j].GiveLinkSc;
		}
	}

	double Max = 0;
	int MaxIndex = 0;
	for (int i = 0; i < Temp.size(); ++i)
	{
		if (Map[Temp[i].Name] > Max)
		{
			Max = Map[Temp[i].Name];
			MaxIndex = i;
		}
	}

	return MaxIndex;
}

int main()
{
	//@Case 1
	//string Word = "Blind";
	//vector<string> Insert;

	//Insert.push_back("<html lang=\"ko\" xml:lang=\"ko\" xmlns=\"http://www.w3.org/1999/xhtml\">\n<head>\n  <meta charset=\"utf-8\">\n  <meta property=\"og:url\" content=\"https://a.com\"/>\n</head>  \n<body>\nBlind Lorem Blind ipsum dolor Blind test sit amet, consectetur adipiscing elit. \n<a href=\"https://b.com\"> Link to b </a>\n</body>\n</html>");


	//@Case 2
	string Word = "MUZI";
	vector<string> Insert;

	Insert.push_back("<html lang=\"ko\" xml:lang=\"ko\" xmlns=\"http://www.w3.org/1999/xhtml\">\n<head>\n  <meta charset=\"utf-8\">\n  <meta property=\"og:url\" content=\"https://careers.kakao.com/interview/list\"/>\n</head>  \n<body>\n<a href=\"https://programmers.co.kr/learn/courses/4673\"></a>#!MuziMuzi!)jayg07con&&\n\n</body>\n</html>");
	Insert.push_back("<html lang=\"ko\" xml:lang=\"ko\" xmlns=\"http://www.w3.org/1999/xhtml\">\n<head>\n  <meta charset=\"utf-8\">\n  <meta property=\"og:url\" content=\"https://www.kakaocorp.com\"/>\n</head>  \n<body>\ncon%\tmuzI92apeach&2<a href=\"https://hashcode.co.kr/tos\"></a>\n\n\t^\n</body>\n</html>");


	int Result = solution(Word, Insert);

	return 0;
}

