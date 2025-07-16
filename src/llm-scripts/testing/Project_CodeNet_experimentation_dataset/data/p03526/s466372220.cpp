#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define fi first
#define se second
void read(int &x){
	char ch=getchar();x=0;
	for (;ch==' '||ch=='\n';ch=getchar());
	for (;ch!=' '&&ch!='\n';x=x*10+ch-'0',ch=getchar());
}
void write(int x){
	if (x>9) write(x/10);
	putchar(x%10+'0');
}
int n;
pii a[100004];
bool cmp(pii A,pii B){
	return A.fi+A.se<B.fi+B.se;
}
int dp[5003];
int main(){
	read(n);
	for (int i=1;i<=n;i++) read(a[i].fi),read(a[i].se);
	sort (a+1,a+1+n,cmp);
	for (int i=1;i<5003;i++) dp[i]=2000000001;
	for (int i=1;i<=n;i++)
		for (int j=i-1;j>=0;j--)
			if (dp[j]<=a[i].fi) dp[j+1]=min(dp[j+1],dp[j]+a[i].se);
	for (int i=5002;i>=0;i--)
		if (dp[i]!=2000000001){
			write(i);break;
		}
}