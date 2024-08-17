/* https://www.acmicpc.net/problem/14267 회사 문화 1
*
*
* 문제: 상사가 직속 부하를 칭찬하면 그 부하가 부하의 직속 부하를 연쇄적으로 칭찬
*	칭찬에는 칭찬의 정도를 의미하는 수치가 있음
*	수치 또한 내리 동일
*	직속 상사와 직속 부하관계가 주어지고, 칭찬에 대한 정보가 주어졌을 때 각자 얼마의 칭찬을 받았는지
*
* 입력:회사의 직원 수 n, 최소 칭찬 횟수 m,
*	직원 n명의 상사 번호, 직속 상사의 번호는 자신의 번호보다 작으며 최종적으로 1은 사장
*	m줄은 직속 상사로 부터 칭찬받은 직원 번호 i, 칭찬 수치 w
*
* 출력: 1번부터 n번 직원까지 칭찬 정도
*/

#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

int n, m;
int prex[100001]; // indx의 부모 저장
int good[100001];
vector <int> v[100001];

void dfs(int cur) {
	if (prex[cur] != -1)
		good[cur] += good[prex[cur]];	// 부모가 받은 칭찬 점수 물려 받음
	for (int nxt : v[cur])
		dfs(nxt);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> prex[i];
		if (prex[i] == -1) continue;
		v[prex[i]].push_back(i);
	}

	while (m--) {
		int i, w;
		cin >> i >> w;
		good[i] += w;
	}

	dfs(1);

	for (int i = 1; i <= n; i++)
		cout << good[i] << " ";

	return 0;
}
