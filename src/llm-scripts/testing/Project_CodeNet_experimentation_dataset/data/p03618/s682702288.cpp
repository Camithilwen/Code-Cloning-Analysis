#include <bits/stdc++.h>
#define rep(i,n) for(ll i=0;i<(n);++i)
#define all(a) (a).begin(),(a).end()
#define dunk(a) cout << (a) << endl
#define rall(a) (a).rbegin(),(a).rend()
const int INF = 2e9;
using namespace std;
using Graph = vector<vector<int>>;
typedef pair<int,int> P;
typedef long long ll;

int main(){
    string s; cin >> s;
    vector<ll> num(26,0);
    ll ans = 0;

    rep(i,s.size()){
        for(char c = 'a'; c<='z'; c++){
            if(c == s[i]) num[c - 'a']++; 
        }
    }

    rep(i,26) ans += (num[i]*(num[i]-1))/2;

    cout << (s.size()*(s.size()-1))/2 - ans + 1 << endl;
}