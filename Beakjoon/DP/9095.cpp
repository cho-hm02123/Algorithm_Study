#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int t, n;
int rst[12];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	rst[1] = 1, rst[2] = 2, rst[3] = 4;
	for (int i = 4; i < 12; i++)
		rst[i] = rst[i - 1] + rst[i - 2] + rst[i - 3];

	cin >> t;

	while (t--) {
		cin >> n;
		cout << rst[n] << "\n";
	}

	return 0;
}
