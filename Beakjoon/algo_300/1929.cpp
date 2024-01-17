#include <iostream>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int prime[1000000];
	int pn = 0;
	bool check[1000001] = { false };
	check[0] = check[1] = true;

	int M, N;
	cin >> M >> N;

	for (int i = 2; i <= N; i++) {
		if (check[i] == false) {
			prime[pn++] = i;
			for (int j = i + i; j <= N; j += i) {
				check[j] = true;
			}
		}
	}

	for (M; M <= N; M++) {
		if (check[M] == false)
			cout << M << '\n';
	}
}