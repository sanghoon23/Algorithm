#include "pch.h"
#include <iostream>
#include <algorithm>

using namespace std;
long long N = 0, M = 0, Input = 0, Board[100001];
long long Find(long long Start, long long End, long long Val)
{
	if (Start > End || Start < 0) return 0;
	if (Start == End)
	{
		if (Board[End] == Val) return 1;
		else return 0;
	}

	long long Ret = 0;
	long long Mid = (Start + End) >> 1;
	if (Board[Mid] < Val) Ret += Find(Mid + 1, End, Val);
	else Ret += Find(Start, Mid, Val);
	return Ret;
	/*
	if (start > end) return 0;
	if (v[start] == key || v[mid] == key || v[end] == key) return 1;
	if (v[mid] > key) return(find(start + 1, mid - 1, key));
	else return(find(mid + 1, end - 1, key));
	*/
}

/*
bool binarySearch(int a, int l, int r) {
	while (l <= r) {
		int mid = (l + r) / 2;
		if (inp[mid] == a)
			return 1;
		else if (inp[mid] < a) {
			l = mid + 1;
		}
		else{
			r = mid - 1;
		}
	}
	return 0;
}
*/

int main()
{
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; ++i)
		cin >> Board[i];
	sort(Board, Board + N);

	cin >> M;
	for (int i = 0; i < M; ++i)
	{
		cin >> Input;
		if (Find(0, N - 1, Input) > 0) cout << 1 << '\n';
		else cout << 0 << '\n';
	}
	return 0;
}

