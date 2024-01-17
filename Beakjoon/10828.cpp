#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	stack<int>s;

	int N;
	int ne = -1;
	int po = 1;
	int ze = 0;

	cin >> N;

	while(N--) {
		string com;
		cin >> com;

		if (com == "push") {
			int num;
			cin >> num;
			s.push(num);
		}

		else if (com == "pop") {
			if (s.empty())
				cout << ne << "\n";
			else {
				cout << s.top() << "\n";
				s.pop();
			}
		}

		else if (com == "size")
			cout << s.size() << "\n";

		else if (com == "empty") {
			if (s.empty())
				cout << po << "\n";
			else
				cout << ze << "\n";
		}

		else if (com == "top") {
			if (s.empty())
				cout << ne << "\n";
			else
				cout << s.top() << "\n";
		}
	}

	return 0;
}