/* [HSAT 7회 정기 코딩 인증평가 기출] 순서대로 방문하기
* 
* 문제: 차량이 이동 가능한 경우의 수 찾기
*	NxN 격자 0은 빈 공간 1은 벽
*	격자 내에서 m개의 지점을 순서대로 방문 이동은 상하좌우 한번 지나간 곳은 다시 지나갈 수 없음
*	
* 입력: N, M
*	격자의 상태
*	m개의 칸
* 
* 출력: m개의 지점을 순서대로 방문할 수 있는 서로 다른 방법의 수
* 
* 풀이: dfs 사용, flag가 각 경우마다 다르므로 지역변수로 값을 복사해서 넘겨주는 방법 사용
*	도착한 좌표가 최종 목적지와 동일하더라도 k가 m+1을 만족하지 않으면 중간에 경유지를 들리지 않은 것 이므로 이를 활용
*/

#include <iostream>
#include <cmath>
#include <algorithm>
#include <queue>
using namespace std;

struct pointxy {
	int x, y;
};

int n, m, cnt;
int arr[5][5];
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };
pointxy p[20];

void dfs(pointxy a, bool cp[5][5], int k) {
	bool flag[5][5];
	copy(&cp[0][0], &cp[0][0] + 25, &flag[0][0]);
	if (flag[a.x][a.y]) return;
	if (k == m + 1 && a.x == p[k-1].x && a.y == p[k-1].y) {
		cnt++;
		return;
	}

	flag[a.x][a.y] = 1;

	for (int i = 0; i < 4; i++) {
		pointxy xy;
		xy.x = a.x + dx[i];
		xy.y = a.y + dy[i];

		if (xy.x < 1 || xy.y < 1 || xy.x > n || xy.y > n) continue;
		if (flag[xy.x][xy.y] || arr[xy.x][xy.y]) continue;
		if (xy.x == p[k].x && xy.y == p[k].y)
			dfs(xy, flag, k + 1);
		else
			dfs(xy, flag, k);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> arr[i][j];

	for (int i = 1; i <= m; i++)
		cin >> p[i].x >> p[i].y;

	bool flag[5][5] = { 0, };
	dfs(p[1], flag, 2);

	cout << cnt;

	return 0;
}
