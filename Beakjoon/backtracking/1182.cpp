#include <istream>
#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int n, s;
int arr[22];
int num;

void a(int k, int sum) {
	if (k == n) {
		if (sum == s) 
			num++;
		return;
	}
	a(k + 1, sum);
	a(k + 1, sum + arr[k]);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n >> s;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	a(0, 0);

	if (s == 0)
		num = num - 1;
	cout << num;

	return 0;
}
