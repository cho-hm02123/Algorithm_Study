#include <iostream>
#include <cmath>
#include <algorithm>
#include <queue>
#include <cctype>

using namespace std;

int t, n;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> t;

    while (t--) {
        bool err = 0;
        bool rv = 0;
        string s, arr;
        deque <int> q;
        cin >> s >> n >> arr;

        int a = 0;
        for (int i = arr.size() - 1; i >= 0; i--) {
            if (isdigit(arr[i])) {
                a++;
            }
            else {
                if (a == 1)
                    q.push_front(arr[i + 1] - '0');
                else if (a == 2) {
                    int k = (arr[i + 1] - '0') * 10 + (arr[i + 2] - '0');
                    q.push_front(k);
                }
                else if (a == 3)
                    q.push_front(100);
                a = 0;
            }
        }

        for (auto c : s) {
            if (c == 'R') {
                if (rv)
                    rv = 0;
                else if (rv == 0)
                    rv = 1;
            }
            else if (c == 'D') {
                if (q.empty()) {
                    err = 1;
                    break;
                }
                else {
                    if (rv)
                        q.pop_back();
                    else
                        q.pop_front();
                }
            }
        }

        if (err)
            cout << "error\n";
        else if (q.empty())
            cout << "[]\n";
        else {
            if (rv == 0) {
                cout << "[" << q.front();
                q.pop_front();
                int sz = q.size();
                for (int i = 0; i < sz; i++) {
                    cout << "," << q.front();
                    q.pop_front();
                }
                cout << "]\n";
            }
            else {
                cout << "[" << q.back();
                q.pop_back();
                int sz = q.size();
                for (int i = 0; i < sz; i++) {
                    cout << "," << q.back();
                    q.pop_back();
                }
                cout << "]\n";
            }
        }
    }
    return 0;
}
