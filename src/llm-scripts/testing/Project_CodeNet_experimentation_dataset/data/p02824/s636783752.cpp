// Alapan
// IIITH

#include<bits/stdc++.h>
using namespace std;

// data types
#define ll long long int
#define ld long double

//funtion macros


// stl
#define lp(var,start,end) for (ll var = start; var <=end ; ++var)
#define ilp(var,start,end) for(ll var = start; var>=end ; var--)
#define pb push_back
#define mp make_pair
#define pf push_front
#define ff first
#define ss second
#define vll vector<ll>
#define vld vector<ld>
#define pll pair<ll,ll> 
#define pld pair<ld,ld> 
#define vpll vector<pll>
#define vpld vector<pld>
#define all(X) X.begin(),X.end()
#define sz(x) ((ll)((x).size()))

#define mod 1000000007

// utility functions
ll max(ll a, ll b){
    if(a>b)return a;
    return b;
}

ll min(ll a, ll b){
	if(a<b)return a;
    return b;
}

ll power(ll x, ll y, ll m=mod){
	if(y<0){
		x = power(x,m-2);
		y = -y;
	}
	ll ans=1;
	x = x % m;
	while(y){
		if(y&1) ans = (ans*x)%m;
		y=y/2;
		x=(x*x)%m;
	}
	return ans;
}

ll factorial(ll n, ll m=mod){
    ll ans = 1;
	ll i = 1;
    while(i<=n){
        ans = (ans*i)%m;
        i++;
    }
    return ans;
}

///////////////////////////////////////////////////////////
ll n,m,v,p;
bool f(ll arr[], ll mid){
    // cout << mid << "\n";
    ll temp[n];
    for(ll i=0;i<n;i++){
        temp[i] = arr[i];
    }
    ll val = temp[mid] + m;
    ll i=0;
    ll cnt = (v-1)*m;
    ll more=0;
    ll alreadymore = 0;
    for(ll i=0;i<n;i++){
        if(val < temp[i]) alreadymore++;
        if(alreadymore >= p) return 0;
    }
    while(more < p-1 && i<n){
        if(i!= mid) cnt -= m;
        if(cnt <= 0) return true;
        if(temp[i]+m > val) more++;
        i++;
    }
    if(temp[i] > val) return false;
    while(i<n){
        if(i!=mid) cnt = cnt - min((val-temp[i]),m);
        if(cnt <= 0) return true;
        i++;
    }
    return false;
}
int main(){
    cin >> n >> m >> v >> p;
    ll arr[n];
    for(ll i=0;i<n;i++){
        cin >> arr[i];
    }
    sort(arr,arr+n);
    reverse(arr,arr+n);
    // for(ll i=0;i<n;i++) cout << arr[i] << " ";
    // cout << endl;
    ll l = 0;
    ll r = n-1;
    while(l < r){
        ll mid = l + (r-l+1)/2;
        if(f(arr,mid)) l = mid;
        else r = mid-1;
    }
    cout << l+1 << endl;
	return 0;
}