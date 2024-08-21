/* https://softeer.ai/practice/6250 [HSAT 5회 정기 코딩 인증평가 기출] 성적 평가
* 
* 30m 14s
* 
* 문제: N명이 참가하는 스터디
*	대회를 3개 개최, 모든 구성원이 참여 각 대회에서 0 이상 1000 이하의 점수를 얻을 수 있음 ( 한 대회에 둘 이상의 동점자 가능)
*	각 대회별 등수 및 최종 등수 동점자 있을 시 가능한 높은 등수
*	최종 등수는 각 대회에서 얻은 점수 합으로 다시 메김
*	각 참가자의 대회별 등수 및 최종 등수 출력
* 
* 입력: 참가자 수 N (3 이상 100,000 이하), 세개의 줄에 각 대회 점수가 N개
* 
* 출력: 첫 세개의 줄에는 각 참가자의 대회별 등수 마지막 줄엔 최종 등수
* 
* 풀이: 값 받아서 내림차순으로 sort 시킴 이때 index를 유지하기 위해 pair를 통해 인덱스도 같이 저장해줌
*	하나의 for문으로 함수를 통해 결과를 얻기 위해 총합도 마지막 입력때 넣어줌
*/

#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

#define MAX 100001
#define X first
#define Y second

int n;
int rst[4][MAX];
vector <pair <int, int>> v[4];

void cal(int k, vector <pair<int, int>> cp) {
	int cnt = 1;
	int num = 1;
	int cur = cp[0].X;
	rst[k][cp[0].Y] = cnt;

	for (int i = 1; i < n; i++) {
		num++;
		if (cur == cp[i].X)
			rst[k][cp[i].Y] = cnt;
		else {
			cnt = num;
			rst[k][cp[i].Y] = cnt;
			cur = cp[i].X;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < n; j++) {
			int a;
			cin >> a;
			v[i].push_back({ a,j });
			if (i == 2) {
				int sum = v[0][j].X + v[1][j].X + v[2][j].X;
				v[3].push_back({ sum, j });
			}
		}
	}

	for (int i = 0; i < 4; i++) {
		sort(v[i].begin(), v[i].end(), greater<>());
		cal(i, v[i]);
	}

	for (int i = 0; i < 4; i++) {
		cout << "\n";
		for (int j = 0; j < n; j++)
			cout << rst[i][j] << " ";
	}

	return 0;
}
