#include<cstdio>
#define RI register int
#define CI const int&
using namespace std;
const int N=1005;
char
tp5[N][N]={
			"aabc.",
			"..bcd",
			"fee.d",
			"f.ghh",
			"iigjj"
		},
tp7[N][N]={
			"ab...c.",
			"ab...c.",
			"..dee.f",
			"..d.g.f",
			"..hhg.i",
			"jj..kki",
			"llmm.nn"
		};
int n; char a[N][N];
inline void odd_paint(CI sx=0)
{
	for (RI i=sx;i<n;i+=2)
	a[i][i]=a[i][i+1]='a',a[i+1>=n?i+1-n+sx:i+1][i]=a[i+1>=n?i+1-n+sx:i+1][i+1]='b',
	a[i+2>=n?i+2-n+sx:i+2][i]=a[i+3>=n?i+3-n+sx:i+3][i]='c',a[i+2>=n?i+2-n+sx:i+2][i+1]=a[i+3>=n?i+3-n+sx:i+3][i+1]='d';
}
inline void print(CI n,char c[N][N])
{
	for (RI i=0;i<n;++i)
	{
		for (RI j=0;j<n;++j) putchar(c[i][j]); if (i!=n-1) putchar('\n');
	}
}
int main()
{
	RI i,j; scanf("%d",&n); if (n==2) return puts("-1"),0;
	if (n==5) return print(5,tp5),0;
	if (n==7) return print(7,tp7),0;
	for (i=0;i<n;++i) for (j=0;j<n;++j) a[i][j]='.';
	if (n%3==0)
	{
		for (i=0;i<n;i+=3) for (j=0;j<n;j+=3)
		a[i][j]=a[i][j+1]='a',a[i+1][j+2]=a[i+2][j+2]='b';
		return print(n,a),0;
	}
	if (n%2==0) return odd_paint(),print(n,a),0;
	for (i=0;i<5;++i) for (j=0;j<5;++j) a[i][j]=tp5[i][j];
	return odd_paint(5),print(n,a),0;
}