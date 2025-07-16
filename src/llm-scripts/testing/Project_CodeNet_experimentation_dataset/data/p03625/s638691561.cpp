#include<bits/stdc++.h>
#define rep(i,N) for(int i=0;i<(N);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
using namespace std;
const long long MOD = 1e9 + 7;
const long long INF = 1e12;
const int inf = 1e9;
const int mod = 1e9+7;
typedef long long ll;
typedef pair<ll,int> P;
typedef set<int> S;
int main(){
    cout << fixed << setprecision(10);
    int n;
    cin >> n;
    map<ll,int> mli;
    rep(i,n){
        ll x;
        cin >> x;
        mli[x]++;
    }
    vector<pair<ll,int>> v;
    for(auto u : mli){
        v.push_back({u.first,u.second});
    }
    sort(v.begin(),v.end());
    reverse(v.begin(),v.end());
    ll ans = 1;
    bool one = 0;
    for(auto u : v){
        if(u.second>=2){
            if(u.second>=4){
                if(one) cout << ans*u.first << endl;
                else cout << u.first*u.first << endl;
                return 0;
            }
            else{
                if(one) {
                    cout << ans*u.first << endl;
                    return 0;
                }
                else ans *= u.first;
            }
            one = 1;
        }
    }
    cout << 0 << endl; 
    return 0;
}