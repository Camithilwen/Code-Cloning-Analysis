#include <bits/stdc++.h>
using namespace std;

#define NDEBUG
#ifdef DEBUG
#include "../cout11.h"
#undef NDEBUG
#endif
#include <cassert>

typedef long long ll;
typedef long double Double;
typedef unsigned long long ull;
typedef pair<int,int> ii;
typedef pair<ll,ll> llll;
typedef pair<double,double> dd;

typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ii> vii;
typedef vector<vector<ii>> vvii;
typedef vector<ll> vll;
typedef vector<string> vs;
typedef vector<double> vd;
typedef vector<long double> vD;

#define sz(a)  int((a).size())
#define pb  push_back
#define FOR(var,from,to) for(int var=(from);var<=(to);++var)
#define rep(var,n)  for(int var=0;var<(n);++var)
#define rep1(var,n)  for(int var=1;var<=(n);++var)
#define repC2(vari,varj,n)  for(int vari=0;vari<(n)-1;++vari)for(int varj=vari+1;varj<(n);++varj)
#define ALL(c)  (c).begin(),(c).end()
#define RALL(c)  (c).rbegin(),(c).rend()
#define tr(i,c)  for(auto i=(c).begin(); i!=(c).end(); ++i)
#define found(s,e)  ((s).find(e)!=(s).end())
#define mset(arr,val)  memset(arr,val,sizeof(arr))
#define mid(x,y) ((x)+((y)-(x))/2)
#define IN(x,a,b) ((a)<=(x)&&(x)<=(b))
#define cons make_pair


long long max_box_area_in_histogram(vector<int>& a) {
    int N = a.size();

    vector<int> L(N);
    stack<int> st;

    for (int i=0; i<N; ++i) {
        while (!st.empty() && a[st.top()] >= a[i]) {
            st.pop();
        }
        L[i] = (st.empty() ? -1 : st.top())+1;
        st.push(i);
    }

    while (!st.empty()) st.pop();

    vector<int> R(N);
    for (int i=N-1; i>=0; --i) {
        while (!st.empty() && a[st.top()] >= a[i]) {
            st.pop();
        }
        R[i] = (st.empty() ? N : st.top())-1;
        st.push(i);
    }

    long long smax = 0;
    for (int i=0; i<N; ++i) {
        int h = a[i], w = R[i] - L[i] + 1;
        // ll s = (long long)h * w;
        ll s = (long long)(h + 1)*(w + 1);
        smax = max(smax, s);
    }

    return smax;
}

ll solve(int H, int W, vector<string>& s) {
    vvi a(H-1, vi(W-1, 0));
    rep(r, H-1) {
        rep(c, W-1) {
            a[r][c] = (s[r][c] == '#') ^ (s[r][c+1] == '#')
                    ^ (s[r+1][c] == '#') ^ (s[r+1][c+1] == '#');
        }
    }

    ll best = max(W, H);

    vi histo(W-1, 0);
    rep(r, H-1){
        rep(c, W-1) {
            if (a[r][c]) histo[c] = 0;
            else         histo[c]++;
        }
        best = max(best, max_box_area_in_histogram(histo));
    }

    return best;
}

int main() {
    int H, W; cin >> H >> W;
    vector<string> s(H);
    rep(i, H) cin >> s[i];
    cout << solve(H,W,s) << endl;
    return 0;
}
