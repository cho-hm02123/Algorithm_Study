/*
  문자에서 숫자 찾는거 isdgit > #include <cctype>
  string int로 변환 stoi
*/

#include <iostream>
#include <cmath>
#include <algorithm>
#include <map>
#include <string>
#include <cctype>

using namespace std;

int n, m;
string arr[100001];
map <string, int> name_to_i;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	for (int i = 1; i < n + 1; i++) {
		cin >> arr[i];
		name_to_i[arr[i]] = i;
	}

	while (m--) {
		string x;
		cin >> x;
		if (isdigit(x[0]))
			cout << arr[stoi(x)] << "\n";
		else
			cout << name_to_i[x] << "\n";
	}
	return 0;
}
