#include <iostream>
#include <cmath>
#include <algorithm>
#include <set>

#define X first
#define Y second

using namespace std;

int n;
multiset <int> st;
pair <int, int> p[500001]; // 키 등수

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> p[i].X >> p[i].Y;
	sort(p, p + n, greater<pair<int,int>>());

	for (int i = 0; i <n; i++) {
		auto it = st.lower_bound(-p[i].Y+1);
		if (it == st.end()) st.insert(-1);
		else {
			int a = *it;
			st.erase(it);
			st.insert(a - 1);
		}
	}

	cout << (int)st.size();

	return 0;
}
