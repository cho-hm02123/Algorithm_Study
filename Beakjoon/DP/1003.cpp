/* https://www.acmicpc.net/problem/1003
* 
*  16m 06s
* 
* 문제: N번째 피보나치 수를 구하는 c++ 함수를 주어짐
*	N을 입력해 fibonacci(N)을 호출했을 때 0과 1이 각각 몇번 출력되는지
* 
* 입력: TC, TC 만큼 N (N은 40이하 자연수 또는 0)
* 
* 출력: 각 TC마다 0이 출력되느 횟수와 1이 출력되는 횟수
* 
* 풀이: 그냥 주어진 피보나치 함수 쓰면 시간초과
*   식이 f(n) = f(n-1) + f(n-2) 이므로 이를 40까지 다 돌려서 저장한 후 n입력 받아 출력하기
*   이때 초기값인 arr[0][0] = 1; arr[1][0] = 0; arr[0][1] = 0; arr[1][1] = 1;은 입력해 줘야 함
*/

#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int tc, n;
int arr[2][41];

void cal() {
    arr[0][0] = 1;
    arr[1][0] = 0;
    arr[0][1] = 0;
    arr[1][1] = 1;

    for (int i = 2; i < 41; i++) {
        arr[0][i] = arr[0][i - 2] + arr[0][i - 1];
        arr[1][i] = arr[1][i - 2] + arr[1][i - 1];
    }
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

    cin >> tc;

    cal();
    while (tc--) {
        cin >> n;
        cout << arr[0][n] << " " << arr[1][n] << "\n";
    }

	return 0;
}
