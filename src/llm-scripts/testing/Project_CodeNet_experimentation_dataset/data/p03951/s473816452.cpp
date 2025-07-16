#include<bits/stdc++.h>
#define forr(i, a, b) for(int i = (a); i < (b); i++)
#define rep(i,n) for(int i = 0; i < (n); i++)
#define rrep(i,n) for(int i = 1; i <= (n); i++)
#define ALL(a) (a.begin()),(a.end())
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<ll, ll> LP;
const ll LINF = 1LL<<60;
const int INF = 1001001001;
const int MOD = 1000000007;

/* --------------------------------------------------- */

int main() {
    int n;
    string s, t;
    cin >> n >> s >> t;
    int ans = s.size() + t.size();
    int tot = 0;
    for(int i = n - 1; i >= 0; i--) {
        bool check = true;
        for(int j = i; j < n; j++) {
            if(s[j] != t[j - i]) check = false;
        }
        if(check) tot = n - i;
    }
    cout << ans - tot << endl;

    return 0;
}