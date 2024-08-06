/* https://www.acmicpc.net/problem/10942
* 
* 28m 51s
* 
* 문제: 자연수 N개를 적음
*	질문을 총 M번 함
*	질문은 S, e러 나타낼 수 있으며 S번째 수부터 E번째 까지 수가 팰린드롬을 이루는지 물어봄
*	
*	팰린드롬 -> 앞에서 시작하나 뒤에서 시작하나 같음
* 
* 입력: N, N개 수, M, M가지 S, E
* 
* 출력: 팰린드롬이면 1 아니면 0
* 
* 풀이: s==e 이면 무조건 True
*	s + 1 = e 일때 arr[s]==arr[e]면 True
*	그 다음부터 arr[s] == arr[e] 이고 a[s+1][e-1] 즉 사이 수가 True 면 True
*/

#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int n, m, s, e;
int arr[2001];
bool a[2001][2001];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 1; i < n+1; i++) {
		cin >> arr[i];
		a[i][i] = true;
		if (arr[i] == arr[i - 1])
			a[i - 1][i] = true;
	}

	for (int i = 2; i < n; i++)
		for (int j = 1; j <= n - i; j++) {
			int s = j;
			int e = j + i;

			if (arr[s] == arr[e] && a[s + 1][e - 1]) a[s][e] = true;
		}
	
	cin >> m;
	while (m--) {
		cin >> s >> e;
		cout << a[s][e] <<"\n";
	}

	return 0;
}
