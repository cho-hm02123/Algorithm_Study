/*
  unordered_set include 해주고 쓰기
  vector 선언할 때 처음부터 끝가지 값 간단하게 넣어줄 수 있네
  for auto는 항상 유용하게 쓰는듯
*/

#include <iostream>
#include <cmath>
#include <algorithm>
#include <unordered_set>
#include <string>
#include <vector>

using namespace std;

unordered_set <string> s;
int n;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	while (n--) {
		string name, log;
		cin >> name >> log;
		if (log == "enter") s.insert(name);
		else s.erase(name);
	}

	vector <string> v(s.begin(), s.end());
	sort(v.begin(), v.end(), greater<string>());

	for (auto x : v)
		cout << x << "\n";

	return 0;
}
