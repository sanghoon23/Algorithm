#include "pch.h"
#include <iostream>
using namespace std;
int N = 0;
int main()
{
	cin >> N;
	if (N % 2 == 0) cout << "CY";
	else cout << "SK";
	return 0;
}

///////////////////////////////////////////////////////////////////////////////////////////////////
//@이상한 짓

//#include <iostream>
//#include <vector>
//#include <string>
//using namespace std;
//int N = 0;
//int main()
//{
//	vector<string> Temp1;
//	Temp1.push_back("Start");
//	for (int i = 1; i <= 999; ++i)
//	{
//		if (i == 1) { Temp1.push_back("SK"); continue; }
//		if (i % 3 == 1 && i != 1) Temp1.push_back("SK");
//		else Temp1.push_back("CY");
//	}
//
//	vector<string> Temp2;
//	Temp2.push_back("Start");
//	for (int i = 1; i <= 999; ++i)
//	{
//		if (i % 2 == 0) Temp2.push_back("CY");
//		else Temp2.push_back("SK");
//	}
//
//	return 0;
//}

