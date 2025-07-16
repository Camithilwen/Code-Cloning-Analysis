
#include<bits/stdc++.h>
#define lln long long int
#define llu unsigned lln
#define sc(n) scanf("%d",&n);
#define scl(n) scanf("%lld",&n);
#define scd(n) scanf("%lf",&n);
#define pf(res) printf("%d\n",res);
#define pfl(res) printf("%lld\n",res);
#define pfd(res) printf("%lf\n",res);
#define maxii 100005
using namespace std;
typedef pair<int,int> pii;
typedef pair<lln,lln> pll;
typedef vector<int> vi;
typedef vector<lln> vl;
typedef vector<pii> vii;
typedef vector<pll> vll;


int arr[maxii];
int arr2[maxii];
int gcd(int a,int b)
{
    if(b==0){
      return a;
     }
    return gcd(b,a%b);
}
int lcm(int a,int b)
{
    int res=(a*b)/gcd(a,b);
    return res;
}
int po(int a,int b)
{
    int res=1;
    while(b)
    {
        if(b%2!=0)
        {
            res*=a;
            b--;
        }
        else
        {
            a*=a;
            b/=2;
        }
    }
    return res;
}

lln modMul(lln  a, lln b,lln mod){
    lln ans = 0;
    a = a % mod;
    while (b > 0){
        if ( b % 2 )ans = (ans%mod+ a%mod) % mod;
        a = (a%mod * 2%mod) % mod;
        b /= 2;
    }
    return ans % mod;
}
lln powerMod(lln a,lln b,lln mod){
	if(b==0)return 1LL%mod;
	lln x=powerMod( a,b/2,mod );
	x = ( x%mod * x%mod ) % mod;
	if( b%2==1 )x = ( x%mod * a%mod ) % mod;
	return x%mod;
}

int main()
{
   string a,b,c;
   cin>>a>>b>>c;
   int len=a.size();
   int len2=b.size();
   int len3=c.size();
   if(a[len-1]==b[0] && b[len2-1]==c[0] )cout<<"YES\n";
   else cout<<"NO";

}




