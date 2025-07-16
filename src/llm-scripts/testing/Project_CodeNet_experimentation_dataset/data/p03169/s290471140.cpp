/*   ꧁༒☬महाकाल☬༒꧂ ꧁༒ঔमहाकालঔ༒꧂
                   
                   ঔৣ۝महाकालᴳᵒᵈ۝ঔৣ            
 
 */ 
#include<bits/stdc++.h>
using namespace std;
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
//template <typename T, typename cmp=less<T>> using oset =tree<T, null_type, cmp, rb_tree_tag, tree_order_statistics_node_update>;
#define ll long long 
#define mod 1000000007
#define MOD 998244353
#define inf 100000000000000000
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define _it iterator
#define all(_x) _x.begin(),_x.end()
#define f first
#define s second
#define pb push_back
#define ar array
#define ld long double
void mahakal(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	freopen("error.txt","w",stderr);
	#endif
}
ll dx[4]={1,0,-1,0};
ll dy[4]={0,1,0,-1};
char c[4]={'D' , 'R' , 'U' , 'L'};
const ll maxN=3e2+5;
ll n , cnt[4] ;
ld dp[maxN][maxN][maxN];

// dp[three][two][one][zero] where three is the no of 3 and two is the no of 2 ......
// three=two=one=zero=n=300 (300^4)
// zero=n-one-two - three
// dp[three][two][one]
// if i pich three dp[three-1][two+1][one] 
// if i pick two dp[three][two-1][one+1]
// if i pick one dp[three][two][one-1];
// dp[three][two][one]=(three/n)*dp[three-1][two+1][one] + (two/n)dp[three][two-1][one+1] + 
					// one/n * dp[three][two][one-1] + zero/n * dp[three][two][one];
// dp[three][two][one](1-zero/n)=(three/n)*dp[three-1][two+1][one] + (two/n)dp[three][two-1][one+1] + 
					// one/n * dp[three][two][one-1]
// dp[three][two][one]==((three/n)*dp[three-1][two+1][one] + (two/n)dp[three][two-1][one+1] + 
					// one/n * dp[three][two][one-1])/(1-zero/n)


void solve(){
	cin>>n ;
	for(ll i=0 , x ;i<n ;i++){
		cin>> x ; cnt[x]++;
	}
	dp[0][0][0]=0;
	for(ll three=0 ;three<=n ; three++){
		for(ll two=0 ; two<=n ; two++){
			for(ll one=0 ; one<=n ; one++){
				ll zero=n-three-two-one;
				if(zero==n)continue;
				if(three+two+one>n)continue;
				ld value=1;
				//  picking three
				if(three>0)value+=(1.0*three/n)*dp[three-1][two+1][one];
				if(two>0)value+=(1.0*two/n)*dp[three][two-1][one+1];
				if(one>0)value+=(1.0*one/n)*dp[three][two][one-1];

				dp[three][two][one]=(value)/(1-1.0*zero/n);
			}
		}
	}

	ld ans=dp[cnt[3]][cnt[2]][cnt[1]];
	cout<<fixed<<setprecision(10);
	cout<<ans<<endl;

}

int main(){
	//mahakal();
	fast;
	ll t =1 ;
	//cin>> t ; 
	while(t--)solve();
	//cerr << "\ntime taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl; 
	return 0;
}