/* 왕실의 기사 대결
*
* 문제: L x L 체스판에서 대결 (1,1) 이 최저점
*	각 칸은 빈칸, 함정, 벽으로 구성 체스판 밖도 벽으로 간주
*	왕실 기사는 자신의 마력으로 상대를 밀쳐낼 수 있음.
*	각 기사의 초기 위치는 (r,c)로 주어지고 이는 좌측이며 h(높이) x w(너비) 크기의 직사각형 형태
*	각 기사의 체력은 k로 주어짐
*
*	1. 기사의 이동
*		기사는 상하좌우 중 하나로 한 칸 이동 가능 이때 이동하려는 위치에 다른 기사가 있다면 그 기사도 함께 연쇄적으로 한칸 밀려남
*		그 옆에 또 기사가 있으면 그 기사도 밀려남
*		밀려나는(이동하는) 방향의 끝에 벽이 있다면 모든 기사는 이동할 수 없음
*		판에 없는 기사에게 명령을 내리면 반응 없음
*	2. 대결 데미지
*		명령을 받은 기사가 다른 기사를 밀치면 밀려난 기사는 피해를 입음
*		이때 각 기사들은 해당 기사가 이동한 곳에서 w x h 직사각형 내에 놓여있는 함정의 수 만큼 피해를 입음
*		체력 이상의 데미지를 입는 경우 기사는 체스판에서 사라짐
*		단, 명령을 받은 기사는 피해를 받지 않으며 기사들은 모두 밀린 이후 데미지를 받음
*
*	Q번에 걸쳐 명령이 주어졌을 때 기사들이 총 받은 데이지의 합을 출력
*
*  입력: L, N, Q
*	체스판 정보 (0: 빈칸, 1: 함정, 2: 벽)
*	N개의 초기 기사들의 정보 (r, c, h, w, k) 순
*	Q개의 명령 (i, d) i번 기사에게 d 방향으로 한칸 이동하라 (d: 0, 1, 2, 3 이며 상우하좌)
*
*  출력: 생존한 기사들이 받은 총 데미지의 합
*/

#include <iostream>
#include <algorithm>
#include <cmath>
#include <queue>
#include <vector>
using namespace std;

struct st {
	int r, c, h, w, k;
};

int l, n, q, rst, idx, d;
int dem[31];		// 데미지 저장
int arr[41][41];	// 덫, 벽 저장
int gi[41][41];		// 기사 저장
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };
vector <int> v;		// 밀려날 기사 저장
st info[31];		// 기사 상태 저장

void DemNight() {
	for (int i = 0; i < v.size(); i++) {
		int x = info[v[i]].r;
		int y = info[v[i]].c;

		for (int ii = x; ii < x + info[v[i]].h; ii++)
			for (int jj = y; jj < y + info[v[i]].w; jj++)
				if (arr[ii][jj] == 1) dem[v[i]]++;		// 밀려난 기사가 밟은 덫 개수
		
		if (info[v[i]].k <= dem[v[i]]) {// 기사 체력과 밟은 덫 개수 비교
			info[v[i]].r = 0;			// 기사 체력이 떨어지면 판 밖으로
			dem[v[i]] = 0;				// 기사 체력이 떨어지면 받은 데미지도 리셋 나중에 결과 출력 때 배열 다 더하기 위함
		}
	}

	for (int i = 1; i <= l; i++)
		for (int j = 1; j <= l; j++)
			gi[i][j] = 0;				// 기사 위치 초기화

	for (int i = 1; i <= n; i++) {		// 기사 위치 재 배치
		if (info[i].r == 0) continue;

		int x = info[i].r;
		int y = info[i].c;

		for (int ii = x; ii < x + info[i].h; ii++)
			for (int jj = y; jj < y + info[i].w; jj++)
				gi[ii][jj] = i;
	}
}

bool MoveNight() {
	bool check[31] = { 0, };
	bool flag = false;

	queue <int> q1;
	q1.push(idx);

	while (!q1.empty()) {	// 밀려나는 기사 찾기
		int cur = q1.front(); q1.pop();
		int x = info[cur].r;
		int y = info[cur].c;

		if (d == 0) {  // 위로
			x += dx[d];
			for (int i = y; i < y + info[cur].w; i++) {
				if (x < 1 || i < 1 || x > l || i > l || arr[x][i] == 2) {	// 벽일 때
					flag = true; // 밀려나지 못하므로 flag 켜주고 아래에서 false를 리턴 > main의 while 속 if를 통해 기사의 이동이 이뤄지지 않도록 함
					break;
				}
				if (gi[x][i] > 0 && !check[gi[x][i]]) {
					q1.push(gi[x][i]);
					v.push_back(gi[x][i]);
					check[gi[x][i]] = 1;		// 밀려난 기사를 중복하여 저장하지 않도록 체크
				}
			}
		}

		if (d == 1) {  // 우로
			y += info[cur].w;
			for (int i = x; i < x + info[cur].h; i++) {
				if (y < 1 || i < 1 || y > l || i > l || arr[i][y] == 2) {
					flag = true;
					break;
				}
				if (gi[i][y] > 0 && !check[gi[i][y]]) {
					q1.push(gi[i][y]);
					v.push_back(gi[i][y]);
					check[gi[i][y]] = 1;
				}
			}
		}

		if (d == 2) {  // 하로
			x += info[cur].h;
			for (int i = y; i < y + info[cur].w; i++) {
				if (x < 1 || i < 1 || x > l || i > l || arr[x][i] == 2) {
					flag = true;
					break;
				}
				if (gi[x][i] > 0 && !check[gi[x][i]]) {
					q1.push(gi[x][i]);
					v.push_back(gi[x][i]);
					check[gi[x][i]] = 1;
				}
			}
		}

		if (d == 3) {  // 좌로
			y += dy[d];
			for (int i = x; i < x + info[cur].h; i++) {
				if (y < 1 || i < 1 || y > l || i > l || arr[i][y] == 2) {
					flag = true;
					break;
				}
				if (gi[i][y] > 0 && !check[gi[i][y]]) {
					q1.push(gi[i][y]);
					v.push_back(gi[i][y]);
					check[gi[i][y]] = 1;
				}
			}
		}
	}

	if (flag) return false;

	for (int i = 0; i < v.size(); i++) {
		int cur = v[i];
		info[cur].r += dx[d];
		info[cur].c += dy[d];
	}
	info[idx].r += dx[d];
	info[idx].c += dy[d];
	return true;
}

int main() {
	ios_base::sync_with_stdio();
	cin.tie(0);
	cout.tie(0);

	cin >> l >> n >> q;
	for (int i = 1; i <= l; i++)
		for (int j = 1; j <= l; j++)
			cin >> arr[i][j];

	for (int i = 1; i <= n; i++) {
		cin >> info[i].r >> info[i].c >> info[i].h >> info[i].w >> info[i].k;

		for (int j = info[i].r; j < info[i].r + info[i].h; j++)
			for (int jj = info[i].c; jj < info[i].c + info[i].w; jj++)
				gi[j][jj] = i;
	}

	while (q--) {
		cin >> idx >> d;
		if (info[idx].r == 0) continue;
		v.clear();
		if (MoveNight())
			DemNight();
	}

	for (int i = 1; i <= n; i++)
		rst += dem[i];

	cout << rst;
	return 0;
}
