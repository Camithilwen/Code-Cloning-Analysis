#include <bits/stdc++.h>
#define range(i,c,o) for(register int i=(c);i<(o);++i)
using namespace std;

// fast_io BEGIN HERE
namespace IO
{
	static const size_t isize=1000000;
	char *cur,pool[isize];
	inline void clear()
	{
		rewind(stdin),cur=pool+isize;
	}
	inline char getC()
	{
		if(cur==pool+isize)
		{
			int siz=fread(pool,1,isize,stdin);
			if(siz<isize) pool[siz]='\0'; cur=pool;
			if(!siz) return '\0';
		}
		return *(cur++);
	}
	inline unsigned getU()
	{
		char c; unsigned r=0;
		while(!isdigit(c=getC()));
		for(;isdigit(c);c=getC())
		{
			r=(r<<3)+(r<<1)+c-'0';
		}
		return r;
	}
	inline char *getS(char*str)
	{
		char *i=str,c; while(isspace(c=getC()));
		for(;!isspace(c)&&c;c=getC()) *(i++)=c;
		return *i='\0',str;
	}
	static const size_t osize=100;
	char stk[osize];
	template<typename T>
	inline size_t putU(const T&n,const char&c='\n')
	{
		int bot=osize;
		stk[--bot]=c,stk[--bot]=n%10+'0';
		for(T i=n;i/=10;stk[--bot]=i%10+'0');
		return fwrite(stk+bot,osize-bot,1,stdout);
	}
	inline size_t putS(const char*str)
	{
		return fwrite(str,strlen(str),1,stdout);
	}
}
// fast_io END HERE

static int N;

// BIT BEGIN HERE
int bit[1000005];

inline int lowbit(const int&x) {return x&-x;}

inline void modify(const int&x,const int&y)
{
	for(int i=x+1;i;i-=lowbit(i)) bit[i]=min(bit[i],y);
}

inline int query(const int&x)
{
	int ret=0x7FFFFFFF;
	for(int i=x+1;i<N+2;i+=lowbit(i)) ret=min(ret,bit[i]);
	return ret;
}
// BIT END HERE

char S[1000005],T[1000005];
int pre[1000005],las[1000005],rec[1000005];
deque<int> que;
int main()
{
	//freopen("game.in" ,"r",stdin );
	//freopen("game.out","w",stdout);
	IO::clear(),N=IO::getU();
	IO::getS(S),IO::getS(T);
	if(!strcmp(S,T)) return IO::putS("0\n"),0;
	for(int i=N,j=N;i--;pre[i]=j)
	{
		for(j-=j>i;~j&&S[j]!=T[i];--j);
		if(!~j) return IO::putS("-1\n"),0;
	}
	int ans=0,cnt=0;
	for(int i=0;i<N;)
	{
		rec[cnt]=i,las[cnt++]=pre[i];
		for(++i;i<N&&pre[i]==pre[i-1];++i);
	}
	memset(bit,0x7F,sizeof bit);
	modify(N-cnt,cnt+1);
	for(int i=cnt;i--;)
	{
		modify(las[i]-i,i+1);
		ans=max(ans,query(rec[i]-i)-i);
	}
	return IO::putU(ans),0;
}