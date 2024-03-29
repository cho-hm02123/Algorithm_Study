/*
문제 : 입력이 '0'이면 이전 값 지우고 아니면 저장 최종 저장된 값 출력
입력 : 입력 개수, 입력

풀이 : 
 이전 값 삭제이므로 stack 사용 
*/

#include <istream>
#include <iostream>
#include <stack>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int k = 0;
	int sum = 0;
	stack<int> s;

	cin >> k;

	while (k--) {
		int n = 0;
		cin >> n;

		if (n == 0) {
			if (!s.empty())
				s.pop();
		}
		else
			s.push(n);
	}

	while (!s.empty()) {
		sum += s.top();
		s.pop();
	}

	cout << sum;
	
	return 0;
}
