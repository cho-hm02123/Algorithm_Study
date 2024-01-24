#include <iostream>

using namespace std;

int max(int a, int b) {
	if (b == 0) {
		return a;
	}
	else {
		int c;
		c = a % b;

		return max(b, c);
	}
}

int min(int a, int b, int c) {
	return a * b / c;
}


int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N;
	cin >> N;
	
	while (N--) {
		int A, B;
		cin >> A;
		cin >> B;

		int C = max(A, B);
		cout << min(A, B, C) << '\n';
	}
}
