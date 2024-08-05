/* https://www.acmicpc.net/problem/15486
* 
* 25m 17s
* 
* 문제: N일 동안 최대한 많은 상담
*	상담하는데 걸리는 기간 T, 상담료 P
*	얻을 수 있는 최대 수익
* 
* 입력: N , T, P
* 
* 출력: 최대 금액
* 
* 풀이: 백트래킹으로 풀면 시간초과 남
*	앞에서 부터 계산하면 날짜 뒤죽박죽
*	맨 뒤에서부터 생각하기
*/

#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

#define X first
#define Y second

int n;
pair<int, int> arr[1500001]; // T, P
long long a[1500002];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 1; i < n + 1; i++)
		cin >> arr[i].X >> arr[i].Y;

	for (int i = n; i > 0; i--) {
		if (i + arr[i].X < n + 2)
			a[i] = max(a[i + 1], a[i + arr[i].X] + arr[i].Y);
		else
			a[i] = a[i + 1];
	}

	cout << *max_element(a, a + n+1);

	return 0;
}
