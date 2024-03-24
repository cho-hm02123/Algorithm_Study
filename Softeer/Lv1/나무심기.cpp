#include <istream>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <list>

using namespace std;

int N;
list <int> l;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N;

	while (N--) {
		int a;
		cin >> a;
		l.push_back(a);
	}

	l.sort();

	if (l.size() > 2) {
		int r1 = l.back();
		l.pop_back();
		int r2 = l.back();

		int r3 = l.front();
		l.pop_front();
		int r4 = l.front();

		cout << max(r1 * r2, r3 * r4);
	}

	else {
		int r1 = l.back();
		l.pop_back();
		int r2 = l.back();

		cout << r1 * r2;
	}

	return 0;
}
