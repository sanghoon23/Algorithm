#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

int Alpha[26] = { 0, };
long long Continus[26][300001];
long long Calc[300001] = { 0, };

long long Sum(long long N)
{
	if (N < 1) return 0;
	if (N == 1) return 1;
	if (Calc[N] != 0) return Calc[N];

	Calc[N] = N + Sum(N - 1);
	return Calc[N];
}

long long solution(string S)
{
	Calc[1] = 1;
	long long Answer = 0;
	for (int i = 1; i < S.size(); ++i)
		Answer += Sum(i);


	long long Count = 1;
	for (int i = 0; i < S.size(); ++i)
	{
		if (Count >= S.size()) return 0;

		Alpha[S[i] - 'a'] += 1;
		if (i != S.size() - 1)
		{
			if (S[i] == S[i + 1])
			{
				++Count;
				continue;
			}
		}

		Continus[S[i] - 'a'][Count] += 1;
		Count = 1;
	}

	for (int i = 0; i < 26; ++i)
	{
		if (Alpha[i] <= 1) continue;

		int Size = Alpha[i];
		for (int j = 0; j < Alpha[i]; ++j)
		{
			long long Num = 0;
			for (int s = j + 1; s <= Alpha[i]; ++s) //@ <= Size 까지 해줘야함.
			{
				Num += (long long)(s - j) * Continus[i][s];
			}
			if (Num == 0) continue;

			Answer -= Sum(Num - 1);
		}
	}

	return Answer;
}

//using ll = long long;
//
//ll solution2(string s) {
//	if (s.size() == 1) return 0;
//	ll ans = 0, count = 1;
//	for (int i = s.size() - 1; i >= 1; --i) {
//		ans += (i*count);
//		++count;
//	}
//	vector<vector<int>> idx(26);
//	for (int i = 0; i < s.size(); ++i) {
//		idx[s[i] - 'a'].push_back(i);
//	}
//
//	for (int i = 0; i < 26; ++i) {
//		if (idx[i].size() < 2) continue;
//		vector<int> series(idx[i].size() + 1);
//		int prev = idx[i][0];
//		int count = 1;
//		for (int j = 1; j < idx[i].size(); ++j) {
//			int &curr = idx[i][j];
//			if ((curr - prev) == 1) {
//				++count;
//			}
//			else {
//				++series[count];
//				count = 1;
//			}
//			prev = curr;
//		}
//		++series[count];
//
//		for (int j = 1; j < idx[i].size(); ++j) {
//			int count = 0;
//			for (int k = j; k < series.size(); ++k) {
//				count += series[k] * (k - j + 1);
//			}
//			if (count == 0) continue;
//			ans -= (ll)count*(count - 1) / 2;
//		}
//	}
//	return max(ans, (ll)0);
//}

typedef long long int ll;
typedef pair<int, int> pii;
#define NM 300005
#define INF 0x7fffffff
#define FOR(i,n,m) for (int i=(n);i<=(m);i++)

long long dy[26], cnt[26], idx[30], alpha[NM], l[NM], r[NM];
long long tree[26][NM * 2][2], B;
void Update(int c, int idx, int v) {
	idx += B;
	tree[c][idx][0]++;
	tree[c][idx][1] += v;
	idx /= 2;
	while (idx) {
		tree[c][idx][0] = tree[c][idx * 2][0] + tree[c][idx * 2 + 1][0];
		tree[c][idx][1] = tree[c][idx * 2][1] + tree[c][idx * 2 + 1][1];
		idx /= 2;
	}
}
pair<ll, ll> Find(int c, int l, int r) {
	l += B, r += B;
	ll res = 0, res2 = 0;
	while (l <= r) {
		if (l & 1) res += tree[c][l][0], res2 += tree[c][l][1], l++;
		if (!(r & 1)) res += tree[c][r][0], res2 += tree[c][r][1], r--;
		l >>= 1, r >>= 1;
	}
	return { res,res2 };
}
long long solution3(string s) {
	long long ans = 0;
	int n = s.length();
	B = n - 1;
	ll same = 0;
	for (int i = 0; i < n; ++i) {
		ll temp = (ll)i * (i + 1) / 2;
		if (i >= 1 && s[i] == s[i - 1]) {
			same++;
		}
		else if (i >= 1) {
			for (int j = 1; j <= same + 1; ++j) {
				Update(s[i - 1] - 'a', j, j);
			}
			same = 0;
		}
		temp -= same * (same + 1) / 2;

		pair<ll, ll> Temp = Find(s[i] - 'a', 1, same + 1);
		ll total = tree[s[i] - 'a'][1][0];

		temp -= Temp.second;

		temp -= (same + 1) * (total - Temp.first);

		ans += temp;
	}

	return ans;
}

