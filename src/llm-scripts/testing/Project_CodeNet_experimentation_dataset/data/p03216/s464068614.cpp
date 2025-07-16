#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
using namespace std;
#define rep(i,x) for(ll i = 0; i < (ll)(x); i++)
#define rrep(i,x) for(ll i = (ll)(x)-1;0 <= i; i--)
#define reps(i,x) for(ll i = 1; i < (ll)(x)+1; i++)
#define rreps(i,x) for(ll i = (ll)(x); 1 <= i; i--)
#define debug(x) cerr << #x << ": " << (x) << "\n";
#define all(x) (x).begin(), (x).end()
typedef long long ll;
typedef long double ld;
typedef pair<int,int> P;
typedef pair<ll,ll> Pll;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;
typedef vector<vector<vector<ll>>> vvvl;
const ll INF = numeric_limits<ll>::max()/4;
const int n_max = 1e5+10;



int main(){
    ll n; cin >> n;
    string s;cin >> s;
    ll q; cin >> q;
    vector<ll> k(q);
    rep(i,q) cin >> k[i];
    auto f = [](auto a, auto b){
        return a + b;
    };
    
    rep(i,q){
        ll kt = k[i];
        ll cnt = 0;
        ll ans = 0;
        ll num = 0;
        ll d_num = 0, m_num = 0;
        rep(i,n){
            num++;
            if(s[i] == 'D')d_num++;
            if(s[i] == 'M'){
                m_num++;
                cnt += d_num;
            }
            if(num > kt){
                if(s[i-kt] == 'M')m_num--;
                if(s[i-kt] == 'D'){
                    d_num--;
                    cnt -= m_num;
                }
                num--;
            }
            if(s[i] == 'C')ans += cnt;
            // debug(i);debug(s[i]);debug(cnt);debug(ans);
        }
        cout << ans << endl;
    }
}