#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<ll> v1;
typedef vector<v1> v2;
typedef vector<v2> v3;

typedef unordered_map<ll, unordered_map<ll, ll>> graph;

const ll INF = 1ll << 50;
const ll mod = 1000000007;

ll n;

ll query(ll x){
    cout << x << endl;
    cout << flush;
    string s;
    cin >> s;
    if(s[0] == 'V') exit(0);
    if(s[0] == 'M') return 0;
    if(s[0] == 'F') return 1;
    return -1;
}

int main(){
    cin >> n;
    ll left_state = query(0);
    // ll right_state = query(n-1);
    ll l = 0;
    ll r = n;
    for(ll i = 0;i < 19;i++){
        ll x = (l+r)/2;
        cerr << i << " " << l << " " << r << " " << x << endl;

        ll ret = query(x);
        if((x % 2) == ((left_state+ret)%2)){
            l = x;
        }else{
            r = x;
        }
    }
}
