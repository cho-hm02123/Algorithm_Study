#include <istream>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <cstring>
#include <list>

using namespace std;
int N;
list <char> l;
list <char> l1;
list <char> l2;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N;

	while (N--) {
		string s1, s2;
		cin >> s1 >> s2;

		for (auto c : s1) {
			l1.push_back(c);
			if(c == 'x' || c == 'X')
				break;
		}
			
		for (auto c : s2) {
			l2.push_back(c);
			if (l2.size() == l1.size())
				break;
		}

		l.push_back(l2.back());
	}

	while (!l.empty()) {
		if (l.front() > 96 && l.front() < 123)
			cout << (char)(l.front() - 32);
		else
			cout << l.front();
		l.pop_front();
	}

	return 0;
}
