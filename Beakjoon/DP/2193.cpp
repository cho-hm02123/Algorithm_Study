/* https://www.acmicpc.net/problem/2193
*
* 13m 11s
*
* 문제: 0으로 시작하지 않으며 1이 연속으로 나타나지 않는 이친수
*	N이 주어졌을 때 N 자리 이친수의 개수를 구해라
*
* 입력: N (1이상 90이하)
*
* 출력: N자리의 이친수의 개수
* 
* 풀이: 최댓값 얼만지 출력 해보고 변수 type 신경쓰기
*/

#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int n;
long long arr[91];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

	arr[1] = 1;
	arr[2] = 1;

	for (int i = 3; i <= n; i++)
		arr[i] = arr[i - 1] + arr[i - 2];

	cout << arr[n];

	return 0;
}
