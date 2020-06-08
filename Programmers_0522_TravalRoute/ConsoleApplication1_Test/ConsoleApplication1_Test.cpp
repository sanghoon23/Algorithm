#include "pch.h"
#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <algorithm>

using namespace std;

static vector<string> Result; //@DFS

//@true - 바꿔야 함, false - 기존 값 그대로
bool Compare(vector<string>& Result, vector<string>& Temp)
{
	if (Result.empty()) return true;

	for (int j = 1; j < Temp.size(); ++j)
	{
		if (Temp[j] == Result[j]) continue;

		for (int i = 0; i < Temp[j].size(); ++i)
		{
			if (Temp[j][i] < Result[j][i]) return true;
			else return false;
		}
	}

	return false;
}

void BFS(vector<vector<string>>& Tickets, vector<bool>& bCheck, vector<string>& In)
{
	queue<string> Queue;
	Queue.push(In.back());

	while (!Queue.empty())
	{
		string PopedStr = Queue.front();
		Queue.pop();

		for (int i = 0; i < Tickets.size(); ++i)
		{
			if (Tickets[i][0] == PopedStr && bCheck[i] == false)
			{
				bCheck[i] = true;
				Queue.push(Tickets[i][1]);
				In.push_back(Tickets[i][1]);

				break;
			}
		}
	}

	if (In.size() < Tickets.size() + 1) return;

	if (Compare(Result, In) == true)
		Result = In;
}

void DFS(vector<string> In, vector<vector<string>>& Tickets, vector<bool>& bCheck)
{
	if (In.size() == Tickets.size() + 1)
	{
		if (Compare(Result, In) == true)
			Result = In;

		return;
	}

	int LastIn = In.size() - 1;
	for (int i = 0; i < Tickets.size(); ++i)
	{
		vector<string> temp;
		if (Tickets[i][0] == In[LastIn] && bCheck[i] == false)
		{
			bCheck[i] = true;

			temp = In;
			temp.push_back(Tickets[i][1]);
			DFS(temp, Tickets, bCheck);

			bCheck[i] = false;
		}
	}
}

vector<string> solution(vector<vector<string>> tickets)
{
	int Size = tickets.size();
	vector<bool> bCheck(Size, false);

	//** 정렬 **
	sort(tickets.begin(), tickets.end());

	////@DFS
	//for (int i = 0; i < Size; ++i)
	//{
	//	vector<string> temp;
	//	std::fill(bCheck.begin(), bCheck.end(), false);
	//	if (tickets[i][0] == "ICN")
	//	{
	//		bCheck[i] = true;
	//		temp.push_back(tickets[i][0]);
	//		temp.push_back(tickets[i][1]);

	//		DFS(temp, tickets, bCheck);
	//	}
	//}

	/* 넓이 탐색으로는 모든 경로를 다 돌 수 있는 경우의 수가 나오지 않을 수 있다. */
	////@BFS
	//for (int i = 0; i < Size; ++i)
	//{
	//	vector<string> temp;
	//	std::fill(bCheck.begin(), bCheck.end(), false);
	//	if (tickets[i][0] == "ICN")
	//	{
	//		bCheck[i] = true;
	//		temp.push_back(tickets[i][0]);
	//		temp.push_back(tickets[i][1]);

	//		BFS(tickets, bCheck, temp);
	//	}
	//}

	return Result;
}

int main()
{
	vector<vector<string>> Input;

	vector<string> In1;
	In1.push_back("ICN");
	In1.push_back("SFO");

	vector<string> In2;
	In2.push_back("ICN");
	In2.push_back("ATL");

	vector<string> In3;
	In3.push_back("SFO");
	In3.push_back("ATL");

	vector<string> In4;
	In4.push_back("ATL");
	In4.push_back("ICN");

	vector<string> In5;
	In5.push_back("ATL");
	In5.push_back("SFO");

	Input.push_back(In1);
	Input.push_back(In2);
	Input.push_back(In3);
	Input.push_back(In4);
	Input.push_back(In5);

	vector<string> Ret;
	Ret = solution(Input);

	return 0;
}

