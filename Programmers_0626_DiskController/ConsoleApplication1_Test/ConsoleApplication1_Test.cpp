#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>
#include <queue>

using namespace std;

class Compare
{
public:
	bool operator()(vector<int> a, vector<int> b)
	{
		return a[1] > b[1];
	}
};

int solution(vector<vector<int>> jobs)
{
	int Answer = 0;
	int Size = jobs.size();

	sort(jobs.begin(), jobs.end());

	priority_queue <vector<int>, vector<vector<int>>, Compare> PQ;
	int CurrentTimer = 0;
	int Index = 0;
	while (Index < Size || !PQ.empty())
	{
		if (Index < Size && jobs[Index][0] <= CurrentTimer)
		{
			PQ.push(jobs[Index++]);
			continue;
		}


		if (!PQ.empty())
		{
			vector<int> Poped = PQ.top();
			PQ.pop();

			Answer += Poped[1] + (CurrentTimer - Poped[0]);

			CurrentTimer += Poped[1];
		}
		else
			CurrentTimer = jobs[Index][0];
	}

	return Answer / Size;


	//..
	//@오류 코드
	//int Answer = 0;
	//int Size = jobs.size();

	//sort(jobs.begin(), jobs.end());

	//priority_queue <vector<int>, vector<vector<int>>, Compare> PQ;
	/* ****************************************************************************************** */
	//@@ 이 부분이 문제 -
	/*
	jobs[0][0] 을 무조건 첫번째값으로 쓰고 있는데,
	이 첫번째 값이 제일 짧은거라는 가정은 어디있나, 없다.
	Index 를 처음 1을 잡고 가는건 무의미하다.
	*/
	//int CurrentTimer = jobs[0][0] + jobs[0][1]; 
	//Answer += jobs[0][0] + jobs[0][1];


	/* ****************************************************************************************** */

	//int Index = 1;
	//while (Index < Size || !PQ.empty())
	//{
	//	if (Index < Size && jobs[Index][0] <= CurrentTimer)
	//	{
	//		PQ.push(jobs[Index++]);

	//		//++Index;
	//		continue;
	//	}
	//	else if (jobs[Index][0] > CurrentTimer && PQ.empty()) //@떨어져있을 때,
	//	{
	//		CurrentTimer += CurrentTimer - jobs[Index][0];
	//	}


	//	if (!PQ.empty())
	//	{
	//		vector<int> Poped = PQ.top();
	//		PQ.pop();

	//		Answer += Poped[1] + (CurrentTimer - Poped[0]);

	//		CurrentTimer += Poped[1];
	//	}
	//}
}

int main()
{
	//[[0, 3], [1, 9], [2, 6]]	9

	vector<vector<int>> Input;

	vector<int> In1;
	In1.push_back(0);
	In1.push_back(3);

	vector<int> In2;
	In2.push_back(1);
	In2.push_back(9);

	vector<int> In3;
	In3.push_back(2);
	In3.push_back(6);

	Input.push_back(In1);
	Input.push_back(In2);
	Input.push_back(In3);

	int Result = solution(Input);

	return 0;
}

