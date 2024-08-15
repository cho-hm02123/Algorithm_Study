/* https://www.acmicpc.net/problem/1389 케빈 베이컨의 6단계 법칙


문제: 임의의 두 사람이 최소 몇 단계만에 이어질 수 있는지
    유저 수와 친구 관계가 입력으로 주어졌을 때 케빈 베이컨의 수가 가장 작은 사람

입력: 유저 수 N, 친구 관계 수 M, m개 줄에 걸쳐 친구 관계

출력: 케빈 베이컨의 수가 갖장 적은 사람 여러명일 경우 번호가 가장 작은 사람
*/

#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int n, m;
int mm = 0x7fffffff;
int ans;
int flag[102];
vector <int> v[102];

int bfs(int k){
    int sum = 0;
    queue <int> q;
    q.push(k);
    flag[k] = 0;

    while(!q.empty()){
        int cur = q.front(); q.pop();

        for(int i = 0; i < v[cur].size(); i++){
            if(flag[v[cur][i]] != -1) continue;
            flag[v[cur][i]] = flag[cur]+1;
            sum += flag[v[cur][i]];
            q.push(v[cur][i]);
        }
    }
    return sum;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    while(m--){
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    for(int i = 1; i <= n; i++){
        fill(flag, flag+n+1, -1);
        int sum = bfs(i);

        if(sum < mm){
            mm = sum;
            ans = i;
        }
    }

    cout << ans;

    return 0;
}
