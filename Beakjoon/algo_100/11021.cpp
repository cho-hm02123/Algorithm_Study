#include <iostream>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    int A, B;
    int count = 1;

    std::cin >> T;

    while (T-- > 0) {
        count ++;
        std::cin >> A >> B;
        std::cout << "Case #" << count << ": " << A + B << "\n";

    }
    return 0;
}