/*
  cur = l.erase(cur)을 하면 iterator가 지운 뒤의 원소 가리킴
*/


#include <istream>
#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <list>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	string a;
	cin >> a;

	list<char> l;

	for (auto c : a)
		l.push_back(c);
	auto cur = l.end();

	int N;

	cin >> N;

	while (N--) {
		char e;
		cin >> e;

		if (e == 'L') {
			if (cur == l.begin()) continue;
			else
				cur--;
		}

		else if (e == 'D') {
			if (cur == l.end()) continue;
			else
				cur++;
		}

		else if (e == 'B') {
			if (cur == l.begin()) continue;
			else {
				cur--;
				cur = l.erase(cur);
			}
		}

		else if (e == 'P') {
			cin >> e;
			l.insert(cur, e);
		}
	}

	while (!l.empty()) {
		cout << l.front();
		l.pop_front();
	}

	return 0;
}
