/* https://www.acmicpc.net/problem/14501

문제: N일 동안 최대한 많은 상담
    하루에 하나씩 서로 다른 사람의 상담
    상담을 완료하는데 걸리는 기간 T, 상담을 했을 때 받을 수 있는 금액 P
    얻을 수 있는 최대 금액

입력: N (1<= N <= 15), T, P

출력: 최대 금액
*/

#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

#define X first
#define Y second

int n, mmm;
pair <int, int> arr[16]; // t, p

int bt(int k, int sum){
    int st = k+1;
    
    int mm = 0;
    for(int i = st; i<n+1; i++){
                                    
        bt(k+arr[i].X, sum + arr[i].Y);
        mm = max(mm, sum+arr[i].Y);
    }
    return mm;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for(int i = 1; i < n+1; i++)
        cin >> arr[i].X >> arr[i].Y;

    cout << bt(0,0);

    return 0;
}
