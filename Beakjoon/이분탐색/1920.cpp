/*
	<algorithm>에 이분탐색 stl
	사용 전에 오름차순 정렬 해야함
	binary_search(시작,끝,타겟)  > 존재하면 True, 없으면 False 반환
*/

#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int n, m;
int arr[100001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	sort(arr, arr + n);

	cin >> m;
	for (int i = 0; i < m; i++) {
		int a;
		cin >> a;
		cout << binary_search(arr, arr + n, a) << "\n";
	}

	return 0;
}
