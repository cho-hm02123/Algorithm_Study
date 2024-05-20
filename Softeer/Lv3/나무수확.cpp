#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector> 

using namespace std;

int n,m,sum;
int arr[1001][1001];
int dx[2] = {0,1};
int dy[2] = {1,0};
vector <int> v;

void bt(int a, int b){
    if(a == n-1 && b == n-1){
        int mm = sum + *max_element(v.begin(), v.end());
        m = max(m, mm);
        return;
    }
    for(int i = 0; i < 2; i++){
        int x = a + dx[i];
        int y = b + dy[i];

        if(x > n-1 || y > n-1) continue;
        sum += arr[x][y];
        v.push_back(arr[x][y]);
        bt(x,y);
        v.pop_back();
        sum -= arr[x][y];
    }
} 

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >>arr[i][j];

    sum = arr[0][0];
    v.push_back(arr[0][0]);
    bt(0,0);
    

    cout << m;

    return 0;
}
