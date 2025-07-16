#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using pi = pair<int,int>;

int MOD = 1e9+7;

//ll po(ll b, ll p){ return !p?1:po(b*b%MOD,p/2)*(p&1?b:1)%MOD;}
// ll pomd(ll a, ll k, ll md) { ll p; if (k == 0){ return 1; } p = pomd(a, k / 2, md); p = p * p % md; if (k % 2){ p = p * a % md; } return p; }
// counting divsrs: vi arr(N); for(int i{1}; i<N; ++i) for(int j=i; j<N; j+=i) d[j]++;

#define mp make_pair
#define pb push_back
#define rsz resize
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)

void setIO(string name = ""){
    freopen((name+".in").c_str(), "r", stdin); 
    freopen((name+".out").c_str(), "w", stdout);
}	

int main(){
 	ios_base::sync_with_stdio(0); cin.tie(0); 
	// setIO();
 	ll n,x; cin >> n >> x;
 	if(n>=10){
 		cout << x << "\n";
 	}else{
 		cout << x+100*(10-n) << "\n";
 	}

}



