#include<cstdio>
#include<cctype>
#include<cstdlib>
#include<algorithm>
typedef signed long long int int64;
inline unsigned getint() {
	register char ch;
	while(!isdigit(ch=getchar()));
	register unsigned x=ch^'0';
	while(isdigit(ch=getchar())) x=(((x<<2)+x)<<1)+(ch^'0');
	return x;
}
inline int64 min(const int64 &a,const int64 &b) {
	return a<b?a:b;
}
const int64 inf=0x7ffffffffffffff;
const int N=200001;
int n;
class FenwickTree {
	private:
		int64 val[N];
		int lowbit(const int &x) const {
			return x&-x;
		}
	public:
		FenwickTree() {
			std::fill(&val[0],&val[N],inf);
		}
		void modify(int p,const int64 &x) {
			while(p<=n) {
				if(x<val[p]) {
					val[p]=x;
				} else 
				p+=lowbit(p);
			}
		}
		int64 query(int p) const {
			int64 ret=inf;
			while(p) {
				ret=min(ret,val[p]);
				p-=lowbit(p);
			}
			return ret;
		}
};
FenwickTree ta;
class RevFenwickTree {
	private:
		int64 val[N];
		int lowbit(const int &x) const {
			return x&-x;
		}
	public:
		RevFenwickTree() {
			std::fill(&val[0],&val[N],inf);
		}
		void modify(int p,const int64 &x) {
			while(p) {
				if(x<val[p]) {
					val[p]=x;
				}
				p-=lowbit(p);
			}
		}
		int64 query(int p) const {
			int64 ret=inf;
			while(p<=n) {
				ret=min(ret,val[p]);
				p+=lowbit(p);
			}
			return ret;
		}
};
RevFenwickTree tb;
int64 f[N];
inline void modify(const int &p,const int64 x) {
	if(1) {
		f[p]=x;
		ta.modify(p,x-p);
		tb.modify(p,x+p);
	}
}
int main() {
	n=getint();
	int q=getint(),a=getint(),b=getint();
	std::fill(&f[0],&f[N],inf);
	modify(a,0);
	int64 sum=0;
	while(q--) {
		a=b;
		b=getint();
		sum+=abs(a-b);
		int64 t1=ta.query(b)+b,t2=tb.query(b)-b;
		modify(a,min(t1,t2)-abs(a-b));
	}
	int64 tmp=inf;
	for(register int i=1;i<=n;i++) {
		tmp=min(tmp,f[i]);
	}
	printf("%lld\n",tmp+sum);
	return 0;
}
