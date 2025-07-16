#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<set>
#include<bitset>
#include<map>

#define fo(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)

using namespace std;

typedef long long LL;
typedef double db;

int get(){
	char ch;
	while(ch=getchar(),(ch<'0'||ch>'9')&&ch!='-');
	if (ch=='-'){
		int s=0;
		while(ch=getchar(),ch>='0'&&ch<='9')s=s*10+ch-'0';
		return -s;
	}
	int s=ch-'0';
	while(ch=getchar(),ch>='0'&&ch<='9')s=s*10+ch-'0';
	return s;
}

const int N = 1e+5+5;

int n;
int a[3][N];
int id[N],inv[N];
bool vis[N];

int main(){
	n=get();
	fo(i,0,2)fo(j,1,n)a[i][j]=get();
	fo(i,1,n){
		int x=(a[0][i]-1)/3+1;
		if (a[0][i]==x*3-2&&a[1][i]==x*3-1&&a[2][i]==x*3)id[i]=x,inv[i]=0;
		if (a[2][i]==x*3-2&&a[1][i]==x*3-1&&a[0][i]==x*3)id[i]=x,inv[i]=1;
		if (!id[i])return printf("No\n"),0;
		if (i%2!=id[i]%2)return printf("No\n"),0;
	}
	int inv0=0,inv1=0;
	fo(i,1,n)
	if (i&1)inv1^=inv[i];else inv0^=inv[i];
	int flip0=(n/2)&1,flip1=(n&1)^((n/2)&1);
	fo(i,1,n)
	if (!vis[i]){
		if (i&1)flip1^=1;else flip0^=1;
		vis[i]=1;
		for(int x=id[i];x!=i;x=id[x])vis[x]=1;
	}
	if (flip1!=inv0||inv1!=flip0)printf("No\n");
	else printf("Yes\n");
	return 0;
}