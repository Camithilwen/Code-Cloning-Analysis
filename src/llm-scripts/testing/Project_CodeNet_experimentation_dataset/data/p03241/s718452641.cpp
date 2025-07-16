//Partition

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
using p = pair<ll,ll>;
using graph = vector<vector<ll>>;
const int inf = 2147483647;//2*10^9
const ll INF = 9223372036854775807;//9*10^18

bool IsPrime(int num){
    if(num<2)return false;
    else if(num==2)return true;
    else if(num%2==0)return false;
    double sqrtNum=sqrt(num);
    for (int i=3;i<=sqrtNum;i+=2)if(num%i==0)return false;
    return true;
}

signed main (){
    int n,m,ans=1;cin>>n>>m;
    if(n==1){cout<<m<<nnn;return 0;}
    if(IsPrime(m)){cout<<1<<nnn;return 0;}
    for(int i=2;i*i<1000001000;i++){
        if(m%i==0&&m/i>=n){
            ans=max(ans,i);
            if(i>=n){
                ans=max(ans,m/i);
            }
        }
    }
    cout<<ans<<nnn;
    return 0;
}