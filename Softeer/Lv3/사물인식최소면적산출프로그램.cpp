/* https://softeer.ai/practice/6277 [HSAT 2회 정기 코딩 인증평가 기출] 사물인식 최소 면적 산출 프로그램
* 
* 문제: 레이더를 통해 인식된 정보의 입력값은 평면에 N개의 점으로 주어짐
*	각 점들은 총 K개의 색깔 중 하나를 가짐
*	k개의 색깔에 대해 해당 색을 적어도 하나씩 포함하는 사물 중 넓이가 가장 작은 것을 찾아 해당 넓이를 출력
*	각 점을 포함한 사물은 반드시 직사각형
*	직사각형은 네 변이 모두 수평 혹은 수직, 내부가 아닌 경계에 놓인 점들도 포함
*	가로 혹은 세로의 길이가 0이면 넓이 0
* 
* 입력: N, K
*	N줄에 x, y, k
* 
* 출력: 주어진 입력에 대해 k개의 색 각각을 적어도 하나 포함하는 직사각형 중 넓이가 가장 작은 것의 넓이
* 
* 풀이: k를 기준으로 백트래킹 전체 탐색
*/

#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

#define MAX 1000
#define X first
#define Y second

int n, k;
int sz[21];
int mm = 0x3f3f3f3f;
vector <pair<int, int>> v[21];

void bt(int knum, int xMin, int yMin, int xMax, int yMax) {
	if (knum > k) {
		mm = min(mm, abs((xMax - xMin) * (yMax - yMin)));
		return;
	}

	for (int i = 0; i < v[knum].size(); i++) {
		int xmx = max(xMax, v[knum][i].X);
		int ymx = max(yMax, v[knum][i].Y);
		int xmn = min(xMin, v[knum][i].X);
		int ymn = min(yMin, v[knum][i].Y);
		int rec = abs((xmx - xmn) * (ymx - ymn));
		if (knum == 1 || rec < mm)
			bt(knum + 1, xmn, ymn, xmx, ymx);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		v[z].push_back({x,y});
	}

	bt(1, MAX, MAX, -MAX, -MAX);
	cout << mm;

	return 0;
}