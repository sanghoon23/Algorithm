#include "pch.h"
#include <iostream>
#include <algorithm>

//////////////////////////////////////////////////////////////////////////////////////////////////////
//@재귀

using namespace std;
int A = 0, B = 0, V = 0;
int FindHeight(int Start, int End)
{
	if (Start > End) return 1e10;
	if (Start == End) return Start;

	int Mid = (Start + End) >> 1;

	int Ret = 1e10;
	if ((A - B) * (Mid - 1) + A >= V)
		Ret = min(Ret, FindHeight(Start, Mid));
	else if((A - B) * (Mid - 1) + A < V)
		Ret = min(Ret, FindHeight(Mid + 1, End));

	return Ret;
}
int main()
{
	cin >> A >> B >> V;
	int Start = 1, End = V;
	int R = FindHeight(Start, End);
	cout << R << '\n';
	//cout << FindHeight(Start, End) << '\n';
	return 0;
}

// 이분 while
//int main() {
//	int a, b, v;
//	cin >> a >> b >> v;
//	long long last = v;
//	long long first = 0;
//	long long mid;
//	long long ans;
//	while (first <= last) {
//		mid = (first + last) / 2;
//		if (v <= (mid - 1)*(a - b) + a)
//		{
//			last = mid - 1;
//			ans = mid;
//		}
//		else {
//			first = mid + 1;
//		}
//	}
//	cout << ans;
//}

