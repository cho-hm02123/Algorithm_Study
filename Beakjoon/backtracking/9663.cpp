#include <istream>
#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;
int n;
bool flagx[16], flagy[16], flagd[30], flagrd[30];
int num;

void a(int k) {
	if (k == n) {
		num++;
		return;
	}
	for (int i = 0; i < n; i++) {
		if (flagx[i] || flagy[i] || flagd[k + i] || flagrd[i - k + n - 1]) continue;
		flagx[i] = 1;
		flagy[i] = 1;
		flagd[k + i] = 1;
		flagrd[i - k + n - 1] = 1;
		a(k + 1);
		flagx[i] = 0;
		flagy[i] = 0;
		flagd[k + i] = 0;
		flagrd[i - k + n - 1] = 0;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n;
	a(0);

	cout << num;

	return 0;
}
