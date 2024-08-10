/* https://www.acmicpc.net/problem/17219 비밀번호 찾기
* 
*  09m 48s
* 
* 문제: 사이트 주소와 비밀번호를 저장
*	비밀번호를 찾는 프로그램
* 
* 입력: 저장된 주소 수 n, 비밀번호를 찾으려는 주소 수 m
*	n개의 사이트 주소 및 비밀번호
*	m개의 비밀번호를 찾으려는 주소
* 
* 출력: 해당 주소의 비밀번호 출력 "\n"
* 
* 풀이: unorder_map을 사용해 주소를 key로, 비밀번호를 value로 하여 저장 후 탐색해 출력
*/

#include <iostream>
#include <algorithm>
#include <cmath>
#include <unordered_map>
using namespace std;

int  n, m;
unordered_map <string, string> um;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string s, pw;
		cin >> s >> pw;
		um[s] = pw;
	}
	for (int i = 0; i < m; i++) {
		string s;
		cin >> s;
		cout << um[s] << "\n";
	}
	return 0;
}
