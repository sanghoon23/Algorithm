#include "pch.h"
#include <iostream>
#include <vector>
#include <string>
#include <string.h>

///////////////////////////////////////////////////////////////////////////////
//@스택을 이용한 코드
/*
#include <stack>
int k, n=9;
char a[15];
std::stack<int> st;

void f() {
	while(!st.empty()) printf("%d", st.top()), st.pop();
}

int main() {
	int i;
	scanf("%d", &k);
	st.push(n--);
	for(i=0; i<k; i++) {
		scanf("%s", &a[i]);
		if(a[i]=='>') f();
		st.push(n--);
	}
	f();
	puts("");
	n = 0;
	st.push(n++);
	for(i=0; i<k; i++) {
		if(a[i]=='<') f();
		st.push(n++);
	}
	f();
	return 0;
}
*/

using namespace std;
int K = 0;
string Str, MaxStr = "", MinStr = "";
bool Visited[10];
void DFS(string Curr, int Idx)
{
	if (Idx >= Str.size())
	{
		if (MaxStr == "" && MinStr == "") { MaxStr = Curr; MinStr = Curr; }
		else
		{
			long long R = atoll(Curr.c_str()), MaxR = atoll(MaxStr.c_str()), MinR = atoll(MinStr.c_str());
			if (R > MaxR) MaxStr = Curr;
			else if (R < MinR) MinStr = Curr;
		}
		return;
	}

	for (int i = 0; i <= 9; ++i)
	{
		if (Visited[i] == false)
		{
			if (Str[Idx] == '<' && Curr[Idx] - '0' < i)
			{
				Visited[i] = true;
				string Loop = Curr;
				Loop.push_back(i + '0');
				DFS(Loop, Idx + 1);
				Visited[i] = false;
			}
			else if (Str[Idx] == '>' && Curr[Idx] - '0' > i)
			{
				Visited[i] = true;
				string Loop = Curr;
				Loop.push_back(i + '0');
				DFS(Loop, Idx + 1);
				Visited[i] = false;
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> K;
	for (int i = 0; i < K; ++i)
	{
		char Input; cin >> Input;
		Str.push_back(Input);
	}

	for (int i = 0; i <= 9; ++i)
	{
		memset(Visited, false, sizeof(Visited));
		Visited[i] = true;
		string C;
		C.push_back(i + '0');
		DFS(C, 0);
	}

	cout << MaxStr << '\n';
	cout << MinStr << '\n';
	return 0;
}
