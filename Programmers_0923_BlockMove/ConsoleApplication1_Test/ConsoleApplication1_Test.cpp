#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <list>
#include <algorithm>

using namespace std;

bool Visited[101][101][4] = { false, };

//0 - 오른, 1 - 아래, 2 - 왼, 3 - 위
int DirY[4] = { 0, 1, 0, -1 };
int DirX[4] = { 1, 0, -1, 0 };

struct Robot
{
	int Dir = 0;
	int Point[2] = { 0, 0 }; //@y, x
};

bool Check(struct Robot Robo, int Size)
{
	int AnotherY = Robo.Point[0] + DirY[Robo.Dir];
	int AnotherX = Robo.Point[1] + DirX[Robo.Dir];
	if (Robo.Point[0] < 0 || Robo.Point[1] < 0 || Robo.Point[0] >= Size || Robo.Point[1] >= Size
		|| AnotherY < 0 || AnotherX < 0 || AnotherY >= Size || AnotherX >= Size)
	{
		return false;
	}//범위
	return true;
}

bool CheckApply(vector<vector<int>>& Board, struct Robot Robo) //그 위치가 가능한지
{
	int AnotherY = Robo.Point[0] + DirY[Robo.Dir];
	int AnotherX = Robo.Point[1] + DirX[Robo.Dir];
	if (Board[AnotherY][AnotherX] == 1 || Board[Robo.Point[0]][Robo.Point[1]] == 1)
	{
		return false;
	}//해당 위치가 벽이 아닌지

	if (Visited[Robo.Point[0]][Robo.Point[1]][Robo.Dir] == true)
	{
		return false;
	}

	Visited[Robo.Point[0]][Robo.Point[1]][Robo.Dir] = true;
	return true;
}

int solution(vector<vector<int>> board)
{
	int Answer = 0;

	queue<Robot> Que;
	struct Robot Robo;
	Que.push(Robo);
	Visited[0][0][Robo.Dir] = true;

	while (!Que.empty())
	{
		int QueSize = Que.size();
		while (QueSize--)
		{
			Robot Poped = Que.front();
			Que.pop();

			int AnotherY = Poped.Point[0] + DirY[Poped.Dir];
			int AnotherX = Poped.Point[1] + DirX[Poped.Dir];
			if ((AnotherY == board.size() - 1 && AnotherX == board.size() - 1)
				|| (Poped.Point[0] == board.size() - 1 && Poped.Point[1] == board.size() - 1))
			{
				return Answer; //n*n 이면 리턴
			}

			for (int i = 0; i < 4; ++i)
			{
				struct Robot Insert = Poped;
				Insert.Point[0] += DirY[i];
				Insert.Point[1] += DirX[i];

				if (Check(Insert, board.size()) == false) continue; //범위
				if (CheckApply(board, Insert) == false) continue;

				Que.push(Insert);

			}

			for (int j = 0; j < 2; ++j) //정방향, 반대방향
			{
				for (int i = -1; i < 2; ++i) // 위쪽, 아래쪽
				{
					if (i == 0) continue;
					struct Robot Insert = Poped;
					if (j != 0)
					{
						Insert.Point[0] = Insert.Point[0] + DirY[Insert.Dir];
						Insert.Point[1] = Insert.Point[1] + DirX[Insert.Dir];
						Insert.Dir = (Insert.Dir + 2) % 4;
					}
					if (Check(Insert, board.size()) == false) continue; //범위

					//@해당 방향에 벽이 있는지 없는지
					int AnotherY = Insert.Point[0] + DirY[Insert.Dir];
					int AnotherX = Insert.Point[1] + DirX[Insert.Dir];
					int CheckDir = (Insert.Dir + i + 4) % 4;
					if (Insert.Dir % 2 == 0)//가로
					{
						if (AnotherY + DirY[CheckDir] < 0 || AnotherY + DirY[CheckDir] >= board.size()) continue;
						if (board[AnotherY + DirY[CheckDir]][AnotherX] == 1) continue; // 가로일때 확인
					}
					else if (Insert.Dir % 2 == 1) //세로
					{
						if (AnotherX + DirX[CheckDir] < 0 || AnotherX + DirX[CheckDir] >= board.size()) continue;
						if (board[AnotherY][AnotherX + DirX[CheckDir]] == 1) continue; // 가로일때 확인
					}

					Insert.Dir = CheckDir; //@방향설정

					if (Check(Insert, board.size()) == false) continue; //범위
					if (CheckApply(board, Insert) == false) continue;

					Que.push(Insert);
				}


			}//회전
		}

		++Answer;
	}

	return Answer;
}

int main()
{
	//[[0, 0, 0, 1, 1],[0, 0, 0, 1, 0],[0, 1, 0, 1, 1],[1, 1, 0, 0, 1],[0, 0, 0, 0, 0]]
	vector<vector<int>> Board;

	vector<int> In1;
	In1.push_back(0);
	In1.push_back(0);
	In1.push_back(0);
	In1.push_back(1);
	In1.push_back(1);

	vector<int> In2;
	In2.push_back(0);
	In2.push_back(0);
	In2.push_back(0);
	In2.push_back(1);
	In2.push_back(0);

	vector<int> In3;
	In3.push_back(0);
	In3.push_back(1);
	In3.push_back(0);
	In3.push_back(1);
	In3.push_back(1);

	vector<int> In4;
	In4.push_back(1);
	In4.push_back(1);
	In4.push_back(0);
	In4.push_back(0);
	In4.push_back(1);

	vector<int> In5;
	In5.push_back(0);
	In5.push_back(0);
	In5.push_back(0);
	In5.push_back(0);
	In5.push_back(0);

	Board.push_back(In1);
	Board.push_back(In2);
	Board.push_back(In3);
	Board.push_back(In4);
	Board.push_back(In5);

	int Result = solution(Board);

	return 0;
}

