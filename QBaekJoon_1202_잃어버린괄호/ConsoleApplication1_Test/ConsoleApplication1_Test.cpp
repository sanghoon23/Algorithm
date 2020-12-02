#include "pch.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int Answer = 0;
string Str = "";

int main()
{
	getline(cin, Str);
	string V = "0";
	bool bMius = false;
	for (int i = 0; i <= Str.size(); ++i)
	{
		if (Str[i] != '+' && Str[i] != '-' && Str[i] != '\0')
		{
			V.push_back(Str[i]);
			continue;
		}

		if (bMius == true) Answer -= stoi(V);
		else Answer += stoi(V);
		V = "";

		if (Str[i] == '-')
			bMius = true;
	}

	cout << Answer;

	return 0;
}

//int Answer = 0;
//string Str = "";
//vector<char> Op;
//vector<int> Val;
//
//void DFS(vector<bool> Visited, int Index) //@Index 1부터
//{
//	if (Visited[Index] == true) return;
//
//	Visited[Index] = true;
//	int F = Val[Index - 1], S = Val[Index];
//	if (Op[Index] == '-')
//		S *= (-1);
//
//	Val[Index - 1] = F + S;
//	Val[Index] = F + S;
//
//	for (int i = 1; i < Op.size(); ++i)
//		DFS(Visited, i);
//}
//
//int main()
//{
//	getline(cin, Str);
//	string V;
//	Op.push_back(' ');
//	for (int i = 0; i < Str.length(); ++i)
//	{
//		if (Str[i] != '+' && Str[i] != '-')
//			V.push_back(Str[i]);
//		else
//		{
//			Op.push_back(Str[i]);
//			Val.push_back(atoi(V.c_str()));
//			V = "";
//		}
//	}
//	Val.push_back(atoi(V.c_str()));
//
//	for (int k = 1; k < Op.size(); ++k)
//	{
//		vector<bool> Visi(Op.size(), false);
//		DFS(Visi, k);
//	}
//
//	return 0;
//}

