#include <iostream>
#include <istream>
#include <string>
#include <stack>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	bool b = 0;

	while (1) {
		string str;
		getline(cin, str);

		stack <char> c;
		if (str == ".")
			break;

		for (auto a : str) {
			if (a == '[' || a == '(')
				c.push(a);

			else if (a == ']' || a == ')') {
				if (c.empty()) {
					b = 0;
					break;
				}

				else {
					if (a == ']' && c.top() == '[')
						c.pop();
					else if(a == ')' && c.top() == '(')
						c.pop();
					else {
						b = 0;
						break;
					}
				}
					
			}

			else if (a == '.') {
				if (c.empty())
					b = 1;
				else
					b = 0;
			}
		}

		if (b == 1)
			cout << "yes\n";
		else
			cout << "no\n";
	}


	return 0;
}
