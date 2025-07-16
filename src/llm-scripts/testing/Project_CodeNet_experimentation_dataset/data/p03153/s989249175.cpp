#include<bits/stdc++.h>
using namespace std;
const int N=200005;
long long a[N],l[N],r[N];
int main()
{
	ios::sync_with_stdio(false);
	int n;
	long long d,ret=0;
	cin>>n>>d;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		ret+=a[i];
	}
	ret+=(n-1)*d;
	r[1]=a[1];
	for(int i=2;i<=n;i++)
		r[i]=min(a[i],r[i-1]+d);
	l[n]=a[n];
	for(int i=n-1;i>=1;i--)
		l[i]=min(a[i],l[i+1]+d);
	for(int i=2;i<n;i++)
		ret+=min(l[i],r[i]);
	cout<<ret<<endl;
	return 0;
}
