#include<algorithm>
#include<iostream>
#include<cstring>
#include<string>
#include<vector>
#include<cstdio>
#include<cmath>
#include<map>
#include<set>
using namespace std;
long long n,d,a[200005],r[200005],l[200005];
int main()
{
	cin>>n>>d;
	long long ret=0;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		ret+=a[i];
	}    
	ret+=(n-1)*d;
	//cout<<ret<<endl;
	r[0]=a[0];
	for(int i=1;i<n;i++)
	    r[i]=min(a[i],r[i-1]+d);
	l[n-1]=a[n-1];
	for(int i=n-2;i>=0;i--)
	    l[i]=min(a[i],l[i+1]+d);
	for(int i=1;i<n-1;i++)
	    ret+=min(l[i],r[i]);
	cout<<ret;
	return 0;
}