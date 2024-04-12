#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

int n;
vector <long long> v;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n;
	while (n--) {
		long long a;
		cin >> a;
		v.push_back(a);
	}
	sort(v.begin(), v.end());
	int cnt = 1;
	int scnt = 0;
	long long sm;

	for (int i = 1; i < v.size(); i++) {
		if (v[i - 1] == v[i]) cnt++;
		else {
			if (cnt > scnt) {
				scnt = cnt;
				sm = v[i-1];
			}
			cnt = 1;
		}
	}
	if (cnt > scnt)
		sm = v[v.size() - 1];

	cout << sm;

	return 0;
}
