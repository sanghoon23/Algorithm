#include "pch.h"
#include <iostream>
#include <math.h>
using namespace std;
int A = 0, B = 0, V = 0;
int main()
{
	cin >> A >> B >> V;
	cout << (int)(ceil((double)(V - A) / (double)(A - B))) + 1;
	return 0;
}

//using namespace std;
//int A = 0, B = 0, V = 0;
//
//void FindHeight(int Start, int End)
//{
//	if (Start < 1 || End < 1) return;
//	if (Start > End) return;
//
//	if ((A - B) * (Start - 1) + A < V || (A - B) * (End - 1) + A < V)
//	{
//		int Mid = (Start + End) >> 1;
//		FindHeight(Start, Mid);
//		FindHeight(Mid + 1, End);
//	}
//	else
//	{
//		{ cout << End; exit(0); }
//	}
//}
//
//int main()
//{
//	cin >> A >> B >> V;
//	int Start = 1, End = 10;
//	FindHeight(Start, End);
//	return 0;
//}

