#include <iostream>
#include <cmath>
#include <algorithm>
#include <list>

using namespace std;

#define X first
#define Y second

int n;
list <pair <int, int>> l;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n;
	while (n--) {
		int a, b;
		cin >> a >> b;
		l.push_front({ a,b });
	}

	l.sort();
	while (!l.empty()) {
		cout << l.front().X << " " << l.front().Y << "\n";
		l.pop_front();
	}

	return 0;
}
