#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int n, m;
int mm[10];
int num[10];
bool flag[10];

void bt(int a) {
	if (a == m) {
		for (int i = 0; i < m; i++)
			cout << num[i] << " ";
		cout << "\n";
		return;
	}

	for (int i = 0; i < n; i++) {
		if (flag[i]) continue;
		num[a] = mm[i];
		flag[i] = 1;
		bt(a + 1);
		flag[i] = 0;
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> mm[i];

	sort(mm, mm+n);
	bt(0);

	return 0;
}
