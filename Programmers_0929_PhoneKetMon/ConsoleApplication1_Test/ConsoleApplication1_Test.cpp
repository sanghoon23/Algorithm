#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>
#include <unordered_map>

using namespace std;

//@다른 코드 - 굳이 여기에 해쉬를..??
//int solution(vector<int> nums)
//{
//	unordered_map<int, int> hash;
//
//	for (auto num : nums) {
//		hash[num] += 1;
//	}
//
//	return min(hash.size(), nums.size() / 2);
//
//}

//@중복 제거 - **unique 쓰기전에 sort 부탁해..꼭..**
int solution(vector<int> nums)
{
	int HalfSize = nums.size() / 2;
	sort(nums.begin(), nums.end()); // *sort 안해서 헤맸잖어..
	nums.erase(unique(nums.begin(), nums.end()), nums.end());

	int NumSize = nums.size();
	return min(NumSize, HalfSize);
}

//@Boolean 으로 체크하기.
//bool Visited[200001] = { false, };
//int solution(vector<int> nums)
//{
//	int Answer = 0;
//
//	int Size = nums.size() / 2;
//	for (int i = 0; i < nums.size(); ++i)
//	{
//		if (Visited[nums[i]] == false)
//		{
//			Visited[nums[i]] = true;
//			++Answer;
//		}
//
//		if (Answer >= Size) break;
//	}
//	return Answer;
//}

int main()
{
	//[3,1,2,3]
	//[3, 3, 3, 2, 2, 4]
	//[3, 3, 3, 2, 2, 2]

	vector<int> Insert;
	Insert.push_back(3);
	Insert.push_back(3);
	Insert.push_back(3);
	Insert.push_back(2);
	Insert.push_back(2);
	Insert.push_back(4);

	int Result = solution(Insert);

	return 0;
}

