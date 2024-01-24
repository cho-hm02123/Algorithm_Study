#include <iostream>
#include <cmath>
using namespace std;

int num2(int n) {
	int num = 0;
	for (int i = 1; n / (int)pow(2, i) > 0; i++) {
		num += (n / (int)pow(2, i));
	}
	return num;
}

int num5(int n) {
	int num = 0;
	for (int i = 1; n / (int)pow(5, i) > 0; i++) {
		num += (n / (int)pow(5, i));
	}
	return num;
}

int cal(int u2, int u5, int d2, int d5) {
	int i = u2 - d2;
	int j = u5 - d5;

	if (i >= j) {
		return j;
	}
	else {
		return i;
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, m;
	cin >> n >> m;

	int n2 = num2(n);
	int n5 = num5(n);
	int m2 = num2(m);
	int m5 = num5(m);
	int nm2 = num2(n - m);
	int nm5 = num5(n - m);

	int a2 = m2 + nm2;
	int a5 = m5 + nm5;

	int rst = cal(n2, n5, a2, a5);

	cout << rst;

	return 0;
}
