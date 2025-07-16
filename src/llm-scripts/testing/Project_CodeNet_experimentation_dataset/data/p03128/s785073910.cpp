#include <bits/stdc++.h>
using namespace std;
struct Fast {
    Fast() {
        cin.tie(0);
        ios::sync_with_stdio(false);
        cout << fixed << setprecision(20);
    }
} fast;
template <typename A, size_t N, typename T> void Fill(A (&array)[N], const T& val) {
    std::fill((T*)array, (T*)(array + N), val);
}
// long long mod = 998244353;
#define REP(i, n) for (long long i = 0; i < (n); i++)
#define rep(i, a, n) for (long long i = a; i < (n); i++)
typedef long long ll;
typedef pair<ll, ll> P;
long long mod = 1000000007;
long long modpow(long long m, long long n, long long modvalue) {
    if (n == 0) return 1;
    if (n % 2 == 0) {
        long long t = modpow(m, n / 2, modvalue);
        return t * t % modvalue;
    } else {
        return modpow(m, n - 1, modvalue) * m % modvalue;
    }
}

long long moddiv(long long a, long long b, ll modvalue) { return (a * modpow(b, mod - 2, modvalue)) % modvalue; }

const ll INF = 1LL << 60;

string change_binary(long long a) {
    string ret;
    for (int i = 31; i >= 0; i--) {
        ret += (a >> i & 1) + '0';
    }
    return ret;
}

ll nCkmod(ll n, ll k, ll modvalue) {
    ll numera = 1;
    for (int i = n; i > n - k; i--) {
        numera *= i;
        numera %= modvalue;
    }
    ll denomi = 1;
    REP(i, k) {
        denomi *= (i + 1);
        denomi %= modvalue;
    }
    return moddiv(numera, denomi, modvalue);
}

map<ll, ll> cnt;
void primeFactors(long long n) {
    while (n % 2 == 0) {
        cnt[2]++;
        n = n / 2;
    }
    for (int i = 3; i <= sqrt(n); i = i + 2) {
        while (n % i == 0) {
            cnt[i]++;
            n = n / i;
        }
    }
    if (n > 2) {
        cnt[n]++;
    }
}
vector<ll> dijkstra(vector<vector<P>> graph, ll s) {
    vector<ll> ans(graph.size(), -1);
    priority_queue<P, vector<P>, greater<P>> pq;
    pq.push({0, s});
    while (pq.size() > 0) {
        ll cur1 = 0;
        ll cur2 = 0;
        if (ans[pq.top().second] != -1) {
            pq.pop();
        } else {
            cur1 = pq.top().first;
            cur2 = pq.top().second;
            pq.pop();
            ans[cur2] = cur1;
            for (ll i = 0; i < graph[cur2].size(); i++) {
                pq.push({cur1 + graph[cur2][i].first, graph[cur2][i].second});
            }
        }
    }
    return ans;
}
vector<string> maze;
ll h, w;
bool check(ll y, ll x) {
    if (x < 0 || x >= w || y < 0 || y >= h || maze[y][x] == '#') {
        return false;
    }
    return true;
}
double p;
long double f(long double x) { return x + p / (pow(2, x / 1.5)); }
ll gcd(ll a, ll b) {
    if (a % b == 0) {
        return b;
    } else {
        return gcd(b, a % b);
    }
}
int main() {
    ll n, m;
    cin >> n >> m;
    vector<ll> as(m);
    ll match[10] = {INF, 2, 5, 5, 4, 5, 6, 3, 7, 6};
    REP(i, m) { cin >> as[i]; }
    sort(as.rbegin(), as.rend());
    vector<ll> digit(10001, -INF);
    digit[0] = 0;
    rep(i, 1, n + 1) {
        REP(j, m) {
            if (i - match[as[j]] >= 0) {
                digit[i] = max(digit[i], 1 + digit[i - match[as[j]]]);
            }
        }
    }
    ll k = n;
    REP(i, digit[n]) {
        REP(j, as.size()) {
            if ((k - match[as[j]]) >= 0 && digit[k - match[as[j]]] == digit[k] - 1) {
                k -= match[as[j]];
                cout << as[j];
                break;
            }
        }
    }
}