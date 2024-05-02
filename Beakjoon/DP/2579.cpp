/*
  밟는 경우 말고 안밟는 경우로 생각하기
*/

#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int n;
int in[301], st[301];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int sum = 0;

	cin >> n;

	for (int i = 1; i < n + 1; i++) {
		cin >> in[i];
		sum += in[i];
	}

	if (n <= 2)
		cout << sum;
	else {
		st[1] = in[1];
		st[2] = in[2];
		st[3] = in[3];
		for (int i = 4; i < n + 1; i++)
			st[i] = min(st[i - 2], st[i - 3]) + in[i];

		cout << sum - min(st[n - 1], st[n - 2]);
	}

	return 0;
}
