/* https://www.acmicpc.net/problem/9655
* 
* 06m 14s
* 
* 문제: 탁자 위에 돌 N개 두명이 번갈아 가며 돌을 가져감 
*	돌은 1개 혹은 3개 가져갈 수 있음
*	마지막 돌을 가져가면 이김
*	이기는 사람을 구하는 프로그램
*	상근이가 먼저 시작
* 
* 입력: N
* 
* 출력: 상근이가 이기면 SK를, 창영이가 이기면 CY를 출력
* 
* 풀이: 그냥 홀수면 상근이 짝수면 창영이가 이김
*/

#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int n;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	if (n % 2 == 1)
		cout << "SK";
	else
		cout << "CY";

	return 0;
}
