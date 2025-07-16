#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = a; i < b; i++)
#define Rep(i, a, b) for(int i = a; i <= b; i++)
#define _GLIBCXX_DEBUG
#define Vl vector<ll>
#define Vs vector<string>
#define Vp vector<pair<ll, ll>>
#define P pair<ll, ll>
using ll = long long;
#define ALL(v) (v).begin(),(v).end()
#define endl "\n"
#define chmin(x, y) x = min(x, y)
#define chmax(x, y) x = max(x, y)
#define co(x) cout << x << endl
#define coel cout << endl
#define pb push_back
#define sz(v) ((ll)(v).size())
using namespace std;  
const double pi = acos(-1.0);
const ll MOD = 1e9 + 7;
const ll INF = 1LL << 60;
#define pp pair<ll, pair<ll, ll>> 




////////////////////////////////////////////////////////


int main() {
    string s; cin >> s;
    bool f = true;
    while(f){
        bool f = true;
        rep(i, 0, sz(s)-5){
            if(s[i]=='S'&&s[i+1]=='S'&&s[i+2]=='S'&&
            s[i+3]=='T'&&s[i+4]=='T'&&s[i+5]=='T'){
                s.erase(i, 6);
                f = false;
                i -= 5;
            }
        }
        rep(i, 0, sz(s)-1){
            if(s[i] == 'S' && s[i+1] == 'T'){
                s.erase(i, 2);
                f = false;
                i--;
            }
        }
        if(f) break;
    }
    co(sz(s));

    return 0;
}
