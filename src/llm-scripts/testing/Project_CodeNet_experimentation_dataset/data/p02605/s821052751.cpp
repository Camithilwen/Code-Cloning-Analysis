#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
const ll MOD = 1e9+7;
const ll INF = 1e16;
#define rep(i,m,n) for(ll i = (m); i <= (n); i++)
#define zep(i,m,n) for(ll i = (m); i < (n); i++)
#define rrep(i,m,n) for(ll i = (m); i >= (n); i--)
#define print(x) cout << (x) << endl;
#define printa(x,m,n) for(int i = (m); i <= n; i++){cout << (x[i]) << " ";} cout<<endl;

const ll N = 2e5 + 10; 
ll n, x[N], y[N];
char c[N];
map<ll, set<ll>> l, r, u, d;

int main(){
    cin.tie(0); ios::sync_with_stdio(false);
    
    
    cin >> n;
    zep(i, 0, n)cin >> x[i] >> y[i] >> c[i];

    ll ans1 = INF;

    zep(i, 0, n){
        if(c[i] == 'L')l[y[i]].insert(x[i]);
        if(c[i] == 'D')u[x[i]].insert(y[i]);
    }

    zep(i, 0, n){
        if(c[i] == 'R' && l.find(y[i]) != l.end()){
            if(l[y[i]].lower_bound(x[i]) != l[y[i]].end()){
                ans1 = min(ans1, (*l[y[i]].lower_bound(x[i])) - x[i]);
            }
        }
        if(c[i] == 'U' && u.find(x[i]) != u.end()){
            if(u[x[i]].lower_bound(y[i]) != u[x[i]].end()){
                ans1 = min(ans1, (*u[x[i]].lower_bound(y[i])) - y[i]);
            }
        }
    }

    ans1 *= 5;
    
    while(!l.empty())l.erase(l.begin());
    while(!u.empty())u.erase(u.begin());
    
    ll ans2 = INF;

    zep(i, 0, n){
        if(c[i] == 'L')l[x[i] - y[i]].insert(y[i]);
        if(c[i] == 'D')d[x[i] - y[i]].insert(y[i]);
    }

    zep(i, 0, n){
        if(c[i] == 'U' && l.find(x[i] - y[i]) != l.end()){
            if(l[x[i] - y[i]].lower_bound(y[i]) != l[x[i] - y[i]].end()){
                ans2 = min(ans2, (*l[x[i] - y[i]].lower_bound(y[i])) - y[i]);
            }
        }
    }

    zep(i, 0, n){
        if(c[i] == 'R' && d.find(x[i] - y[i]) != d.end()){
            if(d[x[i] - y[i]].lower_bound(y[i]) != d[x[i] - y[i]].end()){
                ans2 = min(ans2, (*d[x[i] - y[i]].lower_bound(y[i])) - y[i]);
            }
        }
    }

    while(!l.empty())l.erase(l.begin());
    while(!d.empty())d.erase(d.begin());

    zep(i, 0, n){
        if(c[i] == 'R')r[x[i] + y[i]].insert(y[i]);
        if(c[i] == 'D')d[x[i] + y[i]].insert(y[i]);
    }

    zep(i, 0, n){
        if(c[i] == 'U' && r.find(x[i] + y[i]) != r.end()){
            if(r[x[i] + y[i]].lower_bound(y[i]) != r[x[i] + y[i]].end()){
                ans2 = min(ans2, (*r[x[i] + y[i]].lower_bound(y[i])) - y[i]);
            }
        }
    }

    zep(i, 0, n){
        if(c[i] == 'L' && d.find(x[i] + y[i]) != d.end()){
            if(d[x[i] + y[i]].lower_bound(y[i]) != d[x[i] + y[i]].end()){
                ans2 = min(ans2, (*d[x[i] + y[i]].lower_bound(y[i])) - y[i]);
            }
        }
    }

    ans2 *= 10;

    ll ans = min(min(ans1, ans2), INF);
    if(ans == INF){
        print("SAFE")
    }else{
        print(ans)
    }

    return 0;
}