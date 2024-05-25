#include <iostream>
#include <cmath>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

#define X first
#define Y second

const int INF = 0x3f3f3f3f;
int n, m;
int st, en;
int d[1001];
int path[1001];
vector <pair<int, int>> vv[1001];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for(int i = 1; i < n+1; i++)
        d[i] = INF;

    for(int i = 0; i < m; i++){
        int a, b, w;
        cin >> a >> b >> w;
        vv[a].push_back({w,b});
        path[b] = a;
    }

    cin >> st >> en;
    priority_queue <pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    pq.push({0, st});
    d[st] = 0;
    while(!pq.empty()){
        pair<int, int> cur  = pq.top(); pq.pop();

        if(cur.X != d[cur.Y]) continue;
        for(auto c : vv[cur.Y]){
            if(d[c.Y] <= d[cur.Y] + c.X) continue;
            d[c.Y] = d[cur.Y] + c.X;
            path[c.Y] = cur.Y;
            pq.push({d[c.Y], c.Y});
        }
    }

    cout << d[en] << "\n";
    vector <int> p;
    int kk = en;
    p.push_back(kk);
    while(st!=kk){
        kk = path[kk];
        p.push_back(kk);
    }

    cout << p.size() << "\n";
    reverse(p.begin(), p.end());
    for(auto c : p) cout << c << " ";
    return 0;
}
