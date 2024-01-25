/*
stoi 정리
*/

#include <iostream>
#include <istream>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T = 5;
    int i = 0;

    while (T-- > 0) {
        string start, end;
        int h1 = 0, m1 = 0, h2 = 0, m2 = 0, time1 = 0, time2 = 0;

        cin >> start >> end;
        h1 = stoi(start.substr(0, 2));
        m1 = stoi(start.substr(3, 2));
        h2 = stoi(end.substr(0, 2));
        m2 = stoi(end.substr(3, 2));

        time1 = h1 * 60 + m1;
        time2 = h2 * 60 + m2;

        i = i + (time2 - time1);
    }

    cout << i;

    return 0;
}
