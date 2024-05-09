#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int n, m;
int arr[10001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	int en = 0;
	int num = 0;
	int sum = arr[0];

	for (int st = 0; st < n; st++) {
		while (en < n && sum < m) {
			en++;
			if (en != n)
				sum += arr[en];
		}
		if (en == n) break;
		if (sum == m)
			num++;
		sum -= arr[st];
	}

	cout << num;

	return 0;
}