int main()
{
	/*
	연속된 수
	2 - 1
	3 - 4
	4 - 10
	5 - 20
	*/

	//string S = "abccc"; //16
	//string S = "abcde"; // 20
	//string S = "acbcc"; //17
	//string S = "cabcc"; // 17

	//string S = "abcdef"; // 35
	//string S = "cabccc"; // 28
	//string S = "acbccc"; // 28
	//string S = "abcccc"; // 25
	//string S = "cccc"; // 10

	/* 연속되있지 않은 수, */
	//string S = "abbccd"; // 33

	//string S = "abcdefg"; // 56
	//string S = "abccccc"; // 36
	//string S = "cabcccc"; // 42
	//string S = "acbcccc"; // 42
	string S = "ccabccc"; // 43
	long long Result = solution(S);

	return 0;
}

/////////////////////////////////////////////////////////////////////////////////////////////////
////@1013_ DP 로 풀어보기

//long long Num[300001] = { 0, };
//int Alpha[200] = { 0, };
//
//long long solution(string S)
//{
//	long long Answer = 0;
//
//	bool bSame = true;
//	for (int i = 1; i < S.size(); ++i)
//	{
//		if (S[i - 1] != S[i])
//		{
//			bSame = false;
//			break;
//		}
//	}
//	if (bSame == true) return 0;
//
//	Num[1] = 1;
//	long long Minus = 0;
//	for (int i = 0; i < S.size(); ++i)
//	{
//		if (i + 1 > 1)
//			Num[i + 1] = Num[i] + i + 1;
//
//		Alpha[S[i]] += 1;
//		if (Alpha[S[i]] > 1)
//			Minus += Num[Alpha[S[i]] - 1];
//
//		Answer += Num[i];
//	}
//
//	return Answer;
//}


//long long solution(string S)
//{
//	long long Answer = 0;
//
//	bool bSame = true;
//	for (int i = 1; i < S.size(); ++i)
//	{
//		if (S[i - 1] != S[i])
//		{
//			bSame = false;
//			break;
//		}
//	}
//	if (bSame == true) return 0;
//
//	vector<vector<int>> Temp(S.size(), vector<int>(S.size(), 0));
//	for (int j = 0; j < S.size(); ++j)
//	{
//		for (int i = j; i < S.size(); ++i)
//		{
//
//		}
//	}
//
//	return Answer;
//}


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//@쌩으로 계산

//#include <string>
//#include <vector>
//
//using namespace std;
//
//long long Calc(string Str)
//{
//	if (Str.size() == 1) return 0;
//
//	long long Ret = 0;
//	int j = Str.size() - 1;
//	while (j > 0)
//	{
//		long long Temp = 0;
//		for (int i = 0; i < j; ++i)
//		{
//			if (Str[i] != Str[j])
//			{
//				Temp = j - i;
//				break;
//			}
//		}
//
//		Ret = max(Ret, Temp);
//
//		--j;
//	}
//	return Ret;
//}
//
//long long solution(string S)
//{
//	long long Answer = 0;
//
//	bool bSame = true;
//	for (int i = 1; i < S.size(); ++i)
//	{
//		if (S[i - 1] != S[i])
//		{
//			bSame = false;
//			break;
//		}
//	}
//	if (bSame == true) return 0;
//
//	for (int j = 1; j <= S.size(); ++j)
//	{
//		for (int i = 0; i < S.size() - j + 1; ++i)
//		{
//			string Temp = S.substr(i, j);
//			Answer += Calc(Temp);
//		}
//	}
//
//	return Answer;
//}
