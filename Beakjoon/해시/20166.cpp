/* https://www.acmicpc.net/problem/20166 문자열 지옥에 빠진 호석
* 
* 
* 문제: n*m격자 모양 타일이 있고 각 타일마다 알파벳 소문자가 있음
*	아무 곳에서 시작
*	상하좌우대각선 총 8방향으로 이동 가능, 이미 지나온 칸도 다시 방문 가능
*	이동할 때 마다 타일에 있는 알파벳으로 문자열을 만듬
*	좋아하는 문자열을 k개 입력 받아 만들 수 있는 경우의 수를 출력 이때 방문 순서가 다르면 다른 경우의 수
*	만약 (1,1)에서 위로 한칸 가면 (n,1)임 나머지도 마찬가지
* 
* 입력: 격자 크기 n, m, 좋아하는 문자열 개수 k
*	타일의 상태
*	k개의 문자 열
* 
* 출력: 경우의 수
*/

#include <iostream>
#include <cmath>
#include <algorithm>
#include <queue>
#include <unordered_map>
using namespace std;

int n, m, k;
int dx[8] = { -1, -1, -1, 0, 0, 1, 1, 1,};
int dy[8] = { -1, 0, 1, -1, 1, -1, 0, 1 };
string arr[10];
unordered_map <string, int> um;

void dfs(int i, int j, string s) {
	um[s]++;

	if (s.size() == 5) // 문자열 길이가 최대 5 이므로
		return;
	for (int h = 0; h < 8; h++) {
		int x = (i + dx[h] + n) % n; // 범위 넘어가면 되돌아가므로 (ex. (0,1) 일 때 위로 한칸 가면 (2,0) -> (0 -1 +3)%3
		int y = (j + dy[h] + m) % m;

		dfs(x, y, s + arr[x][y]); // s가 "a"이고, arr[x][y]가 "b"이면 "ab" 입력되는거임
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m >> k;
	for (int i = 0; i < n; i++)
		cin >> arr[i];	// 그냥 하나의 string으로 받기

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			dfs(i, j, string(1, arr[i][j])); //string[]은 char[][]와 같음, string(2, b)라면 "bb" 라는 문자열을 생성함


	for (int i = 0; i < k; i++) {
		string s;
		cin >> s;
		cout << um[s] << "\n";
	}

	return 0;
}
