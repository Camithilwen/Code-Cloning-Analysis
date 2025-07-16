#include <bits/stdc++.h>
#include <cstdlib>  //abs()で絶対値を取得する（整数）
#include <cmath>    //abs()かfabs()で絶対値を取得する（少数）
#define rep(i,n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
int main(){
    int n, r;
    cin >> n >> r;
    if (n >= 10){
        cout << r << endl;
    }else{
        int ans = 100 * (10 - n) + r;
        cout << ans << endl;
    }
}