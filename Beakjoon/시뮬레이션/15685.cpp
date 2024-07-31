/* https://www.acmicpc.net/problem/15685
* 
* 문제: x축이 가로 방향, y축이 세로 방향
*		시작점(0,0)
*		0세대: (0,0), (1,0) - 모양
*		1세대: (0,0), (1,0), (1,-1) _ㅣ모양 -> 0세대 끝점 기준으로 시계 방향으로 90도 회전 후 끝점에 붙인 것 - 끝 점 == 시작점 기준 가장 먼 거리에 있는 점
*		2세대: (0,0), (1,0), (1,-1), (0,-1), (0,-2), (-1, -2) .... 
*		크기가 100x100인 격자 위에 드래곤 커브가 n개 있을 때 크기가 1x1인 정사각형의 네 꼭짓점이 모두 드래곤 커브의 일부인 정사각형의 개수를 구해라
* 
* 입력: 드래곤커브의 개수 n
*		드래곤커브의 정보 x,y,d,g -> x, y (시작점), d (시작 방향), g(세대) 이때 드래곤 커브는 겹칠 수 있음
*		방향은 0 > x좌표가 증가하는 방향 / 1 > y좌표가 감소하는 방향 / 2 > x 좌표가 감소하는 방향 / 3 > y좌표가 증가하는 방향 
* 
* 출력: 1x1인 정사각형의 네 꼭짓점이 모두 드래곤 커브의 일부인 정사각형의 개수
* 
* 풀이: 90도 회전이라고 무조건 배열 돌리지 말고 한번 경로를 그려보고 규칙성을 찾을 것
*/

#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

int n, x, y, d, g;
bool flag[101][101];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 1; i < n + 1; i++) {
		cin >> x >> y >> d >> g;

		flag[x][y] = 1;
		vector<int> v;
		v.push_back(d);

		while (g--) {
			int sz = v.size();

			for (int i = sz - 1; i >= 0; i--) {
				int dd = v[i];
				dd++;
				if (dd == 4)
					dd = 0;
				v.push_back(dd);
			}
		}

		for (int i = 0; i < v.size(); i++) {
			int xx = x;
			int yy = y;
			if (v[i] == 0)
				xx++;
			else if (v[i] == 1)
				yy--;
			else if (v[i] == 2)
				xx--;
			else if (v[i] == 3)
				yy++;

			if (xx < 0 || yy < 0 || xx > 100 || yy > 100) continue;

			x = xx;
			y = yy;
			flag[x][y] = 1;
		}
	}

	int cnt = 0;

	for (int i = 0; i < 100; i++)
		for (int j = 0; j < 100; j++)
			if (flag[i][j] && flag[i + 1][j] && flag[i][j + 1] && flag[i + 1][j + 1]) cnt++;

	cout << cnt;

	return 0;
}
