/* https://www.acmicpc.net/problem/6118 숨바꼭질


문제: 헛간의 개수 N, 모든 헛간은 M개의 양방향 길로 이어짐
    냄새는 1번 헛간에서 거리가 멀어질 수록 감소

입력: N, M, M개의 관계

출력: 숨어야 하는 헛간 번호(여러개면 가장 작은 번호), 헛간까지의 거리, 해당 헛간과 같은 거리를 갖는 헛간의 개수
*/

#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int n, m;
int mm = -1;
int arr[20001];
vector <int> v[20001];
vector <int> num;

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

    for(int i = 1; i <= n; i++)
        arr[i] = 0x7fffffff;
    
    queue <int> q;
    q.push(1);
    arr[1] = 0;

    while(!q.empty()){
        int cur = q.front(); q.pop();

        for(int i = 0; i < v[cur].size(); i++){
            if(arr[v[cur][i]] > arr[cur] + 1){
                arr[v[cur][i]] = arr[cur] + 1;
                q.push(v[cur][i]);
            }
        }
    }

    for(int i = 2; i <= n; i++){
        if(arr[i] > mm){
            num.clear();
            mm = arr[i];
            num.push_back(i);
        }
        else if(arr[i] == mm)
            num.push_back(i);
    }

    cout << num[0] << " " << arr[num[0]] << " " << num.size();
}
