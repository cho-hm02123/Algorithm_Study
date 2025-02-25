/* https://www.acmicpc.net/problem/14442 벽 부수고 이동하기 2
* 
* 28m
* 
* 문제: N by M, 0은 이동 가능, 1은 벽
*	(1,1) > (N,M) 최단 경로 시작, 마지막 칸 포함
*	벽을 K개 까지 부숴도 됨
*	인접은 상하좌우
*	
* 입력: N, M, (1000이하), K
* 
* 출력: 최단 거리 출력 불가능하면 -1
* 
* 풀이: 벽 부순 횟수 저장하는 배열 차원 하나 추가
*/

#include <iostream>
#include <algorithm>
#include <cmath>
#include <queue>

using namespace std;

struct nxy {
	int n, x, y;
};

const int INF = 0x3f3f3f3f;

int N, M, K;
int rst = INF;
char arr[1001][1001];
int cmap[11][1001][1001];
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

void Initialcmap() {
	for (int k = 0; k <= K; k++)
		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= M; j++)
				cmap[k][i][j] = INF;

	cmap[0][1][1] = 1;
}

void FindPath() {
	Initialcmap();
	queue <nxy> q;

	q.push({ 0,1,1 });

	while (!q.empty()) {
		nxy cur = q.front(); q.pop();
		if (cur.x == N && cur.y == M) {
			if (cmap[cur.n][cur.x][cur.y] < rst)
				rst = cmap[cur.n][cur.x][cur.y];
			continue;
		}

		for (int i = 0; i < 4; i++) {
			int x = cur.x + dx[i];
			int y = cur.y + dy[i];
			int n = cur.n;

			if (x < 1 || x > N || y < 1 || y > M) continue;

			if (arr[x][y] == '1') {
				if (n >= K) continue;
				else n += 1;
			}

			if (cmap[cur.n][cur.x][cur.y] + 1 < cmap[n][x][y]) {
				cmap[n][x][y] = cmap[cur.n][cur.x][cur.y] + 1;
				q.push({ n, x, y });
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M >> K;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
			cin >> arr[i][j];

	FindPath();

	if (rst == INF)
		cout << -1;
	else
		cout << rst;

	return 0;
}
