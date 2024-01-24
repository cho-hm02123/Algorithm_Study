#include <iostream>

using namespace std;

int prime[1000000];
int pn = 0;
bool check[1000001] = { false };

int p() {
	check[0] = check[1] = true;
	for (int i = 2; i <= 1000000; i++) {
		if (check[i] == false) {
			prime[pn++] = i;
			for (int j = i + i; j <= 1000000; j += i) {
				check[j] = true;
			}
		}
	}
	return 0;
}

int rst(int n) {
	for (int i = 0; i <= pn; i++) {
		if (prime[i] > 1) {
			if (check[n - prime[i]] == false) {
				cout << n << " = " << prime[i] << " + " << n - prime[i] << '\n';
				return 0;
			}
		}
	}
	return -1;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	p();

	while (1) {
		int n;
		cin >> n;
		if (n == 0) {
			break;
		}
		else {
			if (rst(n) == -1)
				cout << "Goldbach's conjecture is wrong.\n";
		}
	}

	return 0;
}
