#include "pch.h"
#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <algorithm>

using namespace std;

//vector<int> solution(int N, vector<int> In)
//{
//	vector<int> Temp(N, 0);
//	for (int i = In.size() - 1; i >= 0; --i)
//	{
//		if (Temp[(i % (N-1))] == 0)
//			Temp[(i % (N-1))] = i + 1;
//		else
//		{
//			for (int k = In[i]; k < Temp.size() - 1; ++k)
//				Temp[k + 1] = Temp[k];
//
//			Temp[In[i]] = i + 1;
//		}
//	}
//
//	return Temp;
//}

//int main()
//{
//	int N = 0;
//	cin >> N;
//
//	vector<int> Insert = { 2, 1, 1, 0 };
//	vector<int> Result = solution(N, Insert);
//
//	return 0;
//}

vector<int> solution(int N, vector<int> In)
{
	vector<int> Temp(N, 0);
	for (int i = In.size() - 1; i >= 0; --i)
	{
		if (Temp[(i % (N - 1))] == 0)
			Temp[(i % (N - 1))] = i + 1;
		else
		{
			for (int k = In[i]; k < Temp.size() - 1; ++k)
				Temp[k + 1] = Temp[k];

			Temp[In[i]] = i + 1;
		}
	}

	return Temp;
}

int N = 0;
int V = 0;
vector<int> Insert;
vector<int> Temp;

int main()
{
	cin >> N;

	for (int i = 0; i < N; ++i)
	{
		cin >> V;
		Insert.push_back(V);
	}

	for (int i = N - 1; i >= 0; --i)
	{
		auto it = Temp.begin();
		Temp.insert(it + Insert[i], i + 1);
	}

	for (int k = 0; k < N; ++k)
		cout << Temp[k] << " ";

	return 0;
}

