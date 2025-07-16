//Now you are making me a boy with luvv...
//I don't want to do this but I'm being forced to ....pls help!!
#include <bits/stdc++.h>
using namespace std;
#define loop(x,n) for(int x = 0; x < n; ++x)
#define ed end()  
#define bg begin()
# define ld long double
#define ll long long
#define ub(v,a) upper_bound(all(v),a)
#define lb(v,a) lower_bound(all(v),a)
#define sz(a) (int)(a.size())
#define pb push_back
#define mp make_pair
#define all(v) v.begin(),v.end()
#define tr(v,it) for(auto it=v.begin();it!=v.end();it++)
#define present(v,x) (v.find(x)!=v.end()) //set/map etc.
#define vpresent(v,x) (find(all(v),x)!=v.end()) // vector
typedef vector< int > vi;
typedef vector< long long > vll;
typedef vector<pair<ll,ll>> vp;
typedef vector< vi > vvi;
typedef pair< int,int > pii;
const long long max_sz = 1e5 + 1;
const long long mod = 1e9 + 7;
const long long MAXN = 4e18 + 1;
char flip(char k){ if(k=='0') return '1'; return '0'; }
ll sum_digit(ll n){ ll a=0,i; for(i=n;i>0;i=i/10){ a+=(i%10);} return a; }
ll gcd(ll a, ll b){
	if(b == 0) return a;
	return gcd(b, a%b);
}
int main(){
                   // ios_base::sync_with_stdio(false);
                    //cin.tie(NULL);
                    //cout.tie(NULL);
 
                     ll t;
                    // cin >> t;
                     t=1;
                     while (t--){
                             ll h1,m1,h2,m2,k;cin>>h1>>m1>>h2>>m2>>k;
                             if(m2>m1){
                                 ll diff=(h2-h1)*60 + m2-m1;
                                 cout<<diff-k<<endl;
                             }
                             else{
                                 ll diff=(h2-h1)*60 +m2-m1;
                                 cout<<diff -k<<endl;
                             }
                     }
                    cerr << endl
                                  << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
                      return 0;
}
