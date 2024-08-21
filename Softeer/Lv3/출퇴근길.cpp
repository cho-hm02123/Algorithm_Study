/* https://softeer.ai/practice/6248 [HSAT 6회 정기 코딩 인증평가 기출] 출퇴근길
* 
* 1h 23m 28s
* 
* 문제: 출퇴근길을 단방향 그래프로 나타낼 수 있음 n개의 정점, m개의 간선
*	S에서 T로 가는 경로와 T에서 S로 가는 경로에 모두 포함되는 정점의 개수
* 
* 입력: N, M
*	M개의 간선 정점 x, y (x -> y)
*	동환이 집 S, 회사 T
* 
* 출력: 출퇴근길에 겹치는 정점의 개수
* 
* 풀이: 출근 시 들리는 모든 노드 체크, 퇴근 시 들리는 모든 노드 체크 이때 들리기만 하고 목적지에 도달하지 않는 것을 거르기 위해 역방향 벡터를 추가해서 검사
* 
* 반례
* 4 5		
* 3 2
* 3 1
* 1 2
* 1 4
* 4 3
* 1 3
*/

#include <iostream>
#include <cmath>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

# define MAX 100001

int n, m, st, en, ans;
bool flag1[MAX];
bool flag2[MAX];
bool flag3[MAX];
bool flag4[MAX];
vector <int> v[MAX];
vector <int> rv[MAX];

void dfs (int cur, bool flag[], vector <int> cv[]) {
	if (flag[cur]) return;

	flag[cur] = 1;
	for (int nxt : cv[cur])
		dfs(nxt, flag, cv);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;

		v[x].push_back(y);
		rv[y].push_back(x);
	}
	cin >> st >> en;

	flag1[en] = 1;
	flag2[st] = 1;

	dfs(st, flag1, v);
	dfs(en, flag2, v);
	dfs(st, flag3, rv);
	dfs(en, flag4, rv);

	for (int i = 1; i <= n; i++)
		if (flag1[i] && flag2[i] && flag3[i] && flag4[i])
			ans++;

	cout << ans-2; // st, en 빼주기
	return 0;
}