#include<bits/stdc++.h>
using namespace std;
int n,m,x[100],y[100],i=0,j,k;
double ans,d[205],P=acos(-1);
main(){
	cin>>n;m=n;
	while(m--)cin>>x[n-m-1]>>y[n-m-1];
	for(i=0;i<n;i++){
		k=ans=0;
		for(j=0;j<n;j++)if(i-j)d[k++]=atan2(y[j]-y[i],x[j]-x[i]);
		sort(d,d+k);
		for(j=0;j<k;j++)d[j+k]=d[j]+2*P;
		for(j=0;j<k;j++)ans=max(ans,P-d[j+k-1]+d[j]);
		cout<<ans/2./P<<'\n';
	}
}