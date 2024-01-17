#include <iostream>
#include <algorithm>

using namespace std;

int a[9] = { 0, };
int b[9] = { 0, };
int c[7] = { 0, };

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int sum = 0;
	int sum100 = 0;
	int cnt = 0;

	for (int i = 0; i <= 8; i++) {
		cin >> a[i];
		sum += a[i];
	}

	for (int i = 0; i < 9; i++) {
		if (i == 0)
			b[i] = 1;
		else {
			b[i - 1] = 0;
			b[i] = 1;
		}
		for (int j = 0; j < 9; j++) {
			if (j == i) continue;

			b[j] = 1;
			sum100 = sum - a[i] - a[j];

			if (sum100 == 100) {
				for (int k = 0; k < 9; k++) {
					if (b[k] == 0) {
						c[cnt] = a[k];
						cnt++;
					}
				}
				sort(c, c + 7);
				for (int h = 0; h < 7; h++)
					cout << c[h] << "\n";

				return 0;
			}
			else {
				b[j] = 0;
				cnt = 0;
				sum100 = 0;
				cnt = 0;
			}
		}
	}
	return 0;
}
