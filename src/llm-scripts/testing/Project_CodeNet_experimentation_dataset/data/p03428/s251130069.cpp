//by yjz
#include<bits/stdc++.h>
using namespace std;
#define FF first
#define SS second
#define PB push_back
#define MP make_pair
#define bged(v) (v).begin(),(v).end()
#define foreach(it,s) for(__typeof((s).begin()) it=(s).begin();it!=(s).end();it++)
typedef long long ll;
const int Imx=2147483647;
const ll Lbig=2e18;
const int mod=1e9+7;
//My i/o stream
struct fastio
{
	char s[100000];
	int it,len;
	fastio(){it=len=0;}
	inline char get()
	{
		if(it<len)return s[it++];it=0;
		len=fread(s,1,100000,stdin);
		if(len==0)return EOF;else return s[it++];
	}
	bool notend()
	{
		char c=get();
		while(c==' '||c=='\n')c=get();
		if(it>0)it--;
		return c!=EOF;
	}
}_buff;
#define geti(x) x=getnum()
#define getii(x,y) geti(x),geti(y)
#define getiii(x,y,z) getii(x,y),geti(z)
#define puti(x) putnum(x),putchar(' ')
#define putii(x,y) puti(x),puti(y)
#define putiii(x,y,z) putii(x,y),puti(z)
#define putsi(x) putnum(x),putchar('\n')
#define putsii(x,y) puti(x),putsi(y)
#define putsiii(x,y,z) putii(x,y),putsi(z)
inline ll getnum()
{
	ll r=0;bool ng=0;char c;c=_buff.get();
	while(c!='-'&&(c<'0'||c>'9'))c=_buff.get();
	if(c=='-')ng=1,c=_buff.get();
	while(c>='0'&&c<='9')r=r*10+c-'0',c=_buff.get();
	return ng?-r:r;
}
template<class T> inline void putnum(T x)
{
	if(x<0)putchar('-'),x=-x;
	register short a[20]={},sz=0;
	while(x)a[sz++]=x%10,x/=10;
	if(sz==0)putchar('0');
	for(int i=sz-1;i>=0;i--)putchar('0'+a[i]);
}
inline char getreal(){char c=_buff.get();while(c<=32)c=_buff.get();return c;}
ll qpow(ll x,ll k){return k==0?1:1ll*qpow(1ll*x*x%mod,k>>1)*(k&1?x:1)%mod;}
const double eps=1e-7;
const double pi=acos(-1);
bool is0(double x){return x>-eps&&x<eps;}
struct point
{
	double x,y;
	point(double _x=0,double _y=0){x=_x;y=_y;}
	point operator+(const point &t)const{return point(x+t.x,y+t.y);}
	point operator-(const point &t)const{return point(x-t.x,y-t.y);}
	point operator*(const point &t)const{return point(x*t.x-y*t.y,x*t.y+y*t.x);}
	point operator*(const double &t)const{return point(x*t,y*t);}
	point operator/(const double &t)const{return point(x/t,y/t);}
	point operator-()const{return point(-x,-y);}
	double len()const{return sqrt(x*x+y*y);}
	point operator/(const point &t)const{return point(x*t.x+y*t.y,-x*t.y+y*t.x)/t.len()/t.len();}
	double det(const point &t)const{return x*t.y-y*t.x;}
	double dot(const point &t)const{return x*t.x+y*t.y;}
	double len2()const{return x*x+y*y;}
	point unit()const{return (*this)/len();}
	bool operator<(const point &t)const{return is0(x-t.x)?y<t.y:x<t.x;}
	bool operator==(const point &t)const{return is0(x-t.x)&&is0(y-t.y);}
	void out(){cerr<<x<<","<<y<<endl;}
	double rad()const{return atan2(y,x);}
	point conj()const{return point(x,-y);}
};
point a[111];
int n;
int main()
{
	geti(n);
	for(int i=1;i<=n;i++)
	{
		int x,y;
		getii(x,y);
		a[i].x=x;a[i].y=y;
	}
	for(int i=1;i<=n;i++)
	{
		vector<pair<double,int> > v;
		int cur=0;
		for(int j=1;j<=n;j++)
		{
			if(i==j)continue;
			point p=(a[j]-a[i])*point(0,-1);
			point q=(a[j]-a[i])*point(0,1);
			double l=p.rad();
			double r=q.rad();
			v.PB(MP(l,1));
			v.PB(MP(r,-1));
			if(l>r)cur++;
		}
		v.PB(MP(-acos(-1),0));
		v.PB(MP(acos(-1),0));
		sort(v.begin(),v.end());
		double sum=0;
		for(int j=0;j+1<v.size();j++)
		{
			cur+=v[j].SS;
			if(cur==0)
			{
				sum+=v[j+1].FF-v[j].FF;
			}
		}
		cout<<fixed<<setprecision(10)<<sum/acos(-1)/2<<endl;
	}
	
	return 0;
}
