#include <iostream>

using namespace std;

bool prime(int n) {
	if (n < 2) {
		return false;
	}
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0) {
			return false;
		}
	}
	return true;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int i = 0;
	int N;
	cin >> N;

	while (N--) {
		int a;
		cin >> a;
		if (prime(a) == true) {
			i++;
		}
	}

	cout << i;

	return 0;
}