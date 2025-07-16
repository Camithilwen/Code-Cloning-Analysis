#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;
 
 
int main() {
    int n;
    ll x;
    cin >> n >> x;
    vector<ll> a(n);
    rep(i,n) cin >> a.at(i);
    sort(a.begin(),a.end());
    ll i=0;
    while(x-a.at(i)>=0){
        x-=a.at(i);
        i++;
        if(i==n)break;
    }    
    if(i==n&&x>0)cout << i-1 << endl;
    else cout << i << endl;
}
