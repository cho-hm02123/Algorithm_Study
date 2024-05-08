/*
  unique 함수를 사용하면 중복되는 원소를 지울 수 있음.
  하지만 사이즈는 그대로고 나머지에 쓰레기 값이 차기 때문에 erase를 사용하여 뒤에 쓰레기 값을 없애줘야함
  */
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

int n;
int arr[1000001];
vector <int> v;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		v.push_back(arr[i]);
	}
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());

	for (int i = 0; i < n; i++)
		cout << lower_bound(v.begin(), v.end(), arr[i]) - v.begin() << " ";

	return 0;
}
