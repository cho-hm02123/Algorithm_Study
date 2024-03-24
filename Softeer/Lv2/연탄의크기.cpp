#include <istream>
#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

#define X first
#define Y second

int N;
int s[25] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97 };
int save[25] = { 0, };
pair <int, int> p = { 0, 0 };

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N;

	while (N--) {
		int a;
		cin >> a;

		for (int i = 0; i < 25; i++) {
			if (a % s[i] == 0)
				save[i] += 1;
		}
	}

	for (int i = 0; i < 25; i++) {
		if (save[i] > p.Y)
			p = { i, save[i] };
	}

	cout << p.Y;

	return 0;
}
