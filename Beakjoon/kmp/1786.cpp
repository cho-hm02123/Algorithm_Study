/* https://www.acmicpc.net/problem/1786 찾기
* 
* 문제: 문자열 매칭
*		두 개의 문자열 P, T에 대해 문자열 P가 문자열 T 중간에 몇번, 어느 위치에서 나타나는지 알아내는 것
*		이때 P는 패턴, T는 텍스트
*	P, T가 주어졌을 때 문자열 매칭 문제를 해결하라
* 
* 입력: 문자열 T, 문자열 P
* 
* 출력: T 중간에 P가 몇번 나타나는지 \n
*	P가 나타나는 위치를 차례로 공백을 구분해 출력 i ~ i+m까지 일치하면 i 출력
* 
* 풀이: 문자열이 공백을 포함해서 주어지므로 getline을 사용
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int ans;
string t, p;

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

	getline(cin, t);
	getline(cin, p);

	vector <int> f = failfunc();
	vector <int> point;
	int j = 0;
	for (int i = 0; i < t.size(); i++) {
		while (j > 0 && t[i] != p[j]) j = f[j - 1];
		if (t[i] == p[j]) j++;
		if (j == p.size()) {
			ans++;
			point.push_back(i - j + 2);
		}
	}

	cout << ans << "\n";
	for (int i = 0; i < point.size(); i++)
		cout << point[i] << " ";

	return 0;
}
