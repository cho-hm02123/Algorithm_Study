/* https://www.acmicpc.net/problem/7795
* 
*  9m 3s
* 
* 문제: 생명체 A, B 존재 A는 B를 먹음
*	A는 자기보다 작은 B를 먹을 수 있음
*	A, B 가 주어졌을 때 A가 B보다 큰 쌍이 몇개 있는지
* 
* 입력: 테스트케이스 개수 t, A의 수 N, B의 수 M, A 크기, B 크기
* 
* 출력: TC 마다 A > B 인 쌍의 개수
* 
* 풀이: 각각 배열에 넣고 크기순으로 정렬
*	a 첫번째 원소부터 b 원소들이랑 비교 이때 전체 비교하면 시간초과 따라서 큰거 나온 순간 다음 A원소 조사 (정렬해줘서 그래도 됨)
*/

#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int tc, n, m, cnt;
int a[20001];
int b[20001];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> tc;
	
	while (tc--) {
		cnt = 0;
		cin >> n >> m;

		for (int i = 0; i < n; i++)
			cin >> a[i];
		for (int i = 0; i < m; i++)
			cin >> b[i];

		sort(&a[0], &a[0] + n);
		sort(&b[0], &b[0] + m);

		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++) {
				if (a[i] > b[j]) cnt++;
				else
					break;
			}

		cout << cnt << "\n";
	}

	return 0;
}
