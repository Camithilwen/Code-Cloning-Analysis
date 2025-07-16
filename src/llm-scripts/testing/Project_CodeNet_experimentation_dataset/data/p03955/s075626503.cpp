#include<bits/stdc++.h>
const int MN=100000+5,P=1000000007,inv2=P+1>>1;
using namespace std;
typedef long long ll;
template<typename T>inline T&IN(T&in){
	in=0;char c=getchar();int f=1;
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c))in=in*10+c-'0',c=getchar();
	return in*=f;
}
int n;
int a[4][MN],c[2];
int t[MN];
int lowbit(int x){return x&(-x);}
void add(int p,int d){while(p<=n)t[p]+=d,p+=lowbit(p);}
int sum(int p){int c=0;while(p)c+=t[p],p-=lowbit(p);return c;}
void input(){
	IN(n);
	for(int i=1;i<=3;++i)for(int j=1;j<=n;++j)IN(a[i][j]);
	for(int i=1;i<=n;++i){
		if(a[2][i]%3!=2||abs(a[2][i]-a[1][i])!=1||abs(a[3][i]-a[2][i])!=1||(a[2][i]/3)&i&1)return puts("No"),void();
		c[i&1]^=(a[1][i]>a[3][i]);
	}
	for(int i=1;i<=n;i+=2)c[0]^=(sum(n)-sum(a[2][i]/3+1))&1,add(a[2][i]/3+1,1);
	memset(t,0,sizeof t);
	for(int i=2;i<=n;i+=2)c[1]^=(sum(n)-sum(a[2][i]/3+1))&1,add(a[2][i]/3+1,1);
	if(c[0]==0&&c[1]==0)puts("Yes");
	else puts("No");
}
int main(){
	input();
	return 0;
}