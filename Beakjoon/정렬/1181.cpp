/* https://www.acmicpc.net/problem/1181
* 
*  12m 19s
* 
* 문제: 알파벳 소문자로 이루어진 n개의 단어
*	길이가 잛은것 부터, 길이가 같으면 사전순
*	중복이면 제거
* 
* 입력: n, 단어
* 
* 풀이: 문자열 길이는 a.length()로 찾음
*/

#include <iostream>
#include <cmath>
#include <algorithm>
#include <queue>
using namespace std;

class cmp {
public:
	bool operator() (string a, string b) {
		if (a.length() != b.length()) return a.length() > b.length();
		if (a == b) return false;
		return a > b;
	}
}; priority_queue <string, vector<string>, cmp> pq;

int n;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	while (n--) {
		string a;
		cin >> a;
		pq.push(a);
	}

	string a = pq.top();
	cout << a << "\n";
	while (!pq.empty()) {
		if (a == pq.top()) {
			pq.pop();
			continue;
		}
		a = pq.top();
		cout << a << "\n";
		pq.pop();
	}

	return 0;
}
