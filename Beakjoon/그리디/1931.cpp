#include <iostream>
#include <cmath>
#include <algorithm>
#include <list>

#define X first
#define Y second

using namespace std;

int n, cnt;
list <pair <int, int>> l;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		l.push_back({ b,a });
	}
	l.sort();
	int e = l.front().X;
	cnt++;
	l.pop_front();
	while (!l.empty()) {
		if (l.front().Y >= e) {
			e = l.front().X;
			cnt++;
			l.pop_front();
		}
		else
			l.pop_front();
	}

	cout << cnt;

	return 0;
}
