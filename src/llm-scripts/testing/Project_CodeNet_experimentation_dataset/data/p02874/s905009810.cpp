/*Lower_Rating*/
/*AGC040 B*/
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<vector>
using namespace std;

#define LL long long
#define MAXN 800000
#define MOD 998244353
#define Pr pair<int,int>
#define X first
#define Y second
#define INF 2000000000
#define mem(x,p) memset(x,p,sizeof(x))

LL read(){
  LL x=0,F=1;char c=getchar();
  while(c<'0'||c>'9'){if(c=='-')F=-1;c=getchar();}
  while(c>='0'&&c<='9'){x=(x<<3)+(x<<1)+c-'0';c=getchar();}
  return x*F;
}
int add(int x,int y){return (x+y>=MOD)?x+y-MOD:x+y;}
int dec(int x,int y){return (x-y<0)?x-y+MOD:x-y;}
int mul(int x,int y){return 1LL*x*y%MOD;}

int n,mn,id;
struct Seg{
	int l,r;
}p[MAXN+5];
bool cmp(Seg s1,Seg s2){
	if(s1.l==s2.l)return s1.r<s2.r;
	return  s1.l<s2.l;
}
int bin(int l1,int r1,int l2,int r2){
	return max(min(r1,r2)-max(l1,l2)+1,0);
}
int main()
{
	n=read();mn=INF;
	for(int i=1;i<=n;i++)
		p[i].l=read(),p[i].r=read();
    sort(p+1,p+n+1,cmp);
	int l1=p[1].l,r1=p[1].r,l2=p[2].l,r2=p[2].r;
	for(int i=2;i<=n;i++){
		int val1=max(r2-l2+1,0)+bin(l1,r1,p[i].l,p[i].r);
		int val2=max(r1-l1+1,0)+bin(l2,r2,p[i].l,p[i].r);
        int val3=max(p[i].r-p[i].l+1,0)+bin(l1,r1,l2,r2);
		if(val1>=val2&&val1>=val3){
			l1=max(l1,p[i].l);
			r1=min(r1,p[i].r);
		}else if(val2>=val1&&val2>=val3){
			l2=max(l2,p[i].l);
			r2=min(r2,p[i].r);
		}else{
            l1=max(l1,l2);
			r1=min(r1,r2);
            l2=p[i].l,r2=p[i].r;
        }
	}
	printf("%d",max(r1-l1+1,0)+max(r2-l2+1,0));
}
