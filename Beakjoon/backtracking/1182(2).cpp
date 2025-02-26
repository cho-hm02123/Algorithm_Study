/* https://www.acmicpc.net/problem/1182 부분수열의 합
* 
* 문제: N개의 정수로 이루어진 수열, 수열의 원소를 다 더한 값이 S가 되는 경우의 수
* 
* 입력: N, N개의 수열
* 
* 출력: 합이 S가 되는 부분 수열의 경우의 수
*/

#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int N, S;
int rst;
int arr[21];

void bt(int st, int sum) {
	if (st != 0 && sum == S)
		rst++;

	for (int i = st + 1; i <= N; i++)
		bt(i, sum + arr[i]);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> S;
	for (int i = 1; i <= N; i++)
		cin >> arr[i];

	bt(0,0);

	cout << rst;

	return 0;
}
