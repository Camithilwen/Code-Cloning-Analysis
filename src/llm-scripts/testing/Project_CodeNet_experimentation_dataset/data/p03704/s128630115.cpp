#include<bits/stdc++.h>
using namespace std;
long long mi[233];
long long work(int l,int r,long long dlt)
{
	if ((l>=r)&&(dlt)) return 0;
	if (l==r) return 10-(l==0);
	if (l>r) return 1;
	int t=(10-dlt%10)%10;
	dlt-=t*(mi[r-l]-1);
	return (10-(l==0)-t)*work(l+1,r-1,abs(dlt)/10);
}
int main()
{
	mi[0]=1;for (int i=1;i<=18;i++) mi[i]=mi[i-1]*10;
	int d;scanf("%d",&d);long long ans=0;
	for (int i=0;i<=17;i++) ans+=work(0,i,d);
	cout<<ans+(d==0)<<endl;
}  