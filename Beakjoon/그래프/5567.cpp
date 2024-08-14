/* https://www.acmicpc.net/problem/5567 결혼식

15m25s

문제: 동기는 모두 N명 번호는 1 ~ N까지 상근이는 1번
    학교 동기 중 자신의 친구와 친구의 친구를 결혼식에 초대
    결혼식에 초대할 사람의 수를 구해라

입력: 동기의 수 n, 리스트의 길이 m, m개 줄에 걸쳐 친구 관계

출력: 결혼식에 초대할 동기 수

풀이: vector, flag를 이용한 그래프
*/

#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int n, m, cnt;
bool flag[501];
vector <int> v[501];

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

    queue <int> q;
    flag[1] = 1;

    for(int i = 0; i < v[1].size(); i++){
        q.push(v[1][i]);
        flag[v[1][i]] = 1;
        cnt++;
    }

    while(!q.empty()){
        int cur = q.front(); q.pop();
        for(int i = 0; i < v[cur].size(); i++){
            if(flag[v[cur][i]]) continue;
            else{
                flag[v[cur][i]] = 1;
                cnt++;
            }
        }
    }

    cout << cnt;
    
    return 0;
}
