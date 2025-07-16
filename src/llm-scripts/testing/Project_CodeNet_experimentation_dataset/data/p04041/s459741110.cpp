#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

const int M=18,mod=1000000007;

int add(int a,int b,int p=mod){return a+b>=p?a+b-p:a+b;}
int sub(int a,int b,int p=mod){return a-b<0?a-b+p:a-b;}
int mul(int a,int b,int p=mod){return (LL)a*b%p;}
void sadd(int &a,int b,int p=mod){a=add(a,b,p);}
void ssub(int &a,int b,int p=mod){a=sub(a,b,p);}
void smul(int &a,int b,int p=mod){a=mul(a,b,p);}
int Power(int a,int k,int p=mod){int res=1;for (;k;k>>=1,smul(a,a,p)) if (k&1) smul(res,a,p);return res;}

int n,m,a[3];

void into(){
  scanf("%d%d%d%d",&n,&a[0],&a[1],&a[2]);
  a[1]+=a[0];m=max(a[2]+=a[1],10);
}

int dp[2][(1<<M)+9],old,now,ans;

void Get_dp(){
  old=1;now=0;
  dp[now][0]=1;
  for (int i=1;i<=n;++i){
	old^=1;now^=1;
	for (int g=0;g<1<<m;++g) dp[now][g]=0;
	for (int g=0;g<1<<m;++g)
	  for (int j=1;j<=10;++j){
		int t=(g&(1<<m-j)-1)<<j|1<<j-1;
		if (t>>a[0]-1&1&&t>>a[1]-1&1&&t>>a[2]-1&1) continue;
		sadd(dp[now][t],dp[old][g]);
	  }
  }
  for (int g=0;g<1<<m;++g) sadd(ans,dp[now][g]);
}

void work(){
  Get_dp();
}

void outo(){
  printf("%d\n",sub(Power(10,n),ans));
}

int main(){
  into();
  work();
  outo();
  return 0;
}