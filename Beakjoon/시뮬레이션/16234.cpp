/* https://www.acmicpc.net/problem/16234 인구 이동
* 
* 문제: N by N 크기 땅, 1 by 1의 칸으로 나눠져 있음, 각 땅에 나라가 하나씩 존재, (r,c) 위치 나라에 A[r][c]명이 살고 있음
*	인접한 나라엔 국경선 존재, 인구이동이 진행
*		1. 인접한 나라의 인구 차이가 L명 이상, R명 이하이면 이동 가능
*		2. 이동 가능하면 인구 이동 시작
*		3. 이동 가능한 나라를 하루동안 연합이라 함
*		4. 연합을 이루고 있는 각 칸의 인구수는 (연합 인구 수) / (연합을 이루고 있는 칸의 개수) > 소수점 제외
*		5. 연합 해체 후 국경 닫음(이동 불가)
*	각 나라의 인구 수가 주어졌을 때, 인구 이동이 며칠동안 발생하는지
* 
* 입력: N, L, R 각 나라의 인구 수
* 
* 출력: 인구 이동이 발생하는 일수
* 
* 풀이: vector<vector<>> 사용 많이 하기 > 그냥 무지성 [1000] 이런거 때리면 메모리 지랄
*	따라서 동적 할당 이용
*/

#include <iostream>
#include <algorithm>
#include <cmath>
#include <stack>
#include <vector>
using namespace std;

struct rc {
	int r, c;
};

int N, L, R;
int A[51][51];
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };
int day;

bool MovePeople(vector<vector<rc>> &v) {
	bool flag = false;

	for (auto&group : v) {
		if (group.size() > 1) {
			flag = true;
			int sum = 0;
			for (auto& pos : group)
				sum += A[pos.r][pos.c];
			for (auto& pos : group)
				A[pos.r][pos.c] = sum / group.size();
		}
	}

	if (flag) {
		day++;
		return true;
	}
	return false;
}

bool FindMoveGroup() {
	int flag[51][51] = { 0, };	// 연합 tag
	int gp = 1;
	stack <rc> s;
	vector <vector<rc>> v;

	for(int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) {
			if (flag[i][j] > 0) continue;
			vector <rc> group;
			s.push({ i, j });
			group.push_back({i, j});
			flag[i][j] = gp;

			while (!s.empty()) {
				rc cur = s.top(); s.pop();

				for (int k = 0; k < 4; k++) {
					int x = cur.r + dx[k];
					int y = cur.c + dy[k];

					if (x < 0 || y < 0 || x >= N || y >= N || flag[x][y] > 0) continue;

					if (abs(A[cur.r][cur.c] - A[x][y]) >= L && abs(A[cur.r][cur.c] - A[x][y]) <= R) {
						s.push({ x, y });
						group.push_back({ x,y });
						flag[x][y] = gp;
					}
				}
			}
			v.push_back(group);
			gp++;
		}

	if (MovePeople(v)) return true;
	return false;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> L >> R;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> A[i][j];

	while (FindMoveGroup());
	
	
	cout << day;

	return 0;
}
