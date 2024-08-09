/* https://www.acmicpc.net/problem/13144 List of Unique Numbers
* 
* 54m 27s
* 
* 문제: 길이가 N인 수열, 수열에서 연속한 1개 이상의 수를 뽑음
*	같은 수가 여러번 등장하지 않는 경우의 수
* 
* 입력: 수열 길이 N, 수열 원소
* 
* 출력: 경우의 수
* 
* 풀이: 중복되는거 나올 때 뽑고
*	중복되면 중복되기 전 길이 더해줌
*	그리고 st에 해당하는 flag 0으로 바꿔주고 반복 > st값이랑 중복 신경 안써도 되는게 차피 while에 안들어감
*/

#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

int n;
long long cnt;
bool flag[100001];
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

	int en = 0;
	flag[v[en]] = 1;
	for (int st = 0; st < n; st++) {
		while (en < n-1 && !flag[v[en+1]]) {
			en++;
			flag[v[en]] = 1;
		}
		cnt += (en - st + 1);
		flag[v[st]] = 0;
	}
	cout << cnt;
}
