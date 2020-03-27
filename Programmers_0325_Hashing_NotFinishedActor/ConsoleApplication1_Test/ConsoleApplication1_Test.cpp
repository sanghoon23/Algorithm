#include "pch.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <list>

#define HASHMAX 10000
using namespace std;

struct Hash
{
	int OriginCount = 0;
	int CalcCount = 0;
	Hash* NextHash = nullptr;
	string str = "";
};

Hash hash_table[HASHMAX];

int GetKey(string str)
{
	int ret = 0;
	for (int i = 0; i < str.length(); ++i)
	{
		ret += str[i] - '0';
	}

	return ret;
}

void MakeHash(string Input_Str)
{
	int Key = GetKey(Input_Str);

	//@없을 경우,
	if (hash_table[Key].str == "")
	{
		hash_table[Key].str = Input_Str;
		hash_table[Key].OriginCount = 1;
		hash_table[Key].CalcCount = 0;
		hash_table[Key].NextHash = nullptr;
	}

	//@존재할 경우
	else
	{
		//@첫번 째 문자열이 같은 경우
		if (hash_table[Key].str == Input_Str)
		{
			++hash_table[Key].OriginCount;
			return;
		}

		//while 돌면서 찾기
		Hash* Head = &hash_table[Key];
		Hash* NextPtr = hash_table[Key].NextHash;
		while (NextPtr != nullptr)
		{
			Head = NextPtr;
			NextPtr = Head->NextHash;
			if (Head->str == Input_Str)
			{
				++Head->OriginCount;
				return;
			}
		}

		//나오지 않는다면 NextHash 에 추가.
		Hash* InsertHash = new Hash();
		InsertHash->str = Input_Str;
		InsertHash->OriginCount = 1;
		InsertHash->CalcCount = 0;
		InsertHash->NextHash = nullptr;

		Head->NextHash = InsertHash;

		int a = 0;
	}
}

Hash* FindHash(string InputStr)
{
	int Key = GetKey(InputStr);

	//@없을 경우,
	if (hash_table[Key].str == "")
	{
		return nullptr;
	}

	//@존재할 경우
	else
	{
		//@첫번째 문자열이 같은 경우
		if (hash_table[Key].str == InputStr)
		{
			return &hash_table[Key];
		}

		//while 돌면서 찾기
		Hash* Head = &hash_table[Key];
		Hash* NextPtr = hash_table[Key].NextHash;
		while (NextPtr != nullptr)
		{
			Head = NextPtr;
			NextPtr = Head->NextHash;
			if (Head->str == InputStr)
			{
				return Head;
			}
		}

		return nullptr;
	}
}

string solution(vector<string> participant, vector<string> completion)
{
	for (int j = 0; j < completion.size(); ++j)
	{
		MakeHash(completion[j]);
	}

	for (int i = 0; i < participant.size(); ++i)
	{
		Hash* hash = FindHash(participant[i]);
		if (hash == nullptr)
		{
			return participant[i];
		}
		else
		{
			++hash->CalcCount;
			if (hash->OriginCount < hash->CalcCount)
			{
				return participant[i];
			}
		}

	}

	return "";
}

int main()
{
	vector<string> Input1;
	vector<string> Input2;

	Input1.push_back("iiiiii");
	Input1.push_back("iiiiii");
	Input1.push_back("jjjjjj");
	Input1.push_back("ad");
	Input1.push_back("jjjjjj");
	Input1.push_back("ad");
	Input1.push_back("da");
	Input1.push_back("cb");
	Input1.push_back("bc");

	Input2.push_back("ad");
	Input2.push_back("ad");
	Input2.push_back("iiiiii");
	Input2.push_back("iiiiii");
	Input2.push_back("jjjjjj");
	Input2.push_back("jjjjjj");
	Input2.push_back("cb");
	Input2.push_back("da");

	string result = solution(Input1, Input2);
	//	Input1.push_back("kiki");printf("%s\n", result);

	//["iiiiii", "iiiiii", "jjjjjj", "ad", "jjjjjj", "ad", "da", "cb", "bc"]
	//["ad", "ad", "iiiiii", "iiiiii", "jjjjjj", "jjjjjj", "cb", "da"]

	return 0;
}

