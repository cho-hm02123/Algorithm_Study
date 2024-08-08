/* https://www.acmicpc.net/problem/17086 아기 상어2
* 
* 29m 26s
* 
* 문제: NxM 크기 격ㅈ에 상어 여러마리 한 칸에 최대 1마리
*	안전거리 > 해당 칸과 가장 가까운 거리의 상어까지의 거리
*	거리 > 해당 칸으로 가기 위해 지나야 하는 칸의 수
*	이동 > 8방향
*	안전 거리가 가장 큰 칸 구하기
* 
* 입력: N, M, 격자 상태 (상어 있으면 1)
* 
* 출력: 안전 거리의 최댓값
* 
* 풀이: 그냥 빈칸중에 안전거리였음
*/

#include <iostream>
#include <cmath>
#include <algorithm>
#include <queue>
using namespace std;

#define X first
#define Y second

int n, m, rst;
int arr[51][51];
int ch[51][51];
int dx[8] = { -1, -1, -1, 0, 1, 1, 1, 0 };
int dy[8] = { -1, 0, 1, 1, 1, 0, -1, -1 };

void init() {
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			ch[i][j] = 0x7fffffff;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> arr[i][j];

	init();

	for(int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) {
			if (arr[i][j] == 0) continue;

			queue <pair<int, int>> q;
			q.push({ i,j });
			ch[i][j] = 0;

			while (!q.empty()) {
				pair<int, int> cur = q.front(); q.pop();

				for (int h = 0; h < 8; h++) {
					int x = cur.X + dx[h];
					int y = cur.Y + dy[h];

					if (x < 1 || y < 1 || x > n || y > m) continue;

					if (ch[x][y] > ch[cur.X][cur.Y] + 1) {
						if (arr[x][y] == 1) continue;
						ch[x][y] = ch[cur.X][cur.Y] + 1;
						q.push({ x,y });
					}
				}
			}
		}

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			rst = max(rst, ch[i][j]);

	cout << rst;

	return 0;
}
