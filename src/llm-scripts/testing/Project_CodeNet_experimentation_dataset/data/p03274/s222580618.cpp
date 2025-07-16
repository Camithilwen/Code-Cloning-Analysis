/**
*    author:  souzai32
*    created: 14.08.2020 14:10:05
**/

#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;

int main() {

    int n,k;
    cin >> n >> k;
    vector<long long> x(n);
    rep(i,n) cin >> x.at(i);
    long long left,right;
    long long ans=1e9;

    rep(i,n-k+1){
        left=x.at(i);
        right=x.at(i+k-1);
        ans=min(ans,min(abs(left)+abs(left-right),abs(right)+abs(left-right)));
        // cout << left << ' ' << right << endl;    
    }
    cout << ans << endl;

    return 0;
}