#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for (int i = 0; i < (n); i++)

int main(){

    int n;
    cin >> n;
    int a[n];
    double ave = 0;
    rep(i,n) {
        cin >> a[i];
        ave += a[i];
    }
    ave /= n;
    double d = 1e5;
    int ans = 0;
    rep(i,n){
        if(d > abs(ave-a[i])){
            ans = i;
            d = abs(ave-a[i]);
        }
    }

    
    cout << ans << endl;

    return 0;
}