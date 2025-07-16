#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[233],odd[3],top;
int main()
{
	ios_base::sync_with_stdio(false);
	cin>>n>>k;
	for(int i=1;i<=k;i++)
	{
		cin>>a[i];
		if(a[i]%2)
		{
			odd[++top]=i;
		}
	}
	if(top>2)return puts("Impossible"),0;
	else if(top==2)
	{
		swap(a[1],a[odd[1]]);
		swap(a[k],a[odd[2]]);
	}
	else if(top==1)
	{
		swap(a[1],a[odd[1]]);
	}
	for(int i=1;i<=k;i++)cout<<a[i]<<' ';cout<<endl;
	cout<<k-(a[1]==1)+(k==1)<<endl;
	if(a[1]!=1)cout<<a[1]-1<<' ';
	for(int i=2;i<k;i++)cout<<a[i]<<' ';
	if(k!=1)cout<<a[k]+1<<endl;
	else cout<<1<<endl;
	return 0;
}