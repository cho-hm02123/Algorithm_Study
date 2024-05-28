#include <iostream>
#include <cmath>
#include <algorithm>
#include <stack>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	stack <char> s;
	string st;
	cin >> st;
	int rst = 0;
	bool flag = 0;

	for (auto c : st) {
		if (c == '(') {
			s.push(c);
			flag = 1;
		}
		else {
			s.pop();
			if (flag)
				rst += s.size();
			else {
				rst += 1;
			}
			flag = 0;
		}
	}

	cout << rst;

	return 0;
}
