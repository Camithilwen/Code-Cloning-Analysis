#include <bits/stdc++.h>
#include <string>
#include <vector>
#include <algorithm>
#define rep(i,n) for (int i = 0;i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
int INF = 1e9;
void chmax(int& a, int b) { a = max(a, b);}
void chmin(int& a,int b) {a = min(a,b);}

int main(){
    int h,w;cin >> h >> w;
    map<int,int> mp;
    multiset<int> m;
    rep(i,w) mp[i] = i;
    rep(i,w) m.insert(0);
    rep(i,h){
        int l,r;cin >> l >> r;
        --l;
        map<int,int>::iterator it = mp.lower_bound(l);
        int mr = -1;
        while(it != mp.end() && it->first <= r){
            mr = it->second;
            m.erase(m.find(it->first - it->second));
            mp.erase(it++);
        }
        if(mr != -1 && r < w) {
            mp[r] = mr;
            m.insert(r-mr);
        }
        int  ans = -1;
        if(m.size()>0) {
            ans = *m.begin() + (i+1);
        }
        cout << ans << endl;

    }
}