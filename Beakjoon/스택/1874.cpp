#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	string rst;
	int cps = 0;
	int num;
	int T;
	stack <int> t;
	cin >> T;

	while (T--) {
		cin >> num;
		if (num > cps) {
			while (num > cps) {
				t.push(++cps);
				rst += '+';
			}
			rst += '-';
			t.pop();
		}
		else if (num == t.top()) {
			rst += '-';
			t.pop();
		}
		else if (num < t.top())
			break;
		else if (num > t.top()) {
			while (num > cps) {
				t.push(++cps);
				rst += '+';
			}
			rst += '-';
			t.pop();
		}
	}

	if (t.empty()) {
		for (char ch : rst)
			cout << ch << '\n';
	}
	else
		cout << "NO" << '\n';

	return 0;
}
