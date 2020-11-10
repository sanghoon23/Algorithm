#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <algorithm>

using namespace std;

/*
includes 의 활용 - 문자열 다루기 - 문자열.find 함수와 다른점
includes - 부분집합으로서의 판별
find - 모든 곳에 포함되어있는지

밑의 두번째 코드와 다른점.
1. 첫번째(바로아래코드)는 erase 사용 아예 제거해버림.
2. Visited 를 사용해서 방문했는지 확인

	[["100","ryan","music","2"],
	["200","apeach","math","2"],
	["300","tube","computer","3"],
	["400","con","computer","4"],
	["500","muzi","music","3"],
	["600","apeach","music","2"]]

	위 상황을 예시로
1. 똑같이 2
2. 똑같이 2 가 나옴.

	[["100","ryan","music","1"],
	["200","apeach","math","2"],
	["300","tube","computer","3"],
	["400","con","computer","4"],
	["500","muzi","music","3"],
	["600","apeach","music","2"]]

	[0][4] = 1 로 바꾼 상황

1. 3이 나옴.
2. 2가 나옴.

*1번코드에서,, 만약{1} 이 독립적이라면, {1} 이 최소이므로 {1} 이 포함된 모든 조합을 제거.

*2번코드에서,, 만약{1} 이 독립적이라면, {1} 방문체크하고 {1} 이 들어간 모든 곳을 방문 불가능.

이렇게 되면 {2,3} 일 때, {3,4} 도 체크해주어야 하는데, 방문 확인으로 해버린다면
Visited[2]=Visited[3]=ture 이므로, {3,4} 는 방문불가능.

반대로 1번코드는 {2,3}이 들어간 곳을 제거하므로 {3,4}의 조합은 살아있음.

*/

vector<string> Combi;
int Result = 0;

bool Compare(string A, string B)
{
	return A.size() < B.size();
}

void GetCombi(int Col, int Index, string Str)
{
	if (Col <= Index) return;

	for (int j = Index; j < Col; ++j)
	{
		string Insert = Str;
		Insert.append(to_string(j));
		Combi.push_back(Insert);
		GetCombi(Col, j + 1, Insert);
	}
}

bool DFS(vector<vector<string>>& Relation, string Str)
{
	map<string, int> Map;

	for (int j = 0; j < Relation.size(); ++j)
	{
		string Temp = "";
		for (int i = 0; i < Str.size(); ++i)
		{
			int C = Str[i] - '0';
			Temp += (Relation[j][C]);
		}

		Map[Temp] += 1;
		if (Map[Temp] >= 2) return false;
	}

	return true;
}

int solution(vector<vector<string>> Relation)
{
	int Row = Relation.size(), Col = Relation[0].size();

	GetCombi(Col, 0, "");
	sort(Combi.begin(), Combi.end(), Compare);

	for (int j = 0; j < Combi.size(); ++j)
	{
		if (DFS(Relation, Combi[j]) == true)
		{
			while (1)
			{
				bool bErase = false;
				for (int i = j + 1; i < Combi.size(); ++i)
				{
					//if (Combi[i].find(Combi[j]) != string::npos)
					//includes - 부분집합으로서의 판별
					//find - 모든 곳에 포함되어있는지
					if(includes(Combi[i].begin(), Combi[i].end(), Combi[j].begin(), Combi[j].end()))
					{
						Combi.erase(Combi.begin() + i);
						bErase = true;
						break;
					}
				}
				if (bErase == false) break;
			}
			++Result;
		}
	}

	return Result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//vector<string> Combi;
//bool Visited[8] = { false, };
//
//int Result = 0;
//
//bool Compare(string A, string B)
//{
//	return A.size() < B.size();
//}
//
//void GetCombi(int Col, int Index, string Str)
//{
//	if (Col <= Index) return;
//
//	for (int j = Index; j < Col; ++j)
//	{
//		string Insert = Str;
//		Insert.append(to_string(j));
//		Combi.push_back(Insert);
//		GetCombi(Col, j + 1, Insert);
//	}
//}
//
//bool Check(string Str)
//{
//	for (int i = 0; i < Str.size(); ++i)
//	{
//		int C = Str[i] - '0';
//		if (Visited[C] == true) return true;
//	}
//
//	return false;
//}
//
//void DFS(vector<vector<string>>& Relation, string Str)
//{
//	map<string, int> Map;
//	for (int j = 0; j < Relation.size(); ++j)
//	{
//		string Temp = "";
//		for (int i = 0; i < Str.size(); ++i)
//		{
//			int C = Str[i] - '0';
//			Temp += (Relation[j][C]);
//		}
//
//		Map[Temp] += 1;
//		if (Map[Temp] >= 2) return;
//	}
//
//	for (int i = 0; i < Str.size(); ++i)
//	{
//		int C = Str[i] - '0';
//		Visited[C] = true;
//	}
//	++Result;
//}
//
//int solution(vector<vector<string>> Relation)
//{
//	int Row = Relation.size(), Col = Relation[0].size();
//
//	GetCombi(Col, 0, "");
//	sort(Combi.begin(), Combi.end(), Compare);
//
//	int A = 0;
//
//	for (int j = 0; j < Combi.size(); ++j)
//	{
//		if (Check(Combi[j]) == true) continue;
//		DFS(Relation, Combi[j]);
//	}
//
//	return Result;
//}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//void DFS(vector<vector<string>>& Relation, vector<string> Input, int TempIndex, int Size)
//{
//	if (Size <= TempIndex) return;
//
//	map<string, int> Map;
//	for (int i = 0; i < Relation.size(); ++i)
//	{
//		Input[i].append(Relation[i][Temp[TempIndex]]);
//		Map[Input[i]] += 1;
//		if (Map[Input[i]] >= 2) return;
//	}
//
//	++Result;
//	DFS(Relation, Input, TempIndex + 1, Size);
//}
//
//int solution(vector<vector<string>> Relation)
//{
//	int Row = Relation.size(), Col = Relation[0].size();
//	for (int j = 0; j < Col; ++j)
//	{
//		for (int i = 0; i < Row; ++i)
//		{
//			Map[j][Relation[i][j]].push_back(i);
//		}
//	}
//
//	for (int i = 0; i < Col; ++i)
//	{
//		if (Map[i].size() == Row)
//		{
//			++Result;
//			continue;
//		}
//		else Temp.push_back(i);
//	}
//
//	for (int j = 0; j < Temp.size(); ++j)
//	{
//		vector<string> InsertStr;
//		for (int i = 0; i < Relation.size(); ++i)
//		{
//			InsertStr.push_back(Relation[i][Temp[j]]);
//		}
//		DFS(Relation, InsertStr, j + 1, Temp.size());
//	}
//
//	return Result;
//}

int main()
{
	/*
	[["100","ryan","music","2"],
	["200","apeach","math","2"],
	["300","tube","computer","3"],
	["400","con","computer","4"],
	["500","muzi","music","3"],
	["600","apeach","music","2"]]
	*/

	vector<vector<string>> In;
	In.push_back({ "100","ryan","music","4" });
	In.push_back({ "200","apeach","math","2" });
	In.push_back({ "300","tube","computer","3" });
	In.push_back({ "400","con","computer","4" });
	In.push_back({ "500","muzi","music","3" });
	In.push_back({ "600","apeach","music","2" });

	int Result = solution(In);

	return 0;
}

