/* https://www.acmicpc.net/problem/1719 택배
* 
* 문제: 택배 화물이 각 집하장들을 오갈 때 어떤 경로를 거쳐야 하는지
*	각 경로마다 걸리는 시간이 존재하며 최단 경로로 경로 표를 구해야 함
* 
* 입력: 집하장 개수 n, 경로 수 m
*	m개의 a, b, c (a->b c시간)
* 
* 출력: 경로표 출력
*/

#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

#define MAX 200
#define INF 0x3f3f3f3f

int n, m;
int weight[MAX + 2][MAX + 2];
int path[MAX + 2][MAX + 2];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			if (i != j) weight[i][j] = INF;

	while (m--) {
		int a, b, c;
		cin >> a >> b >> c;

		weight[a][b] = c;
		weight[b][a] = c;
		path[a][b] = b;
		path[b][a] = a;
	}

	for(int k = 1; k <= n; k++)
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= n; j++)
				if (weight[i][k] + weight[k][j] < weight[i][j]) {
					weight[i][j] = weight[i][k] + weight[k][j];
					path[i][j] = path[i][k];
				}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j)
				cout << "- ";
			else
				cout << path[i][j] << " ";
		}
		cout << "\n";
	}

	return 0;
}
