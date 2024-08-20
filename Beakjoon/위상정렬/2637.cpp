/* https://www.acmicpc.net/problem/2637 장난감 조립
* 
* 문제: 장난감을 조립하는데 기본 부품과 중간 부품이 사용됨. 이때 기본 부품은 만들 수 없고 중간 부품은 기본 부품이나 중간 부품을 조립해 만든 것
*	장난감 완제품과 그에 필요한 부품들 사이의 관계가 주어졌을 때 하나의 완제품을 위해 필요한 기본 부품의 존류별 개수를 계산
* 
* 입력: N (1 ~ N-1은 기본 부품이나 중간 부품의 번호, N은 완제품 번호)
*	M, M개의 줄에 x, y, k (제품 x를 만드는데 부품 y가 k개 필요함)
* 
* 출력: 하나의 완제품을 조립하는데 필요한 기본 부품의 수를 기본 부품의 번호가 작은 것 부터 번호 개수 출력
*/

#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

#define X first
#define Y second

int n, m;
int indegree[101];
long long num[101];
vector <pair<int, int>> v[101]; // x, k
queue <int> q;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	while (m--) {
		int x, y, k;
		cin >> x >> y >> k;
		v[x].push_back({ y, k });
		indegree[y]++;
	}

	num[n] = 1;

	for (int i = 1; i <= n; i++)
		if (!indegree[i]) q.push(i);

	while (!q.empty()) {
		int cur = q.front(); q.pop();

		for (pair<int,int> nxt : v[cur]) {
			indegree[nxt.X]--;
			num[nxt.X] += num[cur] * nxt.Y;
			if (!indegree[nxt.X])
				q.push(nxt.X);
		}
	}

	for (int i = 1; i <= n; i++)
		if (!v[i].size()) cout << i << " " << num[i] << "\n";

	return 0;
}
