#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>

//@Heap 사용 시도..
//using namespace std;
//
//class Compare
//{
//	bool operator()(int a, int b)
//	{
//		return a > b;
//	}
//};
//
//bool MaxCompare(int a, int b)
//{
//	return a > b;
//}
//
//vector<int> solution(vector<string> operations)
//{
//	vector<int> Answer;
//
//	vector<int> Heap;
//	make_heap(Heap.begin(), Heap.end());
//
//	for (int j = 0; j < operations.size(); ++j)
//	{
//		if (operations[j][0] == 'I')
//		{
//			string In = operations[j].substr(2, operations[j].size());
//			Heap.push_back(atoi(In.c_str()));
//			push_heap(Heap.begin(), Heap.end());
//		}
//		else if (operations[j][0] == 'D')
//		{
//			if (Heap.empty() == true) continue;
//
//			if (operations[j][2] == '1')
//			{
//				sort_heap(Heap.begin(), Heap.end());
//				//pop_heap(Heap.begin(), Heap.end());
//				Heap.pop_back();
//			}
//			else if (operations[j][2] == '-')
//			{
//				make_heap(Heap.begin(), Heap.end());
//				//pop_heap(Heap.begin(), Heap.end());
//				Heap.pop_back();
//			}
//		}
//	}
//
//	//@Result
//	if (Heap.empty())
//	{
//		Answer.push_back(0); Answer.push_back(0);
//	}
//	else
//	{
//		sort_heap(Heap.begin(), Heap.end());
//		Answer.push_back(Heap.back());
//		Heap.pop_back();
//
//		make_heap(Heap.begin(), Heap.end());
//		Answer.push_back(Heap.back());
//	}
//
//	return Answer;
//}


//@Vector 사용
using namespace std;

vector<int> solution(vector<string> operations)
{
	vector<int> Answer;

	vector<int> Heap;

	for (int j = 0; j < operations.size(); ++j)
	{
		if (operations[j][0] == 'I')
		{
			string In = operations[j].substr(2, operations[j].size());
			Heap.push_back(atoi(In.c_str()));
		}
		else if (operations[j][0] == 'D')
		{
			if (Heap.empty() == true) continue;

			if (operations[j][2] == '1') //@최댓값
			{
				sort(Heap.begin(), Heap.end());
				Heap.erase(Heap.begin() + Heap.size() - 1);
			}
			else if (operations[j][2] == '-') //@최솟값
			{
				sort(Heap.begin(), Heap.end());
				Heap.erase(Heap.begin());
			}
		}
	}

	//@Result
	if (Heap.empty())
	{
		Answer.push_back(0); Answer.push_back(0);
	}
	else
	{
		sort(Heap.begin(), Heap.end());
		Answer.push_back(Heap[Heap.size() - 1]);
		Answer.push_back(Heap[0]);
	}

	return Answer;
}

int main()
{
	vector<string> Input;

	//	["I 16", "I -5643", "D -1", "D 1", "D 1", "I 123", "D -1"]
	//Input.push_back(string("I 16"));
	//Input.push_back(string("I -5643"));
	//Input.push_back(string("D -1"));
	//Input.push_back(string("D 1"));
	//Input.push_back(string("D 1"));
	//Input.push_back(string("I 123"));
	//Input.push_back(string("D -1"));

	//["I -45", "I 653", "D 1", "I -642", "I 45", "I 97", "D 1", "D -1", "I 333"]
	Input.push_back(string("I -45"));
	Input.push_back(string("I 653"));
	Input.push_back(string("D 1"));
	Input.push_back(string("I -642"));
	Input.push_back(string("I 45"));
	Input.push_back(string("I 97"));
	Input.push_back(string("D 1"));
	Input.push_back(string("D -1"));
	Input.push_back(string("I 333"));


	vector<int> Result = solution(Input);

	return 0;
}

