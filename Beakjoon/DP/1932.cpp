/* https://www.acmicpc.net/problem/1932
* 
*  1s 10m 11s
* 
* 문제: 삼각형 맨 위층에서 내려오면서 경로에 있는 수의 합이 가장 크게
*	삼각형의 크기는 1~500
*	대각선 오른쪽 혹은 외쪽만 선택 가능
* 
* 입력: 삼각형 크기 n, 정수 삼각형
* 
* 출력: 최댓값
*/

#include <iostream>
#include <cmath>
#include <algorithm>
#include <queue>
using namespace std;

int n;
int arr[500];
int rst[500][500];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	cin >> rst[0][0];

	for(int i = 1; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			cin >> arr[j];
			if (j == 0)
				rst[i][j] = rst[i - 1][j] + arr[j]; // 얘 += 으로 해서 찾는데 오래걸렸네
			else if (j == i)
				rst[i][j] = rst[i-1][j-1] + arr[j];
			else
				rst[i][j] = max(rst[i-1][j - 1], rst[i-1][j]) + arr[j]; // max로 안하면 마지막 개수 최대 2^499개 나옴
		}
	}

	int mm = rst[n-1][0];
	for (int i = 0; i < n; i++)
		mm = max(mm, rst[n-1][i]);
	cout << mm;
	return 0;
}
