// ConsoleApplication1_Test.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include "pch.h"
#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <memory.h>

using namespace std;

// Complete the extraLongFactorials function below.
// static int* CalcVec = new int[200]();
void NumLoops(int** v, int size, int Number)
{
	int checkArray[3];
	memset(checkArray, -1, sizeof(int) * 3);
	if (Number == 100)
	{
		checkArray[0] = 0;
		checkArray[1] = 0;
		checkArray[2] = 1;
	}
	else if (Number >= 10)
	{
		int front = Number / 10;
		int back = Number % 10;
		checkArray[0] = back;
		checkArray[1] = front;
	}
	else
		checkArray[0] = Number;

	////////////////////////////////////////////////////////////

	int tenCheck = 0;
	// Before Code
	// int* CalcVec = new int[size]();
	// Test Code
	int* CalcVec = new int[size]();
	memset(CalcVec, 0, sizeof(int) * size);
	for (int j = 0; j < 3; ++j)
	{
		if (checkArray[j] == 0)
		{
			//++tenCheck;
			continue;
		}
		else if (checkArray[j] == -1)
			continue;


		for (int i = 0; i < size; ++i)			// n
		{
			if (j > 0)
			{
				CalcVec[i + j] += ((*v)[i] * checkArray[j]);
			}
			else
				CalcVec[i] += (*v)[i] * (checkArray[j]);
			// else
			// if ((*v)[i] == 0) continue;
		}
	}

	std::vector<int> Results;
	// 0 이 얼마나 들어갔는지.
	for (int t = 0; t < tenCheck; ++t)
	{
		Results.push_back(0);
	}
	// 10 으로 나누기.
	for (int s = 0; s < size; ++s)			// n
	{
		if (CalcVec[s] == 0)
		{
			Results.push_back(0);
			continue;
		}

		if (CalcVec[s] >= 10)
		{
			int front = CalcVec[s] / 10;
			int back = CalcVec[s] % 10;

			// Plus to (i + 1) - CalcVec
			CalcVec[s + 1] += front;

			// Result Insert - Result
			Results.push_back(back);
		}
		else
		{
			Results.push_back(CalcVec[s]);
		}
	}

	// Copy
	for (int c = 0; c < Results.size(); ++c)
	{
		(*v)[c] = Results[c];
	}

	// delete[] CalcVec;

}

void extraLongFactorials(int n)
{
	int value = n;
	int size = 10000;
	int* printArr = new int[size]();
	memset(printArr, 0, sizeof(int) * size);
	printArr[0] = 1;

	// for Function NumLoops.
	for (int i = n; i > 0; --i)
	{
		NumLoops(&printArr, size, i);
	}

	// std::string printStr = "";



	////////////////////////////////////////////////////////////////////
	// Print
	int start = 0;
	for (int p = size - 1; p >= 0; --p)
	{
		if (printArr[p] != 0)
		{
			start = p;
			break;
		}
	}

	for (int prt = start; prt >= 0; --prt)
	{
		printf("%d", printArr[prt]);
	}

	// delete[] printArr;
}

int main()
{
	int n;
	cin >> n;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	extraLongFactorials(n);

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
