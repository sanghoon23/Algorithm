#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

//int Mini(int a, int b, int c)
//{
//	int Min = min(a, b);
//	Min = min(Min, c);
//	return Min;
//}

int solution(vector<vector<int>> board)
{
	int Answer = board[0][0];

	for (int j = 1; j < board.size(); ++j)
	{
		for (int i = 1; i < board[j].size(); ++i)
		{
			if (board[j][i] == 0) continue;
			int Diag = board[j - 1][i - 1]; //@대각
			int Up = board[j - 1][i]; //@위
			int Side = board[j][i - 1]; //@옆

			if (Diag == 0 || Up == 0 || Side == 0) continue;
			board[j][i] = min(min(Diag, Up), Side) + 1; //@Mini 함수 말고 그냥 min 두개 쓰자.(한줄로)
			Answer = max(Answer, board[j][i]);
		}
	}

	return Answer * Answer;
}

int main()
{
	vector<vector<int>> Board;
	Board.push_back({ 0, 1, 1, 1 });
	Board.push_back({ 1, 1, 1, 1 });
	Board.push_back({ 1, 1, 1, 1 });
	Board.push_back({ 0, 0, 1, 0 });

	int Result = solution(Board);

	return 0;
}

