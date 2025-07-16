#include <bits/stdc++.h>
using namespace std;
#define INF 2000000000000000000LL
typedef long long int ll;
typedef pair<ll,ll> ii;
typedef pair<ii,ll> iii;
typedef vector<ll> vi;
typedef vector<ii> vii;
#define getbit(n,i) (((n)&(1LL<<(i)))!=0)
#define setbit0(n,i) ((n)&(~(1LL<<(i))))
#define setbit1(n,i) ((n)|(1LL<<(i)))
#define lastone(n) ((n)&(-(n)))
#define read freopen("debug\\in.txt","r",stdin)
#define write freopen("debug\\out.txt","w",stdout)
#define DBG(a) cout<<#a<<" ->->->-> "<<a<<"\n"
#define EN cout<<"\n"
#define fi first
#define se second
#define PI (acos(-1))
#define fastread ios::sync_with_stdio(false);cin.tie(NULL)
#define mod (1000000007)
#define asz 2000005
template<class T,class V> ostream& operator<<(ostream &s,pair<T,V> a)
{
    s<<a.fi<<' '<<a.se;
    return s;
}
int main()
{
    fastread;
    int T=1;
//    cin>>T;
    for(int qq=1; qq<=T; qq++)
    {
        int n,m;
        cin>>n>>m;
        ll sum=0,ans=0;
        map<ll,ll> mp;
        mp[0]=1;
        for(int i=0;i<n;i++){
            ll x;
            cin>>x;
            sum+=x;
            ans+=mp[sum%m];
            mp[sum%m]++;
        }
        cout<<ans<<endl;
    }
}
