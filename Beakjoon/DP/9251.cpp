/* https://www.acmicpc.net/problem/9251
* 
* 24m 21s
* 
* 문제: 두 수열이 주어졌을 때 모두의 부분 수열이 되는 것 중 가장 긴 것
* 
* 입력: 문자열 두개
* 
* 출력: LCS 길이
* 
* 풀이: s1의 한 글자가 s2에도 있는지 검사 하면서 겹친 개수 저장
*/

#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

string s1, s2;
int arr[1002][1002];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> s1 >> s2;

	int a = s1.length();
	int b = s2.length();

	for(int i = 1; i <= a; i++)
		for (int j = 1; j <= b; j++) {
			if (s1[i - 1] == s2[j - 1])
				arr[i][j] = arr[i - 1][j - 1] + 1;
			else
				arr[i][j] = max(arr[i - 1][j], arr[i][j-1]);
		}

	cout << arr[a][b];

	return 0;
}
