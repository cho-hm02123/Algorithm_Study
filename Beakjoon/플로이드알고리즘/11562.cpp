/* https://www.acmicpc.net/problem/11562 백양로 브레이크
* 
* 문제: 현재 일방통행인 길 중 반드시 양방향으로 바꿔야 하는 길이 몇개인지 조사해야 함
*	출발지와 목적지를 입력하면 목적지까지 가기 위해 최소 몇개의 길을 양방향 도로로 바꿔야하는지 출력
* 
* 입력: 건물의 수 n, 길의 수 m
*	m개의 u, v, b (u->v, b==0 일방통행, b==1 양방향)
*	질문 수 k
*	k개의 s, e(s->e)
* 
* 출력: k줄의 최소 몇개의 길을 양방향 통행으로 바꿔야 하는지
* 
* 풀이: 처음에 길도 있고 갈 수 있으면 0(통행을 바꿔야하는 수가 0), 길은 있지만 갈 수 없으면 1
*	플로이드
*		만약 가는 길이 길있 갈 없 길 있 갈 없 길 있 이라면 1+1+0 으로 2가 저장 즉 2번 바꿔야 함
*/

#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

#define MAX 250
#define INF 0x3f3f3f3f

int n, m, k;
int arr[MAX + 2][MAX + 2];

void SetOrigin() {
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			if (i != j) arr[i][j] = INF;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	SetOrigin();
	while (m--) {
		int u, v;
		bool b;
		cin >> u >> v >> b;
		arr[u][v] = 0;
		arr[v][u] = !b;
	}

	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				if (arr[i][k] + arr[k][j] < arr[i][j]) arr[i][j] = arr[i][k] + arr[k][j];

	cin >> k;
	while (k--) {
		int s, e;
		cin >> s >> e;
		cout << arr[s][e] << "\n";
	}

	return 0;
}
