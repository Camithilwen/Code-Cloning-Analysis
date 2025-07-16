/*
 _ _ _   _    _   _    _   _ _ _   _    _   _ __ _   __       __
|  _ _| | |  | | | |  | | |  _  | | |  | | |  __  | |   \   /   |
| |_ _  | |__| | | |  | | | |_| | | |__| | | |__| | | |\ \_/ /| |
|_ _  | |  __  | | |  | | |  _ <  |  __  | |  __  | | | \   / | |
 _ _| | | |  | | | |__| | | |_| | | |  | | | |  | | | |  \_/  | |  _   _   _
|_ _ _| |_|  |_| |_ __ _| |_ _ _| |_|  |_| |_|  |_| |_|       |_| |_| |_| |_|

*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define fi first
#define se second
#define pb push_back
#define all(a) (a).begin(), (a).end()
#define debug(a) cout << #a << " = " << a << " ";
#define endl "\n"
const int MOD=1e9 + 7;
const int N=1000100;
template<typename T> istream &operator>>(istream &is, vector<T> &vec){  
                                                        for (auto &v : vec) is >> v; return is; }
#define dbg(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ") " << __FILE__ << endl;

void solve(){
    long n,k;
    cin>>n>>k;
    long double v[n];
    for(int i=0;i<n;i++){
        cin>>v[i];
        v[i]=(v[i]+1.00)/2.00;
    }
    long double pre[n+1];
    pre[0]=0.0;
    for(int i=0;i<n;i++){
        pre[i+1]=pre[i]+v[i];
    }
    long double ans=0.0;
    for(int i=k;i<=n;i++){
        ans=max(ans,pre[i]-pre[i-k]);
    }
    cout<<setprecision(16)<<ans<<endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long int t = 1;
    // cin>>t;
    for (long int tt = 1; tt <= t; tt++) {
        solve();
    }
    return 0;
}
