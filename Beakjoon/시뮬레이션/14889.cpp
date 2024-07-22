/* https://www.acmicpc.net/problem/14889
*
*  33m 40s
* 
* 문제: N명의 사람(N은 짝수), N/2명으로 이루어진 스타트 팀, 링크 팀으로 사람을 나눔
*		사람에게 1~N까지 번호 부여, 능력치 주어짐, 팀의 능력치 = 팀에 속한 모든 쌍의 능력치 합 S_ij, S_ji는 다를 수 있음 -> 팀 능력치 구할 때도 S_ij, S_ji 모두 더함
*		두 팀의 능력치 차이를 최소로
*
* 입력: N
*		N개 줄에 S가 주어짐 (i번 줄의 j번째 수는 S_ij)
*
* 출력: 팀 능력치 차의 최솟값
*
* 풀이: 백트레킹에서 num[k-1] > i 조건 안해줘서 시간초과남 -> 순서 상관없이 중복까지 다 해서
*/

#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int n;
int mm = 0x7fffffff;
int s[21][21];
int num1[11];
bool flag[21];

void cal() {
	int rst1 = 0, rst2 = 0;
	int cnt = 0;
	int num2[11] = { 0, };

	for (int i = 1; i < n + 1; i++) {
		if (!flag[i]) {
			num2[cnt] = i;
			cnt++;
		}
	}

	for (int i = 0; i < n / 2; i++)
		for (int j = 0; j < n / 2; j++) {
			if (i == j) continue;
			rst1 += s[num1[i]][num1[j]];
			rst2 += s[num2[i]][num2[j]];
		}


	mm = min(mm, abs(rst1 - rst2));
}

void bt(int k) {
	if (k == n / 2) {
		cal();
		return;
	}

	int st = 1;
	if (k != 0) st = num1[k - 1];

	for (int i = st; i < n + 1; i++) {
		if (flag[i] || (k!=0 && num1[k-1] > i)) continue;

		num1[k] = i;
		flag[i] = 1;
		bt(k + 1);
		flag[i] = 0;
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 1; i < n + 1; i++)
		for (int j = 1; j < n + 1; j++)
			cin >> s[i][j];

	bt(0);
	cout << mm;

	return 0;
}
