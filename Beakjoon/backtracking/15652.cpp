#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int n, m;
int num[10];

void back(int a) {
	if (a == m) {
		for (int i = 0; i < m; i++)
			cout << num[i] << " ";
		cout << "\n";
		return;
	}
	int b = 1;
	if (a != 0)
		b = num[a-1];
	for (int i = b; i < n+1; i++) {
		num[a] = i;
		back(a + 1);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;

	back(0);

	return 0;
}
