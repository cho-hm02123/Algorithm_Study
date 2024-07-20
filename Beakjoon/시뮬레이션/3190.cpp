/* https://www.acmicpc.net/problem/3190
* 문제 : NxN 보드 위에서 게임, 몇몇 칸에는 사과가 있음
*		 보드 상하좌우 끝엔 벽이 있음
*		 처음 뱀의 길이는 1, 오른쪽을 향하고 있음
*		1. 뱀이 몸 길이를 늘릴 땐 머리를 다음 칸에 위치
*		2. 벽이나 자기 몸에 부딪히면 게임이 끝남
*		3. 이동한 칸에 사과가 있으면 사과는 없어지고 꼬리는 안움직임 > 몸길이가 1 늘어남
*		4. 사과가 없으면 몸 길이를 줄여 꼬리가 위치한 칸 비움 > 몸 길이가 변하지 않는다.
*		 사과 위치와 뱀 이동 경로가 주어질 때 게임이 몇초에 끝나는지
* 
* 입력 : 보드 크기 N, 사과 개수 k
*		 k줄에 걸쳐 사과 위치
*		 뱀의 방향 전환 정보 x, c -> 게임 시작으로 부터 x초가 끝난 후 (왼 : L, 오 : D 방향으로 90도 회전)
* 
* 출력 : 게임이 몇초에 끝나는지
*/

#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int n, k, l, cnt;
int arr[101][101];
int hd; // 0: 위, 1 : 오 , 2 : 아래, 3 : 좌

bool cal(int tm, char c) {
	while (cnt != tm) {
		cnt++;
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	hd = 1;

	cin >> n >> k;
	for (int i = 0; i < k; i++) {
		int x, y;
		cin >> x >> y;
		arr[x][y] = 1;
	}

	cin >> l;
	while (l--) {
		int x; 
		char c;
		cin >> x >> c;

		if (!cal(x, c))
			break;
	}

	cout << cnt;

	return 0;
}
