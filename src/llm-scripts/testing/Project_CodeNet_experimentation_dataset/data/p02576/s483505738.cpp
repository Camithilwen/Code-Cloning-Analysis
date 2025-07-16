#include <bits/stdc++.h>
#define repr(i,a,b) for(int i=a;i<b;i++)
#define rep(i,n) for(int i=0;i<n;i++)
#define reprrev(i,a,b) for(int i=b-1;i>=a;i--) // [a, b)
#define reprev(i,n) reprrev(i,0,n)
                    
                    
using ll = long long;
using ull = unsigned long long;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
const ll mod = 1e9+7;
void chmod(ll &M){
  if(M >= mod) M %= mod;
  else if(M < 0){
     M += (abs(M)/mod + 1)*mod;
    M %= mod;
}
}
ll modpow(ll x, ll n){
   if(n==0) return 1;
  ll res=modpow(x, n/2);
 if(n%2==0) return res*res%mod;
else return res*res%mod*x%mod;
}
int getl(int i, int N) { return i==0? N-1:i-1; };
int getr(int i, int N) { return i==N-1? 0:i+1; };
long long GCD(long long a, long long b) {
  if (b == 0) return a;
  else return GCD(b, a % b);
}

using namespace std;
/* <-----------------------------------------------------------------------------------> */
/* <-----------------------------------------------------------------------------------> */
/* <-----------------------------------------------------------------------------------> */
/* <-----------------------------------------------------------------------------------> */
/*int main() 
{
    double  D, T, S;
    cin >> D >> T >> S; 
    if (T >= D/S) cout << "Yes" << endl;
    else cout << "No" << endl;
}*/

int main() 
{
    int N, X, T;
    cin >> N >> X >> T;
    int ans = 0, sum = 0;
    while (N > sum)
    {
        ans += T;
        sum += X;
    // cout << ans << endl;
    }
    cout << ans << endl;
    
    
}