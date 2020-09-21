#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

//struct Node
//{
//	int Value = 0;
//	int X = 0;
//	int Y = 0;
//	Node* Parent = nullptr;
//	Node* Left = nullptr;
//	Node* Right = nullptr;
//};
//
//bool Compare(Node* A, Node* B)
//{
//	if (A->Y != B->Y) return A->Y > B->Y;
//	else return A->X < B->X;
//}
//
//void Find(vector<Node*> Temp, int Index, bool bLeft)
//{
//	if (bLeft == true)
//	{
//		int X = Temp[Index]->X;
//		int Y = Temp[Index]->Y;
//		for (int i = Index + 1; i < Temp.size(); ++i)
//		{
//			if (Temp[i]->X < X && Temp[i]->Y < Y && Temp[i]->Parent == nullptr)
//			{
//				Temp[Index]->Left = Temp[i];
//				Temp[i]->Parent = Temp[Index];
//				break;
//			}
//		}
//	}
//	else if (bLeft == false) //@Right
//	{
//		int X = Temp[Index]->X;
//		int Y = Temp[Index]->Y;
//		for (int i = Index + 1; i < Temp.size(); ++i)
//		{
//			if (Temp[i]->X > X && Temp[i]->Y < Y && Temp[i]->Parent == nullptr)
//			{
//				Temp[Index]->Right = Temp[i];
//				Temp[i]->Parent = Temp[Index];
//				break;
//			}
//		}
//	}
//}
//
//vector<vector<int>> solution(vector<vector<int>> nodeinfo)
//{
//	vector<vector<int>> Answer;
//
//	vector<Node*> Temp;
//	for (int i = 0; i < nodeinfo.size(); ++i)
//	{
//		Node* Insert = new Node();
//		Insert->Value = i + 1;
//		Insert->X = nodeinfo[i][0];
//		Insert->Y = nodeinfo[i][1];
//		Temp.push_back(Insert);
//	}
//	sort(Temp.begin(), Temp.end(), Compare);
//
//	for (int j = 0; j < Temp.size(); ++j)
//	{
//		Find(Temp, j, true);
//		Find(Temp, j, false);
//	}
//
//
//	return Answer;
//}

struct Node
{
	int Value = 0;
	int X = 0;
	int Y = 0;
	Node* Left = nullptr;
	Node* Right = nullptr;
};

bool Compare(Node* A, Node* B)
{
	if (A->Y != B->Y) return A->Y > B->Y;
	else return A->X < B->X;
}

void Find(vector<Node*> Temp, Node* Standard)
{
	if (Temp.size() == 0) return;

	vector<Node*> Small;
	vector<Node*> Big;

	for (int i = 0; i < Temp.size(); ++i)
	{
		if (Temp[i]->X < Standard->X)
			Small.push_back(Temp[i]);
		else
			Big.push_back(Temp[i]);
	}
	sort(Small.begin(), Small.end(), Compare);
	sort(Big.begin(), Big.end(), Compare);

	if (!Small.empty())
	{
		Standard->Left = Small[0];
		Small.erase(Small.begin());
		Find(Small, Standard->Left);
	}

	if (!Big.empty())
	{
		Standard->Right = Big[0];
		Big.erase(Big.begin());
		Find(Big, Standard->Right);
	}
}

void PreOrder(vector<int>& Value, Node* Root)
{
	if (Root != nullptr)
	{
		Value.push_back(Root->Value);
		PreOrder(Value, Root->Left);
		PreOrder(Value, Root->Right);
	}
}

void PostOrder(vector<int>& Value, Node* Root)
{
	if (Root != nullptr)
	{
		PostOrder(Value, Root->Left);
		PostOrder(Value, Root->Right);
		Value.push_back(Root->Value);
	}
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo)
{
	vector<vector<int>> Answer;

	vector<Node*> Temp;
	for (int i = 0; i < nodeinfo.size(); ++i)
	{
		Node* Insert = new Node();
		Insert->Value = i + 1;
		Insert->X = nodeinfo[i][0];
		Insert->Y = nodeinfo[i][1];
		Temp.push_back(Insert);
	}
	sort(Temp.begin(), Temp.end(), Compare);

	Node* Root = Temp[0];
	Temp.erase(Temp.begin());

	Find(Temp, Root);

	//@전위
	vector<int> Pre;
	PreOrder(Pre, Root);

	//@후위
	vector<int> Post;
	PostOrder(Post, Root);

	//@Result
	Answer.push_back(Pre);
	Answer.push_back(Post);

	return Answer;
}

int main()
{
	//[[5,3],[11,5],[13,3],[3,5],[6,1],[1,3],[8,6],[7,2],[2,2]]

	vector<vector<int>> NodeInfo;
	vector<int> In1;
	In1.push_back(5);
	In1.push_back(3);

	vector<int> In2;
	In2.push_back(11);
	In2.push_back(5);

	vector<int> In3;
	In3.push_back(13);
	In3.push_back(3);

	vector<int> In4;
	In4.push_back(3);
	In4.push_back(5);

	vector<int> In5;
	In5.push_back(6);
	In5.push_back(1);

	vector<int> In6;
	In6.push_back(1);
	In6.push_back(3);

	vector<int> In7;
	In7.push_back(8);
	In7.push_back(6);

	vector<int> In8;
	In8.push_back(7);
	In8.push_back(2);

	vector<int> In9;
	In9.push_back(2);
	In9.push_back(2);

	NodeInfo.push_back(In1);
	NodeInfo.push_back(In2);
	NodeInfo.push_back(In3);
	NodeInfo.push_back(In4);
	NodeInfo.push_back(In5);
	NodeInfo.push_back(In6);
	NodeInfo.push_back(In7);
	NodeInfo.push_back(In8);
	NodeInfo.push_back(In9);

	vector<vector<int>> Result = solution(NodeInfo);


	return 0;
}

