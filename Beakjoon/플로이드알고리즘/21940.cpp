/* https://www.acmicpc.net/problem/21940 가운데에서 만나기
* 
* 문제: 도시를 연결하는 도로는 일방 통행만 있음
*	아래 조건을 만족하는 X 도시에서 만남
*		1. 왕복 시간은 자신이 살고있는 도시에서 X 도시로 이동하는 시간와 다시 X에서 자기 도시로 돌아가는 시간의 합
*		2. 모두가 도로를 이용해 갈 수 있는 도시만 선택
*		3. 모두의 왕복 시간 중 최대가 최소인 도시 X를 선택
*		4. 도시 X는 하나 이상 무조건 있음
* 
* 입력: 도시의 수 N, 도로 수 M
*	M개의 A, B, C (A->B에 걸리는 시간 C)
*	총 인원 K
*	친구들이 살고 있는 도시 번호
* 
* 출력: 도시 X (만약 여러개면 오름차순)
* 
* 풀이: 각 노드별 최단 시간 저장 후 애들이 살고 있는 도시에서 X도시까지 왕복 최대시간 구하기
*	X 도시의 최대 시간이 정해졌으면 현재 기준 시간과 비교해서 기준 시간보다 작으면 벡터 초기화 후 도시 X를 저장, 기준 시간도 변경
*	같으면 벡터에 X 추가
*/

#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

#define INF 0x3f3f3f3f
#define MAX 200
#define ll long long

int n, m, knum;
int city[MAX + 2];
ll arr[MAX + 2][MAX + 2];
vector <int> x;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			if (i != j) arr[i][j] = INF;

	for (int i = 0; i < m; i++) {
		int a, b, t;
		cin >> a >> b >> t;
		arr[a][b] = t;
	}

	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				if (arr[i][j] > arr[i][k] + arr[k][j]) arr[i][j] = arr[i][k] + arr[k][j];

	cin >> knum;
	for (int i = 1; i <= knum; i++)
		cin >> city[i];

	int bi = INF;
	for (int i = 1; i <= n; i++) {
		int mx = 0;
		for (int j = 1; j <= knum; j++) {
			if (arr[i][city[j]] == INF || arr[city[j]][i] == INF) break;
			if (arr[i][city[j]] + arr[city[j]][i] > mx)
				mx = arr[i][city[j]] + arr[city[j]][i];
		}

		if (bi > mx) {
			x.clear();
			x.push_back(i);
			bi = mx;
		}
		else if (bi == mx) x.push_back(i);
	}

	for (int i = 0; i < x.size(); i++)
		cout << x[i] << " ";

	return 0;
}