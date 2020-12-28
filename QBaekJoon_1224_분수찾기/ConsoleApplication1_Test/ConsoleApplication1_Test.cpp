#include "pch.h"
#include <iostream>
using namespace std;
int N = 0, F = 1, S = 1;
int main()
{
	cin >> N;
	if (N == 1) { cout << "1/1"; exit(0); }
	for (int i = 1; ; ++i)
	{
		if (i & 1) { F += ((i / 2) * 4) + 2; S += 1; }
		else { F += 1; S += ((i/ 2) * 4); }

		if (F <= N && N <= S)
		{
			cout << (i + 1) - (N - F) << "/" << (i + 1) - (S - N);
			break;
		}
		if (S <= N && N <= F)
		{
			cout << (i + 1) - (F - N) << "/" << (i + 1) - (N - S);
			break;
		}
	}
	return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//@다른 코드 -  x*(x+1)/2, x*(x-1)/2 방식으로 푼 코드
//int main()
//{
//	int n, x = 0, m = 0;
//	cin >> n;
//	int n2 = n;
//	while (1)
//	{
//		x++;
//		m = x * (x + 1) / 2;
//		if (m >= n)
//		{
//			m = x * (x - 1) / 2;
//			break;
//		}
//	}
//	x += 1;
//	n2 = n - m;
//	if (x % 2 == 0)
//	{
//		cout << x - n2 << "/" << n2;
//	}
//	else
//	{
//		cout << n2 << "/" << x - n2;
//	}
//	return 0;
//}

