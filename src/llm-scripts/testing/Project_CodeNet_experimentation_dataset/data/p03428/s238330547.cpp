#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
#define pu push
#define pb push_back
#define mp make_pair
#define EPS 1e-7
#define INF 1000000000
#define mod 1000000007
#define fi first
#define sc second
#define x real()
#define y imag()
#define rep(i,x) for(int i=0;i<x;i++)
#define repn(i,x) for(int i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
int n,a[105],b[105];
map<P,int>M;
typedef complex<double> pt;
bool eq(double a,double b){
  return (-EPS < a-b && a-b < EPS);
}
double dot(pt a,pt b){
	return (conj(a)*b).x;
}
double cross(pt a,pt b){
	return (conj(a)*b).y;
}
bool cmp(const pt& a,const pt& b){
	if(-EPS < a.x-b.x && a.x-b.x < EPS) return a.y < b.y;
	else return a.x < b.x;
}
int ccw(pt a,pt b,pt c){
	b -= a; c -= a;
	//cout<<cross(b,c)<<endl;
	if(cross(b,c) > EPS) return 1; // counter clockwise
	if(cross(b,c) < -EPS) return -1; // clockwise
	if(dot(b,c) < -EPS) return 2; //c-a-b
	if(norm(b) < norm(c)) return -2; //a-b-c
	return 0; //a-c-b
}
vector<pt>convex_hull(vector<pt>ps)
{
	sort(ps.begin(),ps.end(),cmp);
	int k=0,n = ps.size();
	vector<pt>qs(n*2);
	for(int i=0;i<n;i++)
	{
		while(k>1 && ccw(qs[k-2],qs[k-1],ps[i]) != 1) k--;
		qs[k++] = ps[i];
	}
	for(int i=n-2,t=k;i>=0;i--)
	{
		while(k>t && ccw(qs[k-2],qs[k-1],ps[i]) != 1) k--;
		qs[k++] = ps[i];
	}
	qs.resize(k-1);
	return qs;
}

double ans[105];
int main(){
	cin>>n;
	vector<pt>vec;
	rep(i,n){
		cin>>a[i]>>b[i];
		M[mp(a[i],b[i])] = i;
		vec.pb(pt((double)(a[i]),(double)(b[i])));
	}
	vector<pt>c = convex_hull(vec);
	if(c.size() == 2){
		int xx = floor(c[0].real()+0.5);
		int yy = floor(c[0].imag()+0.5);
		ans[M[mp(xx,yy)]] = 0.5;
		xx = floor(c[1].real()+0.5);
		yy = floor(c[1].imag()+0.5);
		ans[M[mp(xx,yy)]] = 0.5;
	}
	else{
		for(int i=0;i<c.size();i++){
			pt q = c[i];
			pt p = c[(i-1+c.size())%c.size()];
			pt r = c[(i+1)%c.size()];
			double v = arg((p-q)/(r-q));
			v = 3.141592653589 - v;
			int xx = floor(c[i].real()+0.5);
			int yy = floor(c[i].imag()+0.5);
			ans[M[mp(xx,yy)]] = v / (2.0*3.141592653589);
		}
	}
	rep(i,n){
		printf("%.12f\n",ans[i]);
	}
}