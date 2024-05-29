#include <iostream>
#include <cmath>
#include <algorithm>
#include <queue>
#include <tuple>

using namespace std;

const int INF = 0x3f3f3f3f;
int m, n, h;
int arr[101][101][101]; // z,x,y
int dx[6] = {0, 1, 0, -1, 0, 0}; //오아왼위상하
int dy[6] = {1, 0, -1, 0, 0, 0};
int dz[6] = {0, 0, 0, 0, 1, -1};
queue <tuple<int, int, int>> s;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> m >> n >> h;
     
    for(int i = 0; i<h; i++)
        for(int j = 0; j < n; j++)
            for(int k = 0; k <m; k++){
                cin >> arr[i][j][k];
                if(arr[i][j][k] == 1){
                    arr[i][j][k] = 0;
                    s.push({i,j,k});
                }
                else if(arr[i][j][k] == -1)
                    arr[i][j][k] = -1;
                else
                    arr[i][j][k] = INF;
            }

    while(!s.empty()){
        int cz, cx, cy;
        tie(cz, cx, cy) = s.front(); s.pop();
        
        for(int i = 0; i < 6; i++){
            int z = cz + dz[i];
            int x = cx + dx[i];
            int y = cy + dy[i];

            if(z < 0 || x < 0 || y < 0 || z > h-1 || x > n-1 || y > m-1
            || arr[z][x][y] == -1 || arr[z][x][y] == 0) continue;

            if(arr[z][x][y] > arr[cz][cx][cy] + 1){
                arr[z][x][y] = arr[cz][cx][cy] +1;
                s.push({z,x,y});
            }
        }
    }

    int mm = 0;
    for(int i = 0; i<h; i++)
        for(int j = 0; j < n; j++)
            for(int k = 0; k <m; k++)
                mm = max(mm, arr[i][j][k]);

    if(mm == INF) mm = -1;
    cout << mm;

    return 0;
}
