#include <istream>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <queue>

using namespace std;

#define X first
#define Y second

int N, M;
deque <pair <int, int>> q1;
deque <pair <int, int>> q2;
int dM;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		int a, b;
		cin >> a >> b;
		q1.push_back({ a,b });
	}
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		q2.push_back({ a,b });
	}

	while (!q2.empty()) {
		pair <int, int> cur1 = q1.front(); q1.pop_front();
		pair <int, int> cur2 = q2.front(); q2.pop_front();
		if (cur1.X < cur2.X) {
			dM = max(dM, cur2.Y - cur1.Y);
			q2.push_front({ cur2.X - cur1.X, cur2.Y });
		}
		else if (cur1.X == cur2.X) {
			dM = max(dM, cur2.Y - cur1.Y);
		}
		else {
			dM = max(dM, cur2.Y - cur1.Y);
			q1.push_front({ cur1.X - cur2.X, cur1.Y });
		}
	}

	cout << dM;

	return 0;
}
