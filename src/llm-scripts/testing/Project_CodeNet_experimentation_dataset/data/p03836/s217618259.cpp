/**
DufauX-XuafuD
**/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define reset(x) memset(x,-1,sizeof(x))
#define CheckBit(a,b) (a&(1ll<<b))
#define SetBit(a,b) a=(a|(1ll<<b))
#define UnSetBit(a,b) a=(a&(~(1ll<<b)))
#define maxx 10000006
#define PI 2*acos(0.0)
const long long INF = 2000000000000000000LL;	// 2e18
const int inf = 0x3f3f3f3f;	// 1061109567
const long double EPS = 1e-9;
//bitset<maxx/2>vis;
//bitset<maxx>pr;
//int mobi[maxx+10];
//vector<ll>prime;
//void sieve(){
//    ll x=maxx/2, y=sqrt(maxx)/2;
//    for(ll i=1;i<=y;i++){
//        if(vis[i]==0){
//            for(ll j=(i*(i+1)*2);j<x;j+=(2*i)+1)
//                vis[j]=1;
//        }
//    }
//    prime.push_back(2);
//    for(ll i=3;i<maxx;i+=2)
//        if(vis[i/2]==0)
//        prime.push_back(i);
//}
//void generate_mobius()
//{
//    for(int i=0;i<maxx;i++)mobi[i]=1;
//    for(int i=2;i<maxx;i++){
//        if(!pr[i]){
//            mobi[i]*=-1;
//            for(int j=i+i;j<maxx;j+=i){
//                pr[j]=1;
//                mobi[j]*=(j%(i*i)?-1:0);
//            }
//        }
//    }
//}
//bool isprime(ll a)
//{
//    if(a==1)return false;
//    if(a==2)return true;
//    if(a%2==0)return false;
//    for(ll i=0;i<prime.size() && prime[i]*prime[i]<=a;i++)
//        if(a%prime[i]==0)return false;
//    return true;
//}
/* Calculate ( a*b ) %c */
inline ll mulmod(ll a, ll b, ll c) {
    ll ret = 0 , cur = a % c ;
    while(b) { if(b%2) ret=(ret+cur)%c; cur=(cur<<1)%c; b=b>>1; }
    return ret%c;
}
//Calculate (b^p)%m || modular inverse: b^-1 = bigmod(b, m-2, m)
inline ll bigmod(ll b, ll p, ll m){
    ll ret = 1, cur = b % m;
    while(p) { if(p&1) ret=(ret*cur)%m; cur=(cur*cur)%m; p=p>>1; }
    return ret;
}
inline ll modulo(ll a,ll b,ll c) { //Same as big mod, use for numbers over 1e10
    ll ret = 1 , cur = a%c ;
    while(b) { if(b%2) ret=mulmod(ret,cur,c); cur=mulmod(cur,cur,c); b=b>>1; }
    return ret%c ;
}
inline ll power(ll b, ll p){
    ll ret = 1, cur = b;
    while(p) { if(p&1) ret=(ret*cur); cur=(cur*cur); p=p>>1; }
    return ret;
}
ll lcm(ll a,ll b)
{
    return (a/__gcd(a,b))*b;
}
ll gcd(ll a,ll b)
{
    return __gcd(a,b);
}
void Dufaux()
{
    ll sx,sy,tx,ty;
    cin>>sx>>sy>>tx>>ty;
    string ans="";
    for(int i=0;i<ty-sy;i++)ans+="U";
    for(int i=0;i<tx-sx;i++)ans+="R";
    for(int i=0;i<ty-sy;i++)ans+="D";
    for(int i=0;i<tx-sx;i++)ans+="L";
    ans+="L";
    for(int i=0;i<ty-sy+1;i++)ans+="U";
    for(int i=0;i<tx-sx+1;i++)ans+="R";
    ans+="D";
    ans+="R";
    for(int i=0;i<ty-sy+1;i++)ans+="D";
    for(int i=0;i<tx-sx+1;i++)ans+="L";
    ans+="U";
    cout<<ans<<endl;
}
int main()
{
    FastIO;
	///sieve();
	///generate_mobius();
	int test=1;
	while(test--){
        Dufaux();
	}
	return 0;
}




