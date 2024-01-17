#include <iostream>
using namespace std;

int first(int a, int b, int c) {
	return (a + b) % c;
}

int second(int a, int b, int c) {
	return ((a % c) + (b % c)) % c;
}

int third(int a, int b, int c) {
	return (a*b) % c;
}

int fourth(int a, int b, int c) {
	return ((a % c) * (b % c)) % c;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int A, B, C;
	cin >> A;
	cin >> B;
	cin >> C;

	cout << first(A, B, C) << '\n';
	cout << second(A, B, C) << '\n';
	cout << third(A, B, C) << '\n';
	cout << fourth(A, B, C) << '\n';
}