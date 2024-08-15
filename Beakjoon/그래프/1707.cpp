/* https://www.acmicpc.net/problem/1707 이분 그래프


문제: 그래프의 정점의 집합을 둘로 분할, 각 집합에 속한 정접끼리 인접하지 않도록 분할 할 수 있을 때 이를 이분그래프라고 함
    그래프가 주어졌을 때 해당 그래프가 이분 그래프인지 판단

입력: TC, 정점의 개수 V, 간선의 수 E, E개의 줄에 걸쳐 간선에 대한 정보

출력: 이분 그래프이면 YSE"\n", 아니면 NO
*/

#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int tc, v, e;
int arr[20001];

bool bfs(vector <int> nd[200001]){

    for(int i = 1; i <= v; i++){
        if(arr[i]!= -1) continue;
        queue <int> q;
        q.push(i);
        arr[i] = 0;

        while(!q.empty()){
            int cur = q.front(); q.pop();
            int nex = (arr[cur] +1)%2;

            for(int j = 0; j < nd[cur].size(); j++){
                if(arr[nd[cur][j]] == -1){
                    arr[nd[cur][j]] = nex;
                    q.push(nd[cur][j]);
                }
                else if(arr[nd[cur][j]] == arr[cur])
                    return false;
            }
        }
    }
    return true;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> tc;
    while(tc--){
        vector <int> nd[20001];
        cin >> v >> e;

        while(e--){
            int a, b;
            cin >> a >> b;
            nd[a].push_back(b);
            nd[b].push_back(a);
        }

        fill(arr, arr+v+1, -1);
        if(bfs(nd))
            cout << "YES\n";
        else
            cout << "NO\n";

    }
}
