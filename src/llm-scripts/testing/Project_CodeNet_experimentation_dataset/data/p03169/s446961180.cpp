#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define maxn 100005
#define ld long double

ll fastpower (ll b , ll p){
    ll k= p%2 ? b : 1 ;
    return p==0 ? 1 : k*(fastpower(b*b,p/2));
}

ld dp[305][305][305];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	ll n;
	cin>>n;
	ll cnt[4]={0,0,0,0};
	ll x;
	for(int i=0;i<n;i++){
		cin>>x;
		cnt[x]++;
	}
	dp[0][0][0]=0;
	for(ll three=0;three<=n;three++){
		for(ll two=0;two<=n;two++){
			for(ll one=0;one<=n;one++){
				ld i=three,j=two,k=one;
				ll zero=n-two-three-one;
				ld zero1=zero,n1=n;
				if(zero<0 || zero==n) continue;
				ld value=1.0;
				if(three>0) value+=(i/n1)*dp[three-1][two+1][one];
				if(two>0) value+=(j/n1)*dp[three][two-1][one+1];
				if(one>0) value+=(k/n1)*dp[three][two][one-1];
				//dp[three][two][one]=(value)/(1-1.0*zero/n);
				dp[three][two][one]=(value*n1)/(i+j+k);
			}
		}
	}
	ld ans=dp[cnt[3]][cnt[2]][cnt[1]];
	cout.precision(20);
	cout<<ans;
}