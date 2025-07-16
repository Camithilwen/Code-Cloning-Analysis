#include<algorithm>
#include<iostream>
#include<cstdio>
typedef long long ll;
using namespace std;
struct Node{
	int h,p;
}a[5005];
int n;
ll f[5005][5005];
bool cmp(Node a,Node b){
	return a.h+a.p<b.h+b.p;
}
int main(){
	ios::sync_with_stdio(false);
	int i,j;
	cin>>n;
	fill(f[0],f[0]+n+1,2e9+1);
	for(i=1;i<=n;i++)
		cin>>a[i].h>>a[i].p;
	sort(a+1,a+n+1,cmp);
	f[0][0]=0;
	for(i=1;i<=n;i++)
		for(j=0;j<=n;j++){
			f[i][j]=f[i-1][j];
			if(j&&f[i-1][j-1]<=a[i].h)
				f[i][j]=min(f[i][j],f[i-1][j-1]+a[i].p);
		}
	for(i=n;i>=0;i--)
		if(f[n][i]<=2e9)
			break;
	cout<<i;
	return 0;
}
