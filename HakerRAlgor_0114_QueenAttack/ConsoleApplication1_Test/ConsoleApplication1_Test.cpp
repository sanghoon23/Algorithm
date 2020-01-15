// ConsoleApplication1_Test.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//
#include "pch.h"
#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <memory.h>

using namespace std;

struct Pairs
{
	int first	= -1;
	int second	= -1;
};

int queensAttack(int n, int k, int r_q, int c_q, vector<vector<int>> obstacles)
{
	int ResultsCount = 0;
	vector<Pairs> Enemys(8);
	vector<int> Calcs(8, -1);
	for (int i = 0; i < k; ++i)
	{
		// 1. 가로 - 왼쪽
		if (obstacles[i][0] == r_q && obstacles[i][1] < c_q)
		{
			if (Enemys[0].first == -1)
			{
				Enemys[0].first = obstacles[i][0];
				Enemys[0].second = obstacles[i][1];
				Calcs[0] = (c_q - 1) - obstacles[i][1];
				continue;
			}
			else
			{
				if (Enemys[0].second < obstacles[i][1])
				{
					Enemys[0].first = obstacles[i][0];
					Enemys[0].second = obstacles[i][1];
					Calcs[0] = (c_q - 1) - obstacles[i][1];
				}
			}

		}//(1)
		// 2. 가로 - 오른쪽
		if (obstacles[i][0] == r_q && obstacles[i][1] > c_q)
		{
			if (Enemys[1].first == -1)
			{
				Enemys[1].first = obstacles[i][0];
				Enemys[1].second = obstacles[i][1];
				Calcs[1] = (obstacles[i][1] - 1) - c_q;
			}
			else
			{
				if (Enemys[1].second > obstacles[i][1])
				{
					Enemys[1].first = obstacles[i][0];
					Enemys[1].second = obstacles[i][1];
					Calcs[1] = (obstacles[i][1] - 1) - c_q;
				}
			}
		}//(2)

		// 3. 세로 - 위
		if (obstacles[i][1] == c_q && obstacles[i][0] < r_q)
		{
			if (Enemys[2].first == -1)
			{
				Enemys[2].first = obstacles[i][0];
				Enemys[2].second = obstacles[i][1];
				Calcs[2] = (r_q - 1) - obstacles[i][0];
			}
			else
			{
				if (Enemys[2].first < obstacles[i][0])
				{
					Enemys[2].first = obstacles[i][0];
					Enemys[2].second = obstacles[i][1];
					Calcs[2] = (r_q - 1) - obstacles[i][0];
				}
			}
		}//(3)
		// 4. 세로 - 아래
		if (obstacles[i][1] == c_q && obstacles[i][0] > r_q)
		{
			if (Enemys[3].first == -1)
			{
				Enemys[3].first = obstacles[i][0];
				Enemys[3].second = obstacles[i][1];
				Calcs[3] = (obstacles[i][0] - 1) - r_q;
			}
			else
			{
				if (Enemys[3].first > obstacles[i][0])
				{
					Enemys[3].first = obstacles[i][0];
					Enemys[3].second = obstacles[i][1];
					Calcs[3] = (obstacles[i][0] - 1) - r_q;
				}
			}
		}//(4)

		// 5. 왼쪽 대각선 - 위
		if (r_q > obstacles[i][0] && c_q > obstacles[i][1]
			&& (r_q - obstacles[i][0]) == (c_q - obstacles[i][1]))
		{
			if (Enemys[4].first == -1)
			{
				Enemys[4].first = obstacles[i][0];
				Enemys[4].second = obstacles[i][1];
				Calcs[4] = (r_q - 1) - (obstacles[i][0]);
			}
			else
			{
				if (Enemys[4].first < obstacles[i][0]
					&& Enemys[4].second < obstacles[i][1])
				{
					Enemys[4].first = obstacles[i][0];
					Enemys[4].second = obstacles[i][1];
					Calcs[4] = (r_q - 1) - (obstacles[i][0]);
				}
			}
		}

		// 6. 왼쪽 대각선 - 아래
		if (r_q < obstacles[i][0] && c_q > obstacles[i][1]
			&& (obstacles[i][0] - r_q) == (c_q - obstacles[i][1]))
		{
			if (Enemys[5].first == -1)
			{
				Enemys[5].first = obstacles[i][0];
				Enemys[5].second = obstacles[i][1];
				Calcs[5] = (obstacles[i][0] - 1) - (r_q);
			}
			else
			{
				if (Enemys[5].first > obstacles[i][0]
					&& Enemys[5].second < obstacles[i][1])
				{
					Enemys[5].first = obstacles[i][0];
					Enemys[5].second = obstacles[i][1];
					Calcs[5] = (obstacles[i][0] - 1) - (r_q);
				}
			}
		}

		// 7. 오른쪽 대각선 - 위
		if (r_q > obstacles[i][0] && c_q < obstacles[i][1]
			&& (r_q - obstacles[i][0]) == (obstacles[i][1] - c_q))
		{
			if (Enemys[6].first == -1)
			{
				Enemys[6].first = obstacles[i][0];
				Enemys[6].second = obstacles[i][1];
				Calcs[6] = (r_q - 1) - (obstacles[i][0]);
			}
			else
			{
				if (Enemys[6].first < obstacles[i][0]
					&& Enemys[6].second > obstacles[i][1])
				{
					Enemys[6].first = obstacles[i][0];
					Enemys[6].second = obstacles[i][1];
					Calcs[6] = (r_q - 1) - (obstacles[i][0]);
				}
			}
		}

		// 8. 오른쪽 대각선 아래
		if (r_q < obstacles[i][0] && c_q < obstacles[i][1]
			&& (obstacles[i][0] - r_q) == (obstacles[i][1] - c_q))
		{
			if (Enemys[7].first == -1)
			{
				Enemys[7].first = obstacles[i][0];
				Enemys[7].second = obstacles[i][1];
				Calcs[7] = (obstacles[i][0] - 1) - (r_q);
			}
			else
			{
				if (Enemys[7].first > obstacles[i][0]
					&& Enemys[7].second > obstacles[i][1])
				{
					Enemys[7].first = obstacles[i][0];
					Enemys[7].second = obstacles[i][1];
					Calcs[7] = (obstacles[i][0] - 1) - (r_q);
				}
			}
		}
	}

	// Results
	(Calcs[0] == -1) ? ResultsCount += (r_q - 1) : ResultsCount += Calcs[0];
	(Calcs[1] == -1) ? ResultsCount += (n - r_q) : ResultsCount += Calcs[1];
	(Calcs[2] == -1) ? ResultsCount += (c_q - 1) : ResultsCount += Calcs[2];
	(Calcs[3] == -1) ? ResultsCount += (n - c_q) : ResultsCount += Calcs[3];
	(Calcs[4] == -1) ? ResultsCount += min(r_q, c_q) - 1 : ResultsCount += Calcs[4];
	(Calcs[5] == -1) ? ResultsCount += min(n - r_q, c_q - 1) : ResultsCount += Calcs[5];
	(Calcs[6] == -1) ? ResultsCount += min(r_q - 1, n - c_q) : ResultsCount += Calcs[6];
	(Calcs[7] == -1) ? ResultsCount += min(n - r_q, n - c_q) : ResultsCount += Calcs[7];

	return ResultsCount;

}

int main()
{
	int n = 7; // 보드 칸수
	int k = 6; // 장애물 수

	int r_q = 4; // 퀸
	int c_q = 2; // 퀸
	vector<vector<int>> obstacles; // 장애물
	vector<int> test;
	test.push_back(4);
	test.push_back(4);
	obstacles.push_back(test);

	// vector<int> test1;
	test.clear();
	test.push_back(4);
	test.push_back(3);
	obstacles.push_back(test);

	// vector<int> test2;
	test.clear();
	test.push_back(3);
	test.push_back(1);
	obstacles.push_back(test);

	test.clear();
	test.push_back(3);
	test.push_back(3);
	obstacles.push_back(test);

	test.clear();
	test.push_back(5);
	test.push_back(1);
	obstacles.push_back(test);

	test.clear();
	test.push_back(1);
	test.push_back(5);
	obstacles.push_back(test);


	///////////////////////////////////////////////////////////////////////////////////
	int Result = queensAttack(n, k, r_q, c_q, obstacles);
	printf("%d\n", Result);

	return 0;
}



// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.
