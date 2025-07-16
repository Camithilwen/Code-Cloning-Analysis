//Counting of Trees

#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define int long long
#define rep(i,x,y) for(ll i=x;i<y;i++)
#define nvarep(n,a) ll n;cin>>n;vector<ll>a(n);rep(i,0,n)cin>>a[i]
#define vecrep(n,a,type) vector<type>a(n);rep(i,0,n)cin>>a[i]
#define lcm(a,b) (a/__gcd(a, b)*b)
#define range(a) (a).begin(),(a).end() 
#define pb push_back
#define mp make_pair
#define nnn "\n"
#define spa " "
using p = pair<ll, string>;
using graph = vector<vector<ll>>;
const int inf = 2147483647;//2*10^9
const ll INF = 9223372036854775807;//9*10^18

int mpow(int a,int b,int mod){
    int ans = 1;
    rep(i,0,b)ans=(ans*a)%mod;
    if(b==0)return 0;
    else return ans;
}

signed main (){
    int n;cin>>n;
    map<int,int>m{};
    int t = 0,ans = 1;
    rep(i,0,n){
        int a;cin>>a;
        if(i==0&&a!=0){
            cout<<0<<nnn;
            return 0;
        }
        m[a]++;
        t = max(t,a);
    }
    if(m[0]!=1){
        cout<<0<<nnn;
        return 0;
    }
    rep(i,1,t+1){
        ans=(ans*mpow(m[i-1],m[i],998244353))%998244353;
    }
    cout<<ans<<nnn;
    return 0;
}