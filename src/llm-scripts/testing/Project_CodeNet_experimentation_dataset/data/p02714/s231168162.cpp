#include <bits/stdc++.h> 
using namespace std;
using ll = long long;
template<typename T> using v2 = vector<vector<T>>;
template<typename T> inline v2<T> fill(int r, int c, const T& t){ return v2<T>(r, vector<T>(c, t)); }
#define F first
#define S second

void solve(){
    int n;
    string s;
    cin >> n >> s;
    vector<int> r(n), g(n), b(n);
    r[0] = (s[0]=='R');
    for(int i = 1; i < n; ++i) r[i] = r[i-1]+(s[i]=='R');
    g[0] = (s[0]=='G');
    for(int i = 1; i < n; ++i) g[i] = g[i-1]+(s[i]=='G');
    b[0] = (s[0]=='B');
    for(int i = 1; i < n; ++i) b[i] = b[i-1]+(s[i]=='B');

    ll ans = 0;
    for(int i = 0; i < n; ++i){
        for(int j = i+1; j < n; ++j){
            if((s[i]=='R' && s[j]=='G') || (s[i]=='G' && s[j]=='R')){
                ans += b[n-1]-b[j];
                if(2*j-i<n && s[2*j-i]=='B') --ans;
            }
            else if((s[i]=='R' && s[j]=='B') || (s[i]=='B' && s[j]=='R')){
                ans += g[n-1]-g[j];
                if(2*j-i<n && s[2*j-i]=='G') --ans;
            }
            else if((s[i]=='G' && s[j]=='B') || (s[i]=='B' && s[j]=='G')){
                ans += r[n-1]-r[j];
                if(2*j-i<n && s[2*j-i]=='R') --ans;
            }
        }
    }
    cout << ans << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}