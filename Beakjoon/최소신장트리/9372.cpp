/*
  비행기 종류의 개수라는 것에 주의
*/
#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int t;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;

        for(int i = 1; i< m+1; i++){
            int a, b;
            cin >> a >> b;
        }
        cout << n-1 << "\n";
    }
    return 0;
}
