# include <bits/stdc++.h>

using namespace std;

#define pii pair<int, int>
#define pll pair<ll, ll>

#define pb push_back
#define eb emplace_back
#define mp make_pair

#define fi first
#define se second

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

const int inf = (int)1e9 + 7;
const int maxn = (int)6e5 + 7;
const int lmaxn = (int)6e6 + 7;
const ll linf = (ll)1e16 + 7;

const ld eps = ld(1e-11);

const ll dx[] = {-1, 0, 0, 1};
const ll dy[] = {0, -1, 1, 0};

ll gcd(ll a, ll b){
    while(b) a %= b, swap(a, b);
    return a | b;
}

ll lcm(ll a, ll b){
    return a * b / gcd(a, b);
}

string a;

bool ok(string x){
    vector < ll > cnt(27, 0);
    for(ll i : x)
        cnt[i - 'a']++;
    for(ll i : x){
        if(cnt[i - 'a'] > (ll)x.size() / 2)
            return 1;
    }
    return 0;
}

int main(){
  	ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> a;
    for(ll len = 2; len <= min((ll)a.size(), 5ll); ++len){
        for(ll i = 0; i + len - 1 < (ll)a.size(); ++i){
            if(ok(a.substr(i, len))){
                cout << i + 1 << " " << i + len;
                return 0;
            }
        }
    }
    cout << -1 << " " << -1;
    return 0;
}

