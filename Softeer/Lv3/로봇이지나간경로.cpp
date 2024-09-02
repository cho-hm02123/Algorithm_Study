/* https://softeer.ai/practice/6275 [HSAT 1회 정기 코딩 인증평가 기출] 로봇이 지나간 경로
* 
* 1h 34m 32s
* 
* 문제: H행 W열의 2차원 격자(1부터 시작), 동(오) 서(왼) 남(하) 북(상) 중 한 방향을 바라볼 수 있음
*	로봇의 이동 제어 명령
*		L: 로봇이 왼쪽으로 90도 회전
*		R: 로봇이 오른쪽으로 90도 회전
*		A: 로봇이 바라보는 방향으로 두칸 전진 > 로봇이 격자 밖으로 나가면 수행 불가
* 
*	로봇이 같은 칸을 두번 이상 방문하지 않도록 로봇이 방문한 모든 칸(출발지 포함)을 지도에 표시
*	해당 표시를 보고 아래 정보를 계산해 주는 프로그램을 개발
*		1. 처음 로봇을 어떤 칸에, 어떤 방향으로 둬야 하는지
*		2. 이후 로봇에 어떤 명형을 어떤 순서로 입력해야 하는지
*	이때 명령의 입력을 최소화 (처음 로봇을 어디에 어느 방향으로 두는지에 따라 달라짐)
* 
*	제약 조건
*		5 <= H, W <= 25
*		A번 이상의 명령을 내려 로봇의 방문 칸 수는 최소 3개 이상
* 
* 입력: H, W
*	격자 정보 (방문했으면 #, 아니면 .)
* 
* 출력: 두 개의 정수 a, b를 공백을 하나 사이에 두고 출력 (처음 로봇 위치)
*	로봇이 바라보는 방향 ( 동: > / 서: < / 남: v / 북: ^)
*	로봇에 내려야 하는 명령어를 공백 없이 출력
* 
* 풀이: 인접한 4군데 중 하나만 #인 곳이 출발지 후보
*	출발지 후보 저장한 후 경로 찾기 한번 들린 곳은 들리면 안되므로 .으로 바꿔주기
*	위 풀이가 가능한 이유는 중복 방문이 안되므로 길이 겹치는 상황은 있을 수 없음
*/

#include <iostream>
#include <cmath>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

struct xyd {
	int x, y, dir;
	string s;
};

const int MAX = 25;
int h, w;
int mm = 0x3f3f3f3f;
int dx[4] = { 0, 1, 0, -1 };	// 동 남 서 북
int dy[4] = { 1, 0, -1, 0 };
int direc[3] = { 0, 1, -1 };	// 그대로, R, L
char arr[MAX + 2][MAX + 2];
xyd ans;
vector <xyd> v;

bool judmap(int x, int y) {
	if (x < 1 || y < 1 || x > h || y > w) return true;
	return false;
}

void stcheck(){
	string a;
	for(int i = 1; i <= h; i++)
		for (int j = 1; j <= w; j++) {
			int cnt = 0;
			int vec = -1;
			if (arr[i][j] == '.') continue;
			for (int k = 0; k < 4; k++) {
				int x = i + dx[k];
				int y = j + dy[k];

				if (judmap(x, y)) continue;
				if (arr[x][y] == '#') {
					cnt++;
					vec = k;
				}
			}
			if (cnt == 1)
				v.push_back({ i, j, vec, a});
		}
}

xyd findrst(int id) {
	xyd thisrst = v[id];

	char cp[MAX + 2][MAX + 2];
	for (int i = 1; i <= h; i++)
		for (int j = 1; j <= w; j++)
			cp[i][j] = arr[i][j];

	queue <xyd> q;
	q.push(v[id]);

	while (!q.empty()) {
		xyd cur = q.front(); q.pop();
		string sum = cur.s;

		for (int i = 0; i < 3; i++) {
			int vec = cur.dir + direc[i];

			if (vec < 0)
				vec = 3;
			else if (vec > 3)
				vec = 0;

			int xx = cur.x + dx[vec];
			int yy = cur.y + dy[vec];
			int x = cur.x + 2 * dx[vec];
			int y = cur.y + 2 * dy[vec];

			if (judmap(x, y) || judmap(xx, yy)) continue;
			if (cp[x][y] == '#' && cp[xx][yy] == '#') {
				if (i == 1)
					sum += string(1, 'R');
				else if (i == 2)
					sum += string(1, 'L');

				sum += string(1, 'A');

				cp[cur.x][cur.y] = '.';
				cp[xx][yy] = '.';
				q.push({ x, y, vec, sum });
			}
		}
		if (q.empty())
			thisrst.s = sum;
	}

	return thisrst;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> h >> w;
	for (int i = 1; i <= h; i++)
		for (int j = 1; j <= w; j++)
			cin >> arr[i][j];

	stcheck();
	for (int i = 0; i < v.size(); i++) {
		xyd bi = findrst(i);
		if (bi.s.size() != 0 && bi.s.size() < mm) {
			mm = bi.s.size();
			ans = bi;
		}
	}

	cout << ans.x << " " << ans.y << "\n";
	if (ans.dir == 0)
		cout << ">\n";
	else if (ans.dir == 1)
		cout << "v\n";
	else if (ans.dir == 2)
		cout << "<\n";
	else
		cout << "^\n";
	cout << ans.s;

	return 0;
}