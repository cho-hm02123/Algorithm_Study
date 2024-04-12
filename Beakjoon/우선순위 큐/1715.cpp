#include <iostream>
#include <cmath>
#include <algorithm>
#include <queue>

using namespace std;
priority_queue <int, vector<int>, greater<int>> pq;
int n;
int sum;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n;

	while (n--) {
		int a;
		cin >> a;
		pq.push(a);
	}

	while (!(pq.size() == 1)) {
		int a = pq.top();
		pq.pop();
		int b = pq.top();
		pq.pop();
		pq.push(a + b);
		sum += a + b;
	}

	cout << sum;

	return 0;
}
