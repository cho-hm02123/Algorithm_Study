/* https://www.acmicpc.net/problem/16172 나는 친구가 적다 (Large)
* 
* 문제: 키워드의 존재 여부
* 
* 입력: 문자열  S (숫자 섞여있음)
*	키워드 k
* 
* 출력: 키워드가 교과서에 존재하면 1 아니면 0
* 
* 풀이: 실패함수 사용, s 문자열에 숫자가 등장하면 continue로 i 해당 인덱스 넘겨줌
*/

#include <iostream>
#include <vector>
using namespace std;

string s, k;

vector <int> failfunc() {
	vector <int> f(k.size());

	int j = 0;
	for (int i = 1; i < k.size(); i++) {
		while (j > 0 && k[i] != k[j]) j = f[j - 1];
		if (k[i] == k[j]) f[i] = ++j;
	}

	return f;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> s >> k;

	vector <int> f = failfunc();
	int j = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] >= '0' && s[i] <= '9') continue;
		while (j > 0 && s[i] != k[j]) j = f[j - 1];
		if (s[i] == k[j]) j++;
		if (j == k.size()) {
			cout << 1;
			return 0;
		}
	}

	cout << 0;
	return 0;
}
