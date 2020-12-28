#include "pch.h"
#include <iostream>
using namespace std;
int T = 0, H = 0, W = 0, N = 0;
int main()
{
	cin >> T;
	while (T--)
	{
		cin >> H >> W >> N;
		int XX = (N - 1) / H; //@정당성을 위해 N-1 해줘야함. ex) 첫째줄은 0 이 나온다고 가정하고 코드를 짬.
		int YY = N - (H * XX);
		XX += 1;
		if (XX < 10) cout << YY << "0" << XX << '\n';
		else cout << YY << XX << '\n';
	}
	return 0;
}

