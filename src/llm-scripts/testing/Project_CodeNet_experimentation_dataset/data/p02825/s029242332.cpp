#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#define ll long long
#define maxn 1010
inline ll read()
{
	ll x=0; char c=getchar(),f=1;
	for(;c<'0'||'9'<c;c=getchar())if(c=='-')f=-1;
	for(;'0'<=c&&c<='9';c=getchar())x=x*10+c-'0';
	return x*f;
}
inline void write(ll x)
{
	static int buf[20],len; len=0;
	if(x<0)x=-x,putchar('-');
	for(;x;x/=10)buf[len++]=x%10;
	if(!len)putchar('0');
	else while(len)putchar(buf[--len]+'0');
}
inline void writeln(ll x){write(x); putchar('\n');}
inline void writesp(ll x){write(x); putchar(' ');}
const char mat4[4][5]={"aacd","bbcd","cdaa","cdbb"};
const char mat5[5][6]={"aabba","bcc.a","b..cb","a..cb","abbaa"};
const char mat6[6][7]={"aabcc.","b.b..c","baa..c","cc.aab","..cb.b","..cbaa"};
const char mat7[7][8]={"aa.bb.a",".cc..ca","b.dd.c.","b...d.b",".c..d.b","ac..cc.","a.bb.aa"};
char mat[maxn][maxn];
int n;
int main()
{
	n=read();
	if(n<=2){
		puts("-1"); return 0;
	}
	if(n==3){
		puts("aab\nb.b\nbaa");
		return 0;
	}
	memset(mat,'.',sizeof(mat));
	for(int i=0;i<=n-8;i+=4){
		for(int j=0;j<4;j++)
			for(int k=0;k<4;k++)
				mat[i+j][i+k]=mat4[j][k];
	}
	switch(n%4)
	{
		case 0:{
			for(int i=0;i<4;i++)
				for(int j=0;j<4;j++)
					mat[n-4+i][n-4+j]=mat4[i][j];
			break;
		}
		case 1:{
			for(int i=0;i<5;i++)
				for(int j=0;j<5;j++)
					mat[n-5+i][n-5+j]=mat5[i][j];
			break;
		}
		case 2:{
			for(int i=0;i<6;i++)
				for(int j=0;j<6;j++)
					mat[n-6+i][n-6+j]=mat6[i][j];
			break;
		}
		case 3:{
			for(int i=0;i<7;i++)
				for(int j=0;j<7;j++)
					mat[n-7+i][n-7+j]=mat7[i][j];
			break;
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++)
			putchar(mat[i][j]);
		putchar('\n');
	}
	return 0;
}