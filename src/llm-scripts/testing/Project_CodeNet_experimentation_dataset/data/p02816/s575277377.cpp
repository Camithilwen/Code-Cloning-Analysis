#include <bits/stdc++.h>
using namespace std;
#define FOR(i, a, b) for(int i=(a);i<(b);++i)
#define rep(i, n) FOR(i, 0, n)
#define whole(x) (x).begin(),(x).end()
#define UNIQUE(v) v.erase(unique(v.begin(), v.end()), v.end())
using ll = long long;
using P = pair<int, int>;
const int mod = 1000000007;

// Morris-Pratt
// https://youtu.be/9MphwmIsO7Q?t=7283
template<typename T>
struct MP {
    int n;
    T t;
    vector<int> a;
    MP() {}
    MP(const T& t): t(t) {
        n = t.size();
        a = vector<int>(n+1);
        a[0] = -1;
        int j = -1;
        for (int i = 0; i < n; ++i) {
            while (j != -1 && t[j] != t[i]) j = a[j];
            j++;
            a[i+1] = j;
        }
    }
    int operator[](int i) { return a[i];}
    vector<int> findAll(const T& s) {
        vector<int> res;
        int j = 0;
        for (int i = 0; i < s.size(); ++i) {
            while (j != -1 && t[j] != s[i]) j = a[j];
            j++;
            if (j == n) {
                res.push_back(i-j+1);
                j = a[j];
            }
        }
        return res;
    }
};

int main(){
    ll n;
    cin >> n;
    vector<ll> a(n);
    vector<ll> b(n);
    rep(i, n) cin >> a[i];
    rep(i, n) cin >> b[i];
    
    vector<ll> ax(n);
    vector<ll> bx(n);
    rep(i, n) {
        ax[i] = a[i]^a[(i+1)%n];
        bx[i] = b[i]^b[(i+1)%n];
    }
    ax.insert(ax.end(), ax.begin(), ax.end());
    
    MP<vector<ll>> mp(bx);
    vector<int> match = mp.findAll(ax);
    for (int e:match) {
        if (e>=n) continue;
        ll x = a[e] ^ b[0];
        cout << e << " " << x << endl;
    }
    
    
   
    //cout << ans << endl;
    return 0;
}
