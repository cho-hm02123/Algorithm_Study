/*
  list의 end iterator는 원소를 가리키지 않는다 마지막 원소 뒤의 주소를 가리킨다. 따라서 마지막 원소 *it으로 조회하여면 prev(it)을 해야한다.
  prev는 하나 전 next는 하나 후
  long long형 고려좀 해줘라
*/

#include <iostream>
#include <cmath>
#include <algorithm>
#include <list>

#define X first
#define Y second

using namespace std;
int n;
int arr[500001];
list <pair<long long, long long>> l;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (long long i = 1; i < n + 1; i++) {
		long long a;
		cin >> a;
		l.push_back({ i,a });
	}

	auto it = l.begin();
	while (l.size() != 1) {
		if (it == l.begin()) {
			auto it2 = next(it);
			if ((*it).Y >= (*it2).Y) {
				(*it).Y += (*it2).Y;
				l.erase(it2);
			}
		}
		else if (it == prev(l.end())) {
			auto it1 = prev(it);
			if ((*it).Y >= (*it1).Y) {
				(*it).Y += (*it1).Y;
				l.erase(it1);
			}
		}
		else {
			auto it1 = prev(it);
			auto it2 = next(it);
			if ((*it).Y >= (*it1).Y && (*it).Y >= (*it2).Y) {
				(*it).Y += (*it1).Y;
				(*it).Y += (*it2).Y;
				l.erase(it1);
				l.erase(it2);
			}
			else if ((*it).Y >= (*it1).Y) {
				(*it).Y += (*it1).Y;
				l.erase(it1);
			}
			else if ((*it).Y >= (*it2).Y) {
				(*it).Y += (*it2).Y;
				l.erase(it2);
			}
		}
		if (it == prev(l.end()))
			it = l.begin();
		else
			it++;
	}
	cout << l.front().Y << "\n" << l.front().X;

	return 0;
}
