#include <bits/stdc++.h>

const double PI = 3.14159265358979323846;
using namespace std;
typedef long long ll;
const double EPS = 1e-9;
#define rep(i, n) for (int i = 0; i < (n); ++i)
//#define rep(i, n) for (ll i = 0; i < (n); ++i)
typedef pair<ll, ll> P;
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


int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> v(n, vector<int>(m));
    rep(i, n) rep(j, m) cin >> v[i][j], v[i][j]--;

//    rep(i, n) reverse(v[i].begin(), v[i].end());

    vector<bool> exclude(m, false);

    int ans = INT_MAX;

    while (count(exclude.begin(), exclude.end(), false) > 0) {
        vector<int> join(m);

        rep(i, n) {
            rep(j, m) {
                int t = v[i][j];
                if (!exclude[t]) {
                    join[t]++;
                    break;
                }
            }
        }

        int now = *max_element(join.begin(), join.end());
//        cout << now << endl;
        cmin(ans, now);
        rep(i, m) {
            if (join[i] == now) {
                exclude[i] = true;
            }
        }

    }
    cout << ans << endl;

}