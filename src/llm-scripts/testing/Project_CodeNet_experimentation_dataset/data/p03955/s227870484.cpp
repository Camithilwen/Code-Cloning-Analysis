#include<bits/stdc++.h>
#define N 100005
using namespace std;
int n,a[4][N],b[N],c[N],A,B;
void M(int x,int *a){ while(x<=n) a[x]^=1,x+=(x&(-x));}
int Q(int x,int *a){ int s=0; while(x) s^=a[x],x-=(x&(-x)); return s;}
void GG(){ printf("No"); exit(0);}
int main()
{
	int i,p;
	scanf("%d",&n);
	for(i=1;i<=n;i++) scanf("%d",&a[1][i]);
	for(i=1;i<=n;i++) scanf("%d",&a[2][i]);
	for(i=1;i<=n;i++) scanf("%d",&a[3][i]);
	for(i=1;i<=n;i++){
		p=(a[1][i]-1)/3;
		if((a[2][i]-1)/3!=p) GG();
		if((a[3][i]-1)/3!=p) GG();
		if((a[1][i]-1)%3==1) GG();
		if((a[3][i]-1)%3==1) GG();
		if(i&1) b[(a[1][i]+2)/3]=1;
		if((a[1][i]-1)%3==2){
			if(i&1) A^=1; else B^=1;
		  }
	  }
	for(i=1;i<=n;i++) if((i&1)&&!b[i]) GG();
	memset(b,0,sizeof(b));
	for(i=1;i<=n;i++){
		p=(a[1][i]+2)/3;
		if(i&1) B^=Q(n-p+1,b),M(n-p+1,b);
		else A^=Q(n-p+1,c),M(n-p+1,c);
	  }
	if(A+B==0) printf("Yes");
	else printf("No");
	return 0;
}
