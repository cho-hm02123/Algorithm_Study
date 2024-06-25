/*
상근이가 출입구 바로 앞에 있을 때도 고려해줘야함
본래 출입구가 .일때만 sv에 좌표를 저장하였지만,
@이 일때도 좌표를 저장해야함
그래야 마지막에 상근이가 바로 탈츌하는 최단시간 도출 가능
*/

#include <iostream>
#include <cmath>
#include <algorithm>
#include <queue>

using namespace std;

#define X first
#define Y second

int fire[1001][1001];
int sang[1001][1001];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

void rs(int x, int y){
    for(int i = 0; i < x; i++){
        for(int j = 0; j < y; j++){
            fire[i][j] = 0x7fffffff;
            sang[i][j] = 0x7fffffff;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, w, h;  // w = y, h = x
    cin >> n;

    while(n--){
        queue <pair <int, int>> f;
        queue <pair<int, int>> ss;
        queue <pair<int,int>> sv;

        cin >> w >> h;
        rs(h,w);

        for(int i = 0; i < h; i++){
            string s;
            cin >> s;
            int k = 0;
            for(auto c : s){
                if( c == '#'){
                    fire[i][k] = -1;
                    sang[i][k] = -1;
                }
                else if(c == '@'){
                    sang[i][k] = 1;
                    ss.push({i,k});
                    if(i == 0 || i == h-1)
                        sv.push({i,k});
                    else if(k == 0 || k == w-1)
                        sv.push({i,k});
                }
                else if(c == '*'){
                    fire[i][k] = 1;
                    f.push({i,k});
                }
                else if(c == '.'){
                    if(i == 0 || i == h-1)
                        sv.push({i,k});
                    else if(k == 0 || k == w-1)
                        sv.push({i,k});
                }
                k++;
            }
        }

        //fire start
        while(!f.empty()){
            pair <int, int> cur = f.front(); f.pop();

            for(int i = 0; i < 4; i++){
                int x = cur.X + dx[i];
                int y = cur.Y + dy[i];

                if(x < 0 || y < 0 || x > h-1 || y > w-1) continue;
                if(fire[x][y] == -1) continue;

                if(fire[x][y] > fire[cur.X][cur.Y] + 1){
                    fire[x][y] = fire[cur.X][cur.Y] + 1;
                    f.push({x,y});
                }
            }
        } // fire BFS

        while(!ss.empty()){
            pair <int, int> cur = ss.front(); ss.pop();

            for(int i = 0; i < 4; i++){
                int x = cur.X + dx[i];
                int y = cur.Y + dy[i];

                if(x < 0 || y < 0 || x > h-1 || y > w-1) continue;
                if(sang[x][y] == -1) continue;
                
                if(sang[x][y] > sang[cur.X][cur.Y]+1){
                    if(sang[cur.X][cur.Y]+1 < fire[x][y]){
                        sang[x][y] = sang[cur.X][cur.Y] + 1;
                        ss.push({x,y});
                    }
                }
            }
        } // sang BFS

        int m = 0x7fffffff;
        
        while(!sv.empty()){
            pair <int, int> cur = sv.front(); sv.pop();
            m = min(sang[cur.X][cur.Y], m);
        }

        if(m == 0x7fffffff)
            cout << "IMPOSSIBLE\n";
        else
            cout << m <<"\n";

    } //while
    return 0;
}