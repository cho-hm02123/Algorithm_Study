/* https://softeer.ai/practice/6252 [HSAT 4회 정기 코딩 인증평가 기출] 슈퍼컴퓨터 클러스터
* 
* 1h 14m 33s	아니 왜 return false를 for문 안에 쓰면 맞고 밖에 쓰면 틀림?? 이거 때문에 45분 잡아먹음;;
* 
* 문제: 여러개의 컴퓨터를 하나의 클러스터로 묶어 계산을 수행
*	클러스터의 성능은 컴퓨터의 수가 많아질 수록, 각각의 성능이 올라갈 수록 향상
*	클러스터의 성능을 업그레이드 해 달라 근데 클러스터를 이루는 각각의 컴퓨터 중 성능이 가장 낮은 컴퓨터의 성능이 병목 됨
*	클러스터에 N대의 컴퓨터, 각각의 성능은 a_i라는 정수로 평가
*	각각의 컴퓨터에 비용을 들여 업그레이드 진행 단, 한 컴퓨터를 두번 이상 업그레이드 불가
*	성능을 d 향상시키는데 드는 비용은 pow(d, 2)원
*	업그레이드를 위한 예산이 b원, 성능이 가장 낮은 컴퓨터의 성능을 최대화 하는 것이 목표
*	최선의 최저 성능을 계산해라
* 
* 입력: N, b(long long)
*	N개의 컴퓨터 성능
* 
* 출력: 예산을 효율적으로 썼을 때 성능이 가장 낮은 컴퓨터의 성능 최대값
* 
* 풀이: 완전 탐색 시 10^5(N) x 10^9(ai) = 10^14이므로 3*10^9 보다 커 시간 초과 따라서 이분탐색 사용
*	이분 탐색 중에서 parametic search를 사용.
*	가장 큰 업그레이드 범위는 루트(b) 이므로 en = 루트(b), st = 0으로 설정하여 이분탐색
*	mid + arr[0] 보다 성능이 안좋은 컴퓨터는 모두 업그레이드 해야 하므로 이때의 비용을 계산
*	해당 비용이 b를 넘는지에 따라 st, en을 재설정
*/

#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

#define ll long long

int n;
ll arr[100001];
ll b;

bool cal(ll k) {
	ll mini = arr[0] + k;
	ll sum = 0;

	if (k == 0) return true;

	for (int i = 0; i < n; i++) {
		if (arr[i] < mini)
			sum += (ll)pow(mini - arr[i], 2);
		else
			break;
		if (sum > b) return false;
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> b;
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	sort(arr, arr + n);

	ll st = 0;
	ll en = (ll)sqrt(b);

	while (st < en) {
		ll mid = (st + en + 1) / 2;
		if (cal(mid)) // 총합이 b보다 작거나 같음
			st = mid;
		else
			en = mid - 1;
	}

	cout << arr[0] + (st + en + 1) / 2;

	return 0;
}