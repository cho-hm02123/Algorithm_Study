	#include <istream>
	#include <iostream>
	#include <string>
	#include <list>

	using namespace std;

	int main() {
		ios_base::sync_with_stdio(false);
		cin.tie(nullptr);
		cout.tie(nullptr);

		int N = 0;

		cin >> N;
	
		while (N--) {
			string key;
			list<char> l = {};
			auto point = l.begin();
			cin >> key;

			for (auto c : key) {
				if (c == '<') {
					if (point != l.begin())
						point--;
				}

				else if (c == '>') {
					if (point != l.end())
						point++;
				}

				else if (c == '-') {
					if (point != l.begin()) {
						point--;
						point = l.erase(point);
					}
				}

				else
					l.insert(point, c);
			}
			for (auto c : l)
				cout << c;
			cout << '\n';
		}

		return 0;
	}
