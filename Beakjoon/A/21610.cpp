/* https://www.acmicpc.net/problem/21610  마법사 상어와 비바라기
* 
* 문제: N x N 격자, 격자의 각 칸에는 바구니가 있음. 바구니에 저장할 수 있는 물의 양 제한은 없음
*	격자의 가장 왼쪽 윗 칸은 (1, 1), 가장 오른쪽 아래는 (N, N)
*	비바라기를 시전하면 (N, 1), (N, 2), (N-1, 1), (N-2, 2)에 비구름이 생김
*	구름에 이동을 M번 명령, i번째 이동 명령은 방향 d와 거리 s로 이루어짐.
*		방향은 1번 부터 차례로 좌, 좌상, 상, 우상, 우, 우하, 하, 좌하
*	명령 시 순서
*		1. 모든 구름이 d 방향으로 s칸 이동
*		2. 각 구름에서 비가 내려 구름이 있는 칸 바구니에 물 1 증가
*		3. 구름 사라짐
*		4. 2번에서 물이 증가한 칸 (r,c)에 물복사 버그 쓰면 대각선 방향으로 거리가 1인 칸에 물이 있는 바구니 수 만큼 (r,c)에 있는 바구니의 물 양 증가
*		5. 바구니에 저장된 물 양이 2 이상인 모든 칸에 구름이 생기고 물 양이 2 줄어듬(3에서 구름 생긴 칸 제외)
*	M번 이동 후 바구니에 들어있는 물의 양 합
* 
* 입력: N, M, a[r][c], M개의 d, s
* 
* 출력: M번의 이동 후 바구니에 들어있는 물의 총 합
* 
* 풀이: 비바라기는 한번만 시전.
*	구름의 이동은 격자를 초과해도 이어진거 처럼.
*	2에서 구름 소멸된 곳은 5에서 2 줄어들지 않음.
*	5에서 생긴 구름은 다음에 또 씀.
*	구름은 겹칠 수 있고 겹치면 중복해서 하나로 보는게 아니라 따로 봄.
*/

#include <iostream>
#include <cmath>
#include <algorithm>
#include <queue>
using namespace std;

#define X first
#define Y second

int n, m, d, s;
int a[51][51];
int dx[9] = { 0, 0, -1, -1, -1, 0, 1, 1, 1 };
int dy[9] = { 0, -1, -1, 0, 1, 1, 1, 0, -1 };
bool flag[51][51];
queue <pair<int, int>> q;  // 구름 저장
queue <pair<int, int>> qq; // 복사 구름 저장

void SetFlag() {
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			flag[i][j] = 0;
}

void MoveCloudToExt() {	// 1. ~ 3.
	while(!q.empty()) {
		pair <int, int> cur = q.front();
		int x = cur.X + dx[d] * s % n;		// 1.
		int y = cur.Y + dy[d] * s % n;

		x = (x + n) % n;
		y = (y + n) % n;

		if (x == 0)
			x = n;
		if (y == 0)
			y = n;

		flag[x][y] = 1;					// for 5.
		qq.push({ x,y });				// for 4.
		a[x][y]++;						// 2.
		q.pop();						// 3.
	}
}

void CopyWater() {	// 4.
	while (!qq.empty()) {
		pair<int, int> cur = qq.front(); qq.pop();
		int check = 0;

		for (int i = 1; i <= 4; i++) {
			int x = cur.X + dx[i * 2];
			int y = cur.Y + dy[i * 2];

			if (x < 1 || y < 1 || x > n || y > n) continue;
			if (a[x][y]) check++;
		}
		a[cur.X][cur.Y] += check;
	}
}

void LastCloud() {	// 5.
	for(int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) {
			if (flag[i][j]) continue;
			if (a[i][j] >= 2) {
				a[i][j] -= 2;
				q.push({ i,j });
			}
		}
}

void Rst() {
	int rst = 0;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			rst += a[i][j];

	cout << rst;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	q.push({ n, 1 });
	q.push({ n, 2 });
	q.push({ n-1, 1 });
	q.push({ n-1, 2 });

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> a[i][j];

	while (m--) {
		cin >> d >> s;
		SetFlag();
		MoveCloudToExt();
		CopyWater();
		LastCloud();
	}

	Rst();

	return 0;
}
