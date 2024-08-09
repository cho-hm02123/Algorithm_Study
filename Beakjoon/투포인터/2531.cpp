/* https://www.acmicpc.net/problem/2531 회전 초밥
* 
*  29m 17s
* 
* 문제: 임의의 위치에서 k개의 접시를 연속해서 먹을 경우 할인된 가격
*	각 고객에게 초밥 종류가 하나 쓰인 쿠폰을 발행, 위의 행사에 참여할 경우 쿠폰에 적힌 초밥 하나를 추가로 무료로 제공 > 벨트에 없으면 만들어서 줌
*	가능한 다양한 종류 먹을 것임
*	먹을 수 있는 가지수의 최대 값
* 
* 입력: 접시 수 N, 가지 수 d, 연속해서 먹는 접시 수 k, 구폰 번호 c
*	초밥 종류
* 
* 출력: 최대 가짓수
* 
* 풀이: 겹치는거 확인하고 하ㅣ면 됨
*/

#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int n, d, k, c, mm;
int arr[33001];
int flag[30001];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> d >> k >> c;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	for (int i = n; i < n + k - 1; i++)
		arr[i] = arr[i - n];

	int en = 0;
	int cnt = 0;

	for (int st = 0; st < n; st++) {
		while (en < n + k-1 && en - st < k) {
			if (flag[arr[en]] == 0) cnt++;
			flag[arr[en]] += 1;
			en++;
		}

		mm = max(mm, cnt);
		if (flag[c] == 0)
			mm = max(mm, cnt + 1);
		else
			mm = max(mm, cnt);

		if (flag[arr[st]] != 0) {
			flag[arr[st]] -= 1;
			if (flag[arr[st]] == 0)
				cnt--;
		}
		else
			cnt--;
	}

	cout << mm;

	return 0;
}
