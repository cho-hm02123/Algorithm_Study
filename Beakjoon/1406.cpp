#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	stack<char>left;
	stack<char>right;
	cin.clear();
	int M;
	char cs;
	char input;
	string str;
	getline(cin, str);

	for (char ch : str)
		left.push(ch);

	cin >> M;

	while (M--) {
		cin >> cs;

		if (cs == 'L') {
			if (left.empty());
			else {
				right.push(left.top());
				left.pop();
			}
		}
		else if (cs == 'D') {
			if (right.empty());
			else {
				left.push(right.top());
				right.pop();
			}
		}
		else if (cs == 'B') {
			if (left.empty());
			else {
				left.pop();
			}
		}
		else if (cs == 'P') {
			cin >> input;
			left.push(input);
		}
	}

	while (!left.empty()) {
		right.push(left.top());
		left.pop();
	}

	while (!right.empty()) {
		cout << right.top();
		right.pop();
	}

	return 0;
}