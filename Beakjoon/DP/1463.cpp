#include <istream>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <queue>

using namespace std;

int num[1000001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	num[2] = 1;
	num[3] = 1;

	int n;
	cin >> n;

	for (int i = 0; i < n + 1; i++) {
		if (i == 0||i == 1) continue;
		if (i == 1 || i == 2) {
			num[i] = 1;
			continue;
		}
		int m = num[i - 1] + 1;
		if (i % 3 == 0)
			m = min(m, num[i / 3] + 1);
		if (i % 2 == 0)
			m = min(m, num[i / 2] + 1);
		num[i] = m;
	}

	cout << num[n];
	return 0;
}
