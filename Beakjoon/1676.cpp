#include <iostream>
#include <cmath>

using namespace std;

int f(int n) {
	int num = 0;
	for (int i = 1;  n / (int)pow(5, i) > 0; i++) {
		num  += (n / (int)pow(5,i));
	}
	return num;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n;
	cin >> n;

	int i = f(n);
	cout << i;

	return 0;
}