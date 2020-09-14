#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

bool Gidung[102][102] = { 0, };
bool Boo[102][102] = { 0, };

bool Compare(vector<int> A, vector<int> B)
{
	if (A[0] != B[0]) return A[0] < B[0];
	else if (A[0] == B[0] && A[1] != B[1]) return A[1] < B[1];
	else if (A[0] == B[0] && A[1] == B[1]) return A[2] < B[2];
}

bool CheckGidung(int x, int y)
{
	if (y == 1) return true;
	if (Gidung[x][y - 1] == 1) return true;
	if (Boo[x - 1][y] == 1) return true;
	if (Boo[x][y] == 1) return true;

	return false;
}

bool CheckBoo(int x, int y)
{
	if (Gidung[x][y - 1] == 1) return true;
	if (Gidung[x + 1][y - 1] == 1) return true;
	if (Boo[x - 1][y] == 1 && Boo[x + 1][y] == 1) return true;

	return false;
}

bool CheckDel(int n)
{
	for (int j = 1; j <= n + 1; ++j)
	{
		for (int i = 1; i <= n + 1; ++i)
		{
			if (Gidung[j][i] == 1)
			{
				if (CheckGidung(j, i) == false)
					return false;
			}

			if (Boo[j][i] == 1)
			{
				if (CheckBoo(j, i) == false)
					return false;
			}
		}
	}

	return true;
}

//bool CheckDelBoo(int n)
//{
//	for (int j = 1; j <= n + 1; ++j)
//	{
//		for (int i = 1; i <= n + 1; ++i)
//		{
//			if (Boo[j][i] == 1)
//			{
//				if (CheckBoo(j, i) == false)
//					return false;
//			}
//		}
//	}
//
//	return true;
//}

vector<vector<int>> solution(int n, vector<vector<int>> build_frame)
{
	vector<vector<int>> Answer;

	for (int j = 0; j < build_frame.size(); ++j)
	{
		int X = build_frame[j][0] + 1;
		int Y = build_frame[j][1] + 1;
		int Sort = build_frame[j][2];
		int Apply = build_frame[j][3];

		if (Apply == 1 && Sort == 0) //@설치
		{
			if (CheckGidung(X, Y) == true)
			{
				Gidung[X][Y] = true;
			}
		}
		else if (Apply == 1 && Sort == 1) //@보
		{
			if (CheckBoo(X, Y) == true)
			{
				Boo[X][Y] = true;
			}
		}

		if (Apply == 0 && Sort == 0) //@기둥
		{
			Gidung[X][Y] = false;
			if (CheckDel(n) == false)
			{
				Gidung[X][Y] = true;
			}
		}
		else if (Apply == 0 && Sort == 1) //@보
		{
			Boo[X][Y] = false;
			if (CheckDel(n) == false)
			{
				Boo[X][Y] = true;
			}
		}
	}

	for (int j = 1; j <= n + 1; ++j)
	{
		for (int i = 1; i <= n + 1; ++i)
		{
			if (Gidung[j][i] == 1)
			{
				Answer.push_back({ j - 1, i - 1, 0 });
			}
			if (Boo[j][i] == 1)
			{
				Answer.push_back({ j - 1, i - 1, 1 });
			}
		}
	}

	sort(Answer.begin(), Answer.end(), Compare);

	return Answer;
}

int main()
{
	//[[1, 0, 0, 1], [1, 1, 1, 1], [2, 1, 0, 1], [2, 2, 1, 1],
	//[5, 0, 0, 1], [5, 1, 0, 1], [4, 2, 1, 1], [3, 2, 1, 1]]

	vector<vector<int>> Insert;
	
	//vector<int> In1;
	//In1.push_back(1);
	//In1.push_back(0);
	//In1.push_back(0);
	//In1.push_back(1);

	//vector<int> In2;
	//In2.push_back(1);
	//In2.push_back(1);
	//In2.push_back(1);
	//In2.push_back(1);

	//vector<int> In3;
	//In3.push_back(2);
	//In3.push_back(1);
	//In3.push_back(0);
	//In3.push_back(1);

	//vector<int> In4;
	//In4.push_back(2);
	//In4.push_back(2);
	//In4.push_back(1);
	//In4.push_back(1);

	////
	//vector<int> In5;
	//In5.push_back(5);
	//In5.push_back(0);
	//In5.push_back(0);
	//In5.push_back(1);

	//vector<int> In6;
	//In6.push_back(5);
	//In6.push_back(1);
	//In6.push_back(0);
	//In6.push_back(1);

	//vector<int> In7;
	//In7.push_back(4);
	//In7.push_back(2);
	//In7.push_back(1);
	//In7.push_back(1);

	//vector<int> In8;
	//In8.push_back(3);
	//In8.push_back(2);
	//In8.push_back(1);
	//In8.push_back(1);

	//Insert.push_back(In1);
	//Insert.push_back(In2);
	//Insert.push_back(In3);
	//Insert.push_back(In4);
	//Insert.push_back(In5);
	//Insert.push_back(In6);
	//Insert.push_back(In7);
	//Insert.push_back(In8);

	//////////////////////////////////////////////////////////////////////////////////

	vector<int> In1;
	In1.push_back(0);
	In1.push_back(0);
	In1.push_back(0);
	In1.push_back(1);

	vector<int> In2;
	In2.push_back(2);
	In2.push_back(0);
	In2.push_back(0);
	In2.push_back(1);

	vector<int> In3;
	In3.push_back(4);
	In3.push_back(0);
	In3.push_back(0);
	In3.push_back(1);

	vector<int> In4;
	In4.push_back(0);
	In4.push_back(1);
	In4.push_back(1);
	In4.push_back(1);

	//
	vector<int> In5;
	In5.push_back(1);
	In5.push_back(1);
	In5.push_back(1);
	In5.push_back(1);

	vector<int> In6;
	In6.push_back(2);
	In6.push_back(1);
	In6.push_back(1);
	In6.push_back(1);

	vector<int> In7;
	In7.push_back(3);
	In7.push_back(1);
	In7.push_back(1);
	In7.push_back(1);

	vector<int> In8;
	In8.push_back(2);
	In8.push_back(0);
	In8.push_back(0);
	In8.push_back(0);

	vector<int> In9;
	In9.push_back(1);
	In9.push_back(1);
	In9.push_back(1);
	In9.push_back(0);

	vector<int> In10;
	In10.push_back(2);
	In10.push_back(2);
	In10.push_back(0);
	In10.push_back(1);

	Insert.push_back(In1);
	Insert.push_back(In2);
	Insert.push_back(In3);
	Insert.push_back(In4);
	Insert.push_back(In5);
	Insert.push_back(In6);
	Insert.push_back(In7);
	Insert.push_back(In8);
	Insert.push_back(In9);
	Insert.push_back(In10);

	vector<vector<int>> Result = solution(5, Insert);

	return 0;
}

