/*
문제 : 
입력 : 

풀이 :

*/

#include <iostream>
#include <istream>
#include <string>
#include <cstring>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	string S;
	char c[100] = {0, };
	char a[26] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z' };
	int check[26] = { 0, };

	cin >> S;

	strcpy(c, S.c_str());

	for (int i = 0; i < S.length(); i++) {
		for (int j = 0; j < 26; j++) {
			if (c[i] == a[j]) {
				check[j]++;
				break;
			}
		}
	}

	for (int j = 0; j < 26; j++)
		cout << check[j] << " ";

	return 0;
}
