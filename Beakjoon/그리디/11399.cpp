/* https://www.acmicpc.net/problem/11399
* 
* 06m 27s
* 
* 문제: N명의 사람이 1~N까지 번호가 메겨져있음
*	i번째 사람이 돈을 인출하는데 걸리는 시간은 Pi
*	모든 사람이 돈을 인출하는데 걸리는 시간의 최솟값
* 
* 입력: N, P
* 
* 출력: 각 사람들이 돈을 인출하는데 걸리는 총 시간의 최소
* 
* 풀이: 시간 적게 걸리는 순으로 오름차순 정렬 후 해당 시간*(n-idx) 곱해서 더해주기
*/

#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

int n;
vector <int> v;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		v.push_back(a);
	}

	sort(v.begin(), v.end());
	int sum = 0;

	for (int i = 0; i < n; i++)
		sum += v[i]*(n-i);

	cout << sum;
	
	return 0;
}
