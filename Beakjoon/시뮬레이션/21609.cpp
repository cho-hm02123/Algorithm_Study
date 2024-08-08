/* https://www.acmicpc.net/problem/21609
*
* 2h 03m 09s 
*  시간은 조금 걸렸지만 한번에 맞춤 이제 슬슬 한큐에 끝내는걸 연습해야 할 때
*
* 문제: NxN 격자에서 시작, 초기 격자의 모든 칸에 블록이 하나씩 있음 -> 블록은 검, 무지개, 일반
*	일반은 M가지 색이고 색은 M이하 자연수로 표현, 검은색은 -1, 무지개는 0
*
*	그룹
*		블록 그룹은 련결된 블록의 집합, 적어도 하나의 일반 블록을 포함하면서 색이 모두 같아야 함.
*		검은색은 포함되며 안됨, 무지개는 있어도 없어도 상관 없음
*		블록 개수는 2이상
*
*	기준 블록
*		무지개 블록이 아닌 블록 중 x가 가장 작은 블록 > 그런게 여러개면 y가 가장 작은 블록
*
*	게임 진행
*		1. 크기가 가장 큰 블록 그룹 찾기
*			1-1. 그런 블록이 여러개면 무지개 블록이 많은 그룹
*			1-2. 그것도 많으면 기준 블록의 x가 가장 큰 것
*			1-3. 그것도 여러개면 y가 가장 큰 것
*		2. 1에서 찾은 브록 그룹의 모든 블록을 제거, 이때 블록수^2점을 획득
*		3. 중력작용 -> 검은 블록 제외 모든 블록이 아래로 이동 > 내려갈 수 있을 때 까지
*		4. 90도 반시계 회전
*		5. 다시 줄력 작용
*
* 입력: 격자 크기 N, 색상 개수 M
*	격자 정보
*
* 출력: 점수 합
* 
* 풀이: 그냥 하라는대로 하면 됨
*	주의할 점은 그룹 크기가 2 이상이어야 하는 것을 까먹지 않기 + 중력 작용 시 빈칸이 아래 하나만 있단 보장 없음 (이건 저번에 한번 틀려봐서 바로 에러처리 할 수 있었음)
*/

#include <iostream>
#include <cmath>
#include <algorithm>
#include <queue>
using namespace std;

#define X first
#define Y second

int n, m, score;
int arr[21][21];
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

bool comp(vector <pair <int, int>> a, vector <pair<int, int>> b) { // b가 선택이면 true
	int mua = 0;
	int mub = 0;

	for (int i = 0; i < a.size(); i++)
		if (arr[a[i].X][a[i].Y] == -1) mua++;
	for (int i = 0; i < b.size(); i++)
		if (arr[b[i].X][b[i].Y] == -1) mub++;

	if (mua != mub) return mua < mub;
	if (a[0].X != b[0].X) return a[0].X < b[0].X;
	return a[0].Y < b[0].Y;
}

void gra() {
	for (int i = n - 1; i >= 1; i--)
		for (int j = 1; j <= n; j++) {
			if (arr[i][j] == -2) continue;
			if (arr[i + 1][j] == 0) {
				int x = i + 1;
				while (!arr[x][j]) {
					x++;
					if (x > n) break;
				}
				arr[x - 1][j] = arr[i][j];
				arr[i][j] = 0;
			}
		}
}

void ccw90() {
	int car[21][21] = { 0, };

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			car[n - j + 1][i] = arr[i][j];

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			arr[i][j] = car[i][j];
}

bool fset() { // 그룹 찾기
	bool flag[21][21] = { 0, };
	vector <pair <int, int>> v[400];
	int cnt = 0;

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) {
			if (flag[i][j] || arr[i][j] <= 0) continue;

			queue <pair<int, int>> q;
			bool visited[21][21] = { 0, };
			q.push({ i,j });
			v[cnt].push_back({ i,j }); // 0번 인덱스가 무조건 기준 블록
			flag[i][j] = 1;
			visited[i][j] = 1;
			int col = arr[i][j];

			while (!q.empty()) {
				pair<int, int> cur = q.front(); q.pop();

				for (int h = 0; h < 4; h++) {
					int x = cur.X + dx[h];
					int y = cur.Y + dy[h];

					if (x < 1 || y < 1 || x > n || y > n) continue;
					if (arr[x][y] == -2 || arr[x][y] == 0 || visited[x][y]) continue;
					if (arr[x][y] > 0 && arr[x][y] != col) continue;

					visited[x][y] = 1;
					if (arr[x][y] == col)
						flag[x][y] = 1;

					q.push({ x,y });
					v[cnt].push_back({ x,y });
				}
			}
			cnt++;
		}


	if (cnt == 0) return false;

	auto mm = v[0].size();
	int k = 0;
	for (int i = 1; i < cnt; i++) { // 지울거 정함
		auto sz = v[i].size();
		if (sz > mm) {
			k = i;
			mm = sz;
		}
		else if (sz == mm) {
			if (comp(v[k], v[i]))
				k = i;
		}
	}

	if (v[k].size() == 1) return false;

	score += pow(v[k].size(), 2);
	for (int i = 0; i < v[k].size(); i++)
		arr[v[k][i].X][v[k][i].Y] = 0;

	gra();
	ccw90();
	gra();
	return true;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 0)
				arr[i][j] = -1;
			else if (arr[i][j] == -1)
				arr[i][j] = -2;
			// -2: 검, -1: 무지개, 0 빈거, 0이상은 일반
		}

	while (1)
		if (!fset()) break;

	cout << score;

	return 0;
}
