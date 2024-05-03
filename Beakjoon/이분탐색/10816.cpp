/*
  숫자 중복있을 때 개수
  uppper_bound - lower_bound > list면 iterator 반환
*/

#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int n, m;
int s[500001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> s[i];
	sort(s, s + n);

	cin >> m;
	for (int i = 0; i < m; i++) {
		int a;
		cin >> a;
		cout << upper_bound(s, s + n, a) - lower_bound(s, s + n, a) << " ";
	}
	return 0;
}
