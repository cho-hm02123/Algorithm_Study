/* https://www.acmicpc.net/problem/1915
* 
* 36m 50s
* 
* 문제: nxm사이즈의 0, 1 배열이 있다.
*	1로 이루어진 가장 큰 정사각혀으이 크기
* 
* 입력: n, m
*	배열
* 
* 출력: 큰 정사각형 넓이
* 
* 풀이: 이전 (-1,0) (0,-1) (-1,-1)에 1있었는지 검사하면서 찾음
*/

#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int n, m;
int mm;
int a[1001][1001];
char arr[1001][1001];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;

	for (int i = 1; i < n+1; i++)
		for (int j = 1; j < m+1; j++)
			cin >> arr[i][j];

	for(int i = 1; i < n+1; i++)
		for (int j = 1; j < m+1; j++) {
			if (arr[i][j] == '1') {
				a[i][j] = min({ a[i - 1][j], a[i][j - 1], a[i - 1][j - 1] }) + 1;
				mm = max(a[i][j], mm);
			}
		}

	cout << pow(mm,2);

	return 0;
}
