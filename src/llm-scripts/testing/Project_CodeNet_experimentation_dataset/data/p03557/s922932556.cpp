#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repr(i, a, b) for(int i = a; i < b; i++)
#define  all(x) (x).begin(),(x).end()     // 昇順ソート
#define  rall(v) (v).rbegin(), (v).rend() // 降順ソート
#define  FastIO ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
typedef long long ll;
typedef long long int lli;
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return true; } return false; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return true; } return false; }

int dx[] = {1, 1, 0, -1, -1, -1, 0, 1};
int dy[] = {0, 1, 1, 1, 0, -1, -1, -1};

int main(){
    FastIO;
    int n;
    cin >> n;
    vector<int> a(n), b(n), c(n);
    rep(i,n){
        cin >> a[i];
        a[i]*=-1;
    } 
    rep(i,n) cin >> b[i];
    rep(i,n) cin >> c[i];
    sort(all(a));
    sort(all(b));
    sort(all(c));

    ll ans = 0;
    for(int i = 0; i < n; i++){
        int bi = b[i];
        auto itrA = upper_bound(all(a), -bi);
        if (itrA == a.end()) continue;
        size_t posA = distance(a.begin(), itrA);

        auto itrC = upper_bound(all(c), bi);
        if (itrC == c.end()) continue;
        size_t posC = distance(c.begin(), itrC);

        ll cntA = n-posA;
        ll cntC = n-posC;
        ans += cntA * cntC;
    }

    cout << ans << endl;
}