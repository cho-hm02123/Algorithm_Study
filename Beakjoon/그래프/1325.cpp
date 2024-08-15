/* https://www.acmicpc.net/problem/1325 효율적인 해킹

문제: n개 컴퓨터, 컴퓨터는 신뢰하는 관계, 신뢰하지 않는 관계로 이루어짐
    A가 B를 신뢰하는 경우 B를 해킹하면 A도 해킹 가능
    컴퓨터의 신뢰 관계가 주어졌을 때 한번에 가장 많은 컴퓨터를 해킹할 수 있는 컴퓨터의 번호를 출력

입력: N, M, m개의 신뢰 관계

출력: 한번에 가장 많은 컴퓨터를 해킹할 수 있는 컴퓨터의 번호를 오름차순으로 출력
*/

#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int n, m;
int mm = -1;
vector <int> num;
vector <int> v[10001];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    while(m--){
        int a, b;
        cin >> a >> b;
        v[b].push_back(a);
    }

    for(int i = 1; i <= n; i++){
        bool flag[10001] = {0, };
        int cnt = 0;
        queue <int> q;
        q.push(i);
        flag[i] = 1;

        while(!q.empty()){
            int cur = q.front(); q.pop();

            for(int j = 0; j < v[cur].size(); j++){
                if(!flag[v[cur][j]]){
                    cnt++;
                    flag[v[cur][j]] = 1;
                    q.push(v[cur][j]);
                }
            }
        }

        if(cnt > mm){
            num.clear();
            num.push_back(i);
            mm = cnt;
        }
        else if(cnt == mm)
            num.push_back(i);
    }

    for(int i = 0; i < num.size(); i++)
        cout << num[i] << " ";
}
