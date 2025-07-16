/**
 *   @FileName	f.cpp
 *   @Author	kanpurin
 *   @Created	2020.08.31 16:46:32
**/

#include "bits/stdc++.h" 
using namespace std; 
typedef long long ll;

int main() {
    int h,w;cin >> h >> w;
    set<pair<int,int>> st1; // (現在地,スタート位置)
    multiset<int> st2; // 移動回数
    for (int i = 0; i < w; i++) {
        st1.insert({i,i});
        st2.insert(0);
    }
    for (int i = 0; i < h; i++) {
        int a,b;cin >> a >> b;
        // 現在地が[a,b+1]にあるものをb+1に移動させる.
        // b=wなら∞に移動.
        // 移動させるものの中で一番右のものだけ残す.
        a--;b--;
        auto l = st1.lower_bound({a,-1});
        auto r = st1.upper_bound({b+1,w});
        if (l != r) { // ある
            r--;
            while(l != r) {
                st2.erase(st2.find(l->first-l->second));
                l = st1.erase(l);
            }
            st2.erase(st2.find(r->first-r->second));
            st1.erase(r);
            // b+1への移動
            if (b+1 != w) {
                st1.insert({b+1,r->second});
                st2.insert(b+1-r->second);
            }
        }
        if (st1.empty()) cout << -1 << endl;
        else cout << *st2.begin() + i + 1 << endl;
    }
    return 0;
}