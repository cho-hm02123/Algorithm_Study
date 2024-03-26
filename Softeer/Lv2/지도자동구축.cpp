#include <istream>
#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int N;
int st = 2;

int cal(int n) {
	if (N == n) {
		return st;
	}
	else {
		st += st - 1;
		cal(n + 1);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N;
	int a = cal(0);
	cout << a * a;

	return 0;
}
