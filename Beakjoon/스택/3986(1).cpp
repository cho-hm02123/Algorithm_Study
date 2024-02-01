/*
문제 : 괄호랑 똑같음
입력 : 입력될 TC 개수, TC 개수 만큼의 문자열 입력

풀이 : 
 처음에 while 안에 getline 넣어 줬는데 개망함 아 cin 버퍼 클리어 안해줘서 그런가 확인해보러 가야지
그러네 TC 개수 N cin으로 받고 cin.igmore() 버퍼 초기화 안해줘서 그랬네
*/

#include <iostream>
#include <istream>
#include <string>
#include <stack>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N = 0;
	int i = 0;
	cin >> N;

	while (N--) {
		stack <char> c;
		string str;
		cin >> str;

		for (auto a : str) {
			if (c.empty() || c.top() != a)
				c.push(a);
			else
				c.pop();
		}

		if (c.empty())
			i++;
	}

	cout << i;

	return 0;
}
