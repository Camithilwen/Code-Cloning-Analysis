#include <bits/stdc++.h>
typedef long long ll;
#define rep(i,a,n) for(ll i = a;i < n;i++)
#define rrep(i,a,n) for(ll i = n; i >= a;i--)
#define index_check(i,n) if(i > n-1 || i < 0) continue; 
#define LINF 1e18
#define INF 1e9
using namespace std;

#define fs first
#define sc second

using P = pair<ll,ll>;
using Pll = pair<P,ll>;
using PQ = priority_queue<P,vector<P>,greater<P>>;

signed main(){
    ll x,y;
    cin >> x >> y;
    if(x < 0 && y < 0){
        if(x > y){
            cout << 2 + x - y << endl;
        }
        else{
            cout << y - x << endl;
        }
    }
    else if(x < 0 && y >= 0){
        if(y == 0){
            cout << abs(x) << endl;
        } 
        else{
            cout << 1 + abs(abs(x) - abs(y)) << endl;
        }
    }
    else if(x >= 0 && y < 0){
        if(x == 0){
            cout << 1 + abs(y) << endl;
        } 
        else{
            cout << 1 + abs(abs(x) - abs(y)) << endl;
        }
    }
    else{
        if(y == 0){
            cout << 1 + x << endl;
        }
        else if(x <= y){
            cout << y - x << endl; 
        }
        else{
            cout << 2 + x - y << endl;
        }
    }
    return 0;
}
