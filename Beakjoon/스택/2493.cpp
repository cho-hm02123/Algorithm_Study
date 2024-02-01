/*
문제 : 탑에서 레이저를 왼쪽으로 쏴 수신한 탑의 번호를 찾는 문제 (송신한 탑보다 큰 탑이 수신)
입력 : 탑 개수, 탑 높이

풀이 :
 pair를 사용 (#include <utility>)
pair를 통해 탑의 길이와 인덱스를 한번에 저장
어차피 왼쪽 가장 가까이에 있는 탑이 수신하므로 높은 탑이 들어오면 앞에 pop 해서 없애줌 
*/

#include <istream>
#include <iostream>
#include <stack>
#include <utility>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	stack<pair<int, int>> s;

	int N = 0;
	cin >> N;

	for (int i = 1; i <= N; i++) {
		int h;
		cin >> h;

		if (s.empty()) {
			cout << "0 ";
			s.push({ i,h });
		}
		else {
			if (s.top().second > h) {
				cout << s.top().first << " ";
				s.push({ i,h });
			}
			else {
				while (!s.empty()) {
					s.pop();
					if (!s.empty() && s.top().second > h)
						break;
				}
				if (s.empty())
					cout << "0 ";
				else
					cout << s.top().first << " ";
				s.push({ i,h });
			}
		}
	}

	return 0;
}
