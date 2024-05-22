#include <iostream>
#include <cmath>
#include <algorithm>
#include <tuple>
#include <vector>
#include <queue>

using namespace std;

#define X first
#define Y second

int vn, en, cnt, sum;
vector <pair <int, int>> v[10001]; // 가중치, 정점
bool flag[10001];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> vn >> en;
    for(int i = 0; i < en; i++){
        int a, b, cost;
        cin >> a >> b >> cost;
        v[a].push_back({cost, b});
        v[b].push_back({cost, a});
    }

    priority_queue < tuple<int, int, int>, vector <tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;  // 가중치, 정점, 정점
    flag[1] = 1;
    for(auto c : v[1])
        pq.push({c.X, 1, c.Y});
    cnt++;

    while(cnt != vn){
        int a, b, cost;
        tie(cost, a, b) = pq.top(); pq.pop();
        if(flag[b]) continue;
        flag[b] = 1;
        sum += cost;
        cnt++;
        for(auto c : v[b])
            pq.push({c.X, b, c.Y});
    }
    cout << sum;
    return 0;
}
