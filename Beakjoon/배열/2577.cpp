/*
문제 : 주어진 숫자의 곱의 값에 0 ~ 9 까지의 수가 몇개 있는지 출력 
입력 : 100이상 1,000 미만의 자연수 3개 입력

풀이 : 
 0 ~ 9 까지 수가 저장되어있는 배열 생성, 각 숫자의 개수를 저장할 배열 생성
log10()을 이용하여 곱셈 결과의 자릿수 파악 -> #include <cmath>
*/

#include <iostream>
#include <istream>
#include <cmath>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int c[10] = { 0,1,2,3,4,5,6,7,8,9 };
	int check[10] = { 0, };
	int A = 0, B = 0, C = 0, a = 0;

	cin >> A >> B >> C;

	int mul = A * B * C;

	int l = log10(mul) + 1;

	for (int i = 0; i < l; i++) {
		a = mul % 10;
		mul = mul / 10;

		for (int j = 0; j < 10; j++) {
			if (a == c[j]) {
				check[j] ++;
				break;
			}
		}
	}

	for (int j = 0; j < 10; j++)
		cout << check[j] << "\n";

	return 0;
}
