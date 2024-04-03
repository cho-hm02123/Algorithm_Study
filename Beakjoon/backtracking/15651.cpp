#include <istream>
#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int n, m;
int arr[10];

void a(int k) {
	if (k == m) {
		for (int i = 0; i < m; i++)
			cout << arr[i] << " ";
		cout << "\n";
		return;
	}
	
	for (int j = 1; j < n+1; j++) {
		arr[k] = j;
		a(k + 1);
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
