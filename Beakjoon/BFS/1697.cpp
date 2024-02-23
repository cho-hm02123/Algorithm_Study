#include <istream>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <queue>

using namespace std;

#define X first
#define Y second

int flag[200002] = { 0, };
int dx[2] = { 1, -1 };

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int s, d;
	cin >> s >> d;

	if (s == d) {
		cout << 0;
		return 0;
	}

	queue<int> q;
	q.push(s);
	flag[s] += 1;

	while (!q.empty()) {
		int n;
		int cur = q.front(); q.pop();

		for (int i = 0; i < 3; i++) {
			if (i == 2)
				n = cur * 2;
			else
				n = cur + dx[i];

			if ( n < 0 || n > 200001) continue;
			if (flag[n] != 0) continue;

			flag[n] = flag[cur] + 1;
			if (n == d) {
				cout << flag[n] - 1;
				return 0;
			}
			q.push(n);
		}
	}
}
