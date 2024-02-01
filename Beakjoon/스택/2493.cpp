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
