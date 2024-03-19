#include <istream>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;
bool b[2000001] = { 0 };

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	vector <int> v;
	int n,a,k;
	int count = 0;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a;
		v.insert(v.begin() + i, a);
		b[a] = true;
	}
	cin >> k;

	for (int i = 0; i < n; i++) {
		if (k - v[i] > 0 && b[k - v[i]]) {
			if (k - v[i] == v[i]) continue;
			count++;
			b[v[i]] = false;
		}
	 }

	cout << count;

	return 0;
}
