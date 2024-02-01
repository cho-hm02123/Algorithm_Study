/*
문제 : 문자열이 입력됨, 문자열의 끝은 '.'으로 구분 () [] 쌍을 이루면 'yes', 아니면 'no' 출력
입력 : 문자열 입력의 최종 종료는 '.'이 하나 들어오는 것으로 구분함

풀이 : 
 가장 최근에 들어온 여는 괄호와 들어온 닫는 괄호의 종류가 같은지 비교해야하므로 stack 사용 
'(', ')', '[', ']' 문자만을 판단하면 되므로 for(auto a : str) 사용
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

	bool b = 0;

	while (1) {
		string str;
		getline(cin, str);

		stack <char> c;
		if (str == ".")
			break;

		for (auto a : str) {
			if (a == '[' || a == '(')
				c.push(a);

			else if (a == ']' || a == ')') {
				if (c.empty()) {
					b = 0;
					break;
				}

				else {
					if (a == ']' && c.top() == '[')
						c.pop();
					else if(a == ')' && c.top() == '(')
						c.pop();
					else {
						b = 0;
						break;
					}
				}
					
			}

			else if (a == '.') {
				if (c.empty())
					b = 1;
				else
					b = 0;
			}
		}

		if (b == 1)
			cout << "yes\n";
		else
			cout << "no\n";
	}


	return 0;
}
