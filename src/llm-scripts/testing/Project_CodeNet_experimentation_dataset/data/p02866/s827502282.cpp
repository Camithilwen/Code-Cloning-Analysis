/**
*    author:  souzai32
*    created: 13.08.2020 01:38:59
**/

#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;

int main() {

    int n;
    cin >> n;
    vector<int> d(n);
    rep(i,n) cin >> d.at(i);
    long long ans=1;
    if(d.at(0)!=0) ans=0;
    sort(d.begin(),d.end());
    if(n>2){
        if(d.at(1)==0) ans=0;
    }

    long x=1,y=1;
    for(int i=1; i<n; i++){
        if(d.at(i-1)==d.at(i)) y++;
        else if(d.at(i-1)+1==d.at(i)){
            x=y;
            y=1;
        }
        else ans=0;
        ans*=x;
        ans%=998244353;
    }

    cout << ans << endl;

    return 0;
}