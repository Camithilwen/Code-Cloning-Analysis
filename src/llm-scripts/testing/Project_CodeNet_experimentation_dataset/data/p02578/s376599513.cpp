#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    ll x;
    cin>>x;
    ll a[x];
    ll ans = 0;
    ll maxT = 0;
    for(int i=0;i<x;i++) {
        cin>>a[i];
        if(i == 0) {
            maxT = a[0];
        }
        if(i > 0) {
            if(a[i] < a[i-1]) {
                ans += (a[i-1]-a[i]);
                a[i] = a[i-1];
            }
            maxT = a[i];
        }
    }
    // 2 1 5 4 3
    cout<<ans<<endl;

}
