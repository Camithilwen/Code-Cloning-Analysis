#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> c(n+2);
    rep(i,m){
        int l, r;
        cin >> l >> r;
        c[l]++;
        c[r+1]--;
    }
    rep(i,n+1) c[i+1] += c[i];
    int ans = 0;
    rep(i,n+1) if(c[i] == m) ans++;
    cout << ans << endl;
}