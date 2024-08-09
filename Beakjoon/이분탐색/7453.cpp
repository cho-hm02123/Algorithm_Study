/* https://www.acmicpc.net/problem/7453 합이 0인 네 정수
* 
*  36m 19s
* 
* 문제: 정수로 이루어진 크기가 같은 배열 A, B, C, D
*	A[a] + B[b] + C[c] + D[d] 의 합이 0인 (a, b, c, d)의 개수
* 
* 입력: 배열 크기 n, A,B,C,B의 원소 원소는 int, 합은 ll
* 
* 출력: 쌍의 개수
* 
* 풀이: (a,b), (c,d)를 미리 더한 n*n개의 값은 따로 배열에 저장해서 이분탐색하는 무친 아이디어
*/

#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

#define ll long long

int n;
int a[4001], b[4001], c[4001], d[4001];
ll ab[16000001], cd[16000001];
ll cnt;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> a[i] >> b[i] >> c[i] >> d[i];

	for(int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			ab[i * n + j] = a[i] + b[j];
			cd[i * n + j] = c[i] + d[j];
		}

	sort(ab, ab + n*n);
	sort(cd, cd + n*n);


	for (int i = 0; i < n*n; i++)
		cnt += upper_bound(cd, cd + n * n, -ab[i]) - lower_bound(cd, cd + n * n, -ab[i]);

	cout << cnt;

	return 0;
}
