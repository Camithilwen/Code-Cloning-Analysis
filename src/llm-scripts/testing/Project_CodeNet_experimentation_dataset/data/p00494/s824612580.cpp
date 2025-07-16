#include "bits/stdc++.h"

using namespace std;

//int N,M,K,L,R,H,W;
long long int N,M,K,L,R,H,W;

constexpr long long int MOD=1000000007;
//constexpr  int MOD=1000000007;
//constexpr int MOD=998244353;
//constexpr long long int MOD=998244353;

constexpr long double EPS=1e-8;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int ans=0;
	string s;
	cin>>s;
	s='P'+s+'P';
	for(int i=1;i<=s.size();i++){
		if(s[i]=='O'){
			int add=0;
			while(s[i+add]=='O')add++;
			bool flag=true;
			for(int k=i-1;k>=i-add;k--){
				//cout<<"J "<<k<<endl;
				flag&=s[k]=='J';
				if(!flag)break;
			}
			for(int k=i+add;k<i+2*add;k++){
				//cout<<"I "<<k<<endl;
				flag&=s[k]=='I';
				if(!flag)break;
			}
			if(flag)ans=max(ans,add);
			i+=add-1;
		}
	}
	cout<<ans<<endl;
	return 0;
}
