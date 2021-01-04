#include "pch.h"
#include <iostream>
#include <stack>
#include <string>
using namespace std;
string Str, Check = "([])";
int main()
{
	ios::sync_with_stdio(false); cin.tie(0);
	while (1)
	{
		getline(cin, Str);
		if (Str[0] == '.') break;
		stack<char> Stack;
		for (int i = 0; i < Str.size(); ++i)
		{
			for (int j = 0; j < 4; ++j)
			{
				if (Str[i] == Check[j])
				{
					Stack.push(Str[i]);
					break;
				}
			}
		}

		stack<char> Temp;
		while (!Stack.empty())
		{
			char R = Stack.top();
			if (R == ')' || R == ']') Temp.push(R);
			else if (R == '(' && !Temp.empty() && Temp.top() == ')') Temp.pop();
			else if (R == '[' && !Temp.empty() && Temp.top() == ']') Temp.pop();
			else break;

			Stack.pop();
		}
		if (Stack.empty() && Temp.empty()) cout << "yes" << '\n';
		else cout << "no" << '\n';
	}
	return 0;
}

