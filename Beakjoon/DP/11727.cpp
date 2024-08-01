/* https://www.acmicpc.net/problem/11727
* 
*  33m 37s
* 
* 문제: 2xN 직사각형을 1x2, 2x1, 2x2 타일로 채우는 방법의 수
* 
* 입력: n
* 
* 출력: 2xN 크기 직사각형을 채우는 방법의 수 % 10007
*/

#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

#define X 10007

int n, arr[1001];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	arr[1] = 1;
	arr[2] = 3;

	cin >> n;
	for (int i = 3; i < n + 1; i++)
		arr[i] = (2 * arr[i - 2] + arr[i - 1]) % X;

	cout << arr[n];


	return 0;
}
