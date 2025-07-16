#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <cassert>

using namespace std;
typedef long long LL;
template <typename F, typename S> std::ostream& operator<<(ostream& os, const pair<F,S>& p) {
    os << "(" << p.first << "," << p.second << ")"; return os; }
template <typename T> ostream& operator<<(ostream& os, const vector<T>& v) {
    os << "["; for(const T& a: v){ os << a << ", "; } os << "]"; return os; }
template <typename K, typename V> ostream& operator<<(ostream& os, const map<K,V>& m) {
    os << "{"; for(const auto& p: m){ os << p.first <<":"<< p.second << ", "; } os << "}"; return os; }


LL solve(vector<LL>& a){
    LL res = 0;
    for(LL d = 60; d >= 0; --d){
        LL cur = -1;
        for(LL i = 0; i < a.size(); ++i){
            if(a[i] & (1LL<<d)) cur = i;
        }
        if(cur < 0) continue;
        if((res & (1LL<<d)) == 0){
            res ^= a[cur];
        }
        for(LL i = 0; i < a.size(); ++i){
            if(a[i] & (1LL<<d)) a[i] ^= a[cur];
        }
    }
    return res;
}

int main(){
    LL n;
    cin >> n;
    vector<LL> a(n);
    for(LL i = 0; i < n; ++i){
        cin >> a[i];
    }
    vector<LL> cnt(61);
    for(LL i = 0; i < n; ++i){
        for(LL j = 0; j < 61; ++j){
            if((a[i]>>j)&1) cnt[j] += 1;
        }
    }
    LL ans = 0;
    LL mask = 0;
    for(LL j = 0; j < 61; ++j){
        if(cnt[j] % 2 == 1){
            ans += (1LL << j);
        }else{
            mask |= (1LL << j);
        }
    }
    for(LL i = 0; i < n; ++i){
        a[i] = (a[i] & mask);
    }
    ans += solve(a) * 2;
    cout << ans << endl;
    return 0;
}

