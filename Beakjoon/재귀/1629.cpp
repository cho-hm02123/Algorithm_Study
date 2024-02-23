#include <istream>
#include <iostream>
#include <cmath>

using namespace std;

long long cal (long long a , long long b, long long c) {
	if (b == 1) return a % c;
	long long d = cal(a, b / 2, c);
	d = d * d % c;
	if (b % 2 == 0) return d;
	return d * a % c;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	long long a, b, c;
	cin >> a >> b >> c;

	cout << cal(a, b, c);

	return 0;
}
