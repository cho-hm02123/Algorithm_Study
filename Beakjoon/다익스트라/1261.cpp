/* https://www.acmicpc.net/problem/1261 알고스팟
* 
* 문제: 미로는 NxM, 빈방 혹은 벽으로 이루어져있음
*	이동할 수 있는 방은 상하좌우로 인접한 빈방
*	벽은 부술 수 있음
*	1,1에서 N,M 까지 이동하기 위해 쵯 몇개의 벽을 부숴야 하는지
* 
* 입력: 가로M, 세로 N
*	N개의 미로 상태 (0 이면 빈 방 1 이면 벽)
* 
* 출력: (1,1)에서 (N,M)을 이동하기 위해 최소 몇개의 벽을 부숴야 하는지
* 
* 풀이: 다익스트라
*		입력이 string 형식으로 들어오기 때문에 char로 받고 '0'을 빼서 int로 변경 이를 arr에 저장
*		weight 배열에 1,1 제외 모두 INF로 초기화 후 부숴야 하는 벽 개수를 저장
*/

#include <iostream>
#include <cmath>
#include <algorithm>
#include <queue>
using namespace std;

#define MAX 100
#define INF 0x3f3f3f3f

struct xysum {
	int x, y, sum;
};

class cmp {
public:
	bool operator()(xysum a, xysum b) {
		if (a.sum == b.sum) {
			if (a.x == b.x) return a.y > b.y;
			return a.x > b.x;
		}
		return a.sum > b.sum;
	}
};	priority_queue<xysum, vector<xysum>, cmp> pq;

int n, m;
int arr[MAX + 2][MAX + 2];
int weight[MAX + 2][MAX + 2];
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> m >> n;

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			weight[i][j] = INF;
	weight[1][1] = 0;

	for(int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) {
			char a;
			cin >> a;
			arr[i][j] = a - '0';
		}

	pq.push({ 1, 1, 0 });

	while (!pq.empty()) {
		xysum cur = pq.top(); pq.pop();

		for (int i = 0; i < 4; i++) {
			int x = cur.x + dx[i];
			int y = cur.y + dy[i];

			if (x < 1 || y < 1 || x > n || y > m) continue;
			int nxt = weight[cur.x][cur.y] + arr[x][y];

			if (nxt < weight[x][y]) {
				pq.push({ x, y, nxt });
				weight[x][y] = nxt;
			}
		}
	}

	cout << weight[n][m];

	return 0;
}
