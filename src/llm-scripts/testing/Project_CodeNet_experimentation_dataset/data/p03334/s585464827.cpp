#include <cstdio> 
typedef long long ll;
#define ri register int
namespace io {
	const int SIZE = (1 << 21) + 1;
	char ibuf[SIZE], *iS, *iT, obuf[SIZE], *oS = obuf, *oT = oS + SIZE - 1, c, qu[55]; int f, qr;
	// getchar
	#define gc() (iS == iT ? (iT = (iS = ibuf) + fread (ibuf, 1, SIZE, stdin), (iS == iT ? EOF : *iS ++)) : *iS ++)
	// print the remaining part
	inline void flush () {
		fwrite (obuf, 1, oS - obuf, stdout);
		oS = obuf;
	}
	// putchar
	inline void putc (char x) {
		*oS ++ = x;
		if (oS == oT) flush ();
	}
	// input a signed integer
	template <class I>
	inline void gi (I &x) {
		for (f = 1, c = gc(); c < '0' || c > '9'; c = gc()) if (c == '-') f = -1;
		for (x = 0; c <= '9' && c >= '0'; c = gc()) x = (x << 1) + (x << 3) + (c & 15); x *= f;
	}
	// print a signed integer
	template <class I>
	inline void print (I x) {
		if (!x) putc ('0'); if (x < 0) putc ('-'), x = -x;
		while (x) qu[++ qr] = x % 10 + '0',  x /= 10;
		while (qr) putc (qu[qr --]);
	}
	//no need to call flush at the end manually!
	struct Flusher_ {~Flusher_(){flush();}}io_flusher_;
}
using io :: gi;
using io :: putc;
using io :: print;
const int N=605;
int n,m,col1[N][N],col2[N][N],tag[2][2];
inline void solve(ri d,int col[N][N]){
	ri i,j,k;
	k=0;
	while(d%4==0) d>>=2,++k;
	if(d&1){
		for(i=0;i<m;++i)
			for(j=0;j<m;++j)
				if((i>>k)+(j>>k)&1)
					col[i][j]=1;
	}
	else{
		for(i=0;i<m;++i)
			for(j=0;j<m;++j)
				if((i>>k)&1)
					col[i][j]=1;
	}
}
int main(){
	ri d1,d2,i,j,x,y,cnt;
	gi(n);gi(d1);gi(d2); 
	m=n<<1;
	solve(d1,col1);
	solve(d2,col2);
	for(i=0;i<m;++i)
		for(j=0;j<m;++j)
			++tag[col1[i][j]][col2[i][j]];
	for(i=0;i<=1;++i)
		for(j=0;j<=1;++j)
			if(tag[i][j]>=n*n){
				cnt=0;
				for(x=0;x<m;++x)
					for(y=0;y<m;++y)
						if(col1[x][y]==i&&col2[x][y]==j){
							print(x);putc(' ');print(y);putc('\n');
							if(++cnt==n*n) return 0;
						}
			}
}