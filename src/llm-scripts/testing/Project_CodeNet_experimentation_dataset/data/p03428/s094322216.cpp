#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <set>
#include <map>
#include <queue>
#include <iostream>
#include <sstream>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <cstring>
#include <cctype>
#include <cassert>
#include <limits>
#include <functional>
#include <iomanip>
#include <complex>
#include <bitset>
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
#if defined(_MSC_VER) || __cplusplus > 199711L
#define aut(r,v) auto r = (v)
#else
#define aut(r,v) __typeof(v) r = (v)
#endif
#define each(it,o) for(aut(it, (o).begin()); it != (o).end(); ++ it)
#define all(o) (o).begin(), (o).end()
#define pb(x) push_back(x)
#define mp(x,y) make_pair((x),(y))
#define mset(m,v) memset(m,v,sizeof(m))
#define INF 0x3f3f3f3f3f3f3f3fLL
#define SIZE 200010

using namespace std;
typedef vector<int> vi; typedef pair<int, int> pii; typedef vector<pair<int, int> > vpii; typedef long long ll;
typedef pair<int,ll> pill; typedef pair<ll,int> plli; 
typedef pair<double, int> pdi;
template<typename T, typename U> inline void amin(T &x, U y) { if(y < x) x = y; }
template<typename T, typename U> inline void amax(T &x, U y) { if(x < y) x = y; }
typedef complex<double> P;
long long int MOD = 1000000007;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};


int N;
double pi=2.0*acos(0.0);
vector<pair<pair<double,double>,int> > data;
vi ans;
double calcvec(pair<double,double> hoge1,pair<double,double> hoge2){
	double x=hoge2.first,y=hoge2.second;
	x-=hoge1.first,y-=hoge1.second;
	double ret=acos(x/sqrt(x*x+y*y));
	if(y<0)ret=2.0*pi-ret;
	return ret;
}
double calckaku(double a,double b){
	double ret=b-a;
	if(ret<0)ret+=2.0*pi;
	return ret;
}
int main(){
	cin>>N;
	int lef=0;
	for(int i=0;i<N;i++){
		double x,y;
		cin>>x>>y;
		data.pb(mp(mp(x,y),i));
	}
	sort(data.begin(),data.end());
	reverse(data.begin(),data.end());
	int num=0,nxnum;
	double kakub=acos(0.0);
	while(1){
		nxnum=0;
		double mi=2.0*pi,kakumemo;
		for(int i=0;i<N;i++){
			if(i!=num){
				double kaku=calcvec(data[num].first,data[i].first);
				double kakuc=calckaku(kakub,kaku);
				if(kakuc<mi){
					mi=kakuc,nxnum=i,kakumemo=kaku;
				}
			}
		}
		ans.pb(num);
		kakub=kakumemo;
		if(nxnum==0)break;
		num=nxnum;
	}
	double ans2[105]={0.0};
	int n=ans.size();
	for(int i=0;i<n;i++){
		int n1=ans[i],n2=ans[((i+1)%n)],n0=ans[((i+n-1)%n)];
		double ka1=calcvec(data[n1].first,data[n2].first);
		double ka2=calcvec(data[n0].first,data[n1].first);
		double ka=calckaku(ka2,ka1);
		ans2[data[ans[i]].second]=ka/(2.0*pi);
	}
	for(int i=0;i<N;i++)printf("%.7lf\n",ans2[i]);
}