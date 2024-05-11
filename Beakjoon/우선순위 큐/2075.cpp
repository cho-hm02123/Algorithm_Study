#include <iostream>
#include <cmath>
#include <algorithm>
#include <queue>

using namespace std;

int n;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	int k = n * n;
	priority_queue <int, vector<int>, greater<int>> q;
	for (int i = 0; i < k; i++) {
		int a;
		cin >> a;
		q.push(a);
		if (q.size() > n) q.pop();
	}
	cout << q.top();
	return 0;
}
