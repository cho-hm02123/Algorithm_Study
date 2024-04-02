#include <istream>
#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int n, m;
int arr[10];
bool flag[10];

void a(int k) {
	if (k == m) {
		for (int i = 0; i < m; i++)
			cout << arr[i] << " ";
		cout << "\n";
		return;
	}

	for (int j = 1; j < n + 1; j++) {
		if (!flag[j]) {
			if (k > 0 && arr[k - 1] > j) continue;
			arr[k] = j;
			flag[j] = 1;
			a(k + 1);
			flag[j] = 0;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n >> m;
	a(0);

	return 0;
}
