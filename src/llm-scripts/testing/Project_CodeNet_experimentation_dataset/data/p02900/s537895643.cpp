#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll u(ll a, ll b){
	if(a%b==0) return b;
	
	else return u(b,a%b);
	
	
}

//素数判別じゃなかったです
//ll s( ll n){
//	bool k[n+1]={};
//	ll ans=0;
//	for(ll i=2; i<n; i++){
//		if(!k[i]){
//			ll d=i;
//			if(n%i==0){
//				ans++;
//				cout<<i<<endl;
//			}
//			//cout<<i<<" "<<ans<<endl;
//			while(d<=n){
//				k[d]=true;
//				d+=i;
//			}
//		}
//		///cout<<ans<<endl;
//	}
//	//cout<<ans<<endl;
//	return ans;
//}
		


int main(){
	ll n,a,b;
	cin>>a>>b;
	n=u( max(a,b),min(a,b));
	//cout<<n<<endl;
	ll ans=1;
	ll k=2;
	//ans+=s(n);
	//ルートn以上の素因数は１コまで
	while(n>=k*k){
		if(n%k==0) ans++;
		
		
		while(n%k==0){
			n/=k;
		}
		//cout<<n<<endl;
		k++;
	}
	if(n>1){
		ans++;
	}
	//cout<<n<<endl;
	cout<< ans <<endl;
}