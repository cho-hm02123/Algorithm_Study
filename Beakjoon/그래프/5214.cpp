/* https://www.acmicpc.net/problem/2617 구슬 찾기


문제: 하이퍼튜브 하나는 역 K개를 연결
    1번 역에서 N번 역으로 가는데 방문하는 최소 역의 수는?

입력: 역의 수 N, 연결하는 역의 수 K, 하이퍼튜브의 개수 M, M개의 줄에 하이퍼튜브가 연결하는 역의 정보

출력: 1번 역에서 N번 역으로 가는데 방문한 역의 최소 개수 만약 갈 수 없다면 -1출력
*/

#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int n, m, k;
int arr[101002];
vector <int> v[101002];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k >> m;
    for(int i = 1; i <= m; i++)
        for(int j = 1; j <= k; j++){
            int a;
            cin >> a;
            v[n+i].push_back(a);    //하이퍼튜브를 하나의 정점으로 생각하고 풀이
            v[a].push_back(n+i);
        }

    fill(arr, arr+n+m+1, -1);
    queue <int> q;
    q.push(1);
    arr[1] = 0;

    while(!q.empty()){
        int cur = q.front(); q.pop();

        for(int i = 0; i < v[cur].size(); i++){
            if(arr[v[cur][i]]==-1){
                arr[v[cur][i]] = arr[cur]+1;
                q.push(v[cur][i]);
            }
        }
    }

    if(arr[n] == -1)
        cout << -1;
    else
        cout << arr[n]/2 + 1; // 하이퍼튜브를 거친 횟수를 빼줘야 하므로 2로 나눔
    return 0;
}
