/* https://www.acmicpc.net/problem/1507 궁금한 민호
* 
* 문제: N개의 도시, M개의 도로, 도로를 지날 깨 걸리는 시간 존재 (A에서 B로 이동할 수 없는 경우는 없음)
*	모든 쌍의 도시에 대해 최소의 시간은 있음 이 표를 보고 원래 도로가 몇개였는지 구해야함
* 
* 입력: 도시 개수 N, N*N 걸리는 시간
* 
* 출력: 도로의 개수가 최소일 때 모든 도로의 시간의 합
*	불가능한 경우 1 출력
* 
* 풀이: 플로이드로 푼다.
*		최단 시간을 줬으므로 origin[i][k] + origin[k][j] < origin[i][j]인 경우는 발생 할 수 없어 -1을 출력한다.
*		경유지를 들러 갈 수 있으면 해당 경로를 잇는 도로는 최초의 도로가 될 수 없다.
*/

#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

#define MAX 20

int n, ans;
int origin[MAX + 2][MAX + 2];
bool flag[MAX + 2][MAX+2];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for(int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) {
			cin >> origin[i][j];
			if (i == j) flag[i][j] = 1;
		}

	for(int k = 1; k <= n; k++)
		for(int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++) {
				if (i == k || k == j) continue;
				if (origin[i][k] + origin[k][j] < origin[i][j]) {
					cout << "-1";
					return 0;
				}
				if (origin[i][k] + origin[k][j] == origin[i][j]) {
					flag[i][j] = 1;
					flag[j][i] = 1;
				}
			}

	for (int i = 1; i <= n; i++)
		for (int j = i+1; j <= n; j++)
			if (!flag[i][j]) ans += origin[i][j];

	cout << ans;

	return 0;
}
