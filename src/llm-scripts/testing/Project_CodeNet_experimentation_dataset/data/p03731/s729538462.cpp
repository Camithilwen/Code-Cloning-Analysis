#include<bits/stdc++.h>
#define fast ios::sync_with_stdio(false);cin.tie(NULL)
using namespace std;
#define int long long
#define MOD 1000000007
typedef vector<int> vi;
typedef pair<int,int> pi;
#define inf 1e18
#define For(i,a,b) for (int i = a; i < b; i++)
#define Rep(i,a,b) for (int i = a; i <= b; i++)
#define ps(x,y) fixed << setprecision(y) << x 
#define pb push_back 
#define mp make_pair 

int a[200005];
 
int32_t main()
{
    fast;
    int n, t, ans = 0; cin >> n >> t;
    For(i, 0, n) cin >> a[i];
    ans += t;
    For(i, 1, n) {
        ans += t;
        if(a[i] < a[i-1] + t) ans -= (a[i-1] + t - a[i]);
    }
    cout << ans;

    
    
    
    return 0;
}