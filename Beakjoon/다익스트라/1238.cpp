#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

#define X first
#define Y second

const int INF = 0x3f3f3f3f;
int n, m, x; //마을 수 , 길 수 , 약속 장소
int sum;
int xth[1001];
int htx[1001][1001];
vector <pair<int, int>> v[1001];

void cal(int k){
    priority_queue <pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> pq;
    pq.push({0, k});
    htx[k][k] = 0;

    while(!pq.empty()){
        pair <int, int> cur = pq.top(); pq.pop();

        if(htx[k][cur.Y] != cur.X) continue;
        for(auto c : v[cur.Y]){
            if(htx[k][c.Y] <= htx[k][cur.Y] + c.X) continue;
            htx[k][c.Y] = htx[k][cur.Y] + c.X;
            pq.push({htx[k][c.Y], c.Y});
        }
    }
    sum = xth[k] + htx[k][x];
}

void cal_x(){
    priority_queue <pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> pq;
    pq.push({0, x});
    xth[x] = 0;

    while(!pq.empty()){
        pair <int, int> cur = pq.top(); pq.pop();

        if(xth[cur.Y] != cur.X) continue;
        for(auto c : v[cur.Y]){
            if(xth[c.Y] <= xth[cur.Y] + c.X) continue;
            xth[c.Y] = xth[cur.Y] + c.X;
            pq.push({xth[c.Y], c.Y});
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> x;
    for(int i = 1; i < n+1; i++)
        xth[i] = INF;
    for(int i = 1; i <n+1; i++)
        for(int j = 1; j < n+1; j++)
            htx[i][j] = INF;
    
    for(int i = 0; i < m; i++){
        int a, b, t;
        cin >> a >> b >> t;
        v[a].push_back({t, b});
    }

    cal_x();

    int mx = 0;
    for(int i = 1; i < n+1; i++){
        cal(i);
        mx = max(mx, sum);
    }

    cout << mx;

    return 0;
}
