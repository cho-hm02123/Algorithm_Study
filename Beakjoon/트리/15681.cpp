/* https://www.acmicpc.net/problem/15681 트리와 쿼리

문제: 간선에 가중치와 방향이 없는 임의의 루트 있는 트리가 주어졌을 때 아래 쿼리에 답
    정점 U를 루트로 하는 서브트리에 속한 정점의 수

입력: 트리의 정점 수 N, 루트의 번호 R, 쿼리의 수 Q
    N-1줄에 걸쳐 u, v의 형태로 트리에 속한 간선의 정보
    Q줄에 걸쳐 문제에 설명한 U가 주어짐

출력: Q줄에 걸쳐 각 쿼리의 답을 정수 하나로 출력
*/

#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int n, r, q;
int cnt[100001];
bool flag[100001];
vector <int> v[100001];

int dfs(int cur, int per){
    for(int i = 0; i < v[cur].size(); i++){
        int nxt = v[cur][i];
        if(flag[nxt]) continue;
        if(nxt == per) continue;
        flag[nxt] = 1;
        cnt[cur] += dfs(nxt, cur);
    }
    cnt[cur]++;
    return cnt[cur];
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> r >> q;
    for(int i = 1; i < n; i++){
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    dfs(r,0);
    
    while(q--){
        int a;
        cin >> a;
        cout << cnt[a] << "\n";
    }

    return 0;
}
