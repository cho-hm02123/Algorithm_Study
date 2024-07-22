/* https://www.acmicpc.net/problem/14888
* 
* 29m 20s -> 아니 초기 최솟값이랑 곱셈 2인데 3으로 조건문 써서 삽질함
* 
* 문제: N개 수로 이루어진 수열, 수 사이에 끼워 넣을 수 있는 연산자 N-1개 (+, -, x, 나누기)
*		수 사이에 연산자를 하나씩 넣어서 수식을 만듦 -> 수열 순서는 바꾸면 안됨
*		우선순위 연산 무시하고 순서대로 진행, 나눗셈은 정수 몫만,음수를 양수로 나눌 땐 C++14 기준
*		식 결과가 최대, 최소인 것을 구해라
* 
* 입력: N
*		수열
*		합이 N-1인 4개의 정수 (덧셈, 뺄셈, 곱셈, 나눗셈) 개수임
* 
* 출력: 최댓값 \n 최솟값
* 
* 풀이: 백트래킹으로 연산자 순서 다 정해서 해보는거지 뭐
*/

#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int n;
int arr[101];
int p, m, mul, mo;
int mn = 0x7fffffff, mx = -0x7fffffff;
int cal[101];
int com[101];
bool flag[101];

void fin() {
	int rst = arr[0];
	for (int i = 0; i < n-1; i++) {
		if (cal[com[i]] == 0)
			rst += arr[i + 1];

		else if (cal[com[i]] == 1)
			rst -= arr[i + 1];

		else if (cal[com[i]] == 2)
			rst *= arr[i + 1];
		else
			rst /= arr[i + 1];
	}
	mx = max(mx, rst);
	mn = min(mn, rst);
}

void bt(int k) {
	if (k == n-1) {
		fin();
		return;
	}

	for (int i = 0; i < n-1; i++) {
		if (flag[i]) continue;
		com[k] = i;
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
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	cin >> p >> m >> mul >> mo;
	for (int i = 0; i < p; i++)
		cal[i] = 0;
	for (int i = p; i < m + p; i++)
		cal[i] = 1;
	for (int i = m + p; i < p + m + mul; i++)
		cal[i] = 2;
	for (int i = p + m + mul; i < p + m + mul + mo; i++)
		cal[i] = 3;

	bt(0);

	cout << mx << "\n" << mn;
	return 0;
}
