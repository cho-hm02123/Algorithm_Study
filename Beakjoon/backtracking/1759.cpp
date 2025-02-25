/* https://www.acmicpc.net/problem/1759 암호 만들기
* 
* 문제: 암호는 서로 다른 L개의 알파벳 소문자로 동작, 이때 최소 한개의 모음 (a, e, i, o, u)와 최소 두개의 자음으로 구성
*	암호는 오름차순, 사용했을 법한 문자의 종류가 C가지 있을 때 가능한 암호 모두 구하기
* 
* 입력: L, C, C개의 문자 공백을 포함
* 
* 출력: 각 줄에 하나씩 암호 출력
*/

#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int L, C;
int num[16];
char key[16];

bool aeiou(char a) {
	return a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u';
}

void bt(int k, int st) {
	if (k == L) {
		bool flag = 0;
		int cntj = 0;
		int cntm = 0;

		for (int i = 0; i < L; i++) {
			if (aeiou(key[num[i]])) cntm++;
			else cntj++;
		}

		if (cntm >= 1 && cntj >= 2) flag = true;

		if (flag) {
			for (int i = 0; i < L; i++)
				cout << key[num[i]];
			cout << "\n";
		}
		return;
	}

	for (int i = st; i < C; i++) {
		num[k] = i;
		bt(k + 1, i + 1);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> L >> C;

	int jn = 0;
	int mn = 0;
	for (int i = 0; i < C; i++)
		cin >> key[i];

	sort(key, key + C);
	bt(0, 0);

	return 0;
}
