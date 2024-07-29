/* https://www.acmicpc.net/problem/15684
* 
* 
* 문제: N개의 세로선, M개의 가로선
*	인접한 세로선 사이에는 가로선을 놓을 수 있음
*	세로선마다 가로선을 놓을 수 있는 위치의 개수는 H
*	가로선은 연속하거나 접하면 안됨
*	사다리에 가로선을 추가해서 i번이 i번으로 나오게 할 때 추가하는 가로선의 최솟값
* 
* 입력: N, M, H
*	M개의 가로선 정보 a,b -> b번 세로선과 b+1번 세로선을 a번 점선으로 연결
* 
* 출력: 가로선 최소 개수 (3보다 크거나 불가능하면 -1 출력)
* 
* 풀이: arr[a][b+1]을 true로 두지 말것
*	bt에서 i가 다음 행으로 넘어갈 때 y를 1로 초기화해서 1부터 볼 것
*/

#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int n, m, h;
int mm = 4;
bool arr[31][11];

void cal(int k) {
	for (int i = 1; i <= m; i++) {
		int x = 1;
		int y = i;
		while (x <= n) {
			if (arr[x][y])
				y++;
			else if (y > 1 && arr[x][y - 1])
				y--;
			x++;
		}
		if (y != i) return;
	}
	mm = min(mm, k);
}

void bt (int k, int x, int y) {
	if (k >= mm) return;
	cal(k);
	if (k == 3) return;

	for (int i = x; i <= n; i++, y = 1) {
		for (int j = y; j < m; j++) {
			if (arr[i][j] || arr[i][j + 1] || (j > 1 && arr[i][j - 1]))continue;

			arr[i][j] = 1;
			bt(k + 1, i, j+2);
			arr[i][j] = 0;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> m >> h >> n;


	if (h == 0) {
		cout << "0";
		return 0;
	}
	
	while (h--) {
		int a, b;
		cin >> a >> b;
		arr[a][b] = 1;
	}

	bt(0, 1, 1);
	if (mm == 4)
		cout << "-1";
	else
		cout << mm;

	return 0;
}
