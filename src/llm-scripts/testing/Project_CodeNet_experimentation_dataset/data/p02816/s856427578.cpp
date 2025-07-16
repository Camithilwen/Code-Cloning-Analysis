#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(ll i=0;i<n;i++)
#define REP(i,a,n) for(ll i=a;i<n;i++)

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef tuple<int,int,int> tiii;
typedef pair<ll, ll> pll;

const int INF = 100000000;
const ll LINF = 1e18+5;

ll A[200000];
ll B[200000];
ll C[200000];
ll D[400000];
//ll T[200000];

int main() {
    ll N;
    cin >> N;
    rep(i,N) cin >> A[i];
    rep(i,N) cin >> B[i];
    rep(i,N) {
        C[i] = A[i] ^ A[(i+1)%N];
        D[i] = B[i] ^ B[(i+1)%N];
        D[i+N] = D[i];
    }
    ll pos = 0;
    ll wpos = 0;

    // T構築
    /*ll tpos = 2;
    ll twpos = -1;
    T[0] = -1;
    T[1] = 0;
    while(tpos < N) {
        if (C[tpos-1] == C[twpos]) {
            T[tpos] = twpos + 1;
            tpos++;
            twpos++;
        } else if (twpos > 0) {
            twpos = T[twpos];
        } else {
            T[tpos] = 0;
            tpos++;
        }
    }*/

    vector<int> T(N+1);
    T[0] = -1;
    int j = -1;
    for (int i = 0; i < N; i++) {
        while (j >= 0 && C[i] != C[j]) j = T[j];
        T[i+1] = ++j;
    }

    vector<ll> Ks;

    while(pos + wpos < 2*N-1) {
        if(C[wpos] == D[pos+wpos]) {
            wpos++;
            if(wpos == N) {
                Ks.push_back((N-pos)%N);
                pos = pos + wpos - T[wpos];
                wpos = T[wpos];
            }
        } else {
            pos = pos + wpos - T[wpos];
            if(wpos > 0) wpos = T[wpos];
        }
    }
    sort(Ks.begin(), Ks.end());
    for(auto k : Ks) {
        ll x = B[0] ^ A[k];
        cout << k << " " << x << endl;
    }
    return 0;
}