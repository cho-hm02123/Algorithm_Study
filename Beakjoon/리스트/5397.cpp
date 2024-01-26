/*
문제 : 문자열을 입력받아 규칙에 따른 최종 문자열 출력 '<' 커서 앞으로, '>' 커서 뒤로, '-' 앞 글자 지우기
입력 : TC 개수, 1,000,000 자리 이하 문자열

풀이 : 
 list를 사용하여 풀이 -> iterator 관리 너무 어려운 것
auto, 범위기반 for문 사용
*/

#include <istream>
#include <iostream>
#include <string>
#include <list>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N = 0;

	cin >> N;
	
	while (N--) {
		string key;
		list<char> l = {};
		auto point = l.begin();
		cin >> key;

		for (auto c : key) {
			if (c == '<') {
				if (point != l.begin())
					point--;
			}

			else if (c == '>') {
				if (point != l.end())
					point++;
			}

			else if (c == '-') {
				if (point != l.begin()) {
					point--;
					point = l.erase(point);
				}
			}

			else
				l.insert(point, c);
		}
		for (auto c : l)
			cout << c;
		cout << '\n';
	}

	return 0;
}
