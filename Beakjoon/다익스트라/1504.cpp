#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

#define X first
#define Y second

const int INF = 0x3f3f3f3f;
int n, e;
int arr[801];
vector <pair<int, int>> v[801];

long long cal(int st, int en) {
    for (int i = 1; i < n + 1; i++)
        arr[i] = INF;

    priority_queue < pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;
    arr[st] = 0;
    pq.push({ arr[st], st});

    while (!pq.empty()) {
        pair<int, int> cur = pq.top(); pq.pop();
        if (arr[cur.Y] != cur.X) continue;
        for (auto k : v[cur.Y]) {
            if (arr[k.Y] > cur.X + k.X) {
                arr[k.Y] = cur.X + k.X;
                pq.push({ arr[k.Y], k.Y });
            }
        }
    }
    return arr[en];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> e;

    for (int i = 0; i < e; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        v[a].push_back({ c,b });
        v[b].push_back({ c,a });
    }

    int v1, v2;
    cin >> v1 >> v2;

    long long sum1 = cal(1, v1) + cal(v1, v2) + cal(v2, n);
    long long sum2 = cal(1, v2) + cal(v2, v1) + cal(v1, n);
    long long an = min(sum1, sum2);
    if (an >= INF)
        cout << "-1";
    else
        cout << an;

    return 0;
}
