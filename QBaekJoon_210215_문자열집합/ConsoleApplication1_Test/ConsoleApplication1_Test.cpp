#include "pch.h"
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;
#define FASTIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
int N, M;
string Input;
int main()
{
	FASTIO;
	cin >> N >> M;
	unordered_map<string, int> UnMap;
	for (int i = 0; i < N; ++i)
	{
		cin >> Input;
		++UnMap[Input];
	}
	int Answer = 0;
	for (int i = 0; i < M; ++i)
	{
		cin >> Input;
		if (UnMap[Input] == 1) ++Answer;
	}
	cout << Answer;
	return 0;
}

/////////////////////////////////////////////////////////////////////////////////
//@Trie 를 사용한 풀이
//int N, M;
//string Input;
//
//struct TrieNode
//{
//	TrieNode* Alpha[26];
//	bool bFinal = false;
//
//	void Insert(string& Str)
//	{
//		int NSize = Str.size(), Idx = 0;
//		TrieNode* Node = this;
//		while (Idx < NSize)
//		{
//			int Curr = Str[Idx] - 'a';
//			if (Node->Alpha[Curr] == nullptr)
//				Node->Alpha[Curr] = new TrieNode();
//			Node = Node->Alpha[Curr];
//			++Idx;
//		}
//		Node->bFinal = true;
//	}
//
//	bool Check(string& Str)
//	{
//		bool bFind = true;
//		int NSize = Str.size(), Idx = 0;
//		TrieNode* Node = this;
//		while (Idx < NSize)
//		{
//			int Curr = Str[Idx] - 'a';
//			if (Node->Alpha[Curr] == nullptr) { bFind = false; break; }
//			Node = Node->Alpha[Curr];
//			++Idx;
//		}
//		if (Node->bFinal == false) return false;
//		return bFind;
//	}
//};
//int main()
//{
//	FASTIO;
//	cin >> N >> M;
//	TrieNode* Root = new TrieNode();
//	for (int i = 0; i < N; ++i)
//	{
//		cin >> Input;
//		Root->Insert(Input);
//	}
//	int Answer = 0;
//	for (int i = 0; i < M; ++i)
//	{
//		cin >> Input;
//		if (Root->Check(Input))
//			++Answer;
//	}
//	cout << Answer;
//	return 0;
//}


