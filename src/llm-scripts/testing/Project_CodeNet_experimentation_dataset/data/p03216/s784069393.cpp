#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,q,k;
char s[1000005];
int main(){
	scanf("%lld%s%lld",&n,s,&q);
	while(q--){
		scanf("%lld",&k);
		ll D=0,M=0,DM=0,DMC=0;
		for(ll i=0;i<n;i++){
			if(i>=k){
				if(s[i-k]=='D'){
					DM-=M;
					D--;
				}
				if(s[i-k]=='M')
					M--;
			}
			if(s[i]=='D')
				D++;
			if(s[i]=='M'){
				M++;
				DM+=D;
			}
			if(s[i]=='C')
				DMC+=DM;
		}
		printf("%lld\n",DMC);
	}
}