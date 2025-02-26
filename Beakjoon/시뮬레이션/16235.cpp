/* https://www.acmicpc.net/problem/16235 나무 재테크
* 
* 문제: N by N, (r, c), 각 칸에 양분이 있으며 처음엔 5만큼 있다.
*	M개의 나무를 심음 (같은 칸에 여러개 심을 수 있다.)
*	나무는 사계절을 보냄
*		봄: 자신의 나이만큼 양분을 먹고 나이 1 증가, 해당 칸의 양분만 먹을 수 있음, 나무 여러개면 어린 나무 먼저 (만약 나이만큼 못먹으면 바로 죽음)
*		여름: 봄에 죽은 나무가 양분으로 변함, (나무 나이)/2 만큼 양분으로 추가
*		가을: 번식 (나이가 5의 배수인 나무가 번식) 인접한 8개의 칸에 나이가 1인 나무 생성
*		겨울: 입력을 통해 추가된 양분이 정해짐
*	K년이 지난 후 살아있는 나무의 개수
* 
* 입력: N, M, K, 겨울에 추가할 양분의 양, M개의 줄 동안 심은 나무의 정보 (x, y, age)
* 
* 출력: K년이 지난 후 살아남은 나무의 수
* 
* 풀이: 여름에 죽은 나무 양분 더할 때 (나이 총합)/2 랑 (각 나이)/2 의 총합이랑 결과 다름;;
*/

#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

struct info {
	int x, y, age;
};

int N, M, K;
int A[11][11];
int arr[11][11];
int dx[8] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int dy[8] = { -1, 0, 1, -1, 1, -1, 0, 1 };
vector <int> v[11][11];

void Winter() {
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			arr[i][j] += A[i][j];
}

void Autumn() {
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++) {
			if (v[i][j].empty()) continue;

			int cnt = 0;
			for (auto id : v[i][j])
				if (id % 5 == 0) cnt++;

			if (cnt > 0) {
				for (int k = 0; k < 8; k++) {
					int x = i + dx[k];
					int y = j + dy[k];

					if (x < 1 || y < 1 || x > N || y > N) continue;
					for (int h = 0; h < cnt; h++)
						v[x][y].push_back(1);
				}
			}
		}

	Winter();
}

void Summer(int x, int y, int idx) {
	int sum = 0;
	for (int i = idx; i < v[x][y].size(); i++)
		sum += v[x][y][i]/2;

	arr[x][y] += sum;

	v[x][y].erase(v[x][y].begin() + idx, v[x][y].end());
}

void Spring() {
	for(int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++) {
			if (v[i][j].empty()) continue;

			if ((int)v[i][j].size() > 1)
				sort(v[i][j].begin(), v[i][j].end());

			for (int k = 0; k < v[i][j].size(); k++) {
				if (v[i][j][k] <= arr[i][j]) {
					arr[i][j] -= v[i][j][k];
					v[i][j][k]++;
				}
				else {
					Summer(i, j, k);
					break;
				}
			}
			
		}
	Autumn();
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M >> K;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++) {
			cin >> A[i][j];
			arr[i][j] = 5;
		}

	while (M--) {
		info a;
		cin >> a.x >> a.y >> a.age;
		v[a.x][a.y].push_back(a.age);
	}

	while (K--) {
		Spring();
	}

	int rst = 0;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			rst += (int)v[i][j].size();

	cout << rst;

	return 0;
}
