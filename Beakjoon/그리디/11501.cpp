/* https://www.acmicpc.net/problem/11501
* 
*  54m 27s
* 
* 문제: 1. 주식을 하나 산다.
*	2. 원하는 만큼 가지고 있는 주식을 판다.
*	3. 아무것도 안한다.
*	
*	날 수, 날 별 주가 주어졌을 때 최대 이익
* 
* 입력: TC, N, 날 별 주가
* 
* 출력: 테스트케이스 별 최대 이익
* 
* 풀이: 맨 뒤 값을 max라고 하고 n-1일 부터 1일까지 검사
*	만약에 max보다 큰 수가 나오면 해당 값을 max값으로 바꿔주고 그렇지 않으면 (max-현재 주가)를 sum에 더해 줌
*/

#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

int tc;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> tc;
	while (tc--) {
		vector <int> v;
		long long sum = 0;
		int n;
		cin >> n;
		for (int i = 1; i <= n; i++) {
			int a;
			cin >> a;
			v.push_back(a);
		}

		int mm = v[n - 1];

		for (int i = n - 2; i >= 0; i--) {
			if (v[i] > mm) mm = v[i];
			else
				sum += mm - v[i];
		}
		cout << sum << "\n";
	}

	return 0;
}
