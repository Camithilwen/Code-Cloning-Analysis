#include <bits/stdc++.h>
#pragma GCC optimize("unroll-loops,no-stack-protector")
#pragma GCC target("sse,sse2,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define watch(x) cout << (#x) << " is " << (x) << endl
#define debug cout << "hi" << endl

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

const ll mod = 1e9 + 7;
const int INF32 = 1<<30;
const ll INF64 = 1LL<<60;
const ld pi = 3.141592653589793;

void solve(){
     int n;cin >> n;
     vector<ll>a(n);
     for(int i = 0;i<n;i++) cin >> a[i];
     int cnt = 0;ll sum = 0;ll mini = INT_MAX;
     for(int i = 0;i<n;i++){
        if(a[i]<0) cnt++;
        sum += abs(a[i]);
        mini = min(abs(a[i]),mini);
       // cout << sum <<endl;
     }
     if(cnt%2) cout << sum - 2*mini;
     else cout << sum;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}