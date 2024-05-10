/*
  해당 가격의 보석을 담을 수 있는 가방 중 무게가 가장 적은 걸 찾기 위해 lower_bound 시용
*/

#include <iostream>
#include <cmath>
#include <algorithm>
#include <set>

#define X first
#define Y second

using namespace std;

int n, k;
long long sum;
multiset<int> bag;
pair <int, int> p[300001]; // 가격 무게 순

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> k;

	for (int i = 0; i < n; i++)
		cin >> p[i].Y >> p[i].X;
	sort(p, p + n);

	for (int i = 0; i < k; i++) {
		int c;
		cin >> c;
		bag.insert(c);
	}
	
	for (int i = n - 1; i >= 0; i--) {
		pair <int, int> cur = p[i];
		auto it = bag.lower_bound(cur.Y);
		if (it == bag.end()) continue;
		sum += cur.X;
		bag.erase(it);
	}

	cout << sum;
	return 0;
}
