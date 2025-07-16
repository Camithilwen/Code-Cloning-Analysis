#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define pb push_back
#define all(t) t.begin(), t.end()
#define inrange(i, a, b) (((i)>= min((a), (b))) && ((i) <= max((a), (b))))
typedef vector<ll> vi;
#define fi first
#define se second
#define show(x) cout << #x << " is " << x << "\n";
const ll inf = 9e18;
const ll mod = 1e9 + 7;
const ld pi = 3.141592653589793238462643383279502884;

void print(ll a[], ll n){for(ll i=0;i<n;i++){cout<<a[i]<<" ";}cout<<"\n";}
ll power(ll x, ll y, ll M = inf){
    if(y<=0) return 1;
    ll ans = 1;
    x %= M;
    while(y){
        if(y&1)
            ans = (x * ans) % M;

        x = (x * x) % M;
        y >>= 1;
    }
    return ans;
}
ll modInverse(ll n) {return power(n, mod-2, mod);}
inline ll mul(ll a, ll b){ return (a * b) % mod; }
inline ll sub(ll a, ll b){ ll c = a - b; if(c < 0) c += mod; return c; }
inline ll add(ll a, ll b){ ll c = a + b; if(c > mod) c -= mod; return c; }
inline ll divi(ll a, ll b){ return mul(a, modInverse(b)); }

//------------------------------------------------------------------------------------------

//const ll N = 1e5 + 1;
//vector<ll> adj[N];
//bool visited[N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout<<fixed<<setprecision(10);

    int n;
    cin >> n;
    vector<pair<int, int> > s1, s2;

    for(int i=0;i<n;i++){
        string s;
        cin >> s;
        for(auto it = s.find("()"); it != string::npos; it = s.find("()")) {
            s.erase(it, 2);
        }

        int l = count(all(s), ')');
        int r = count(all(s), '(');

        if (r - l >= 0) {
            s1.push_back(make_pair(l, r));
        }
        else {
            s2.push_back(make_pair(l, r));
        }
    }

    sort(all(s1), [](const auto& l, const auto& r){
        return l.fi < r.fi;
    });
    sort(all(s2), [](const auto& l, const auto& r){
        return l.se > r.se;
    });

    int l = 0, r = 0;
    for (auto s: s1) {
        l = l + s.fi - min(s.fi, r);
        r = r - min(s.fi, r) + s.se;
    }
    for (auto s: s2) {
        l = l + s.fi - min(s.fi, r);
        r = r - min(s.fi, r) + s.se;
    }


    if (l == 0 && r == 0) {
        cout << "Yes";
    }
    else {
        cout << "No";
    }
    return 0;
}
