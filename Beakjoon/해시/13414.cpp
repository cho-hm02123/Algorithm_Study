/*
  cmp 함수 만들어서 쓰기
  주어진 k 보다 v.size()가 더 작을 수 있음을 주의
  min으로 비교할 때 v.size() int로 해줘야함
*/

#include <iostream>
#include <cmath>
#include <algorithm>
#include <unordered_map>
#include <vector>

#define X first
#define Y second

using namespace std;

int k, l;
unordered_map <int,int> u;

bool cmp(const pair<int, int>& a, const pair<int, int>& b) {
	return a.Y < b.Y;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> k >> l;

	for (int i = 0; i < l; i++) {
		int a;
		cin >> a;
		u[a] = i;
	}
	vector <pair<int, int>> v(u.begin(), u.end());
	sort(v.begin(), v.end(), cmp);

	k = min(k, (int)v.size());
	for (int i = 0; i < k; i++) {
		cout.width(8);
		cout.fill('0');
		cout << v[i].X << "\n";
	}

	return 0;
}
