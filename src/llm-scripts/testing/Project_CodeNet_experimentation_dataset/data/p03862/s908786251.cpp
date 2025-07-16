//Boxes and Candies

#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define int long long
#define rep(i,x,y) for(ll i=x;i<y;i++)
#define nvarep(n,a) ll n;cin>>n;vector<ll>a(n);rep(i,0,n)cin>>a[i]
#define vecrep(n,a,type) vector<type>a(n);rep(i,0,n)cin>>a[i]
#define YN(flag) (flag?"Yes":"No")
#define lcm(a,b) (a/__gcd(a, b)*b)
#define range(a) (a).begin(),(a).end() 
#define pb push_back
#define mp make_pair
#define nnn "\n"
#define spa " "
using P = pair<ll,ll>;
using graph = vector<vector<ll>>;
const int inf = 2147483647;//2*10^9
const ll INF = 9223372036854775807;//9*10^18

signed main (){
    int n,x,ans=0;cin>>n>>x;
    vecrep(n,a,int);
    int t=a[0];
    rep(i,1,n){
        t+=a[i];
        if(t>x){
            int s=t-x;
            if(s>a[i]){
                s-=a[i];
                t-=a[i];
                ans+=a[i];
                a[i]=0;
                a[i-1]-=s;
            }else{
                a[i]-=s;
            }
            ans+=s;
            t-=s;
        }
        t-=a[i-1];
    }
    cout<<ans<<nnn;
    return 0;
}