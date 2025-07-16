#include<bits/stdc++.h>
using namespace std;
/*******  All Required define Pre-Processors and Constants    *******/

#define int long long
#define ull unsigned long long 
#define ld long double
#define mem(a, b) memset(a, (b), sizeof(a))
#define rep(i, j, k) for (int i = j ; i < k ; ++i)
#define rrep(i, j, k) for (int i = j; i > k; --i)
#define all(cont) cont.begin(), cont.end()
#define rall(cont) cont.end(), cont.begin()
#define foreach(i, a) for(auto i: a)
#define forEach(it, l) for (auto it = l.begin(); it != l.end(); it++)
#define in(A, B, C) assert( B <= A && A <= C)
#define debug(a) cout << #a << ": " << a << endl
#define Flag(n) cout << "here " << n << endl
#define w(x) int x;cin>>x;while(t--)
#define mp make_pair
#define pb push_back

#define endl '\n';
#define io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

 

#define TRACE
#ifdef TRACE
#define see(...) __f(#__VA_ARGS__,__VA_ARGS__);
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
    cerr<<name<<" : "<<arg1<<endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
    const char* comma=strchr(names+1,',');cerr.write(names,comma-names)<<" : "<<arg1<<" | ";__f(comma+1, args...);
}
#else
#endif

const int POSITIVE_INFINITY = 9223372036854775807;
const int NEGATIVE_INFINITY = -9223372036854775807;
const int MOD = 1000000007;
const ld PI = acos(-1.0);
const int INF = 1e18;
const int MX = 1000001;


int32_t main() {
    io;
    // freopen("input.txt","r",stdin); 
    // freopen("output.txt","w",stdout);
    int n;
    cin>>n;
    int arr[n],pref[n];
    rep(i,0,n)cin>>arr[i];
    pref[0]=arr[n-1];
    for(int i = 1;i<n;i++){
        pref[i]=pref[i-1]+arr[n-1-i];
        // see(pref[i]);
    }
    int sum = 0;
    for(int i = 0;i<n-1;i++){
        sum=((sum%MOD)+((arr[i]%MOD)*(pref[n-2-i]%MOD))%MOD)%MOD;
    }
    cout<<sum<<endl;

    
 
    return 0;
}
