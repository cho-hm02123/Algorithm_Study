#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int n, k, s;
int arr[11];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> k;

	for (int i = 1; i < n + 1; i++) {
		cin >> arr[i];

		if (arr[i] > k) {
			arr[i] = 0;
			break;
		}
		s++;
	}
	int mm = k;
	for (int j = 0; j < s; j++) {
		int kk = k;
		int m = 0;
		for (int i = 1; i <= s-j; i++) { // s-i로 할거 임 큰거부터 할라고
			if (kk == 0)
				break;
			if (kk / arr[s - i + 1-j] == 0) continue;

			m += kk / arr[s - i + 1-j];
			kk = kk % arr[s - i + 1-j];
		}
		mm = min(m, mm);
	}
	cout << mm;
	return 0;
}
