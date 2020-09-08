#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

bool CheckVec(vector<vector<int>>& Vec, int LockSize)
{
	for (int j = LockSize; j < Vec.size() - LockSize; ++j) //@ex) 3,4,5
	{
		for (int i = LockSize; i < Vec.size() - LockSize; ++i)
		{
			if (Vec[j][i] == 0 || Vec[j][i] > 1)
			{
				return false;
			}
		}
	}
	return true;
}

void InitVec(vector<vector<int>>& Vec, vector<vector<int>>& Lock)
{
	int LockSize = Lock.size();
	for (int j = 0; j < Vec.size(); ++j)
	{
		for (int i = 0; i < Vec[j].size(); ++i)
		{
			Vec[j][i] = 0;

			if (i < Vec.size() - LockSize && i >= LockSize)
			{
				if (j < Vec.size() - LockSize && j >= LockSize)
				{
					Vec[j][i] = Lock[j - LockSize][i - LockSize];
				}
			}

		}
	}
}

void PlusVec(vector<vector<int>>& Vec, vector<vector<int>> Key, int StartIndexX, int StartIndexY, int KeySize)
{
	for (int j = StartIndexY; j < StartIndexY + KeySize; ++j)
	{
		for (int i = StartIndexX; i < StartIndexX + KeySize; ++i)
		{
			Vec[j][i] += Key[j - StartIndexY][i - StartIndexX];
		}
	}
}

void RotateVec(vector<vector<int>>& Vec, vector<vector<int>>& Key, int Rotation)
{
	if (Rotation == 0)
	{
		Vec = Key;
		return;
	}

	if (Rotation == 90)
	{
		for (int j = 0; j < Key.size(); ++j)
		{
			vector<int> Insert;
			for (int i = Key[j].size() - 1; i >= 0 ; --i)
			{
				Insert.push_back(Key[i][j]); //@i, j 가 바뀜.
			}
			Vec.push_back(Insert);
		}
	}
	else if (Rotation == 180)
	{
		for (int j = Key.size() - 1; j >= 0; --j)
		{
			vector<int> Insert;
			for (int i = Key[j].size() - 1; i >= 0; --i)
			{
				Insert.push_back(Key[j][i]);
			}
			Vec.push_back(Insert);
		}

	}
	else if (Rotation == 270)
	{
		for (int j = Key.size() - 1; j >= 0; --j)
		{
			vector<int> Insert;
			for (int i = 0; i < Key[j].size(); ++i)
			{
				Insert.push_back(Key[i][j]); //@i, j 가 바뀜.
			}
			Vec.push_back(Insert);
		}
	}
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock)
{
	int LockSize = lock.size();
	vector<vector<int>> Pan;
	for (int i = 0; i < LockSize * 3; ++i) //@가로,세로 3배 큰 배열
	{
		vector<int> Insert(LockSize * 3, 0);
		Pan.push_back(Insert);
	}

	InitVec(Pan, lock);

	for (int s = 0; s < 4; ++s)
	{
		vector<vector<int>> Calc;
		RotateVec(Calc, key, 90 * s);

		for (int j = 0; j < LockSize * 2; ++j)
		{
			for (int i = 0; i < LockSize * 2; ++i)
			{
				PlusVec(Pan, Calc, i, j, Calc.size());
				if (CheckVec(Pan, LockSize) == true)
				{
					return true;
				}

				InitVec(Pan, lock);
			}
		}
	}

	return false;
}

int main()
{
	vector<vector<int>> Key;
	vector<int> In1;
	In1.push_back(0);
	In1.push_back(0);
	In1.push_back(0);

	vector<int> In2;
	In2.push_back(1);
	In2.push_back(0);
	In2.push_back(0);

	vector<int> In3;
	In3.push_back(0);
	In3.push_back(1);
	In3.push_back(1);

	Key.push_back(In1);
	Key.push_back(In2);
	Key.push_back(In3);


	vector<vector<int>> Lock;
	vector<int> Insert1;
	Insert1.push_back(1);
	Insert1.push_back(1);
	Insert1.push_back(1);

	vector<int> Insert2;
	Insert2.push_back(1);
	Insert2.push_back(1);
	Insert2.push_back(0);

	vector<int> Insert3;
	Insert3.push_back(1);
	Insert3.push_back(0);
	Insert3.push_back(1);

	Lock.push_back(Insert1);
	Lock.push_back(Insert2);
	Lock.push_back(Insert3);

	bool Result = solution(Key, Lock);

	return 0;
}

