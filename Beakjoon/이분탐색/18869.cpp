/* https://www.acmicpc.net/problem/18869
* 
* 31m 15s
* 
* 문제: M개의 우주, 각 우주에는 1~N 까지 번호가 메겨진 행성이 존재행성의 크기를 알고 있을 때 균등한 우주가 몇쌍인가
*	구성은 같은데 순서가 다른 우주 쌍은 한번만 센다
*	
*	Ai < Aj && Bi < Bj
*	Ai == Aj && Bi == Bj
*	Ai > Aj && Bi > Bj
* 
* 입력: 우주의 개수 M, 행성의 개수 N
*	1번 우주부터 차례로 행성의 크기  
* 
* 출력: 균등한 우주쌍의 개수
* 
* 풀이: 압축 후 인덱스 저장 후 비교
*/

#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

int m, n;
int arr[101][10001];

int cc(int a[], int b[]) {
	for (int i = 0; i < n; i++)
		if (a[i] != b[i]) return 0;		// 크기 순으로 정렬한 인덱스를 가지고 있음 즉 각 배열의 인덱스가 동일하면 균등한 행성
	return 1;
}

void c(int a[]) {
	vector <int> v( a, a + n );
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());

	for (int i = 0; i < n; i++)
		a[i] = lower_bound(v.begin(), v.end(), a[i]) - v.begin(); // 크기 순으로 정렬했으므로 인덱스 값이 저장됨
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> m >> n;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++)
			cin >> arr[i][j];

		c(arr[i]);
	}

	int cnt = 0;
	for (int i = 0; i < m; i++)
		for (int j = i + 1; j < m; j++)
			cnt+=cc(arr[i], arr[j]);

	cout << cnt;

	return 0;
}
