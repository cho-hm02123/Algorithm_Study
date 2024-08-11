/* https://www.acmicpc.net/problem/21608
* 
* 1h 11m 48s
* 
* 문제: 교실 크기 NxN, 학교에 다니는 학생 수 N^2
*	교실 최좌상단은 (1,1) 최우하단은 (n,n)
*	학생 순서있고(고유 번호따로 있음) 학생이 좋아하는 학생 4명 있음
*	규칙대로 한 칸에 한명씩
* 
*	규칙
*		1. 비어있는 칸 중 좋아하는 학생이 인접한 칸에 가장 많은 칸으로 자리 지정
*		2. 1을 만족하는 칸이 여러개이면 인접한 칸 중 비어있는 칸이 가장 많은 칸으로
*		3. 2를 만족하는게 여러개면 x가 가장 작은 칸
*		4. 3도 여러개면 y가 가장 작은 칸
* 
*	만족도
*		a학생의 만족도 = 10^(a학생과 인접한 칸에 앉은 좋아하는 학생의 수 - 1)
*	학생들 만족도 총 합을 구해라
* 
* 입력: N, 학생의 번호, 해당 학생이 좋아하는 학생의 번호 4개
* 
* 출력: 총 만족도
* 
* 풀이: v[401]의 벡터를 만들어서 idx에 해당하는 학생의 좋아하는 애 번호를 저장
*	입력을 다 받고 cal을 호출 시 자리선택 순서에 대한 고려를 도 해줘야 하므로 한 학생의 좋아하는 애 입력이 끝날 때 마다 cal을 호출
*	선택할 좌표는 우선순위 큐를 이용 
*	이때 구조체에 빈칸, 좋아하는 학생의 인접 여부 현재 조사하고 있는 위치의 x좌표, y좌표를 저장할 수 있도록함
*	비어있는 모든 곳을 우선순위큐에서 비교하며 최적의 좌표를 찾음
*/

#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

#define X first
#define Y second

struct kan {
	int bi, fa, x, y; // 빈칸, 좋아하는 애
};

int n, a, sum;
int arr[21][21];
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };
vector <int> v[401];

class cmp {
public:
	bool operator() (kan a, kan b) {
		if (a.fa != b.fa) return a.fa < b.fa;
		if (a.bi != b.bi) return a.bi < b.bi;
		if (a.x != b.x) return a.x > b.x;
		return a.y > b.y;
	}
};

void cal(int h) {
	kan flag[21][21] = { 0, };
	priority_queue <kan, vector<kan>, cmp> pq;

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) {
			if (arr[i][j] != 0) continue;

			flag[i][j].x = i;
			flag[i][j].y = j;
			for (int k = 0; k < 4; k++) {
				int x = i + dx[k];
				int y = j + dy[k];

				if (x < 1 || y < 1 || x > n || y > n) continue;

				if (arr[x][y] == 0)
					flag[i][j].bi++;
				else {
					for (int t = 0; t < 4; t++) {
						if (v[h][t] == arr[x][y])
							flag[i][j].fa++;
					}
				}
			}

			pq.push(flag[i][j]);
		}
	arr[pq.top().x][pq.top().y] = h;
}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	a = pow(n, 2);
	for (int i = 1; i <= a; i++) {
		int b;
		cin >> b;
		for (int j = 0; j < 4; j++) {
			int c;
			cin >> c;
			v[b].push_back(c);
		}
		cal(b);
	}

	for(int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) {
			int num = 0;
			int k = arr[i][j];
			int k1 = v[k][0];
			int k2 = v[k][1];
			int k3 = v[k][2];
			int k4 = v[k][3];

			for (int h = 0; h < 4; h++) {
				int x = i + dx[h];
				int y = j + dy[h];

				if (x < 1 || y < 1 || x > n || y > n) continue;
				if (arr[x][y] == k1 || arr[x][y] == k2 || arr[x][y] == k3 || arr[x][y] == k4)
					num++;
			}
			sum += pow(10, num - 1);
		}

	cout << sum;

	return 0;
}
