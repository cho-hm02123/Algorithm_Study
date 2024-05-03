#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int n, sum;
int a[50], b[50];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < n; i++)
		cin >> b[i];

	sort(a, a + n);
	sort(b, b + n, greater<int>());

	for (int i = 0; i < n; i++)
		sum += a[i] * b[i];

	cout << sum;
	return 0;
}
