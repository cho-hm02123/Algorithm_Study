#include <istream>
#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;
int n, m;
bool flag[10];
int num[10];

void a(int k) {
	if (k == m) {
		for (int i = 0; i < m; i++)
			cout << num[i] << ' ';
		cout << '\n';
		return;
	}

	for (int i = 1; i <= n; i++) {
		if (!flag[i]) {
			num[k] = i;
			flag[i] = 1;
			a(k + 1);
			flag[i] = 0;
		}
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n >> m;

	a(0);
}
