#include<bits/stdc++.h>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>

#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long int
#define mod 1000000007
#define inf 1e18+42
#define endl "\n"
#define pi 3.1415926535897932384626433832795028841971693993751058
#define maxn 100005

#define out1(a) cout<<#a<<" "<<a<<endl
#define out2(a,b) cout<<#a<<" "<<a<<" "<<#b<<" "<<b<<endl
#define out3(a,b,c) cout<<#a<<" "<<a<<" "<<#b<<" "<<b<<" "<<#c<<" "<<c<<endl

#define rep(i,a,b) for(int i=a;i<b;i++)
#define repr(i,a,b) for(int i=a;i>=b;i--)
#define fori(it,A) for(auto it=A.begin();it!=A.end();it++)

#define ft first
#define sd second
#define pb push_back
#define mp make_pair
#define pq priority_queue
#define all(x) (x).begin(),(x).end()
#define zero(x) memset(x,0,sizeof(x));
#define ceil(a,b) (a+b-1)/b
 
using namespace std;

int binpow(int a, int b) {
    int res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}

const int N = 1000001; 
  
int factorialNumInverse[N + 1]; 
int naturalNumInverse[N + 1]; 
int fact[N + 1]; 
  
void InverseofNumber(int p) 
{ 
    naturalNumInverse[0] = naturalNumInverse[1] = 1; 
    for (int i = 2; i <= N; i++) 
        naturalNumInverse[i] = naturalNumInverse[p % i] * (p - p / i) % p; 
} 
void InverseofFactorial(int p) 
{ 
    factorialNumInverse[0] = factorialNumInverse[1] = 1; 
  
    for (int i = 2; i <= N; i++) 
        factorialNumInverse[i] = (naturalNumInverse[i] * factorialNumInverse[i - 1]) % p; 
} 
  
void factorial(int p) 
{ 
    fact[0] = 1; 

    for (int i = 1; i <= N; i++) 
    { 
        fact[i] = (fact[i - 1] * i) % p; 
    } 
} 
  
int Binomial(int N, int R, int p) 
{ 
    int ans = ((fact[N] * factorialNumInverse[R]) 
              % p * factorialNumInverse[N - R]) 
             % p; 
    return ans; 
}

//START OF CODE ->->->->->->->

void solve()
{
    int n,m,k;
    cin>>n>>m>>k;
    InverseofNumber(mod);
    InverseofFactorial(mod);
    factorial(mod);
    int b = Binomial(n*m-2,k-2,mod)%mod;
    int x = 0;
    rep(i,1,n){
        int coef = (n-i);
        coef %= mod;
        coef *= m;
        coef %= mod;
        coef *= m;
        coef %= mod;
        coef *= i;
        coef %= mod;
        x += coef;
        x %= mod;
    }
    int y = 0;
    rep(j,1,m){
        int coef = (m-j);
        coef %= mod;
        coef *= n;
        coef %= mod;
        coef *= n;
        coef %= mod;
        coef *= j;
        coef %= mod;
        y += coef;
        y %= mod;
    }

    cout<<(((x+y)%mod)*b)%mod<<endl;

}

//END OF CODE ->->->->->->->->

signed main()
{
    fast;
    int t = 1;
    // cin>>t;

    while(t--)
    {
        solve();
    }
    return 0;
}

