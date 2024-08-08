/* https://www.acmicpc.net/problem/3151 합이 0
* 
* 51m 26s
* 
* 문제: 3명으로 구성된 팀 코딩 잘하면 팀워크 병신, 코딩 병신이면 팀워크 굳
*	각 학생의 코딩 실력이 -10^4 ~ 10^4
*	팀원의 코딩 실력의 합이 0이 되도록
*	대회에 출전할 수 있는 팀의 경우의 수
* 
* 입력: 학생 수 N, 실력 A N개
* 
* 출력: 팀의 수
* 
* 풀이: 일단 sort하고 0 ~ n-1 인덱스 일 때 1 ~ n 까지 검사
*/

#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

int n;
int arr[10001];
vector <int> v;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		v.push_back(arr[i]);
	}

	sort(v.begin(), v.end());

	long long cnt = 0;

	for (int i = 0; i < n-1; i++) {
		for (int j = i + 1; j < n; j++) {
			int a = -v[i] - v[j];
			cnt += (upper_bound(v.begin() + j + 1, v.end(), a) - lower_bound(v.begin() + j + 1, v.end(), a));
		}
	}

	cout << cnt;

	return 0;
}
