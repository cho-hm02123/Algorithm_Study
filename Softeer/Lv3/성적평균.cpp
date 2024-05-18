/*
    소수점 자리수 맞추기
*/

#include<iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int n, k;
float arr[1000001];

int main(int argc, char** argv)
{
    cin >> n >> k;
    for (int i = 1; i < n + 1; i++)
        cin >> arr[i];
    while (k--) {
        float a, b;
        cin >> a >> b;
        float sum = 0;
        for (int i = a; i < b + 1; i++)
            sum += arr[i];
        float rst = sum / (b - a + 1);
        rst = ceil(rst * 100) / 100.0;
        cout.setf(ios::fixed);
        cout.precision(2);
        cout << rst << "\n";
    }

    return 0;
}
