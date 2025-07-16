#include <iostream>
#include <functional>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <set>
#include <queue>
#include <map>
#include <iomanip>
#include <complex>
#include <random>
#include <bitset>
#include <list>
// #include <prettyprint.hpp>
using namespace std;
#define repi(i,n) for(int i=0;i<n;++i)
#define rep(i,n) for(ll i=0;i<n;++i)
#define repinvi(i,n) for(int i=n-1;i>=0;--i)
#define sll(n) scanf("%lld", &n);
#define sii(n) scanf("%d", &n);
#define slf(n) scanf("%lf", &n);
#define pll pair<ll,ll>
#define pii pair<int,int>
#define psi pair<si,si>
typedef long long ll;
typedef double lf;
typedef short int si;


template<typename T>
class BIT{
    public:
        vector<T> x_list;
        ll n;

        BIT(ll n=1, T fill_value=0): n(n){
            x_list.resize(n+1);
            fill(x_list.begin(), x_list.end(), fill_value);
        }

        void add(ll idx, T v){
            for(ll x=idx; x<= n;x += (x & -x)){
                x_list[x] += v;
            }
        }

        ll get_sum(ll idx){
            T v = 0;
            for(ll x=idx;x>0;x-=(x & -x)){
                v += x_list[x];
            }
            return v;
        }
};

void Main(){
    ll N, Q, c, l, r;
    cin >> N >> Q;
    vector<ll> as(N);
    vector<vector<pll>> qs(N);
    // vector<pll> qs_org(Q);
    vector<ll> ans(Q);
    rep(i, N){
        cin >> as[i];
    }

    rep(i, Q){
        cin >> l >> r;
        -- l;
        -- r;
        qs[r].emplace_back(l, i);
        // qs_org[i] = make_pair(r, l);
    }

    // sort(qs.begin(), qs.end());

    map<ll,ll> color_best;
    // ll now_r = qs[0].first;

    BIT<ll> bitree(N, 0);

    rep(i, N){
        // if(color_best[as[i]]<=i){
            // continue;
        // }
        if(color_best.find(as[i])!=color_best.end() ){
            if(color_best[as[i]]<i){
                bitree.add(color_best[as[i]]+1, -1);
                bitree.add(i+1, 1);
                color_best[as[i]] = i;
            }
        }else{
            bitree.add(i+1, 1);
            color_best[as[i]] = i;
        }
        if(qs[i].size() == 0){
            continue;
        }
        for(auto q:qs[i]){
            ans[q.second] = bitree.get_sum(i+1) - bitree.get_sum(q.first);
        }
    }
    rep(i, Q){
        cout << ans[i] <<endl;
    }

}

int main(){
    Main();
}