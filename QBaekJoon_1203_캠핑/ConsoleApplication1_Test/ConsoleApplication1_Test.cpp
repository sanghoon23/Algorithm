#include "pch.h"
#include <iostream>
#include <vector>

using namespace std;

int L = 0, P = 0, V = 0;
int Count = 1, Result = 0;
int main()
{
	while (1)
	{
		cin >> L >> P >> V;
		if (L == 0 && P == 0 && V == 0) break;

		Result = 0;
		if (L == P)
		{
			Result = V;
		}
		else if (V < P)
		{
			if (V < L) Result = V;
			else Result = L;
		}
		else
		{
			int A = L * (V / P);
			Result += A;
			int R = V - ((V / P) * P);
			if (R < L) Result += R;
			else Result += L;
		}

		cout << "Case " << Count << ": " << Result << endl;
		++Count;
	}

	return 0;
}

