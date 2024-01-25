#include <iostream>
#include <istream>
#include <cmath>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int c[10] = { 0,1,2,3,4,5,6,7,8,9 };
	int check[10] = { 0, };
	int A = 0, B = 0, C = 0, a = 0;

	cin >> A >> B >> C;

	int mul = A * B * C;

	int l = log10(mul) + 1;

	for (int i = 0; i < l; i++) {
		a = mul % 10;
		mul = mul / 10;

		for (int j = 0; j < 10; j++) {
			if (a == c[j]) {
				check[j] ++;
				break;
			}
		}
	}

	for (int j = 0; j < 10; j++)
		cout << check[j] << "\n";

	return 0;
}
