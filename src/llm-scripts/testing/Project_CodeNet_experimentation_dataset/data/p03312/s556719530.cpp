
#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
#include <functional>

using namespace std;
using namespace __gnu_pbds; 

typedef tree<int, null_type, less<int>, rb_tree_tag, 
             tree_order_statistics_node_update> 
    policy_set;  

#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (ll)(x).size()
#define fill(a)  memset(a, 0, sizeof (a))
#define ALL(c) c.begin(),c.end()
#define ff first
#define ss second
#define pb push_back
#define eb emplace_back
typedef long double ld;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef vector<ll> vll;

void preprocess(){


}
const ll N=3e5+7;
const ll INF=1e18+1;
const ll MOD=1e9+7;
//Have to ramp up more on implementation skillz to do it fast,
// and debug skillz, it is not as easy as you think with two pointers
ll n,a[N],pref[N];
ll f(ll l1,ll r1,ll l2, ll r2){
    return abs((pref[r1]-pref[l1-1])-(pref[r2]-pref[l2-1]));
}
// So we will implement the two pointer solution to this also 
// very well
// So in ternary search we always need to check 4 values near, the start,end
// like in that cf problem, no need to do this all over again
ll find_left(ll i){
    ll start=1,end=i-1;
    while(start<=end){
        ll mid1=(2*start+end)/3,mid2=(start+2*end)/3;
        // cout<<start<<" "<<mid1<<" "<<mid2<<" "<<end<<"\n";
        if(f(1,mid1,mid1+1,i)>f(1,mid2,mid2+1,i))
            start=mid1+1;
        else
            end=mid2-1;
    }
        // cout<<start<<" "<<end<<"\n";
    ll arr[]={start,end},ans=1e18,ansidx=start;
    for(ll j=0;j<2;j++)
        for(ll jj=-1;jj<=1;jj++){
            ll idx=arr[j]+jj;
            if(idx<1 || idx>i-1)continue;
            if(ans>f(1,idx,idx+1,i))ans=f(1,idx,idx+1,i),ansidx=idx;
        }
    
    return ansidx;
}
// I remember facing this problem before
ll find_right(ll i){
    ll start=i+1,end=n-1;
    while(start<=end){
        ll mid1=(2*start+end)/3,mid2=(start+2*end)/3;
        if(f(i+1,mid1,mid1+1,n)>f(i+1,mid2,mid2+1,n))
            start=mid1+1;
        else
            end=mid2-1;
    }

    ll arr[]={start,end},ans=1e18,ansidx=start;
    for(ll j=0;j<2;j++)
        for(ll jj=-1;jj<=1;jj++){
            ll idx=arr[j]+jj;
            if(idx<i+1 || idx>n)continue;
            if(ans>f(i+1,idx,idx+1,n))ans=f(i+1,idx,idx+1,n),ansidx=idx;
        }
    return ansidx;
}
void solve(){
    cin>>n;
    for(ll i=1;i<=n;i++)cin>>a[i],pref[i]=pref[i-1]+a[i];
    ll ans=INT64_MAX;
    // cout<<find_left(4)<<" "<<f(1,1,2,4)<<" "<<f(1,2,3,4)<<" "<<f(1,3,4,4)<<"\n";
    // return;
    for(ll i=1;i<=n;i++){
        //i ins the middle split, in this case
        // 1..left left+1..i i+1..right right+1..n
        ll left=find_left(i),right=find_right(i);
        // cout<<left<<" "<<right<<"\n";
        vector<ll> vecs({pref[left],pref[i]-pref[left],pref[right]-pref[i],pref[n]-pref[right]});
        sort(all(vecs));
        ans=min(ans,vecs.back()-vecs[0]);
    }
    cout<<ans<<"\n";
}
int main() {
	// #ifndef ONLINE_JUDGE
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
	// #endif
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	preprocess();
	int t=1;
	//cin>>t;
	//cout<<t<<endl;
	for(int i=0;i<t;i++)
		solve();
	return 0;
}

