/* https://www.acmicpc.net/problem/2467 용액
* 
* 26m 07s
* 
* 문제: 산성, 알칼리 용액 존재, 산성은 1 ~ 10^9 까지, 알칼리는 -1 ~ -10^9
*	같은 양의 두 용액을 섞은 용액의 특성은 특성합과 동일
*	최대한 0이 되도록해야 함
* 
* 입력: 전체 용액 수 N, 용액 특성 값
* 
* 출력: 혼합 특성값이 0에 가까운 두 용액을 오름차순으로 출력
* 
* 풀이: 가장 끝단 기준으로 더해서 비교
*	만약에 st+1, en 더한게 st, en-1 보다 크거나 같으면 en--
*	아니면 st++
*/

#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

#define LL long long

int n;
LL arr[100001];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	LL rst[2] = { arr[0], arr[n-1]};

	int st = 0;
	int en = n - 1;

	while (st < en) {
		if (abs(arr[st] + arr[en]) < abs(rst[0]+rst[1])) {
			rst[0] = arr[st];
			rst[1] = arr[en];
		}
		
		if (abs(arr[st + 1] + arr[en]) >= abs(arr[st] + arr[en - 1]))
			en--;
		else
			st++;
	}

	cout << rst[0] << " " << rst[1];

	return 0;
}
