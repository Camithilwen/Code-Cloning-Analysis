#include <bits/stdc++.h>
using namespace std;
#define int long long   // <-----!!!!!!!!!!!!!!!!!!!

#define rep(i,n) for (int i=0;i<(n);i++)
#define rep2(i,a,b) for (int i=(a);i<(b);i++)
#define rrep(i,n) for (int i=(n)-1;i>=0;i--)
#define rrep2(i,a,b) for (int i=(b)-1;i>=(a);i--)
#define all(a) (a).begin(),(a).end()

typedef long long ll;
typedef pair<int, int> P;
typedef tuple<int, int, int> TUPLE;
typedef vector<int> V;
typedef vector<V> VV;
typedef vector<VV> VVV;

int n, k;
set<string> st;
string a[10];
bool done[10];

void dfs(string s, int c) {
    if (c == k) {
        st.insert(s);
        return;
    }

    rep(i, n) {
        if (!done[i]) {
            done[i] = true;
            dfs(s + a[i], c + 1);
            done[i] = false;
        }
    }
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    while (cin >> n >> k, n) {
        rep(i, n) cin >> a[i];

        st.clear();
        fill(done, done + 10, false);
        dfs("", 0);
        cout << st.size() << endl;
    }

}