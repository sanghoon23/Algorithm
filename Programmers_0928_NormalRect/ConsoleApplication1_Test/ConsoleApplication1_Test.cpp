#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

int GCD(int a, int b)
{
	if (b == 0)
		return a;
	else
	{
		return GCD(b, a % b);
	}
}

long long CheckRange(int Width, int Height)
{
	long long Ret = 0;
	double W = 0, H = 0;
	double Value = (double)Width / (double)Height;
	int Comp = 1;
	while (H < Height)
	{
		W += Value;
		++H;
		++Ret;

		if (W > Comp)
		{
			++Ret;
			++Comp;
		}
	}
	return Ret;
}

long long solution(int w, int h)
{
	long long Width = static_cast<long long>(w);
	long long Height = static_cast<long long>(h);
	long long Answer = Width * Height;

	//@최대공약수 -gcd
	long long GCDValue = GCD(w, h);
	long long x = (long long)w / GCDValue;
	long long y = (long long)h / GCDValue;

	//int Temp = 0;
	//if (x > y)
	//	Temp = CheckRange(y, x);
	//else if (x < y)
	//	Temp = CheckRange(x, y);
	//else
	//	Temp = x;

	/*
	최대 공약수 되어진 값이라
	2*6, 3*9 ... 등 나누어떨어지는 값은 생각하지 않아도 됨.....

	*/
	return Answer - ((x + y - 1)* GCDValue);
}

int main()
{
	int W = 8;
	int H = 12;

	int Result = solution(W, H);
	return 0;
}

