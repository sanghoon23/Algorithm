#include "pch.h"
#include <iostream>
#include <math.h>

//@참고.
/*
int main(int argc, const char * argv[]) {
	int p[1000001];
	int m, n;
	scanf("%d %d", &m, &n);
	fill_n(p, 1000001, 1);
	p[0] = 0; p[1] = 0;

	for(int i = 2; i <= n; i++)
	{
		if(p[i] == 0) continue;
		for(int j = i + i; j <= n; j+=i)
		{
			p[j] = 0;
		}
	}
	for(int i = m; i <= n; i++)
	{
		if(p[i] == 1) printf("%d\n", i);
	}
	return 0;
}
*/

using namespace std;
int M, N;
bool Solve(int Num)
{
	if (Num == 1) return false;
	for (int i = 2; i <= (int)sqrt(Num); ++i)
		if (Num % i == 0) return false;
	return true;
}
int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> M >> N;
	for (int i = M; i <= N; ++i)
		if (Solve(i) == true) { cout << i << '\n'; }
	return 0;
}

