#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define fi first
#define se second
#define rep(i,s,n) for(int i = s;i<n;i++)
#define rrep(i,s,n) for(int i = (n)-1;i>=(s);i--)
#define all(v) (v).begin(),(v).end()
#define chmin(a,b) a=min((a),(b))
#define chmax(a,b) a=max((a),(b))
#define endl '\n'
#define IOS() ios_base::sync_with_stdio(0);cin.tie(0)
typedef long long ll;
typedef pair<int,int>pint;
typedef vector<int>vint;
const ll MOD=1000000007,INF=1e18;
 
int K;

signed main() {
    IOS();
    cin>>K;
    int x=K/50,y=K%50;
    int N=50;
    vint a(N,49+x);
    rep(i,0,50){
        a[i]-=y;
        if(i<y)a[i]+=50;
    }
    cout<<50<<endl;
    rep(i,0,50){
        if(i)cout<<" ";
        cout<<a[i];
    }
    cout<<endl;
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    return 0;
}