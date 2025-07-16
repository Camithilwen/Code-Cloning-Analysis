                                                                   //author rhythmicankur
                                                                  //god_is_almighty
#pragma GCC optimize("O3")
#pragma GCC target ("sse4")
#include<bits/stdc++.h>
#define f 		first
#define s 		second
#define int     long long
#define ll      int
#define ld 		long double
#define pb 		push_back
#define eb 		emplace_back
#define mk 		make_pair
#define vi 		vector<int>
#define pii 		pair<int,int>
#define pip             pair<int,pii>
#define vpi 		vector<pii>
#define sbcount(x) __builtin_popcountll(x)
#define REP(i,n) for (int i = 1; i <= n; i++)
#define trav(a, x)      for(auto& a : x)
#define all(x)          x.begin(), x.end()
#define fill(a,val)	memset(a,val,sizeof(a))
#define 	PI acos(-1)
#define coud(a,b) cout<<fixed << setprecision((b)) << (a)
#define M1 	998244353
#define M2 	1000000007
#define mod 2038077799
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;

template<typename T> T gcd(T a,T b) { if(a==0) return b; return gcd(b%a,a); } 
#define test4(x,y,z,a) 		    cerr<<#x<<":" <<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<"  |  "<<#a<<": "<<a<<endl;
#define test1(x)                cerr<<#x<<": "<<x<<endl
#define test2(x, y)             cerr<<#x<<": "<<x<<" | "<<#y<<": "<<y<<endl
#define test3(x, y, z)          cerr<<#x<<":" <<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<endl
ll power(ll a,ll b,ll m=M2){ll answer=1;while(b){if(b&1)answer=(answer*a)%m;b/=2;a=(a*a)%m;}return answer;}
using namespace std;
void ctrl(){cout<<"Control"<<endl;}
int make_num(string p){stringstream geek(p); int x = 0; geek >> x;return x;}
string make_str(int x){ostringstream str1; str1 << x; string geek = str1.str(); return geek;}

signed main()
{	ios::sync_with_stdio(0);
	cin.tie(0); 
	cin.exceptions(cin.failbit);
	int n;
    cin>>n;
    int A[n],B[n];
    int dA[n],dB[n];
    for(int i=0;i<n;i++)cin>>A[i];
    
    for(int i=0;i<n;i++)cin>>B[i];
    
    for(int i=0;i<n;i++)
    {
        dA[i] = A[(i+1)%n]^A[i];
        dB[i] = B[(i+1)%n]^B[i];
    }
    int hashB=0;
    int base = 1400312813;
    for(int i=0;i<n;i++)
    {
        hashB*=base;
        hashB%=mod;
        hashB+=dB[i];
        hashB%=mod;
    }
    int hashA=0;
    for(int i=0;i<n;i++)
    {
        hashA*=base;
        hashA%=mod;
        hashA+=dA[i];
        hashA%=mod;
    }
    int exp = power(base,n-1,mod);
    vi ans;
    for(int i=0;i<n;i++)
    {
        if(hashA==hashB)
        ans.pb(i);

        int val = exp*dA[i];
        val%=mod;
        hashA+=mod - val;
        hashA%=mod;
        hashA*=base;
        hashA%=mod;
        hashA+=dA[i];
        hashA%=mod;
    }
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" "<<(A[0]^B[(n-ans[i])%n])<<'\n';
    }
return 0;
}