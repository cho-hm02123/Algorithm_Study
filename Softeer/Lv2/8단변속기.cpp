#include <istream>
#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	vector<int> a = { 1, 2, 3, 4, 5, 6, 7, 8 };
	vector<int> d = { 8, 7, 6, 5, 4, 3, 2, 1 };
	vector<int> in(8);

	for (int i = 0; i < 8; i++) 
		cin >> in[i];

	if (in == a) 
		cout << "ascending";
		
	else if (in == d) 
		cout << "descending";
		
	else
		cout << "mixed";
		

	return 0;
}
