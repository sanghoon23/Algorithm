#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

struct Link
{
	int value = 0;
	int NodeNumber = 0;
	int LinkedNumber = 0;
};

class Compare
{
public:
	bool operator()(Link a1, Link b2)
	{
		return a1.value > b2.value;
	}
};

int Find(vector<int>& parent, int x)
{
	if (x == parent[x])
	{
		return x;
	}
	else
	{
		int p = Find(parent, parent[x]);
		parent[x] = p;
		return p;
	}
}

bool Merge(vector<int>& parent, int x, int y)
{
	x = Find(parent, x);
	y = Find(parent, y);

	if (x != y)
	{
		parent[y] = x;
		return true;
	}
	else return false;
}

int solution(int n, vector<vector<int>> costs)
{
	vector<int> parent;
	for (int i = 0; i < n; ++i)
	{
		parent.push_back(i);
	}

	priority_queue<Link, vector<Link>, Compare> pq;

	for (int j = 0; j < costs.size(); ++j)
	{
		Link Insert;
		Insert.NodeNumber = costs[j][0];
		Insert.LinkedNumber = costs[j][1];
		Insert.value = costs[j][2];

		pq.push(Insert);
	}

	int Result = 0;
	int Count = 0;
	while (!pq.empty())
	{
		Link PopedLink = pq.top();
		pq.pop();
		if (Merge(parent, PopedLink.NodeNumber, PopedLink.LinkedNumber) == true)
		{
			Result += PopedLink.value;
		}
	}

	return Result;
}

int main()
{
	vector< vector<int> > Input;

	// [[0, 1, 1], [0, 4, 5], [2, 4, 1], [2, 3, 1], [3, 4, 1]]

	vector<int> a1;
	a1.push_back(0);
	a1.push_back(2);
	a1.push_back(1);

	vector<int> a2;
	a2.push_back(0);
	a2.push_back(1);
	a2.push_back(3);

	vector<int> a3;
	a3.push_back(0);
	a3.push_back(3);
	a3.push_back(1);

	vector<int> a4;
	a4.push_back(2);
	a4.push_back(3);
	a4.push_back(1);

	vector<int> a5;
	a5.push_back(3);
	a5.push_back(1);
	a5.push_back(5);

	vector<int> a6;
	a6.push_back(1);
	a6.push_back(4);
	a6.push_back(7);

	Input.push_back(a1);
	Input.push_back(a2);
	Input.push_back(a3);
	Input.push_back(a4);
	Input.push_back(a5);
	Input.push_back(a6);

	int Result = solution(5, Input);

	return 0;
}

