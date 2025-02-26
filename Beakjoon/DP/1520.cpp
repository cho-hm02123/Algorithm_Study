/* https://www.acmicpc.net/problem/1520 내리막 길
* 
* 문제: 해당 칸의 수는 높이, 각 지점 사이의 이동은 상하좌우, (1,1)에서 (N,M)으로 가야함
*	이때 내리막 길로 만 가는 경우의 수
* 
* 입력: N, M, 각 지점의 높이
* 
* 출력: 경우의 수
*/

#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int N, M;
int height[501][501];
int arr[501][501];
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

int FindPath(int r, int c) {
	if (arr[r][c] != -1) return arr[r][c]; 
	if (r == N && c == M) return 1;

	int &len = arr[r][c];
	len = 0;

	for (int i = 0; i < 4; i++) {
		int x = r + dx[i];
		int y = c + dy[i];

		if (x < 1 || y < 1 || x > N || y > M) continue;
		if (height[r][c] > height[x][y]) len += FindPath(x, y);
	}

	return len;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++) {
			cin >> height[i][j];
			arr[i][j] = -1;
		}
	
	cout << FindPath(1, 1);

	return 0;
}
