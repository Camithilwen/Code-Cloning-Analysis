#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>
#include <string>
#include <set>
#include <bitset>
#include <unordered_map>
#include <cmath>
#include <functional>
#include <map>
#include <cstdlib>

using namespace std;
using ll = long long;
using Pii = pair<int, int>;
using Pll = pair<ll, ll>;
template <class T>
using Vvec = vector<vector<T> >;

template <class T>
void debug(T& v)
{
    for(auto& x: v) cout << x << " ";
    cout << endl;
}

int main()
{
    const ll push = 0;
    const ll pop = 1;
    const ll get = 2;
    struct Data{
        ll key, qid, val;
        Data(): key(0), qid(0), val(0){}
        Data(ll k, ll q, ll v): key(k), qid(q), val(v){}
        bool operator<(const Data& e) const{
            if(key == e.key){
                if(qid == e.qid) return val < e.val;
                return qid < e.qid;
            }
            return key < e.key;
        }
    };

    int N, Q;
    cin >> N >> Q;
    vector<ll> S(N), T(N), X(N), D(Q), ans(Q);
    for(int i=0; i<N; i++) cin >> S[i] >> T[i] >> X[i];
    for(auto& x: D) cin >> x;

    multimap<ll, Pll> mp;
    vector<Data> ds(2*N+Q);
    for(int i=0; i<N; i++){
        ds[2*i] = Data(S[i]-X[i], push, X[i]);
        ds[2*i+1] = Data(T[i]-X[i], pop, X[i]);
    }
    for(int i=0; i<Q; i++) ds[2*N+i] = Data(D[i], get, i);
    sort(ds.begin(), ds.end());

    multiset<ll> Xs;
    for(auto& d: ds){
        ll qid = d.qid;
        ll val = d.val;
        // cout << d.key << " " << qid << " " << val << "\n";
        if(qid == push) Xs.insert(val);
        else if(qid == pop){
            auto itr = Xs.find(val);
            Xs.erase(itr);
        }else{
            if(Xs.empty()) ans[val] = -1;
            else ans[val] = *Xs.begin();
        }
    }

    for(auto& x: ans) cout << x << "\n";
}