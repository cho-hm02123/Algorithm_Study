/* https://softeer.ai/practice/6257 [HSAT 4회 정기 코딩 인증평가 기출] 통근버스 출발 순서 검증하기
* 
* 1h 20m 08s
* 
* 문제: 퇴근 버스는 번호 순서대로 출발해야 함 이때 앞 버스가 나가야 그 뒤 버스가 나갈 수 있음 (원래 주차장)
*	버스는 스택처럼 맨 처름 들어간 버스가 가장 늦게 나옴 (새로운 주차장)
*	새 주차장에 들어간 버스는 다시 원래 주차장으로 이동할 수 없음 (원래 주차장에서 새 주차장으로 이동하는 것은 가능)
*	임시 주차장을 활용하여 오름차순으로 버스가 출발할 수 있는지 알아 볼 때 불가능한 경우가 몇개인지 출력 (0이면 가능)
*		예) i < j < k에 대해 a_i < a_j 이고, a_i > a_k
* 
* 입력: 수열의 크기 N (3이상 5000 이하)
*	n개의 수열
* 
* 출력: 서로 다른 (i,j,k) 순서 쌍의 개수
* 
* 풀이: O(5000 * 5000 * 3) = 0.75s
*/

#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

# define MAX 5000

int n, ans;
int arr[MAX + 2];
int judik[MAX + 2][MAX + 2];
long long rst[MAX+2][MAX+2];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	for (int i = 0; i < n - 2; i++)		// i, k 값을 비교 (만약 a_i > a_k를 만족하면 judik에 1)
		for (int k = i + 2; k < n; k++)
			if (arr[i] > arr[k]) judik[i][k] = 1;

	for (int i = 0; i < n - 2; i++) {	// 만약 입력이 4 2 5 3 1이면 a_i = 4일 때 a_j = 5인 a_k 는 3, 1로 2개 이므로 개수 맞춰줘야 함
		long long sum = 0;
		for (int k = i + 2; k < n; k++) {
			rst[i][k] = judik[i][k] + sum;
			sum += judik[i][k];
		}
	}

	long long ans = 0;
	for (int i = 0; i < n - 2; i++)
		for (int j = i + 1; j < n - 1; j++)
			if (arr[i] < arr[j]) ans += rst[i][n - 1] - rst[i][j];

	// 위 예로 i = 0, j = 2 일 때 (0, 2, 4), (0, 2, 5) 가능 이때 전체 a_i > a_k 개수 rst[i][n-1] 에서 이 전까지 개수 즉 rst[i][j]를 빼주면 i = 0, j = 2 일 때 경우의 수
	// 그니까 전체에서 전에 나온 걍우를 빼주면서 앞으로 i < j < k에 대해 a_i < a_j 이고, a_i > a_k를 만족할 경우를 구함

	cout << ans;
	return 0;
}