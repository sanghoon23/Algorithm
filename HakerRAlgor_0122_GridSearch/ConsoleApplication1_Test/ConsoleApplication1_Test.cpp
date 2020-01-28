#include "pch.h"
#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;
bool FoundStr(vector<string>* G, int r, int c, vector<string>* P)
{
	// 찾은 행 r , 열 c 를 이용해서
	// P 에 해당하는 행렬이 존재하는지 bool 체크.
	// 같지 않다면 바로 return false;
	for (int i = 0; i < (*P).size(); ++i)
	{
		for (int j = 0; j < (*P)[i].size(); ++j)
		{
			if ((*P)[i][j] != (*G)[i + r][j + c])
				return false;
		}
	}

	return true;
}

string gridSearch(vector<string> G, vector<string> P)
{
	// G 를 돌면서,
	// 해당 첫 문자가 같다면
	// FoundStr 실행.
	for (int i = 0; i < G.size() - P.size() + 1; ++i)
	{
		for (int j = 0; j < G[i].size() - P[0].size() + 1; ++j)
		{
			if (G[i][j] == P[0][0])
			{
				if (FoundStr(&G, i, j, &P) == true)
					return "YES";
			}
		}
	}

	return "NO";
}


int main()
{
	vector<string> G;
	G.push_back("test");
	G.push_back("test");
	G.push_back("test");
	G.push_back("test");

	vector<string> P; // True
	P.push_back("est");
	P.push_back("est");

	vector<string> F; // False
	P.push_back("est");
	P.push_back("est");

	string result = gridSearch(G, P);
	cout << result.c_str() << endl;

	result = gridSearch(G, F);
	cout << result.c_str() << endl;

	return 0;
}

