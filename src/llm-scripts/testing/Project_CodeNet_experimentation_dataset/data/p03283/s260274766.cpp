#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n,m,q;
ll a[505][505];
ll b[505][505];

int main(){
    cin >> n >> m >> q;
    for(ll i=0;i<m;i++){
        ll l,r;
        cin >> l >> r;
        a[r][l]++;
    }
    for(ll i=0;i<=500;i++){
        for(ll j=0;j<=500;j++){
            b[i][j+1]=b[i][j]+a[i][j];
        }
    }
    for(ll i=0;i<q;i++){
        ll c,d;
        cin >> c >> d;
        ll res=0;
        for(ll j=c;j<=d;j++){
            res+=b[j][d+1]-b[j][c];
        }
        cout << res << endl;
    }
}
