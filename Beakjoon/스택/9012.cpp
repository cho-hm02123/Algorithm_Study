#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	int T;
	cin >> T;
	cin.ignore();

	while (T-- > 0) {
		int check = 0;
		stack <char> s;
		stack <char> out;
		string str;
		getline(cin, str);

		for (char ch : str) {
			s.push(ch);
		}

		while (!s.empty()) {
			if (s.top() == '(') {
				if (out.empty())
					check = 1;
				else
					out.pop();
				s.pop();
			}

			else if (s.top() == ')') {
				out.push(s.top());
				s.pop();
			}
		}

		if ((check == 0) & out.empty())
			cout << "YES\n";
		else
			cout << "NO\n";
	}

	return 0;
}
