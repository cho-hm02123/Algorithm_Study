/* https://www.acmicpc.net/problem/21611  마법사 상어와 블리자드
*
* 문제: N x N 격자 (N은 홀수), 최상단 좌측 (1,1), 최하단 우측 (N,N)
*	마법사 상어는 ((N+1)/2, (N+1)/2)에 존재 (가운데).
*	일부 칸과 칸 사이에 벽이 세워져 있음 칸에 적힌 수는 칸의 번호
*	가운데 칸을 제외한 나머지 칸에는 구슬이 들어갈 수 있음.
*	구슬은 1번, 2번, 3번 구슬 존재
*	연속: 같은 번호를 가진 구슬이 번호가 연속하는 칸에 있으면 연속하는 구슬
*	블리자드 시전 위해 방향 d, 거리 s 필요 (d: 상하좌우)
*	1. 상어 기준 d방향으로 거리가 s 이하인 모든 칸에 얼음 파편을 던져 그 칸에 있는 구슬을 모두 파괴
*		>구슬이 파괴되면 그 칸은 빈칸 (벽은 파괴되지 않음)
*	2. 만약 어떤 칸 A의 번호보다 번호가 하나 작은 칸이 빈칸이면, A에 있는 구슬은 해당 빈칸으로 이동
*		> 이는 더 이상 구슬이 이동하지 않을 때 까지 반복
*	3. 4개 이상 연속하는 구슬이 있으면 폭발
*		> 구슬이 폭발해 없어지면 다시 구슬 이동 이는 폭발 안될 때 까지 반복
*	4. 연속하는 구슬은 하나의 그룹
*		> 하나의 그룹은 두 개의 구슬 A, B로 변함
*		> A: 그룹에 들어있는 구슬의 개수
*		> B: 그룹을 이루는 구슬의 번호
*		> 구슬은 다시 그룹의 순서대로 1번 칸 부터 차례로 A, B의 순서로 들어감 (만약 칸 수보다 구슬이 많으면 남은 구슬 소멸)
*
*	마법사 상어가 블리자드를 M번 시전했을 때 1x(폭발한 1번 구슬 개수) + 2x(폭발한 2번 구슬 개수) + 3x(폭발한 3번 구슬 개수) 구하기
*
* 입력: N, M, 격자에 들어있는 구슬 정보 구슬 없으면 0(상어 위치도)
*	마법 방향 d, s
*
* 출력: 1x(폭발한 1번 구슬 개수) + 2x(폭발한 2번 구슬 개수) + 3x(폭발한 3번 구슬 개수)
* 
* 풀이: 미로를 Linear하게 풀어서 생각하면 2, 3을 한번에 해결 가능 > ExplosionBead 참고
*		> 주의 <
*			1. 폭발은 동시에 진행 따라서 stack에 넣어 vector iterator를 관리
*			2. 1칸 1칸 2칸 2칸 3칸 3칸...의 규칙을 따르지만 마지막의 경우 n이 아닌 n-1 칸임
*			3. 얼음 던져서 구슬 없애는건 폭발이 아니므로 폭발 개수에서 제외
*/

#include <iostream>
#include <cmath>
#include <algorithm>
#include <queue>
#include <stack>
#include <vector>
using namespace std;

int n, m, d, s;
int destroy[4];
int a[50][50];
int dx[5] = { 0, -1, 1, 0, 0 };
int dy[5] = { 0, 0, 0, -1, 1 };
int ddx[4] = { 0, 1, 0, -1 };
int ddy[4] = { -1, 0, 1, 0 };
vector <int> v;

bool JudgeRan(int x, int y) {
	if (x < 1 || y < 1 || x > n || y > n) return true;
	return false;
}

void DestroyDS() { // 1.
	int x = (n + 1) / 2;
	int y = (n + 1) / 2;
	for (int i = 0; i < s; i++) {
		x += dx[d];
		y += dy[d];
		if (JudgeRan(x, y)) continue;
		a[x][y] = 0;
	}
}

void CopyArray() { // for 2. ~ 3.
	int x = (n + 1) / 2;
	int y = (n + 1) / 2;
	v.clear();

	for (int i = 0; i < 2 * n - 1; i++) {
		int check = i / 2 + 1;
		int vec = i % 4;
		if (i == 2 * n - 2) check = n-1;
		while (check--) {
			x += ddx[vec];
			y += ddy[vec];

			if (a[x][y] == 0) continue;
			v.push_back(a[x][y]);
		}
	}
	v.push_back(0);
}

void ExplosionBead() { // 2. ~ 3.
	stack <int> q;
	while (1) {
		bool flag = 0;
		int check = v[0];
		int num = 0;
		for (int i = 0; i < v.size(); i++) {
			if (check == v[i]) num++;
			else {
				if (num >= 4) {
					destroy[check] += num;
					q.push(i);
					q.push(i - num);
					flag = 1;
				}
				check = v[i];
				num = 1;
			}
		}
		if (flag == 0) break;
		while (!q.empty()) {
			int st = q.top(); q.pop();
			int en = q.top(); q.pop();
			v.erase(v.begin() + st, v.begin() + en);
		}
	}
}

void GroupBead() { //4.
	queue <int> q;
	int check = v[0];
	int num = 0;
	int x = (n + 1) / 2;
	int y = (n + 1) / 2;

	for (int i = 0; i < v.size(); i++) {
		if (check == v[i]) num++;
		else {
			q.push(num);
			q.push(check);
			check = v[i];
			num = 1;
		}
	}
	for (int i = 0; i < 2 * n - 1; i++) {
		int ch = i / 2 + 1;
		int vec = i % 4;
		if (i == 2 * n - 2) ch = n - 1;
		while (ch--) {
			x += ddx[vec];
			y += ddy[vec];

			if (q.empty()) a[x][y] = 0;
			else {
				a[x][y] = q.front();
				q.pop();
			}
		}
	}
}

void Rst() {
	int rst = 0;
	for (int i = 1; i <= 3; i++)
		rst += i * destroy[i];

	cout << rst;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> a[i][j];

	while (m--) {
		cin >> d >> s;
		DestroyDS();
		CopyArray();
		ExplosionBead();
		GroupBead();
	}


	Rst();

	return 0;
}
