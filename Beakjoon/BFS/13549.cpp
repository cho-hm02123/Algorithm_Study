/*
BFS가 맞다
2배 하는게 무게값이 작으므로 먼저 하게 하고
한번 들린곳은 또 들릴 필요 없음
*/

#include <iostream>
#include <cmath>
#include <algorithm>
#include <queue>
using namespace std;

int s, d; // 수빈, 동생
int arr[100001];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> s >> d;

	if (d <= s) {
		cout << s - d;
		return 0;
	}

	queue <int> q;
	q.push(s);
	arr[s] = 1;

	while (!q.empty()) {
		int x = q.front(); q.pop();
		int dx[3] = { x, -1, 1};

		if (x == d) continue;

		for (int i = 0; i < 3; i++) {
			int xx = x + dx[i];

			if (xx < 0 || xx > 100000 || arr[xx] != 0) continue;

			if (i == 0) {
				arr[xx] = arr[x];
				q.push(xx);
			}
			else {
				arr[xx] = arr[x] + 1;
				q.push(xx);
			}
		}
	}

	cout << arr[d] - 1;
	return 0;
}
