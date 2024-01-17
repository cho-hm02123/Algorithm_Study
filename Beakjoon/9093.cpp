#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int T;

	cin >> T;
	cin.ignore();													// 버퍼 초기화

	while (T--){

		string str;
		getline(cin, str);											// 띄어쓰기까지 한번에 string 받기
		str += '\n';												// 마지막 구분용으로 추가
		stack<char>s;

		for (char ch : str) {										// string을 char 로 받음
			if (ch == ' ' || ch == '\n') {
				while(!s.empty()) {									
					cout << s.top();								// 띄어쓰기 전까지 stack에 저장한 단어 꺼내면서 출력
					s.pop();
				}
				cout << ch;											// 띄어쓰기 출력
			}
			else 
				s.push(ch);
		}
	}

	return 0;
}