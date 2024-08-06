/* https://www.acmicpc.net/problem/1541
* 
* 21m 03s
* 
* 문제: 양수, +,-, 괄호를 이용해 식을 구성
*	이후 괄호를 지움
*	괄호를 적절히 그려 식의 값을 최소로
* 
* 입력: 식
* 
* 출력: 최소 값
* 
* 풀이: 괄호 여러개 쳐도 상관 없어서 - 나오면 무조건 무지성 - 해주면 됨
*/

#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

string s;
int sum, cur;
int pm = 1;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> s;
	for (auto c : s) {
		if (c == '+' || c == '-') {
			sum += cur * pm;
			if (c == '-') pm = -1;
			cur = 0;
		}

		else {
			cur *= 10;
			cur += c - '0';
		}
	}

	sum += cur * pm;
	cout << sum;

	return 0;
}
