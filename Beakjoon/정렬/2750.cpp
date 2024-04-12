#include <iostream>
#include <cmath>
#include <algorithm>
#include <list>

using namespace std;

int n;
list <int> l;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n;
	while (n--) {
		int a;
		cin >> a;
		l.push_back(a);
	}

	l.sort();
	while (!l.empty()) {
		cout << l.front() << "\n";
		l.pop_front();
	}

	return 0;
}
