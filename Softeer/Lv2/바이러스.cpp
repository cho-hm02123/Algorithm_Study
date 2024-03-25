#include <istream>
#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

#define ull unsigned long long
ull k, p, n;

ull cal(ull num) {
	if (num == n)
		return k;
	else {
		k = k * p % 1000000007;
		num++;
		cal(num);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> k >> p >> n;

	cout << cal(0);

	return 0;
}
