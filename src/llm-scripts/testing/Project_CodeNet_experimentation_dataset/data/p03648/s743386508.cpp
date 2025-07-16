#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define per(i,b,a) for(int i=b;i>=a;i--)
#define For(i,a,b) for(int i=a;i<=b;i++)
#define Forenska(it,c) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define fi first
#define se second
#define all(x) x.begin(),x.end()
#define sqr(x) ((x)*(x))
#define lowbit(x) ((x)&(-x))
#define GREATER(x) x,vector<x>,greater<x>
#define randIn(L,R) (((LL)rand()*rand())%(R-L)+L)
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
typedef pair<LL,LL> pLL;
typedef vector<int> vec;
typedef vector<LL> vecL;
typedef vector<pii> vecP;
typedef vector<pLL> vecPL;
typedef vector<string> vecS;
typedef vector<vec> mat;
typedef complex<double> point;
const long double PI=3.14159265358979323846264338327950;
const LL INFLL=0x3f3f3f3f3f3f3f3f;
const int INF=0x3f3f3f3f;
const long double EPS=1e-10;
LL read()
{
    LL x=0;
    char ch=' ';
    bool flag=false;
    while(ch<'0' || ch>'9')
    {
        if(ch=='-')flag=true;
        ch=getchar();
    }
    while(ch>='0' && ch<='9')
    {
        x=(x<<3)+(x<<1)+ch-'0';
        ch=getchar();
    }
    return flag?-x:x;
}
int lcm(int a,int b)
{
	return a/__gcd(a,b)*b;
}

int main()
{
	LL k=read(),L=k/50,M=k%50;
	cout<<50<<endl;
	For(i,1,50)cout<<49-M+(i<=M)*51+L<<" ";
	return 0;
}


