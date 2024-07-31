/* https://www.acmicpc.net/problem/16236
* 
*  1h 54m 50s
* 
* 문제: nxn 크기의 공간 물고기 m마리 아기 상어 1마리
*		한 칸에 최대 1마리
*		상어, 물고기 모두 크기를 가지고 있음
*		처음 상어의 크기는 2이고 아기 상어는 1초에 상하좌우로 움직임
*		상어는 자기보가 큰 물고기가 있는 칸을 지나지 못함
*		자신보다 작은 물고기 먹을 수 있음
*		크기가 같으면 먹을 수 ㄴ없지만 지날 순 있음??
* 
*		더이상 먹을 수 있는 물고기가 없으면 엄마한테 도움
*		먹을 수 있는 물고기가 1마리면 그거 먹으러 감
*		먹을 수 있는 물고기가 1마리보다 많으면 거리가 가장 가까운 몰고기 먹으러 감 (칸의 개수의 최소)
*			거리가 동일 할 땐 가장 위의 물고기, 또 많으면 가장 왼쪽
* 
*		상어 이동은 1초 걸림 크기가 같은 수의 물고기를 먹으면 크기가 1 증가
* 
*		상어가 몇초 동안 엄마한테 도움을 요청하지 않고 물고기를 먹는지
* 
* 입력: N (2이상 20이하)
*		0 : 빈칸, 1~6: 물고기 크기, 9: 아기상어 위치
* 
* 출력: 먹을 물고기 없을 때 까지 걸리는 시간
* 
* 풀이: 전체 칸에 대한 이동 거리 계산 -> 갈 수 있는 칸 우선순위 큐로 우선순위 정함 -> 이동 거리 시간에 더함 -> 다시 처음으로
*		*주의*
*			먹은 물고기 수는 상어 크기 1 증가하면 0으로 초기화
*			우선순위 정할 때 상어 위치에서 최단거리가 아닌 실제 이동할 수 있는 칸으로 갔을 때의 최단 거리로 계산해야 함
*/

#include <iostream>
#include <cmath>
#include <algorithm>
#include <queue>
using namespace std;

#define X first
#define Y second

int n, sx, sy, t, eat;
int arr[21][21];
int board[21][21];
int sz = 2;
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

class cmp {
public:
	bool operator() (pair<int, int> a, pair<int, int> b) {
		if (board[a.X][a.Y] != board[b.X][b.Y])
			return board[a.X][a.Y] > board[b.X][b.Y];

		if (a.X == b.X) return a.Y > b.Y;

		return a.X > b.X;
	}
};

priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;

void rst() {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			board[i][j] = 0x7fffffff;
	while (!pq.empty())
		pq.pop();
}

void ff() {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			if (arr[i][j] > 0 && arr[i][j] < sz)
				pq.push({ i,j });
		}
}

bool check(int x, int y) {
	if (x < 0 || x > n - 1 || y < 0 || y > n - 1) return true;

	return false;
}

void dr() {
	rst();
	queue <pair<int, int>> q;
	q.push({sx, sy});
	board[sx][sy] = 0;
	while (!q.empty()) {
		pair<int, int> cur = q.front(); q.pop();

		for (int i = 0; i < 4; i++) {
			int x = cur.X + dx[i];
			int y = cur.Y + dy[i];

			if (check(x,y)) continue;
			if (arr[x][y] > sz) continue;

			if (board[x][y] > board[cur.X][cur.Y] + 1) {
				board[x][y] = board[cur.X][cur.Y] + 1;
				q.push({ x,y });
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 9) {
				sx = i;
				sy = j;
				arr[i][j] = 0;
			}
		}

	while (1) {
		dr();
		ff();
		if (pq.empty() || board[pq.top().X][pq.top().Y] == 0x7fffffff) break; // 여기 0x7fffffff일 때 안막아줘서 틀렸음
		sx = pq.top().X;
		sy = pq.top().Y;
		pq.pop();
		eat++;
		arr[sx][sy] = 0;
		if (sz == eat) {
			sz++;
			eat = 0;
		}
		t += board[sx][sy];
	}

	cout << t;

	return 0;
}
