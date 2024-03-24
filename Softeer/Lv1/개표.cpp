#include <istream>
#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;
int T;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> T;

	while (T--) {
		int n;
		int cnt = 0;
		cin >> n;

		while (n) {
			if (n > 4) {
				cout << "++++";
				n = n - 5;
			}
			else {
				for (int i = 0; i < n; i++)
					cout << "|";
				n = 0;
			}

			cout << " ";
		}
		cout << "\n";
	}

	return 0;
}
