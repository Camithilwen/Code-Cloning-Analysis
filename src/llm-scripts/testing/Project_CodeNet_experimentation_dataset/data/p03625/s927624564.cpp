#include <bits/stdc++.h>
using namespace std;
 
#define int         long long
#define endl        "\n"
#define pii         pair<int, int>

const int mod = 1e9+7;
const int MAXN = 1e5+5;
const int N = 1e5+5;

int fac[N];
int spf[MAXN]; 

void pre(int p) {
    fac[0] = 1;
    for(int i=1; i<N; i++) {
        fac[i] = (fac[i-1] * i) % p;
    }
}


void sieve() 
{ 
    spf[1] = 1; 
    for (int i=2; i<MAXN; i++) spf[i] = i; 
    for (int i=4; i<MAXN; i+=2) spf[i] = 2; 
  
    for (int i=3; i*i<MAXN; i++) 
    { 
        if (spf[i] == i) 
        { 
            for (int j=i*i; j<MAXN; j+=i) if (spf[j]==j) spf[j] = i; 
        } 
    } 
} 

vector<int> getFactorization(int x) 
{ 
    vector<int> ret; 
    while (x != 1) 
    { 
        ret.push_back(spf[x]); 
        x = x / spf[x]; 
    } 
    return ret; 
} 

unsigned long long power(unsigned long long x, 
                         int y, int p) 
{ 
    unsigned long long res = 1; // Initialize result 
  
    x = x % p; // Update x if it is more than or 
    // equal to p 
  
    while (y > 0) { 
        // If y is odd, multiply x with result 
        if (y & 1) 
            res = (res * x) % p; 
  
        // y must be even now 
        y = y >> 1; // y = y/2 
        x = (x * x) % p; 
    } 
    return res; 
} 
  
// Returns n^(-1) mod p 
unsigned long long modInverse(unsigned long long n, int p) 
{ 
    return power(n, p - 2, p); 
} 
  
// Returns nCr % p using Fermat's little 
// theorem. 
unsigned long long nCr(unsigned long long n, 
                                 int r, int p) 
{ 
    // Base case 
    if (r == 0) return 1; 
    return (fac[n] * modInverse(fac[r], p) % p * modInverse(fac[n - r], p) % p) % p; 
}

///////////////////////////////////////////////////////////////////////////////////////////////////
 
void solve(int TC) { 
   int n; cin >> n;
   map<int, int> cnt;
   for(int i=0; i<n; i++) {
       int x; cin >> x;
       cnt[x]++;
   }
   vector<int> a;
   for(auto it : cnt) {
       if(it.second >= 2) {
           int times = it.second / 2;
           for(int i=0; i<times; i++) {
               a.push_back(it.first);
           }
       }
   }
   sort(a.rbegin(), a.rend());
   if((int)a.size() < 2) {
       cout << 0; return;
   }
   int ans = a[0]*a[1];
   cout << ans;
}
 
signed main() {
 
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(12);
 
 
    int T = 1;
    //cin >> T;
    for(int i=1; i<=T; i++) {
        solve(i);
    }
    return 0;
 
}