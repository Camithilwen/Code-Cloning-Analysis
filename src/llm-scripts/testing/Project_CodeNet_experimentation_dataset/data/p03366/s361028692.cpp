#include<bits/stdc++.h>
using namespace std;
long long pd,n,s,p[200005],loc,num,l,r,ss;
long long ans,val[200005];
int main(){
//	freopen("go home.in","r",stdin);
//	freopen("go home.out","w",stdout);
	scanf("%lld%lld",&n,&s);
	pd=0;l=1;r=n+1;
	for (long long i=1;(i<=n);i++){
		scanf("%lld%lld",&loc,&num);
		if(pd==0)
			if (loc>=s){
				p[i]=s;val[i]=0;pd=1;ss=i;
			}
		p[i+pd]=loc;val[i+pd]=num;
	} 
	if (pd==0) p[n+1]=s;
	while (true){
		if (p[l]>=p[ss]){
			
			ans+=p[r]-p[l];
			printf("%lld",ans);
			return 0;
		}
		if (p[r]<=p[ss]){
			
			ans+=p[r]-p[l];
			printf("%lld",ans);
			return 0;
		}
		ans+=p[r]-p[l];
		if (val[l]>=val[r]){
			while (val[l]>=val[r]){
				val[l]+=val[r];
				r--;
				if (p[r]==p[ss]) break;
			}
			
		} else{
			while (val[r]>val[l]){
				val[r]+=val[l];
				l++;
				if (p[l]==p[ss]) break;
			}
		}
		
	}
	//fclose(stdin);fclose(stdout);
	return 0;
}