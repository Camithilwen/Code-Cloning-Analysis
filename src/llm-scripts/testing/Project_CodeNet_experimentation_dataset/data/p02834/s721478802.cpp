#include <bits/stdc++.h>
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
using ll = long long;
using P = pair<int, int>;
ll GCD(ll a, ll b) { return b?GCD(b, a%b):a; }
ll LCM(ll a, ll b) { return a/GCD(a, b)*b; }

int n, u, v;
vector< vector<int> > graphlist(100100, vector<int>());
vector<int> takahashi(100100, -1);
vector<int> aoki(100100, -1);
struct posdata {
    int p; int dist;
};

int main() {
    cin >> n >> u >> v;
    u--; v--;
    takahashi.at(u) = 0; aoki.at(v) = 0;
    for(int i = 0; i < n-1; ++i) {
        int aa, bb; cin >> aa >> bb;
        aa--; bb--;
        graphlist.at(aa).emplace_back(bb);
        graphlist.at(bb).emplace_back(aa);
    }

    queue<posdata> tque;
    posdata tfirst;
    tfirst.p = u; tfirst.dist = 0;
    tque.push(tfirst);
    while(!tque.empty()) {
        posdata now = tque.front();
        tque.pop();
        for(int i = 0; i < (int)graphlist.at(now.p).size(); ++i) {
            int np = graphlist.at(now.p).at(i);
            int ndist = now.dist+1;
            if(takahashi.at(np) == -1) {
                takahashi.at(np) = ndist;
                posdata next;
                next.p = np; next.dist = ndist;
                tque.push(next);
            }
        }
    }

    queue<posdata> aque;
    posdata afirst;
    afirst.p = v; afirst.dist = 0;
    aque.push(afirst);
    while(!aque.empty()) {
        posdata now = aque.front();
        aque.pop();
        for(int i = 0; i < (int)graphlist.at(now.p).size(); ++i) {
            int np = graphlist.at(now.p).at(i);
            int ndist = now.dist+1;
            if(aoki.at(np) == -1) {
                aoki.at(np) = ndist;
                posdata next;
                next.p = np; next.dist = ndist;
                aque.push(next);
            }
        }
    }

    int amax = 0;
    for(int i = 0; i < n; ++i) {
        if(aoki.at(i) > takahashi.at(i)) {
            chmax(amax, aoki.at(i));
        }
    }

    cout << amax-1 << endl;
}