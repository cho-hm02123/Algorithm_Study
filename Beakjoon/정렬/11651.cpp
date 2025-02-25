/* https://www.acmicpc.net/problem/11651 좌표 정렬하기 2
* 
* 10m
* 
* 문제: 2차원 평면 위 점 N개
*		1. y 좌표가 증가하는 순
*		2. x 좌표가 증가하는 순
* 
* 입력: 점 개수 N, i번 점 위치 x_i, y_i
* 
* 출력: 정렬한 결과
*/

#include <iostream>
#include <algorithm>
#include <cmath>
#include <queue>
using namespace std;

struct xy {
	int x, y;
};

class cmp {
public:
	bool operator() (xy a, xy b) {
		if (a.y == b.y) return a.x > b.x;
		return a.y > b.y;
	}
}; priority_queue <xy, vector<xy>, cmp> pq;

int N;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		xy coor;
		cin >> coor.x >> coor.y;

		pq.push(coor);
	}

	for (int i = 0; i < N; i++) {
		cout << pq.top().x << " " << pq.top().y << "\n";
		pq.pop();
	}

	return 0;
}
