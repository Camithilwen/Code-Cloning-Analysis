#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(i = 0;i < n;++i)
#define all(v) v.begin(), v.end()
using ll = int;

int main()
{
    ll i,j,k;
    ll h,w;
    cin >> h >> w;
    ll inf = 160*80;
    vector<vector<ll>> a(h,vector<ll>(w,0));
    vector<vector<ll>> b(h,vector<ll>(w,0));
    for(i = 0;i < h;++i){
        rep(j,w) cin >> a.at(i).at(j);
    }
    for(i = 0;i < h;++i){
        rep(j,w) cin >> b.at(i).at(j);
    }
    vector<vector<vector<ll>>> dp(h, vector<vector<ll>>(w, vector<ll>(2*inf+1,0)));
    ll tmp = a.at(0).at(0) - b.at(0).at(0);
    dp.at(0).at(0).at(inf + tmp) = 1;
    dp.at(0).at(0).at(inf - tmp) = 1;
    for(i = 0;i < h;++i){
        rep(j,w){
            ll ni = i + 1;
            ll nj = j + 1;
            ll t1, t2;
            if(ni < h) t1 = a.at(ni).at(j) - b.at(ni).at(j);
            if(nj < w) t2 = a.at(i).at(nj) - b.at(i).at(nj);
            rep(k, 2*inf+1){
                if(dp.at(i).at(j).at(k)){
                    if(ni < h){
                        dp.at(ni).at(j).at(k + t1) = 1;
                        dp.at(ni).at(j).at(k - t1) = 1;
                    }
                    if(nj < w){
                        dp.at(i).at(nj).at(k + t2) = 1;
                        dp.at(i).at(nj).at(k - t2) = 1;
                    }
                }
            }
        }
    }
    ll ans = 1e9;
    for(i = 0;i < 2*inf + 1;++i){
        if(dp.at(h-1).at(w-1).at(i)){
            ans = min(ans, abs(i - inf));
        }
    }
    cout << ans << endl;

    return 0;
}