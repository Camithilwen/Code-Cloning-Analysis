#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(i = 0;i < n;++i)
#define all(v) v.begin(), v.end()
using ll = long long;

ll n;
vector<vector<ll>> graph(1000*1000);
vector<ll> vdist(1000*1000,-1);
vector<ll> seen(1000*1000,-1);

ll dfs(ll now)
{
    if(seen.at(now) == 2) return vdist.at(now);
    seen.at(now) = 1;
    ll tmp = 0;
    for(auto next:graph.at(now)){
        if(seen.at(next) == 1){
            cout << -1 << endl;
            exit(0);
        }
        tmp = max(tmp, dfs(next)+1);
    }
    seen.at(now) = 2;
    return vdist.at(now) = tmp;
}

int main()
{
    ll i,j;
    cin >> n;
    for(i = 0;i < n;++i){
        ll p = 0;
        rep(j,n-1){
            ll k;
            cin >> k;
            --k;
            ll ni = min(i,k);
            ll nj = max(i,k);
            ll next = ni*n + nj;
            graph.at(p).push_back(next);
            p = next;
        }
    }
    vdist.at(0) = 0;
    dfs(0);
    cout << vdist.at(0) << endl;
    return 0;
}