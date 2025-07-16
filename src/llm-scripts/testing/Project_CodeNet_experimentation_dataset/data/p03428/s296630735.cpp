//Relive your past life.
//Face your demons.
//The past is never dead,it is not even past.
//The memories are not only the key to the past but...also to the future.
//coded in Rusty Lake
#include<cmath>
#include<math.h>
#include<ctype.h>
#include<algorithm>
#include<bitset>
#include<cassert>
#include<cctype>
#include<cerrno>
#include<cfloat>
#include<ciso646>
#include<climits>
#include<clocale>
#include<complex>
#include<csetjmp>
#include<csignal>
#include<cstdarg>
#include<cstddef>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<ctime>
#include<cwchar>
#include<cwctype>
#include<deque>
#include<exception>
#include<fstream>
#include<functional>
#include<iomanip>
#include<ios>
#include<iosfwd>
#include<iostream>
#include<istream>
#include<iterator>
#include<limits>
#include<list>
#include<locale>
#include<map>
#include<memory>
#include<new>
#include<numeric>
#include<ostream>
#include<queue>
#include<set>
#include<sstream>
#include<stack>
#include<stdexcept>
#include<streambuf>
#include<string>
#include<typeinfo>
#include<utility>
#include<valarray>
#include<vector>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>
//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define ll   long long
#define pb   push_back
#define mp   make_pair
#define orz  1000000007
#define fi   first
#define se   second
using namespace std;
struct P{int x,y;};
P mns(P x,P y){x.x-=y.x,x.y-=y.y;return x;}
ll det(P x,P y){return x.x*1ll*y.y-x.y*1ll*y.x;}
int n;
pair<pair<int,int>,int> p[105];
int U,D,iu[105],id[105],Q,iq[105];
P pu[105],pd[105],pq[105];
double ans[105],PI=6.2831853071795864769;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d%d",&p[i].fi.fi,&p[i].fi.se),p[i].se=i;
	sort(p+1,p+n+1);
	for(int i=1;i<=n;++i){
		P a;
		a.x=p[i].fi.fi,a.y=p[i].fi.se;
        while(U>1&&det(mns(pu[U],pu[U-1]),mns(a,pu[U]))>=0)--U;
        pu[++U]=a;
        iu[U]=p[i].se;
    }
    for(int i=1;i<=n;++i){
		P a;
		a.x=p[i].fi.fi,a.y=p[i].fi.se;
        while(D>1&&det(mns(pd[D],pd[D-1]),mns(a,pd[D]))<=0)--D;
        pd[++D]=a;
        id[D]=p[i].se;
    }
    for(int i=1;i<=U;++i)++Q,iq[Q]=iu[i],pq[Q]=pu[i];
    for(int i=D-1;i>1;--i)++Q,iq[Q]=id[i],pq[Q]=pd[i];
    if(Q==2){
    	ans[iq[1]]=ans[iq[2]]=0.5;
    }
    else{
    	pq[Q+1]=pq[1];
    	pq[0]=pq[Q];
    	for(int i=1;i<=Q;++i){
    		P p1=mns(pq[i],pq[i-1]),p2=mns(pq[i+1],pq[i]);
    		double d=acos((p1.x*1.0*p2.x+p1.y*1.0*p2.y)/sqrt(p1.x*1.0*p1.x+p1.y*1.0*p1.y)/sqrt(p2.x*1.0*p2.x+p2.y*1.0*p2.y));
    		ans[iq[i]]=d/PI;
    	}
    }
    for(int i=1;i<=n;++i)printf("%.10lf\n",ans[i]);
    return 0;
}
