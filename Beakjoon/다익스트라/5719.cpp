/* https://www.acmicpc.net/problem/5719 거의 최단 경로
* 
* 문제: 거의 최단경로란 최단 경로에 포함되지 않는 도로로만 이루어진 경로 중 가장 짧은 것
*	거의 최단 경로는 여러개 있을 수 있고 없을 수도 있다.
* 
* 입력: 장소의 수 N, 도로의 수 M
*	시작점 S, 도착점 D
*	M개의 u, v, p (u->v 도로 길이 p)
*	TC 마지막은 0 0 입력
* 
* 출력: 각 테스트 케이스에 대해 거의 최단 경로의 길이를 출력 없으면 -1
* 
* 풀이: 최단경로에 포함된 도로 인지 구분하기 위해 도로에 고유 번호를 붙여 저장
*	최단 경로를 구한 후 도착지에서 출발지로 역행하며 포함 도로를 찾기 위해 역방향 벡터를 생성
*	현재 len에서 다음 도로 길이를 뺀 것이 다음 도로 len과 동일하다면 path에 저장
*/

#include <iostream>
#include <cmath>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

typedef struct {
	int l, v;
} lv;

typedef struct {
	int l, v, idx;
} lvid;

const int NMAX = 500;
const int MMAX = 10000;
const int INF = 0x3f3f3f3f;
int n, m, s, d;
int mn;
int len[NMAX + 2];
bool path[MMAX + 2];
vector <lvid> arr[NMAX + 2];
vector<lvid> rev[NMAX + 2];
queue <int> q;

class cmp {
public:
	bool operator() (lv a, lv b) {
		if (a.l == b.l) return a.v > b.v;
		return a.l > b.l;
	}
};	priority_queue <lv, vector<lv>, cmp> pq;

void setup() {
	for (int i = 0; i < n; i++) {
		arr[i].clear();
		rev[i].clear();
	}
	fill(path, path + m, false);	// +n이 아닌 +m임을 주의

	for (int i = 0; i < m; i++) {
		int u, v, p;
		cin >> u >> v >> p;
		arr[u].push_back({ p, v, i });
		rev[v].push_back({ p, u, i });
	}
}

void dijk() {
	fill(len, len + n, INF);
	len[s] = 0;
	pq.push({ 0, s });

	while (!pq.empty()) {
		lv cur = pq.top(); pq.pop();

		if (len[cur.v] != cur.l) continue;
		for (auto nxt : arr[cur.v]) {
			if (path[nxt.idx]) continue;
			nxt.l += cur.l;
			if (len[nxt.v] <= nxt.l) continue;
			len[nxt.v] = nxt.l;
			pq.push({ nxt.l, nxt.v });
		}
	}
}

void findpath() {
	q.push(d);

	while (!q.empty()) {
		int cur = q.front(); q.pop();

		for (auto nxt : rev[cur]) {
			if (path[nxt.idx]) continue;

			int distance = len[cur] - nxt.l;
			if (distance == len[nxt.v]) {
				path[nxt.idx] = true;
				q.push(nxt.v);
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	while (1) {
		cin >> n >> m;
		if (!n && !m) break;
		cin >> s >> d;
		setup();
		dijk();
		findpath();
		dijk();

		if (len[d] != INF) cout << len[d] << "\n";
		else cout << "-1\n";
	}

	return 0;
}
