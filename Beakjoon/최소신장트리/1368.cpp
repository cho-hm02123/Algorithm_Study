/*
우물을 0번째 정점이라 생각하고 우물파는 비용을 각각 정점에 맞춰 넣어줌
*/

#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

#define X first
#define Y second
#define ll long long
ll n, sum;
vector <pair<ll, ll>> v[301];
bool flag[301];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for(ll i = 1; i < n+1; i++){
        ll a;
        cin >> a;
        v[0].push_back({a,i});
        v[i].push_back({a,0});
    }

    for(ll i = 1; i < n+1; i++)
        for(ll j = 1; j < n+1; j++){
            ll a;
            cin >> a;
            if(i==j) continue;
            v[i].push_back({a, j});
        }
    priority_queue <tuple<ll, ll, ll>, vector<tuple <ll, ll, ll>>, greater<tuple<ll,ll,ll>>> pq;
    for(auto c : v[0])
        pq.push({c.X, 0, c.Y});
    flag[0] = 1;
    int cnt = 0;
    while(cnt != n){
        ll a, b, cost;
        tie(cost, a, b) = pq.top(); pq.pop();

        if(flag[b]) continue;
        flag[b] = 1;

        for(auto c : v[b])
            pq.push({c.X, 0, c.Y});
        sum += cost;
        cnt++;
    }

    cout << sum;
    return 0;
}
