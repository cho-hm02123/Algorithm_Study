#include <istream>
#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int k;
int arr[15];

void a(int c,bool flag[], int ar[]) {
	if (c == 6) {
		for (int i = 0; i < 6; i++)
			cout << ar[i] << " ";
		cout << "\n";
		return;
	}
	for (int j = 0; j < k; j++) {
		if (!flag[j]) {
			if (ar[c - 1] > arr[j]) continue;
			ar[c] = arr[j];
			flag[j] = 1;
			a(c + 1, flag, ar);
			flag[j] = 0;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	while (1) {
		bool flag[15] = { 0, };
		int ar[8] = { 0, };
		cin >> k;
		if (k == 0)
			break;
		for (int i = 0; i < k; i++)
			cin >> arr[i];
		a(0, flag, ar);
		cout << "\n";

	}

	return 0;
}
