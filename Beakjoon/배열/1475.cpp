#include <istream>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int num[10] = { 0, };
	int n = 0;

	cin >> n;
	int m=0, s = 0;

	while (1) {
		num[n % 10]++;
		n = n / 10;

		if (n == 0)
			break;
	}

	for (int i = 0; i < 10; i++) {
		if (i == 6 || i == 9) {
			s += num[i];
			continue;
		}
		m = max(m, num[i]);
	}

	if (s % 2 == 0) 
		cout << max(m, s / 2);
	else 
		cout << max(m, s / 2 + 1);
	return 0;
}
