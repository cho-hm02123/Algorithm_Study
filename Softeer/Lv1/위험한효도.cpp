#include <istream>
#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;
int d, a, b;

int go(int k) {
	int cnt = 0;
	while (k) {
		if (k >= a) {
			k = k - a;
			if (k == 0)
				cnt = cnt + a;
			else
				cnt = cnt + a + b;
		}
		else {
			cnt = cnt + k;
			break;
		}
	}
	return cnt;
}

int back(int k) {
	int cnt = 0;
	while (k) {
		if (k >= b) {
			k = k - b;
			cnt = cnt + b + a;
		}
		else {
			cnt = cnt + k;
			break;
		}
	}
	return cnt;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> a >> b >> d;

	cout << go(d) + back(d);

	return 0;
}
