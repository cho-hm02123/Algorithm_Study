#include <iostream>
#include <istream>
#include <string>
#include <stack>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N = 0;
	int i = 0;
	cin >> N;

	cin.ignore();

	while (N--) {
		stack <char> c;
		string str;
		getline(cin, str);

		for (auto a : str) {
			if (c.empty() || c.top() != a)
				c.push(a);
			else
				c.pop();
		}

		if (c.empty())
			i++;
	}

	cout << i;

	return 0;
}
