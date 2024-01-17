#include <iostream>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int rst = 1;
	int N;
	cin >> N;
	for (N; N > 0; N--) {
		rst = rst * N;
	}

	cout << rst;

	return 0;
}