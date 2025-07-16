#include <bits/stdc++.h>

const double PI = 3.14159265358979323846;
using namespace std;
typedef long long ll;
const double EPS = 1e-9;
#define rep(i, n) for (int i = 0; i < (n); ++i)
//#define rep(i, n) for (ll i = 0; i < (n); ++i)
//typedef pair<ll, ll> P;
const ll INF = 10e17;
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)
#define ret() return 0;

std::istream &operator>>(std::istream &in, set<ll> &o) {
    ll a;
    in >> a;
    o.insert(a);
    return in;
}

std::istream &operator>>(std::istream &in, queue<int> &o) {
    ll a;
    in >> a;
    o.push(a);
    return in;
}


bool contain(set<int> &s, int a) { return s.find(a) != s.end(); }

//ifstream myfile("C:\\Users\\riku\\Downloads\\0_00.txt");
//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);

//const ll mod = 1e10;
//typedef priority_queue<P, vector<P>, greater<P> > PQ_ASK;



unordered_map<string, ll> check(int n, string &s) {
    unordered_map<string, ll> ans;
    rep(i, 1 << n) {
        string a, b;
        rep(j, n) {
            if ((i >> j) & 1) a.push_back(s[j]);
            else b.push_back(s[j]);
        }
        ans[a + ' ' + b]++;
    }
    return ans;
}

int main() {
    int n;
    string s;
    cin >> n >> s;

    string a = s.substr(0, n);
    string b = s.substr(n);

    unordered_map<string, ll> m1 = check(n, a);
    reverse(b.begin(), b.end());
    unordered_map<string, ll> m2 = check(n, b);

    ll ans = 0;
    for (auto &e : m1) {
        ll now = e.second * m2[e.first];
        ans += now;
    }
    cout << ans << endl;


}
