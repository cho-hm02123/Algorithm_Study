/*
  벽을 부수면서 이동할 수 있다. 이때 벽은 한번만 부술 수 있음
  그럼 3차원 배열에서 마지막 인덱스가 0이면 벽을 안부수고 이동했을 때, 1이면 벽을 부수고 이돌했을 때를 나타대고
  이동 거리가 -1로 초기화 해줘서 방문 했는지 여부를 알 수 있도록 함
  */

#include <iostream>
#include <cmath>
#include <algorithm>
#include <tuple>
#include <queue>

using namespace std;

int n, m;
char arr[1001][1001];
int len[1001][1001][2];
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

int bfs() {
	queue <tuple<int, int, int>> q;

	for(int i = 1; i < n+1; i++)
		for (int j = 1; j < m + 1; j++) {
			len[i][j][0] = -1;
			len[i][j][1] = -1;
		}
	len[1][1][0] = 1;
	len[1][1][1] = 1;

	q.push({ 1,1,0 });

	while (!q.empty()) {
		int x, y, w;
		tie(x, y, w) = q.front();

		if (x == n && y == m) return len[x][y][w];

		int nlen = len[x][y][w] + 1;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int xx = x + dx[i];
			int yy = y + dy[i];

			if (xx < 1 || xx > n || yy < 1 || yy > m) continue;
			if (arr[xx][yy] == '0' && len[xx][yy][w] == -1) {
				len[xx][yy][w] = nlen;
				q.push({ xx,yy,w });
			}
			if (w == 0 && len[xx][yy][1] == -1 && arr[xx][yy] == '1') {
				len[xx][yy][1] = nlen;
				q.push({ xx,yy,1 });
			}
		}
	}
	return -1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	for (int i = 1; i < n + 1; i++)
		for (int j = 1; j < m + 1; j++)
			cin >> arr[i][j];

	cout << bfs();

	return 0;
}
