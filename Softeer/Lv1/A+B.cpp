#include <iostream>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T, a, b;
    int cnt = 1;

    std::cin >> T;

    while (T-- > 0) {
        std::cin >> a >> b;
        std::cout << "Case #" << cnt << ":" << a + b;
        cnt++;
    }
    return 0;
}
