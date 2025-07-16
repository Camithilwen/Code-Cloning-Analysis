#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
int main(){
	ios::sync_with_stdio(false);
	int n;string s;
	cin>>n>>s;
	int num=0;
	long long ans=1;
	for(int i=1;i<=n;++i) ans=ans*i%mod;
	for(int i=0;i<2*n;++i){
		if((s[i]=='W')^num&1) ans=ans*num%mod,num--;
		else num++;
	}
	printf("%lld\n",num?0:ans);
}