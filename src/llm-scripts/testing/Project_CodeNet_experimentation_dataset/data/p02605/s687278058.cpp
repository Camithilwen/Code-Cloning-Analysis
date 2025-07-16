#include<cstring>
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
#include<map>
#include<set>
#define l(x) (x<<1)
#define r(x) ((x<<1)|1)
#define IL inline
#define reg register
#define LL long long
#define N 200010
#define INF 0x3f3f3f3f
using namespace std;

int n,i,j;
int ans=INF;
set <int> S[N*4];

struct Data{
	int x,y;
	char c;
}a[N];

IL int Abs(int x){return (x<0)?-x:x;}
IL void Swap(int &a,int &b){a^=b^=a^=b;}
IL int Min(int a,int b){return (a<b)?a:b;}
IL int Max(int a,int b){return (a>b)?a:b;}

IL int read(){
	int p=0,f=1;	char	c=getchar();
	while (c<48||c>57)	{if (c=='-')	f=-1;	c=getchar();}
	while (c>=48&&c<=57)	p=(p<<1)+(p<<3)+c-48,c=getchar();
	return p*f;
}

int main(){
	#ifdef __Marvolo
	freopen("zht.in","r",stdin);
	freopen("zht.out","w",stdout);
	#endif
	n=read();
	for (i=1;i<=n;i++){
		a[i].x=read();	a[i].y=read();	a[i].c=getchar();
	}
	if (n==1){
		puts("SAFE");
		return 0;
	}

	for (i=1;i<=n;i++)
		if (a[i].c=='U')	S[a[i].x+a[i].y].insert(a[i].x);
	
	for (i=1;i<=n;i++){
		if (a[i].c=='R'){
			if (!S[a[i].x+a[i].y].size())	continue;
			j=*(--S[a[i].x+a[i].y].end());
			if (j<a[i].x)	continue;
			j=*S[a[i].x+a[i].y].upper_bound(a[i].x);
			ans=Min(ans,j-a[i].x);
		}
	}
	for (i=0;i<4*N;i++)	S[i].clear();
	//U--R

	for (i=1;i<=n;i++)
		if (a[i].c=='D')	S[a[i].x+a[i].y].insert(a[i].x);
	
	for (i=1;i<=n;i++){
		if (a[i].c=='L'){
			if (!S[a[i].x+a[i].y].size())	continue;
			j=*S[a[i].x+a[i].y].begin();
			if (j>a[i].x)	continue;
			j=*(--S[a[i].x+a[i].y].upper_bound(a[i].x));
			ans=Min(ans,a[i].x-j);
		}
	}
	for (i=0;i<4*N;i++)	S[i].clear();
	//D--L


	for (i=1;i<=n;i++)
		if (a[i].c=='R')	S[a[i].y-a[i].x+N].insert(a[i].x);
	
	for (i=1;i<=n;i++){
		if (a[i].c=='D'){
			if (!S[a[i].y-a[i].x+N].size())	continue;
			j=*S[a[i].y-a[i].x+N].begin();
			if (j>a[i].x)	continue;
			j=*(--S[a[i].y-a[i].x+N].upper_bound(a[i].x));
			ans=Min(ans,a[i].x-j);
		}
	}
	for (i=0;i<4*N;i++)	S[i].clear();
	//D--R
	

	for (i=1;i<=n;i++)
		if (a[i].c=='L')	S[a[i].y-a[i].x+N].insert(a[i].x);
	
	for (i=1;i<=n;i++){
		if (a[i].c=='U'){
			if (!S[a[i].y-a[i].x+N].size())	continue;
			j=*(--S[a[i].y-a[i].x+N].end());
			if (j<a[i].x)	continue;
			j=*S[a[i].y-a[i].x+N].upper_bound(a[i].x);
			ans=Min(ans,j-a[i].x);
		}
	}
	for (i=0;i<4*N;i++)	S[i].clear();
	//D--R
	if (ans!=INF)	ans*=2;


	for (i=1;i<=n;i++)
		if (a[i].c=='R')	S[a[i].y].insert(a[i].x);
	
	for (i=1;i<=n;i++){
		if (a[i].c=='L'){
			if (!S[a[i].y].size())	continue;
			j=*S[a[i].y].begin();
			if (j>a[i].x)	continue;
			j=*(--S[a[i].y].upper_bound(a[i].x));
			ans=Min(ans,a[i].x-j);
		}
	}
	for (i=0;i<4*N;i++)	S[i].clear();
	//L--R

	for (i=1;i<=n;i++)
		if (a[i].c=='U')	S[a[i].x].insert(a[i].y);
	
	for (i=1;i<=n;i++){
		if (a[i].c=='D'){
			if (!S[a[i].x].size())	continue;
			j=*S[a[i].x].begin();
			if (j>a[i].y)	continue;
			j=*(--S[a[i].x].upper_bound(a[i].y));
			ans=Min(ans,a[i].y-j);
		}
	}
	for (i=0;i<4*N;i++)	S[i].clear();
	//U--D

	if (ans==INF)	puts("SAFE");
	else cout<<ans*5<<endl;	
	return 0;
}