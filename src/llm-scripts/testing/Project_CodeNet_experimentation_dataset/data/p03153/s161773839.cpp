#include<cstdio>
#include<algorithm>

using int64=long long;
using uchar=unsigned char;

constexpr int maxn(200000);
constexpr int64 inf(1e17);

template<class _Tp>
	inline bool bchkMin(_Tp&x,const _Tp&y)
		{return(x>y)&&(x=y,1);}

namespace IOManager{
	constexpr int FILESZ(131072);
	char buf[FILESZ];
	const char*ibuf=buf,*tbuf=buf;

	struct IOManager{
		inline char gc()
			{return(ibuf==tbuf)&&(tbuf=(ibuf=buf)+fread(buf,1,FILESZ,stdin),ibuf==tbuf)?EOF:*ibuf++;}

		template<class _Tp>
			inline operator _Tp(){
				_Tp s=0u;char c=gc();
				for(;c<48;c=gc());
				for(;c>47;c=gc())
					s=(_Tp)(s*10u+c-48u);
				return s;
			}
	};
}IOManager::IOManager io;

int sz[maxn+1];
int64 szl[maxn+1],szr[maxn+1];

struct Edge{
	int s,t;int64 w;

	inline void init(const int&is,const int&it,const int64&iw)
		{s=is;t=it;w=iw;}

	inline bool operator<(const Edge&rhs)
		const{return w<rhs.w;}
}e[maxn*30],*cur=e;

void calc(const int&l,const int&r){
	if(l==r)
		return;
	const int m=(l+r)>>1;

	int lmp,rmp;
	int64 lmv=inf,rmv=inf;

	for(int i=l;i<=m;++i)
		if(bchkMin(lmv,szl[i]))
			lmp=i;
	for(int i=m+1;i<=r;++i)
		if(bchkMin(rmv,szr[i]))
			rmp=i;

	for(int i=l;i<=m;++i)
		(++cur)->init(i,rmp,szl[i]+rmv);
	for(int i=m+1;i<=r;++i)
		(++cur)->init(lmp,i,lmv+szr[i]);

	calc(l,m);calc(m+1,r);
}

int ufs[maxn+1];

inline int anc(const int&v)
	{return v==ufs[v]?v:ufs[v]=anc(ufs[v]);}

int main(){
	const int n=io,D=io;
	int64 t=0;
	for(int i=1;i<=n;++i,t+=D)
		ufs[i]=i,
		sz[i]=io,
		szl[i]=sz[i]-t,
		szr[i]=sz[i]+t;

	calc(1,n);
	std::sort(e+1,cur+1);
	int64 ans=0;
	for(Edge*i=e+1;i<=cur;++i)
		if(anc(i->s)!=anc(i->t))
			ans+=i->w,ufs[ufs[i->s]]=ufs[i->t];
	printf("%lld",ans);

	return 0;
}
