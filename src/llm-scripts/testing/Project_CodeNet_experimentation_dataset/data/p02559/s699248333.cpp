#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <queue>
#include <set>
#include <map>

#define debug_value(x) cerr << "line" << __LINE__ << ":<" << __func__ << ">:" << #x << "=" << x << endl;
#define debug(x) cerr << "line" << __LINE__ << ":<" << __func__ << ">:" << x << endl;

using namespace std;
typedef long long ll;

template <typename T>
struct bit{
    int n;
    vector<T> data;

    bit(int n_){
        n = 1;
        while(n < n_) n *= 2;
        data = vector<T>(n+1);
        for(int i = 0; i <= n; i++) data[i] = 0;
    }
    
    T sum(int i){
        T ret = 0;
        while(i > 0){
            ret += data[i];
            i -= i&-i;
        }
        return ret;
    }

    void add(int i, T x){
        while(i <= n){
            data[i] += x;
            i += i&-i;
        }
    }
};


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int N, Q; cin >> N >> Q;
    bit<ll> bt(N);
    for(int i = 1; i <= N; i++){
        ll a; cin >> a;
        bt.add(i, a);
    }    
    for(int i = 0; i < Q; i++){
        int t; cin >> t;
        if(t == 0){
            int p; ll x; cin >> p >> x; p++;
            bt.add(p, x);
        }else{
            int l, r; cin >> l >> r; r;
            cout << bt.sum(r)-bt.sum(l) << endl;
        }
    }
}