#include <bits/stdc++.h>

using namespace std;

#ifndef ONLINE_JUDGE
	#define W(x, y) cerr << "\033[31m" << #x << " = " << x << "\033[0m" << y;
#else
	#define W(x, y)
#endif

using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vii = vector<pii>;
using vl = vector<ll>;
using vll = vector<pll>;
using ld = long double;
#define ff first
#define ss second
const ld pi = acosl(-1);
const ll prime = 1000000000 + 7;
const ll INF = 1000000000;

struct UnionFind{
    vl pai;
    vl rank;
    vl sum;
    UnionFind(ll n): pai(n), rank(n), sum(n){
        iota(pai.begin(), pai.end(), 0);
        fill(rank.begin(), rank.end(), 1);
        fill(sum.begin(), sum.end(), 1);
    }
    ll Find(ll x){
        if(x == pai[x]){
            return x;
        }
        return pai[x] = Find(pai[x]);
    }
    void Union(ll a, ll b){
        a = Find(a);
        b = Find(b);
        if(a == b){
            return;
        }
        if(rank[a] == rank[b]){
            rank[a]++;
        }
        if(rank[a] < rank[b]){
            sum[b] += sum[a];
            pai[a] = b;
        } else{
            sum[a] += sum[b];
            pai[b] = a;
        }
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    ll n, q;
    while(cin >> n >> q){
        vector<tuple<ll, ll, ll>> vet(n);
        map<ll, ll> conj;
        vl res(q, -1);
        for(int i = 0; i < n; ++i){
            ll s, t, x;
            cin >> s >> t >> x;
            vet[i] = make_tuple(x, s, t);
        }
        sort(vet.begin(), vet.end(), [](tuple<ll, ll, ll>a, tuple<ll, ll, ll>b){
            ll as, at, ax;
            tie(ax, as, at) = a;
            ll bs, bt, bx;
            tie(bx, bs, bt) = b;
            if(ax == bx){
                return as < bs;
            }
            return ax < bx;
        });
        for(int i = 0; i < q; ++i){
            ll d;
            cin >> d;
            conj[d] = i;
        }
        vector<ll> aux;
        for(int i = 0; i < n; ++i){
            ll s, t, x;
            tie(x, s, t) = vet[i];
            auto it1 = conj.lower_bound(s-x);
            if(it1 != conj.end()){
                
            }
            auto it2 = conj.lower_bound(t-x);
            if(it2 != conj.begin()){
                it2;
            }
            for(; it1 != it2; ++it1){
                res[it1->ss] = x;
                aux.push_back(it1->ff);
            }
            while(aux.size()){
                conj.erase(aux.back());
                aux.pop_back();
            }
        }

        for(int i = 0; i < q; ++i){
            cout << res[i] << endl;
        }
    }

    
    return 0;
}