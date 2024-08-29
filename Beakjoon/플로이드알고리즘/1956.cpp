/* https://www.acmicpc.net/problem/1956 운동
* 
* 문제: V개의 마을과 E개의 일방통행 도로
*	운동을 하기 위한 경로 찾기, 운동이 끝나면 다시 시작점으로 돌아오는 것이 좋아 사이클을 찾아햐 함
*	사이클을 이루는 도로의 길이의 합이 최소가 되도록
* 
* 입력: V, E
*	E개의 a, b, c (a->b, 길이 c)
* 
* 출력: 최소 사이클의 도로 길이의 합 (불가능하면 -1)
* 
* 풀이: 플로이드로 a마을에서 b마을로 가는 최단 경로 계산
*/

#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

#define INF 0x3f3f3f3f
#define MAX 400
#define ll long long

int v, e;
int mm = INF;
ll road[MAX + 2][MAX + 2];

void Setarray() {
	for (int i = 1; i <= v; i++)
		for (int j = 1; j <= v; j++)
			if (i != j) road[i][j] = INF;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> v >> e;
	Setarray();

	while (e--) {
		int a, b, c;
		cin >> a >> b >> c;
		road[a][b] = c;
	}

	for(int k = 1; k <= v; k++)
		for(int i = 1; i <= v; i++)
			for(int j = 1; j <= v; j++)
				if (road[i][k] + road[k][j] < road[i][j]) {
					road[i][j] = road[i][k] + road[k][j];
				}

	for (int i = 1; i <= v; i++)
		for (int j = 1; j <= v; j++) {
			if (i == j) continue;
			if (road[i][j] + road[j][i] < mm)
				mm = road[i][j] + road[j][i];
		}

	if (mm == INF)
		cout << "-1";
	else
		cout << mm;
	
	return 0;
}
