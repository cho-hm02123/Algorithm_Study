#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int n, m;
int arr[100001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	sort(arr, arr + n);

	cin >> m;
	for (int i = 0; i < m; i++) {
		int a;
		cin >> a;
		cout << binary_search(arr, arr + n, a) << "\n";
	}

	return 0;
}
