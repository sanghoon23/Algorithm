#include "pch.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

/*
43번째 줄 - int N = T.size(), M = P.size() - 계산을 위해서 int 형에 담아두기 필요.

22번째 줄과 비교해보면, Begin + Match < Str.size() 는 가능하다.
하지만,
50번째 줄
while (Begin <= N - M) 을
while (Begin <= T.size() - P.size()) 로 해버린다면,

**해당 문제에선 T 가 P 보다 크다는 사실이 없다.**
만약 T 크기가 P 크기보다 작을 때, T 크기와 P 크기를 빼는 과정에서 오류가 발생.
T < P 일 때 T.size() - P.size() 뺀 값은??
T.size() - P.size() 에서의 값은 P.size() 는 2의 보수를 취하면서 엄청나게 큰 값이 될 수 있다.
왜냐하면 T.size(), P.size() 는 - 가 없다고 확신하기 때문에 (T.size() < P.size()) 인 상황이 발생하게 되고 엄청난 오류가 생긴다.
따라서, Begin(int) 값이 배열 사이즈를 초과되어도 if문이 통과된다.

습관을 잘 들이자..잘하자 쫌..
size_t - https://c10106.tistory.com/4452
https://hashcode.co.kr/questions/754/size_t%EB%8A%94-%EC%A0%95%ED%99%95%ED%9E%88-%EC%96%B4%EB%96%A4-%ED%83%80%EC%9E%85%EC%9D%B8%EA%B0%80%EC%9A%94

*2 의 보수 표현 체계 하에서 어떤 수의 부호를 바꾸려면 먼저 비트를 반전 시킨 뒤에 1 을 더하면 된다.
2의보수 - https://modoocode.com/308

결론은 문자열의 길이를 계산할 때 즉, stl 을 쓸 때는 size_t 를 항상 조심해야한다.
string 에서 size, length 는 둘 다 size_t 형을 반환한다. (stl 은 모두 size_t 를 사용)
단지 연산하지 않고 for 문만 도는 경우라면 Str.size() 를 써도 무방하다.
그게 아니라면 문제가 어디서 터질지 모른다.

*특히 메모리 공간 제어가 필수인 게임 개발 같은 경우 가변 자료형은 최적화 최대 기피사항 중 하나다.
typedef나 using으로 멀티플랫폼 처리를 해서 쓰는게 보통이다.

*불변 크기의 정수를 사용하고 싶다면 stdint.h의 int8_t~int64_t를 사용

*size_t의 대체품을 찾는다면 쓸 수 있는 가장 좋은 것은 int, 필요하다면 unsigned int이며,
C++11 이후로는 auto를 써 주면 개발 편의성도 잡고 컴파일 경고까지 쉽게 없애줄 수 있다.
auto가 지원이 안 된다면 static_cast<int> 캐스팅을 이용하면 강제로 size_t의 문제점에서 벗어날 수 있다.

참고 - https://namu.wiki/w/size_t
*/

using namespace std;
string T, P;
vector<int> MakeTable(string& Str)
{
	int M = Str.size();
	vector<int> Pi(M, 0);

	int Begin = 1, Match = 0;
	while (Begin + Match < Str.size())
	{
		if (Str[Begin + Match] == Str[Match])
		{
			++Match;
			Pi[Begin + Match - 1] = Match;
		}
		else
		{
			if (Match == 0) ++Begin;
			else
			{
				Begin += Match - Pi[Match - 1];
				Match = Pi[Match - 1];
			}
		}
	}
	return Pi;
}

vector<int> Search(string& T, string& P)
{
	int N = T.size(), M = P.size(); //**중요**
	vector<int> Ret;
	vector<int> Pi = MakeTable(P);
	int Begin = 0, Match = 0;
	while (Begin <= N - M)
	{
		if (Match < M && T[Begin + Match] == P[Match])
		{
			++Match;
			if (Match == M)
				Ret.push_back(Begin);
		}
		else
		{
			if (Match == 0) ++Begin;
			else
			{
				Begin += (Match - Pi[Match - 1]);
				Match = Pi[Match - 1];
			}
		}
	}
	return Ret;
}

int main()
{
	//ios_base::sync_with_stdio(0); cin.tie(0);
	//getline(cin, T);
	//getline(cin, P);

	/* 만약 아래 부분을 추가하면 통과된다. */
	// if (T.size() < P.size()) { cout << 0 << '\n'; exit(0); }

	/* size_t Test */
	// 해당 문제에선 T 가 P 보다 크다는 사실이 없다.
	size_t TTT = 1000000;
	size_t PPP = 1000001;
	size_t Test = TTT - PPP;
	string A;
	string B;
	A.resize(1000000);
	B.resize(1000000);
	int BBB = 1;
	if (BBB <= A.size() - B.size())
	{
		int A = 0;
	}

	//vector<int> Result = Search(T, P);
	//cout << Result.size() << '\n';
	//for (int k = 0; k < Result.size(); ++k)
	//	cout << Result[k] + 1 << '\n';

	return 0;
}

