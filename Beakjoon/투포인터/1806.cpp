#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int n, s, sum;
int arr[100001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> s;
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	sum = arr[0];
	int en = 0;
	int mm = 0x7fffffff;
	for (int st = 0; st < n; st++) {
		while (en < n && sum < s) {
			en++;
			if (en != n)
				sum += arr[en];
		}
		if (en == n) break;
		mm = min(mm, en - st + 1);
		sum -= arr[st];
	}
	if (mm == 0x7fffffff)
		cout << 0;
	else
		cout << mm;
	return 0;
}
