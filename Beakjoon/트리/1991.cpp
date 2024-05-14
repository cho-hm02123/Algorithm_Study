#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

int n;
int lc[27];
int rc[27];

void bd(int cur) {
	if (lc[cur])
		bd(lc[cur] - 'A' + 1);
	if (rc[cur])
		bd(rc[cur] - 'A' + 1);
	cout << char(cur + 'A' - 1);
}

void md(int cur) {
	if (lc[cur])
		md(lc[cur] - 'A' + 1);
	cout << char(cur + 'A' - 1);
	if (rc[cur])
		md(rc[cur] - 'A' + 1);
}

void fd(int cur) {
	cout << char(cur + 'A' - 1);
	if (lc[cur])
		fd(lc[cur] - 'A' + 1);
	if (rc[cur])
		fd(rc[cur] - 'A' + 1);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 1; i < n+1; i++) {
		char p, l, r;
		cin >> p >> l >> r;
		if (l != '.') lc[p - 'A' + 1] = l;
		if (r != '.') rc[p - 'A' + 1] = r;
	}

	fd(1);
	cout << "\n";
	md(1);
	cout << "\n";
	bd(1);

	return 0;
}
