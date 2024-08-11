/* https://www.acmicpc.net/problem/20056 마법사 상어와 파이어볼
*
* 3h 58m 55s 이상한데 집착하다 시간 만수르됨
*
* 문제: NxN 격자에 파이어볼 M개 발사 -> 처음에 파이어볼은 각자 위치에서 이동을 대기하고있음 (위치rc, 질량m, 방향d, 속력s) (좌상단 (1,1))
*	1행은 n행과 연결되어있고, 1열은 n열과 연결되어있음
*	인접한 8방향으로 이동 가능(0-상, 1-우상, 2-우, 3-우하, 4-하, 5-좌하, 6-좌, 7-좌상)
*
*	모든 파이어 볼에 이동 명령시
*		1. 모든 파이어볼이 자신의 방향 d로 속력 s 칸 만큼 움직임
*		2. 이동이 모두 끝난 뒤 2개 이상의 파이어볼이 있는 곳에서 다음과 같은 일이 일어남
*			2-1. 같은 칸에 있는 파이어볼은 하나로 합쳐짐
*			2-2. 파이어볼은 4개의 파이어볼로 나뉨
*			2-3. 나누어진 파이어볼의 질량, 속력, 방향은 다음과 같음
*				2-3-1. 질량: 합쳐진 질량 / 5
*				2-3-2. 속력: 합쳐진 속력의 합 / 합쳐진 파이어볼의 개수
*				2-3-3. 합쳐진 파이어볼의 방향이 모두 홀수이거나 짝수면 방향은 0, 2, 4, 6 / 그렇지 않으면 1, 3, 5, 7
*		4. 질량이 0인 파이어볼은 소멸
*
*	마법사 상어가 k번 명령을 한 후  남아있는 파이어 볼의 질량의 합
*
* 입력: n, m, k
*	m개의 파이어볼 정보 (r,c,m,s,d)
*
* 출력: k번 이동 병령 후 남아있는 파이어볼 질량의 합
* 
* 풀이: 두개의 벡터선언 현재와 다음 파이어볼을 저장
*	s가 n을 넘어가 배열의 인덱스가 이상하게 계산되는 경우가 있어 s%n을 통해 필터링해줌
*/

#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

struct fb {
	int x, y, m, s, d, idx;
};

int n, m, k, ans;
int dx[8] = { -1, -1, 0, 1, 1, 1, 0, -1 };
int dy[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };
int direction[2][4] = { {0, 2, 4, 6}, {1, 3, 5, 7} };
vector <fb> v;
vector <fb> next_v;

bool cmp(fb a, fb b){
	if (a.x != b.x) return a.x < b.x;
	if (a.y != b.y) return a.y < b.y;
	return a.idx < b.idx;
}

void MultiFire() {
	sort(next_v.begin(), next_v.end(), cmp);

	for (int i = 0; i < next_v.size(); i++) {
		int x = next_v[i].x;
		int y = next_v[i].y;
		int msum = next_v[i].m;
		int ssum = next_v[i].s;
		int oddnum = 0;
		int evennum = 0;
		int cnt = 1;
		int dir = 0;

		if (next_v[i].d % 2 == 0)
			evennum++;
		else
			oddnum++;

		for (int j = i + 1; j < next_v.size(); j++) {
			if (next_v[j].x != x || next_v[j].y != y) break;

			msum += next_v[j].m;
			ssum += next_v[j].s;
			if (next_v[j].d % 2 == 0)
				evennum++;
			else
				oddnum++;
			cnt++;
		}

		i += (cnt-1);
		msum /= 5;
		ssum /= cnt;

		if (cnt > 1 && msum !=0) {
			if (evennum == cnt || oddnum == cnt)
				dir = 0;
			else
				dir = 1;

			for (int h = 0; h < 4; h++) {
				fb multimoverst;
				multimoverst.x = x;
				multimoverst.y = y;
				multimoverst.m = msum;
				multimoverst.s = ssum;
				multimoverst.d = direction[dir][h];
				v.push_back(multimoverst);
			}
		}

		else if(cnt == 1)
			v.push_back(next_v[i]);
	}
	next_v.clear();
}

void MoveFire() {
	for (int i = 0; i < v.size(); i++) {
		fb nextfire = v[i];
		int recovervel = v[i].s % n;	// s가 n보다 커지면서 - 나오고 인덱스 이상해져서 %n 을 통해 필터링 함
		nextfire.x = (v[i].x + dx[v[i].d] * recovervel + n - 1) % n + 1;
		nextfire.y = (v[i].y + dy[v[i].d] * recovervel + n - 1) % n + 1;
		nextfire.idx = i;
		next_v.push_back(nextfire);
	}
	v.clear();
	MultiFire();
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m >> k;
	for (int i = 0; i < m; i++) {
		fb a;
		cin >> a.x >> a.y >> a.m >> a.s >> a.d;
		v.push_back(a);
	}

	while (k--) 
		MoveFire();

	for (int i = 0; i < v.size(); i++)
		ans += v[i].m;

	cout << ans;

	return 0;
}
