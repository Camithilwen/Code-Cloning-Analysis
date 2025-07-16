// C - Factors of Factorial
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

int sieve[1005];
vi primes;

int32_t main()
{
    fast;
    int n, ans = 1; cin >> n;
    for(int x = 2; x <= n; x++) {
        if(sieve[x]) continue;
        for(int u = 2*x; u <= n; u += x) {
            sieve[u] = x;
        }
    }

    Rep(i, 2, n) {
        int cnt = 0;
        if(sieve[i] == 0) {
            int exp = 1;
            while(pow(i, exp) <= n) {
                int x = pow(i, exp);
                cnt += (n/x);
                exp++;
            }
            ans *= (cnt+1);
            ans %= MOD;
        }
    }

    cout << ans;
   
    
    return 0;
}