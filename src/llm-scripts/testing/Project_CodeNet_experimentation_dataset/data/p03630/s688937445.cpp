//    Have a nice day
//    ∠( ᐛ 」∠)

#include<bits/stdc++.h>

#define mp make_pair
#define pb push_back
#define x first
#define y second

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;

template <typename T> inline T read()
{
	T sum=0, fl=1; char ch=getchar();
	for(; !isdigit(ch); ch=getchar()) if(ch=='-') fl=-1;
	for(; isdigit(ch); ch=getchar()) sum=(sum<<3)+(sum<<1)+ch-'0';
	return sum*fl;
}

const int maxn=2000+5;
int n, m, ans;
char s[maxn][maxn];
int l[maxn], r[maxn], h[maxn], c[maxn][maxn];

void Solve()
{
	n=read<int>(), m=read<int>(); ans=max(n, m);
	for(int i=1; i<=n; ++i) scanf("%s", s[i]+1);
	--n, --m;
	for(int i=1; i<=n; ++i)
		for(int j=1; j<=m; ++j)
			if(((s[i][j]=='#')+(s[i+1][j]=='#')+(s[i][j+1]=='#')+(s[i+1][j+1]=='#'))&1);
			else c[i][j]=1;

	for(int i=1; i<=m; ++i) l[i]=r[i]=maxn;
	for(int i=1; i<=n; ++i)
	{
		for(int j=1, p=0; j<=m; ++j)
		{
			if(c[i][j]) ++p; else p=0;
			l[j]=min(l[j], p);
		}
		for(int j=m, p=0; j>=1; --j)
		{
			if(c[i][j]) ++p; else p=0;
			r[j]=min(r[j], p);
		}
		for(int j=1; j<=m; ++j) 
		{
			if(c[i][j]) ++h[j], ans=max(ans, (l[j]+r[j])*(h[j]+1));
			else l[j]=r[j]=maxn, h[j]=0;
		}
	}
	printf("%d\n", ans);
}

int main()
{

   // freopen("081d.in","r",stdin);
    //freopen("081d.out","w",stdout);

    Solve();

    return 0;
}

