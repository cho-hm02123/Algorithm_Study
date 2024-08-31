/* https://www.acmicpc.net/problem/16916 부분 문자열
* 
* 문제: 문자열 S의 부분 문자열이랑 문자열의 연속된 일부
*	문자열 S, P 가 주어 졌을 때 P가 S의 부분 문자열인지 알아보기
* 
* 입력: 문자열 S, 문자열 P
* 
* 출력: P가 S의 부분 문자열이라면 1 아니면 0을 출력
* 
* 풀이: 실패함수 사용
*	비교할 문자열 p의 실패함수 구하기 i = 1부터 
*	위에서 구한 실패함수를 기반으로 기준 문자열과 비교 문자열을 비교 i = 0 부터
*/

#include <iostream>
#include <vector>
using namespace std;

string s, p;

vector <int> failfunc() {
	vector <int> f(p.size());
	int j = 0;
	for (int i = 1; i < p.size(); i++) {
		while (j > 0 && p[i] != p[j]) j = f[j - 1];
		if (p[i] == p[j]) f[i] = ++j;
	}
	return f;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> s >> p;

	vector <int> f = failfunc();

	int j = 0;
	for (int i = 0; i < s.size(); i++) {
		while (j > 0 && s[i] != p[j]) j = f[j - 1];
		if (s[i] == p[j]) j++;
		if (j == p.size()) {
			cout << "1";
			return 0;
		}
	}
	cout << "0";

	return 0;
}
