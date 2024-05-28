#include <iostream>
#include <cmath>
#include <algorithm>
#include <stack>

using namespace std;

// () : 2 , [] : 3 
// ( : -1, [ : -2

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	string st;
	cin >> st;

	stack <int> s;

	int cur = 0;

	for (auto c : st) {
		cur = 0;
		if (c == '(')
			s.push(-1);

		else if (c == '[')
			s.push(-2);

		else if (c == ')') {
			if (s.empty()) {
				cout << "0";
				return 0;
			}

			else if (s.top() == -1) {
				s.pop();
				s.push(2);
			}

			else if (s.top() == -2) {
				cout << "0";
				return 0;
			}

			else {
				cur = s.top();
				s.pop();
				while (1) {
					if (s.empty()) {
						cout << "0";
						return 0;
					}
					if (s.top() == -1 || s.top() == -2)
						break;
					cur += s.top();
					s.pop();
				}
				if (s.top() == -1) {
					s.pop();
					s.push(cur * 2);
				}
				else {
					cout << "0";
					return 0;
				}
			}
		}

		else if (c == ']') {

			if (s.empty()) {
				cout << "0";
				return 0;
			}

			else if (s.top() == -2) {
				s.pop();
				s.push(3);
			}

			else if (s.top() == -1) {
				cout << "0";
				return 0;
			}

			else {
				cur = s.top();
				s.pop();
				while (1) {
					if (s.empty()) {
						cout << "0";
						return 0;
					}
					if (s.top() == -1 || s.top() == -2)
						break;

					cur += s.top();
					s.pop();
				}
				if (s.top() == -2) {
					s.pop();
					s.push(cur * 3);
				}
				else {
					cout << "0";
					return 0;
				}
			}
		}
	}
	int rst = 0;

	while (!s.empty()) {
		cur = s.top();
		if (cur == -1 || cur == -2) {
			cout << "0";
			return 0;
		}
		rst += cur;
		s.pop();
	}
	cout << rst;
	return 0;
}
