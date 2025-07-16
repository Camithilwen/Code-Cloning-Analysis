#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define rrep(i,n) for(int i=(n)-1; i>=0; i--)
#define FOR(i,a,b) for(int i=(a); i<(b); i++)
#define RFOR(i,a,b) for(int i=(b-1); i>=(a); i--)
#define ALL(v) v.begin(), v.end()
#define RALL(v) v.rbegin(), v.rend()
#define UNIQUE(v) v.erase( unique(v.begin(), v.end()), v.end() );
#define pb push_back
using ll = long long;
using D = double;
using LD = long double;
using P = pair<int, int>;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

int main(){
    int h,w; cin >> h >> w;
    vector<int> a(h), b(h);
    rep(i,h) {
        cin >> a[i] >> b[i];
        a[i]--;
    }

    map<int, int> mp;
    multiset<int> cand;
    rep(i,w) mp[i] = i;
    rep(i,w) cand.insert(0);

    rep(i,h){
        int l = a[i], r = b[i];
        auto it = mp.lower_bound(l);
        int rb = -1;
        while(it != mp.end() && it -> first <= r){
            chmax(rb, it -> second);
            cand.erase(cand.find(it -> first - it -> second));
            mp.erase(it++);
        }

        if(rb != -1 && r < w){
            cand.insert(r - rb);
            mp[r] = rb;
        }

        int ans = -1;
        if(cand.size()) ans = *cand.begin() + i+1;
        cout << ans << endl;
    }
}
