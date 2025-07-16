#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define fi first
#define se second
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int INF = (1<<30) - 1;
const ll LINF = (1LL<<60) - 1;

vector<ll> enum_divisors(ll n){
    vector<ll> res;
    for (ll i = 1; i * i <= n; ++i) {
        if (n % i == 0){
            res.push_back(i);
            if (n/i != i) res.push_back(n/i);
        }
    }
    sort(res.begin(), res.end());
    return res;
}

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<int> sum(n+1, 0);
    vector<int> num(n+1, -1);
    vector<int> res;
    for (int i = n-1; i >= 0; --i) {
        int tmp;
        if (sum[i+1] % 2 != a[i]) {
            tmp = 1;
        } else {
            tmp = 0;
        }

        if (num[i+1] != -1 && num[i+1] != tmp) {
            cout << -1 << endl;
            return 0;
        }
        num[i+1] = tmp;
        if (tmp == 1) {
            res.push_back(i+1);
            auto V = enum_divisors(i+1);
            for (auto v : V) {
                sum[v]++;
            }
        }
    }
    cout << res.size() << endl;
    for (auto v : res) {
        cout << v << endl;
    }
}