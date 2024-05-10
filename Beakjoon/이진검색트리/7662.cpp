/*
  end()의 iterator가 끝 원소의 다음 위치를 반환하므로 끝 원소의 iterator를 알고 싶으면 prev(ms.end())를 사용해야함
  c 포인터에서 했던거처럼 auto로 iterator 주소 저장하고 *it 하면 해당 주소의 값이 반환됨
*/

#include <iostream>
#include <cmath>
#include <algorithm>
#include <set>

using namespace std;

int t, n;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> t;
	while (t--) {
		cin >> n;
		multiset <int> ms;
		for (int i = 0; i < n; i++) {
			char c;
			int a;

			cin >> c >> a;
			if (c == 'I')
				ms.insert(a);
			else {
				if (ms.empty()) continue;
				if (a == -1)
					ms.erase(ms.begin());
				else if (a == 1)
					ms.erase(prev(ms.end()));
			}
		}
		if (ms.empty())
			cout << "EMPTY" << "\n";
		else {
			auto it1 = ms.begin();
			auto it2 = prev(ms.end());
			cout << *it2 << " " << *it1 << "\n";
		}
	}

	return 0;
}
