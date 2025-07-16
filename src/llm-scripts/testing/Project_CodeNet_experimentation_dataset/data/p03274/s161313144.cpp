#include<bits/stdc++.h>
using namespace std;

#define fastio 			ios::sync_with_stdio(0);	cin.tie(0); cout.tie(0);  cout<<fixed;  cout<<setprecision(12);
#define randomINT 		mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
#define	newl 			cout<<"\n"
#define DISP(as)		for(auto it : as) cout<<it<<" ";newl;
#define all(x)         	(x).begin(),(x).end()
#define mset(x,val)    	memset(x,val,sizeof(x))
#define newl           	cout<<"\n"
#define pb             	push_back
#define mp             	make_pair
#define f 				first
#define s 				second
#define dline          cerr<<"///REACHED///\n";
#define deb1(x)        cerr<<#x<<" = "<<x<<'\n';
#define deb2(x,y)      cerr<<'['<<#x<<','<<#y<<"] = "<<'['<<x<<','<<y<<']'<<'\n';
#define deb3(x,y,z)    cerr<<'['<<#x<<','<<#y<<','<<#z<<"] = "<<'['<<x<<','<<y<<','<<z<<']'<<'\n';

typedef long long 				ll;
typedef long double 			ld;
typedef vector<ll> 				vll;
typedef pair<ll , ll> 			pll;
typedef pair<ld, ld> 			pld;
typedef unordered_map<ll, ll> 	um;
typedef vector<pll> 			vpll;

const ll 	MAX5 	= 	1e+5 + 7;
const ll 	MAX7 	= 	1e+7 + 7;
const ll 	MAXN 	= 	MAX7;
const ll   	INF   	=  	0x7f7f7f7f7f7f7f7f;
const int  	INFi 	=  	0x7f7f7f7f;
const ll 	MOD		=  	1e+9 + 7;


// <------------- Declare Variables Here ------------> //

ll T = 1;
ll n, x, m, y, k, z, N;
string s, t, d, c;


// <------------- Implement Functions Here ----------> //



// <------------- Start of main() -------------------> //

void MAIN() {
	cin >> n >> k ;
	vll pos,neg;
	bool zero = false;
	for(ll i=0;i<n;i++) {
		cin>>x;
		if(x == 0) zero = true;
		if(x > 0) pos.pb(x);
		if(x < 0) neg.pb(x);
	}
	reverse(all(neg));

	//for(ll i=1;i<pos.size();i++) pos[i]+=pos[i-1];
	//for(ll i=1;i<neg.size();i++) neg[i]+=neg[i-1];
	for(ll i=0;i<neg.size();i++) neg[i]=-neg[i];

	k-=zero;
	
	ll ans = INT_MAX;
	ll i=k,j=0;
	while(i>=0) {
		if(neg.size() >= i && pos.size() >= j) {
			ll val = ((i)?neg[i-1]:0) + ((j)?pos[j-1]:0);
			//cout<<i<<" "<<j<<" "<<val;newl;
			if(i && j) val += min(neg[i-1],pos[j-1]);
			//cout<<i<<" "<<j<<" "<<val;newl;
			ans = min(ans, val);

		}
		i--;
		j++;
	}	
	cout<<ans;
}

int main() {
	fastio; randomINT;
	//cin >> T;
	while (T--) {
		MAIN();
	}
	return 0;
}
