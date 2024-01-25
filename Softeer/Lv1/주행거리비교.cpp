#include <iostream>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int A, B;

    cin >> A >> B;

    if (A > B)
        cout << "A";
    else if (A < B)
        cout << "B";
    else
        cout << "same";

    return 0;
}
