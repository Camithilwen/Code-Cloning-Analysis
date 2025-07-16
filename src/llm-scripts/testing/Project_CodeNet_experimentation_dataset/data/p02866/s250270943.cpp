#include<bits/stdc++.h>
#define ll long long int
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
static const ll MAX = 1000000000000000;
static const int NIL = -1;
using namespace std;
const long double EPS = 0.0000000001;
const long double PI = (acos(-1));
const int MOD = 1000000007;

#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")


int main() {

    ll n,a; cin >> n;
    map<ll,ll> mp;
    set<ll> st;
    ll ans = 1;
    ll prev,val;
    bool f = false;

    rep(i,n){
        cin >> a;
        if(mp.count(a) == 0) mp[a] = 1;
        else mp[a] ++;
        st.insert(a);

        if(a == 0 && i != 0){
            cout << 0;
            return 0;
        }
        if(a == 0 && i == 0) f = true;
    }

    if(!f){
        cout << 0;
        return 0;
    }



    for(auto itr = st.begin(); itr != st.end(); ++itr) {
        if(*itr == 0) {
            prev = mp[*itr];
            val = *itr;
        }
        else{
            if(*itr - val != 1){
                cout << 0;
                return 0;
            }
            if(prev == 0){
                cout << 0;
                return 0;
            }
            rep(i,mp[*itr]){
                ans = (prev*ans)%998244353;
            }
            prev = mp[*itr];
            val = *itr;
        }
    }
    cout << ans;


    return 0;
}
