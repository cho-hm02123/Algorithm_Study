#include <iostream>
#include <cmath>
#include <algorithm>
#include <queue>

using namespace std;

int n;
priority_queue <long long> pq;
vector<vector<int>> v(200002);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n;
	for(int i = 0; i < n; i++) {
		long long del, cnt;
		cin >> del >> cnt;
		v[del].push_back(cnt);
	}
	int sum = 0;
	for (int i = 200001; i != 0; i--) {
		for (int j : v[i])
			pq.push(j);

		if (pq.empty()) continue;
		sum += pq.top(); pq.pop();
	}

	cout << sum;

	return 0;
}
