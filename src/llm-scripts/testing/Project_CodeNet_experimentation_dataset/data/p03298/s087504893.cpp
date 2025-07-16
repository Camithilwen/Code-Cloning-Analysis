#pragma GCC optimize("O3")
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <string>
#include <cstring>
#include <deque>
#include <list>
#include <queue>
#include <stack>
#include <vector>
#include <utility>
#include <algorithm>
#include <map>
#include <set>
#include <complex>
#include <cmath>
#include <limits>
#include <cfloat>
#include <climits>
#include <ctime>
#include <cassert>
#include <numeric>
#include <fstream>
#include <functional>
#include <bitset>
using namespace std;

using ll = long long;
using P = pair<int, int>;
using T = tuple<int, int, int>;

template <class T> inline T chmax(T &a, const T b) {return a = (a < b) ? b : a;}
template <class T> inline T chmin(T &a, const T b) {return a = (a > b) ? b : a;}

constexpr int MOD = 1e9 + 7;
constexpr int inf = 1e9;
constexpr long long INF = 1e18;
constexpr double pi = acos(-1);
constexpr double EPS = 1e-10;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n; cin>>n;
    string s; cin>>s;
    string head = s.substr(0, n);
    string tail = s.substr(n, n);
    reverse(tail.begin(), tail.end());
    
    map<pair<string, string>, ll> head_paint, tail_paint;
    for(int bit=0; bit<(1<<n); bit++){
        string ha, hb, ta, tb;
        for(int i=0; i<n; i++){
            if(bit & (1 << i)){
                ha += head[i];
                ta += tail[i];
            }
            else{
                hb += head[i];
                tb += tail[i];
            }
        }

        reverse(hb.begin(), hb.end());
        reverse(tb.begin(), tb.end());

        head_paint[make_pair(ha, hb)]++;
        tail_paint[make_pair(ta, tb)]++;
    }

    ll ans = 0;
    for(auto i : head_paint){
        ans += i.second * tail_paint[make_pair(i.first.first, i.first.second)];
    }

    cout << ans << endl;
}