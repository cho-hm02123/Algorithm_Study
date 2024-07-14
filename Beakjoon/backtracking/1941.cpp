#include <iostream>
#include <cmath>
#include <algorithm>
#include <queue>
using namespace std;

#define X first
#define Y second

char arr[5][5];
int num[7];
bool flag[25];
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };
int cnt;

bool check() {
	queue <pair <int, int>> q;
	bool f[7] = { 0, };
	q.push({ num[0] / 5, num[0] % 5 });
	f[0] = 1;

	while (!q.empty()) {
		pair <int, int> cur = q.front(); q.pop();
		for (int i = 0; i < 4; i++) {
			int x = cur.X + dx[i];
			int y = cur.Y + dy[i];

			if (x < 0 || y < 0 || x > 4 || y > 4) continue;
			for (int j = 0; j < 7; j++) {
				if (num[j] == x * 5 + y && f[j] != 1) {
					q.push({ x,y });
					f[j] = 1;
				}
			}
		}
	}

	for (int i = 0; i < 7; i++)
		if (f[i] == 0) return 0;

	return 1;
}

void bt(int a) {
	if (a == 7) {
		if (check()) {
			int l = 0;
			for (int i = 0; i < 7; i++) {
				int x = num[i];
				if (arr[x / 5][x % 5] == 'S') l++;
			}
			if (l > 3) cnt++;
		}
		return;
	}

	int st = 0;
	if (a != 0) st = num[a - 1];
	for (int i = st; i < 25; i++) {
		if (flag[i]) continue;
		if (a != 0 && num[a - 1] > i) continue;

		num[a] = i;
		flag[i] = 1;
		bt(a + 1);
		flag[i] = 0;
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++) 
			cin >> arr[i][j];

	bt(0);

	cout << cnt;

	return 0;
}
