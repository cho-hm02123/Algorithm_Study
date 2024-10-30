/* https://www.acmicpc.net/problem/20058 마법사 상어와 파이어스톰
* 
* 문제: 크기가 2^N x 2^N 인 격자로 나누어진 얼음판 (r, c)는 r행 c열 A[r][c]는 (r, c)에 있는 얼음의 양
*	파이어스톰 시전할 때마다 단계 L을 결정해야 함
*		1. 격자를 2^L x 2^L으로 크기의 부분 격자로 나눔
*		2. 모든 부분 격자를 시계 방향으로 90도 회전
*		3. 얼음이 있는 칸 3개 또는 그 이상과 인접해있지 않은 칸은 얼음의 양이 1 줄어듬 (인접은 상하좌우)
*	파이어스톰을 Q번 시전한 후
*		남아있는 얼음 A[r][c]의 합
*		남아있는 얼음 중 가장 큰 덩어리가 차지하는 칸의 개수 (얼음이 있는 칸끼리 인접하면 해당 칸들이 연결되어있음, 덩어리는 연결된 칸의 집합)
* 
* 
* 입력: N, Q, 격자에 있는 얼음 양
*	마법사 상어가 시전한 단계가 순서대로 주어짐
* 
* 풀이: 90도 돌리는게 포인트 부분 회전일 때 좌측 상단 좌표를 더해주는거 사용하면 그리 어렵지 않음
*/

#include <iostream>
#include <cmath>
#include <algorithm>
#include <queue>
using namespace std;

#define X first
#define Y second

int a[65][65];
int cparr[65][65];
int n, q, sz;
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

void SaveTable() {	// 배열 저장
	for (int i = 0; i < sz; i++)		
		for (int j = 0; j < sz; j++)
			cparr[i][j] = a[i][j];
}

void TurnTable(int par, int num) {	// 90도 회전
	for (int cnt = 0; cnt < num * num; cnt++) { 
		int x = cnt / num * par;
		int y = cnt % num * par;
		for (int i = 0; i < par; i++)
			for (int j = 0; j < par; j++)
				a[j + y][par - i - 1 + x] = cparr[i + y][j + x];
	}
}

void ReICE() {
	for(int i = 0; i < sz; i++)
		for (int j = 0; j < sz; j++) {
			if (!cparr[i][j]) continue;
			int check = 0;
			for (int d = 0; d < 4; d++) {
				int x = i + dx[d];
				int y = j + dy[d];

				if (x < 0 || y < 0 || x >= sz || y >= sz) continue;
				if (cparr[x][y]) check++;
			}
			if (check < 3)
				a[i][j]--;
		}
}

void FireStorm(int k) {
	int par = pow(2, k);
	int num = sz / par;
	SaveTable();
	TurnTable(par, num);
	SaveTable();
	ReICE();
}

void Rst1() {	// 1번 결과 도출
	int rst = 0;
	for (int i = 0; i < sz; i++)
		for (int j = 0; j < sz; j++)
			rst += a[i][j];
	cout << rst << "\n";
}

void Rst2() {	// 2번 결과 도출
	bool flag[65][65] = { 0, };
	queue <pair<int, int>> q;
	int maxsize = 0;

	for(int i = 0; i < sz; i++)
		for (int j = 0; j < sz; j++) {
			if (!a[i][j] || flag[i][j]) continue;
			int area = 1;
			q.push({ i, j });
			flag[i][j] = 1;

			while (!q.empty()) {
				pair <int, int> cur = q.front(); q.pop();
				for (int d = 0; d < 4; d++) {
					int x = cur.X + dx[d];
					int y = cur.Y + dy[d];

					if (x < 0 || y < 0 || x >= sz || y >= sz || flag[x][y] || !a[x][y]) continue;
					area++;
					q.push({ x,y });
					flag[x][y] = 1;
				}
			}

			maxsize = max(maxsize, area);
		}

	cout << maxsize;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> q;
	sz = pow(2, n);
	for (int i = 0; i < sz; i++)
		for (int j = 0; j < sz; j++)
			cin >> a[i][j];

	while (q--) {
		int l;
		cin >> l;
		FireStorm(l);
	}

	Rst1();
	Rst2();

	return 0;
}
