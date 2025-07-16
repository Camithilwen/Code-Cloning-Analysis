#include<bits/stdc++.h> 
using namespace std;
typedef long long int ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pii;
#define fo(i,s,e_ex) for(i=s;i<e_ex;i++)
#define Fo(i,k,n) for(i=k;k<n?i<=n:i>=n;k<n?i+=1:i-=1)
#define endl '\n'
#define MOD 1000000007//998244353
#define pbb push_back
#define mpp make_pair
#define setbits(x) __builtin_popcountll(x)
#define ff first
#define ss second
#define all(x) x.begin(),x.end()
#define mset(arr,val) memset(arr,val,sizeof(arr))
ll a[20][20],n;
ll dp[66000],gc[66000];
vi sm[66000];
bool dpp[66000];
void findsm(ll pos,ll bitmask,ll submask){
    if(pos==n){
        if(setbits(submask)==0) return;
        sm[bitmask].pbb(submask);
        return;
    }
    findsm(pos+1,bitmask,submask);
    findsm(pos+1,bitmask|(1<<pos),submask);
    findsm(pos+1,bitmask|(1<<pos),submask|(1<<pos));
}
void findgc(){
    for(ll b=1;b<pow(2,n);b++){
        //b is the bitmask
        gc[b]=0;
        for(ll i=0;i<n;i++){
            if(        ((1<<i) & b)==0   ) continue;
            for(ll j=i+1;j<n;j++){
                if(        ((1<<j) & b)==0   ) continue;
                gc[b]+=a[i][j];
            }
        }
    }
}
ll findans(ll bitmask){
    if(bitmask==0) return 0;
    if(dpp[bitmask]) return dp[bitmask];
    ll ans=LLONG_MIN;
    for(auto submask:sm[bitmask]){
        ans = max(ans,findans(bitmask^submask)+gc[submask]);
    }
    dpp[bitmask]=true;
    return dp[bitmask]=ans;
}
void solve(ll caseno){
	ll i,j,ans;
    cin>>n;
    fo(i,0,n){
        fo(j,0,n){
            cin>>a[i][j];
        }
    }
    findsm(0,0,0);
    findgc();
    mset(dpp,0);
    ans = findans(pow(2,n)-1);
    cout<<ans<<endl;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	ll t=1;
	//cin>>t;
	for(ll i=1;i<=t;i++){
		solve(i);
	}
	return 0;
}
