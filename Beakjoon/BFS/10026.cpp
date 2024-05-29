#include <iostream>
#include <cmath>
#include <algorithm>
#include <stack>
#include <string>

using namespace std;

#define X first
#define Y second

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int n, num;
char arr1[101][101];
char arr2[101][101];
bool flag1[101][101];
bool flag2[101][101];

// (R,G)
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for(int i = 0; i < n; i++){
        string s;
        cin >> s;

        int j = 0;
        for(auto c : s){
            arr1[i][j] = c;
            if(c == 'R' || c == 'G')
                arr2[i][j] = 'R';
            else
                arr2[i][j] = 'B';
            j++;
        }
    }

    stack <pair<int, int>> s1;
    for(int i = 0; i <n; i++)
        for(int j = 0; j < n; j++){
            if(flag1[i][j]) continue;

            s1.push({i,j});
            num++;
            while(!s1.empty()){
                pair <int, int> cur = s1.top(); s1.pop();

                if(flag1[cur.X][cur.Y]) continue;
                flag1[cur.X][cur.Y] = 1;

                for(int h = 0; h < 4; h++){
                    int x = cur.X + dx[h];
                    int y = cur.Y + dy[h];

                    if(x < 0 || y < 0 || x > n-1 || y > n-1 || flag1[x][y] || arr1[cur.X][cur.Y] != arr1[x][y]) continue;
                    s1.push({x,y});
                }
            }
        }

    cout << num << " ";

    num = 0;
    stack <pair<int, int>> s2;
    for(int i = 0; i <n; i++)
        for(int j = 0; j < n; j++){
            if(flag2[i][j]) continue;

            s2.push({i,j});
            num++;
            while(!s2.empty()){
                pair <int, int> cur = s2.top(); s2.pop();

                if(flag2[cur.X][cur.Y]) continue;
                flag2[cur.X][cur.Y] = 1;

                for(int h = 0; h < 4; h++){
                    int x = cur.X + dx[h];
                    int y = cur.Y + dy[h];

                    if(x < 0 || y < 0 || x > n-1 || y > n-1 || flag2[x][y] || arr2[cur.X][cur.Y] != arr2[x][y]) continue;
                    s2.push({x,y});
                }
            }
        }
    cout << num;
    return 0;
}
